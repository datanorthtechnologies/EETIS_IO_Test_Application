#include "plcComm.h"
#include <QThread>


plcComm::plcComm(QObject *parent) : QObject(parent)
{
    modbusTcpSocket = new QTcpSocket(this);

    connectModbusTcpSocket(IP_ADDR, PORT_NUM);
    qDebug("modbusTcpSocket:%d", modbusTcpSocket);

    setBaseAddrOfDI(BASE_DI_REG_ADDR);
    setBaseAddrOfDO(BASE_DO_REG_ADDR);
    setBaseAddrOfAI(BASE_AI_REG_ADDR);
    setBaseAddrOfAO(BASE_AO_REG_ADDR);

    //    qRegisterMetaType<QAbstractSocket::SocketError>("QAbstractSocket::SocketError");

    qDebug("before calling connect of onconnected inside constructor of plcComm");
    connect(modbusTcpSocket, &QTcpSocket::connected, this, &plcComm::onConnected);
    connect(modbusTcpSocket, &QTcpSocket::disconnected, this, &plcComm::onDisconnected);
    connect(modbusTcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error), this, &plcComm::onError);

    reconnectTimer = new QTimer(this);
    reconnectTimer->setInterval(5000); // Attempt to reconnect every 5 seconds
    connect(reconnectTimer, &QTimer::timeout, this, &plcComm::reconnect);
    reconnectTimer->start();

    qDebug("At end of constructor of plcComm");
}


void plcComm::initReadWriteTimers()
{
    sendReqTimer = new QTimer(this);
    connect(sendReqTimer, SIGNAL(timeout()), this, SLOT(sendModbusReadWriteRequest()));
    sendReqTimer->start(WRITE_CYCLE_TIME_IN_MS);

    recvReqTimer = new QTimer(this);
    connect(recvReqTimer, SIGNAL(timeout()), this, SLOT(readModbusData()));
    recvReqTimer->start(READ_CYCLE_TIME_IN_MS);

    responseTimer = new QTimer(this);
    responseTimer->setInterval(RESPONSE_TIMEOUT); // Set the timeout interval
    responseTimer->setSingleShot(true); // Make it a single shot timer
    connect(responseTimer, SIGNAL(timeout()), this, SLOT(respTimeOut()));
}

void plcComm::respTimeOut()
{
    waitingResponse = 0;
    //    qDebug() << "Response timeout!";
}

void plcComm::onConnected()
{
    linkStatus = 1;
    reconnectTimer->stop(); // Stop reconnection timer if connected
}

void plcComm::onDisconnected()
{
    linkStatus = 0;
    reconnectTimer->start(); // Start reconnection timer on disconnection
}

void plcComm::onError(QAbstractSocket::SocketError socketError)
{
    linkStatus = 0;
    //qDebug() << "onError's Error: " << modbusTcpSocket->errorString();
    reconnectTimer->start(); // Start reconnection timer on error
}

void plcComm::reconnect()
{
    if (modbusTcpSocket->state() == QAbstractSocket::UnconnectedState)
    {
        //qDebug() << "Inside if Attempting to reconnect...";
        connectModbusTcpSocket(IP_ADDR, PORT_NUM);
    }
}

plcComm::~plcComm()
{
    delete modbusTcpSocket;
}

void plcComm::connectModbusTcpSocket(const QString &host, quint16 port)
{

    modbusTcpSocket->connectToHost(host, port);

    if (!modbusTcpSocket->waitForConnected(3000)) // Wait for 3 seconds to connect
    {
        //qDebug() << "Initial connection error: " << modbusTcpSocket->errorString();
        linkStatus = 0;
        //reconnectTimer->start(); // Start reconnection timer if connection fails

        qDebug() << "Error: " << modbusTcpSocket->errorString();

        // delete modbusTcpSocket;
    }
    else
    {
        qDebug() << "Initial connection successful!";
        linkStatus = 1;
    }
}

void plcComm::sendModbusReadWriteRequest()
{
    if(!modbusTcpSocket->isOpen())
    {
        return;
    }

#if DEBUG
    simulateDoAoData(AO_CHANNEL);
    simulateDoAoData(DO_CHANNEL);
#endif

    if(waitingResponse == 1)
    {
        return;
    }

    if(cycleId == DI_CHANNEL)
    {
        readMulHoldReg(BASE_DI_REG_ADDR, NO_OF_DI_REG, NULL, DI_CHANNEL);
        waitingResponse = 1;
        responseTimer->start();

        cycleId = DO_CHANNEL;
    }
    else if(cycleId == DO_CHANNEL)
    {
        writeMulHoldReg(BASE_DO_REG_ADDR, NO_OF_DO_REG, DO_CHANNEL);
        waitingResponse = 1;
        responseTimer->start();

        cycleId = AI_CHANNEL;
    }
    else if(cycleId == AI_CHANNEL)
    {
        readMulHoldReg(BASE_AI_REG_ADDR, NO_OF_AI_REG, NULL, AI_CHANNEL);
        waitingResponse = 1;
        responseTimer->start();

        cycleId = AO_CHANNEL;
    }
    else if(cycleId == AO_CHANNEL)
    {
        writeMulHoldReg(BASE_AO_REG_ADDR, NO_OF_AO_REG, AO_CHANNEL);
        waitingResponse = 1;
        responseTimer->start();

        cycleId = DI_CHANNEL;
    }
}

void plcComm::readModbusData()
{
    QByteArray response;

    if(modbusTcpSocket->isOpen())
    {
        response = modbusTcpSocket->readAll();

        if(!response.isEmpty())
        {
            decodeDataRecvdFrmPLC(response);
        }
    }
    else
    {
        qDebug() << "Socket not open";
    }
}

void plcComm::sendModbusRequest(QByteArray dataTobeSent)
{
    if(modbusTcpSocket == NULL)
    {
        qDebug("modbusTcpSocket null");
    }
    else if(modbusTcpSocket->isOpen())
    {
        int noBytesWritten = modbusTcpSocket->write(dataTobeSent);
        // qDebug("noBytesWritten:%d", noBytesWritten);

        if (!modbusTcpSocket->waitForBytesWritten())
        {
            //            qDebug() << "Error: " << modbusTcpSocket->errorString();
            return;
        }
    }
}

void plcComm::decodeDataRecvdFrmPLC(QByteArray responseData)
{
    //Check if correct modbus response is received
    if(responseData.length() < 5)
    {
        qDebug("Invalid packet");
        return;
    }

    // qDebug() << "Response received:" << responseData.toHex();

    waitingResponse = 0;
    responseTimer->stop();

    //Extract function code
    unsigned char funcCode = responseData.at(7);

    switch(funcCode)
    {
    //Read Holding registers
    case READ_HOLDING_REGS:
    {
        //Extract data length
        unsigned char dataLength = responseData.at(8);

        for (int i = 0; i < dataLength; i += 2)
        {
            unsigned char lowByte = responseData.at(9+i);
            unsigned char highByte = responseData.at(10+i);

            inputReg[i/2] = ((lowByte << 8) | (highByte));
        }

        //Check if the data is for DI or AI based on transaction ID
        unsigned short transId = (responseData.at(0) << 8) | responseData.at(1);
        if (transId == DI_TRANS_ID)
        {
            // Data is for DI
            // Process DI data here
            unsigned short noOfRegToRead = (((responseData.at(4) << 8) | responseData.at(5))-3)/2;
            storeDiData(noOfRegToRead);
        }
        else if (transId == AI_TRANS_ID)
        {
            // Data is for AI
            // Process AI data here
            unsigned short noOfRegToRead = (((responseData.at(4) << 8) | responseData.at(5))-3)/2;
            storeAiData(noOfRegToRead);
        }
        break;
    }
    }
}

QByteArray plcComm::createModbusWriteRequest(int transId, unsigned char funcCode, unsigned short startingRegAddr,
                                             unsigned short noOfRegToWrite, short* data)
{
    QByteArray request;

    QDataStream stream(&request, QIODevice::ReadWrite);

    // Modbus TCP header
    stream << quint16(transId);                         // Transaction identifier
    stream << quint16(0);                               // Protocol identifier (0 for Modbus TCP/IP)
    stream << quint16(7 + noOfRegToWrite*2);            // Length of remaining packet (6 bytes for Modbus PDU + 2*noOfRegToWrite bytes for data)

    // Modbus PDU
    unsigned char byteCount = noOfRegToWrite * 2;

    //qDebug("byteCount : %d", byteCount);

    stream << quint8(SLAVE_ADDRESS);            // Slave address
    stream << quint8(funcCode);                 // Function code (read function code)
    stream << quint16(startingRegAddr);         // Register address
    stream << quint16(noOfRegToWrite);          // Data to write at the register
    stream << quint8(byteCount);                // Byte count

    //Data to write
    for(int i = 0; i < noOfRegToWrite; i++)
    {
        qint16 value = data[i];
        stream <<value;
    }

    return request;
}

int plcComm::writeMulHoldReg(unsigned short startRegAddr, unsigned short noOfRegToWrite,
                             unsigned char doOrAoChannel)
{
    if(doOrAoChannel == DO_CHANNEL)
    {
        short regArrayForDO[NO_OF_DI_REG] = {0};

        if( (startRegAddr < baseAddrOfDO) || ((((startRegAddr - baseAddrOfDO) + noOfRegToWrite) * 16) > NO_OF_DOs) )
        {
            return -1;
        }
        else
        {
            storeDoDataInRegArray(&regArrayForDO[0], noOfRegToWrite, &plcDOs[startRegAddr-baseAddrOfDO]);

            QByteArray writeDoChannels = createModbusWriteRequest(DO_TRANS_ID, WRITE_MULTIPLE_REGS, startRegAddr, noOfRegToWrite, &regArrayForDO[0]);
            sendModbusRequest(writeDoChannels);

            return 1;
        }
    }
    else if(doOrAoChannel == AO_CHANNEL)
    {
        if( (startRegAddr < baseAddrOfAO) || (((startRegAddr-baseAddrOfAO) + noOfRegToWrite) > NO_OF_BYTES_AO) )
        {
            return -1;
        }
        else
        {
            QByteArray writeAoChannels = createModbusWriteRequest(AO_TRANS_ID, WRITE_MULTIPLE_REGS, startRegAddr, noOfRegToWrite, &plcAOs[startRegAddr-baseAddrOfAO]);
            sendModbusRequest(writeAoChannels);

            return 1;
        }
    }
}

int plcComm::readMulHoldReg(unsigned short startRegAddr, unsigned short noOfRegToRead,
                            unsigned char *data, unsigned char diOrAiChannel)
{
    if(diOrAiChannel == DI_CHANNEL)
    {
        if(startRegAddr < baseAddrOfDI)
        {
            return -1;
        }
        else
        {
            QByteArray readDiChannels;
            readDiChannels = createModbusReadRequest(DI_TRANS_ID, READ_HOLDING_REGS, startRegAddr, noOfRegToRead);
            sendModbusRequest(readDiChannels);
        }
    }
    else if(diOrAiChannel == AI_CHANNEL)
    {
        if(startRegAddr < baseAddrOfAI)
        {
            return -1;
        }
        else
        {
            QByteArray readAiChannels;
            readAiChannels = createModbusReadRequest(AI_TRANS_ID, READ_HOLDING_REGS, startRegAddr, noOfRegToRead);
            sendModbusRequest(readAiChannels);
        }
    }
}

//Store DI data from registers & store into DI arrays
void plcComm::storeDiData(unsigned short noOfRegToRead)
{
    int index = 0, i = 0, bitPos = 0;

    //checking if no of regs are less than or equal to no of DIs
    if(noOfRegToRead <= (NO_OF_DIs / MAX_BITS_IN_REG))
    {
        for(int j = 0; j < noOfRegToRead; j++)
        {
            for(i = index, bitPos = 0; bitPos < MAX_BITS_IN_REG, i < (index + MAX_BITS_IN_REG); bitPos++, i++)
            {
                plcDIs[i] = getBitValFrmReg(inputReg[j] , bitPos);
            }
            index = i;
        }
    }
    else
    {
        qDebug("No of regs are more than DI channels");
    }
}

void plcComm::storeAiData(unsigned short noOfRegToRead)
{
    if (noOfRegToRead <= (NO_OF_BYTES_AI / BYTES_IN_REG))
    {
        for (int i = 0; i < noOfRegToRead; i++)
        {
            plcAIs[i] = inputReg[i];
        }
    }
    else
    {
        qDebug("Number of registers exceeds available AI channels.");
    }
}

bool plcComm::getBitValFrmReg(unsigned short regValue, int bitPosition)
{
    int temp = ( (regValue & (1 << bitPosition)) != 0 );
    return(temp);
}

int plcComm::getDiValue(int diChannel)
{
    int diValue = 0;

    if(diChannel > 0)
    {
        diValue = plcDIs[diChannel - 1];
    }
    return (diValue);}

int plcComm::getDoValue(int doChannel)
{
    int doValue = 0;

    if(doChannel > 0)
    {
        doValue = plcDOs[doChannel - 1];
    }

    return (doValue);
}

short plcComm::getAiValue(int aiChannel)
{
    short aiData = 0;
    unsigned char temp1;
    unsigned char temp2;

    if(aiChannel > 0)
    {
        temp1 = plcAIs[aiChannel - 1] & 0xFF;
        temp2 = (plcAIs[aiChannel - 1] >> 8) & 0xFF;
        aiData = temp1 * 256 + temp2;

        qDebug()<<"plcAIs[aiChannel - 1] :"<<plcAIs[aiChannel - 1];
        qDebug()<<"temp1:"<<temp1;
        qDebug()<<"temp2:"<<temp2;
    }

    return(aiData);
}

short plcComm::getAoValue(int aoChannel)
{
    short aoData = 0;
    unsigned char temp1;
    unsigned char temp2;

    if(aoChannel > 0)
    {
        temp1 = plcAOs[aoChannel - 1] & 0xFF;
        temp2 = (plcAOs[aoChannel - 1] >> 8) & 0xFF;
        aoData = temp1 * 256 + temp2;
    }

    return(aoData);
    //return(plcAOs[aoChannel]);
}

void plcComm::setDoValue(int doChannel, char data)
{
    if(doChannel > 0)
    {
        plcDOs[doChannel - 1] = data;
    }

    //print DOs
//    qDebug() << "DOs:";
//    for(int i = 0; i < NO_OF_DOs; i++)
//    {
//        qDebug() << "plcDOs[" << i << "]:" << plcDOs[i];
    //    }
}


void plcComm::setAoValue(int aoChannel, short data)
{
    qDebug()<< "aoChannel" << aoChannel << "data:" << data;
    unsigned char temp1;
    unsigned char temp2;

    temp1 = data & 0xFF;
    temp2 = (data >> 8) & 0xFF;

    if(aoChannel > 0)
    {
        plcAOs[aoChannel - 1]= temp1 * 256 + temp2;
    }
}

QByteArray plcComm::createModbusReadRequest(int transId, unsigned char funcCode, unsigned short startingRegAddr, unsigned short noOfRegToRead)
{
    QByteArray request;

    QDataStream stream(&request, QIODevice::ReadWrite);

    // Modbus TCP header
    stream << quint16(transId);
    stream << quint16(0);                   // Protocol identifier (0 for Modbus TCP/IP)
    stream << quint16(6);                   // Length of remaining packet (6 bytes for Modbus PDU)

    // Modbus PDU
    stream << quint8(SLAVE_ADDRESS);            // Slave address
    stream << quint8(funcCode);                 // Function code (read function code)
    stream << quint16(startingRegAddr);         // Register address
    stream << quint16(noOfRegToRead);           // Data to write at the register

    return request;
}

void plcComm::storeDoDataInRegArray(short *doDataInRegArray, unsigned short noOfRegToWrite, char *doData)
{
    for(int i = 0; i < (noOfRegToWrite * 16); i++)
    {
        int regNo = i/16;
        short int dataMask = doData[i] << (i % 16);
        doDataInRegArray[regNo] = doDataInRegArray[regNo] | dataMask;
    }
}

bool plcComm::getLinkStatus()
{
    //    qDebug() << "Inside getLinkStatus of plcComm linkStatus:"<< linkStatus;
    return(linkStatus);
}

void plcComm::setBaseAddrOfDI(unsigned short regAddr)
{
    baseAddrOfDI = regAddr;
}

void plcComm::setBaseAddrOfDO(unsigned short regAddr)
{
    baseAddrOfDO = regAddr;
}

void plcComm::setBaseAddrOfAI(unsigned short regAddr)
{
    baseAddrOfAI = regAddr;
}

void plcComm::setBaseAddrOfAO(unsigned short regAddr)
{
    baseAddrOfAO = regAddr;
}

void plcComm::simulateDoAoData(unsigned char aoOrDoChannel)
{
    if(aoOrDoChannel == AO_CHANNEL)
    {
        for(int i = 0; i < NO_OF_BYTES_AO; i++)
        {
            plcAOs[i] = plcAOs[i] + i + 1;
        }
    }
    else if(aoOrDoChannel == DO_CHANNEL)
    {
        for(int i = 0; i < NO_OF_DOs; i++)
        {
            if(plcDOs[i] == 0)
            {
                plcDOs[i] = 1;
            }
            else
            {
                plcDOs[i] = 0;
            }
        }
    }
}
