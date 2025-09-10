#include "fcuccucomm.h"


// Constructor
FCUCCUComm::FCUCCUComm(QObject *parent) : QObject(parent)
{
    // create all the UDP sockets
    AIReadSocket = create_udp_socket(AI_READ_PORT);
    DIReadSocket = create_udp_socket(DI_READ_PORT);
    DOWriteSocket = create_udp_socket(DO_WRITE_PORT);
    AOWriteSocket = create_udp_socket(AO_WRITE_PORT);
    Serial1WriteSocket = create_udp_socket(SERIAL1_WRITE_PORT);
    Serial2WriteSocket = create_udp_socket(SERIAL2_WRITE_PORT);
    Serial3WriteSocket = create_udp_socket(SERIAL3_WRITE_PORT);
    Serial4WriteSocket = create_udp_socket(SERIAL4_WRITE_PORT);

    for (int i = 0; i < 64; i++)
    {
        FCU_CCU_DOWrite[i] =false;
    }

    for (int i = 0; i < 64; i++)
    {
        FCU_CCU_DIRead[i] =false;
    }

    for (int i = 0; i < 8; i++)
    {
        FCU_CCU_AIRead[i] =false;
    }

    for (int i = 0; i < 8; i++)
    {
        FCU_CCU_AOWrite[i] =false;
    }
}

// Destructor
FCUCCUComm::~FCUCCUComm()
{

}

void FCUCCUComm::setIPAddress(std::string ip)
{
    IP_ADDRESS = ip;
}

bool FCUCCUComm::connectUDPSocket()
{
//    QHostAddress server_addr(IP_ADDRESS.c_str());
//    AIReadSocket->connectToHost(server_addr, AI_READ_PORT);

//    if (!AIReadSocket->waitForConnected(3000)) // Wait for 3 seconds to connect
//    {
//        qDebug() << "Initial connection error: " << AIReadSocket->errorString();
//        qDebug() << "Error: " << AIReadSocket->errorString();
//        return false;
//    }
//    else
//    {
//        qDebug() << "Initial connection successful!";
//        return true;
//    }
    return true;
}

// Function to create a UDP socket
QUdpSocket* FCUCCUComm::create_udp_socket(int port)
{
    QUdpSocket* sock = new QUdpSocket();
    if (!sock->bind(QHostAddress::Any, port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint))
    {
        qWarning() << "Socket binding failed:" << sock->errorString();
        delete sock;
        throw QException();
    }

    return sock;
}

// Function to calculate checksum (XOR of all bytes in Data Size + Data)
uint8_t FCUCCUComm::calculate_checksum(const UdpMessage &msg)
{
    uint8_t chk = msg.data_size & 0xFF;
    chk += (msg.data_size >> 8) & 0xFF;
    for (uint8_t byte : msg.data)
    {
        chk += byte;
    }

    chk = ~chk + 1;

    return chk;
}

/*
unsigned char FCUCCUComm::ChecksumCalc(const unsigned char *buf, int len)
{
    int counter;
    unsigned char csum = 0;

    for (counter = 0; counter < len; counter++)
    {
        csum += buf[counter];
    }

    csum = ~csum + 1;
    return csum;
}
*/

// Function to create a UDP message
void FCUCCUComm::create_message(UdpMessage &msg, uint16_t size, const std::vector<uint8_t>& input_data)
{
    if (size > MAX_DATA_SIZE)
    {
        qDebug() << "Data size exceeds maximum limit";
    }

    msg.sof = SOF;
    msg.data_size = size;
    for(uint8_t byte : input_data)
    {
        msg.data.push_back(byte);
    }
    msg.checksum = calculate_checksum(msg);
    msg.eot = EOT;
}

// Serialize message to raw buffer for UDP transmission
std::vector<uint8_t> FCUCCUComm::serialize_message(const UdpMessage &msg)
{
    std::vector<uint8_t> buffer;
    buffer.push_back(msg.sof);
    buffer.push_back(msg.data_size & 0xFF);
    buffer.push_back((msg.data_size >> 8) & 0xFF);
    buffer.insert(buffer.end(), msg.data.begin(), msg.data.end());
    buffer.push_back(msg.checksum);
    buffer.push_back(msg.eot);
    return buffer;
}

// Deserialize received buffer into UdpMessage
FCUCCUComm::UdpMessage FCUCCUComm::deserialize_message(const std::vector<uint8_t>& buffer)
{
    UdpMessage msg;

    if (buffer.size() < 5 || buffer.front() != SOF || buffer.back() != EOT)
    {
        qDebug() << "Invalid message format";
        return msg;
    }

    msg.sof = buffer[0];
    msg.data_size = buffer[1] | (buffer[2] << 8);
    for (size_t i = 3; i < buffer.size() - 2; i++)
    {
        msg.data.push_back(buffer[i]);
    }
    msg.checksum = buffer[buffer.size() - 2];
    msg.eot = buffer[buffer.size() - 1];

    if (msg.checksum != calculate_checksum(msg))
    {
        qDebug() << "Checksum mismatch";
    }

    return msg;
}

// Function to send UDP message
void FCUCCUComm::send_udp_message(const std::string& ip, int port, const UdpMessage& msg, QUdpSocket *sock)
{
    QHostAddress server_addr(ip.c_str());
    std::vector<uint8_t> packet = serialize_message(msg);
    sock->writeDatagram((char*)packet.data(), packet.size(), server_addr, port);
}

// Function to receive UDP message
FCUCCUComm::UdpMessage FCUCCUComm::receive_udp_message(QUdpSocket *sock)
{
    QHostAddress server_addr;
    quint16 port;
    std::vector<uint8_t> buffer(512);
    UdpMessage receivedMsg;
    int received = 0;

    receivedMsg.data_size = 0;

    if(sock->hasPendingDatagrams())
    {
        received = sock->readDatagram((char*)buffer.data(), buffer.size(), &server_addr, &port);
        qDebug()<<"received Input size "<<received;
    }

    if (received <= 0)
    {
        qDebug() << "No message";
    }
    else
    {
        buffer.resize(received);
        receivedMsg = deserialize_message(buffer);
    }

    return receivedMsg;
}

/*****  Application functions *****/

// Function to read AI data from FCU
/*
AI READ : TOTAL 8 Analog Outputs(AO) (4 byte  each DO)—MAX32 BYTES OF DATA
<FE><LENGTH- 2BYTE><AO1-4BYTE><AO2-4BYTE>----------<AO8-4BYTE><CHECKSUM-1BYTE><E7>
*/
void FCUCCUComm::readAIChannels()
{
    float ai_value;

    UdpMessage response = receive_udp_message(AIReadSocket);
      qDebug()<<"response.data_size AI"<<response.data_size;
    // Each channel is 4 bytes, so total 8*4 = 32 bytes
    if (response.data_size < 32)
    {
        qDebug() << "Invalid AI data size";
    }
    else
    {
        for (int i = 0; i < 8; ++i)
        {
            uint32_t raw_value = (response.data[i * 4]) | (response.data[i * 4 + 1] << 8) |
                    (response.data[i * 4 + 2] << 16) | (response.data[i * 4 + 3] << 24);

            memcpy(&ai_value, &raw_value, sizeof(float));

            FCU_CCU_AIRead[i] = ai_value;
        }
        qDebug()<<"ai_value Read value"<<ai_value;

    }
}

/*
DI READ :  TOTAL 64 DO bitwise (1 bit each)-MAX8 BYTES OF DATA
<FE><LENGTH- 2BYTE><DI0-64-8BYTE><CHECKSUM-1BYTE><E7>
*/
void FCUCCUComm::readDIChannels()
{
    UdpMessage response = receive_udp_message(DIReadSocket);

    //bitwiseByteStruct bitwiseData;
    qDebug() << "response"<<response.data_size;
    // 64 bits = 8 bytes
    if (response.data_size < 8)
    {
        qDebug() << "Invalid DI data size";
    }
    else
    {
        for (int i = 0; i < 64; i++)
        {
            FCU_CCU_DIRead[i] = (response.data[i / 8] >> (i % 8)) & 1;

        }

        //        for (int i = 0; i < 8; i++)
        //        {
        //            memcpy(&bitwiseData, &response.data[i], 1);
        //            FCU_CCU_DIRead[i*8] = bitwiseData.bit0;
        //            FCU_CCU_DIRead[i*8 + 1] = bitwiseData.bit1;
        //            FCU_CCU_DIRead[i*8 + 2] = bitwiseData.bit2;
        //            FCU_CCU_DIRead[i*8 + 3] = bitwiseData.bit3;
        //            FCU_CCU_DIRead[i*8 + 4] = bitwiseData.bit4;
        //            FCU_CCU_DIRead[i*8 + 5] = bitwiseData.bit5;
        //            FCU_CCU_DIRead[i*8 + 6] = bitwiseData.bit6;
        //            FCU_CCU_DIRead[i*8 + 7] = bitwiseData.bit7;
        //        }
    }
}

/*
A0 WRITE : TOTAL 8 Analog Outputs(AO) (4 byte  each DO)—MAX32 BYTES OF DATA. AO MAX VAL(0-10V)
<FE><LENGTH- 2BYTE><CH1-4BYTE><CH2-4BYTE>----------<CH8-4BYTE><CHECKSUM-1BYTE><E7>
*/
void FCUCCUComm::writeAOChannels()
{
    std::vector<uint8_t> data;
    UdpMessage msg;
    uint32_t raw_value;

//    for (int i = 0; i < 8; i++)
//    {
//        float ao_value = FCU_CCU_AOWrite[i];
//        memcpy(&raw_value, &ao_value, sizeof(float));

//        data.push_back(raw_value & 0xFF);
//        data.push_back((raw_value >> 8) & 0xFF);
//        data.push_back((raw_value >> 16) & 0xFF);
//        data.push_back((raw_value >> 24) & 0xFF);
//    }



    for (int i = 0; i < 8; i++)
    {
        float ao_value = FCU_CCU_AOWrite[i];
        memcpy(&raw_value, &ao_value, sizeof(float));

        data.push_back(raw_value & 0xFF);
        data.push_back((raw_value >> 8) & 0xFF);
        data.push_back((raw_value >> 16) & 0xFF);
        data.push_back((raw_value >> 24) & 0xFF);
    }


    create_message(msg, 32, data);

    send_udp_message(IP_ADDRESS, AO_WRITE_PORT, msg, AOWriteSocket);
    qDebug()<<"FCU_CCU_AOWrite : "<<data;

}

/*
DO WRITE:  TOTAL 64 DO bitwise (1 bit each)-MAX8 BYTES OF DATA
<FE><LENGTH- 2BYTE><CH1-64-8BYTE><CHECKSUM-1BYTE><E7>
*/
void FCUCCUComm::writeDOChannels()
{
    std::vector<uint8_t> data(8, 0);
    UdpMessage msg;

    for (int i = 0; i < 64; ++i)
    {
        if (FCU_CCU_DOWrite[i])
        {
            data[i / 8] |= (FCU_CCU_DOWrite[i] << (i % 8));
        }
    }

    create_message(msg, 8, data);

    send_udp_message(IP_ADDRESS, DO_WRITE_PORT, msg, DOWriteSocket);
     qDebug()<<"FCU_CCU_DOWrite"<<data;
}

/*
SERIAL WRITE : Data in hex string with length
<FE><MESSAGE LENGTH><MESSAGE><CHECKSUM-1BYTE><E7>
*/
void FCUCCUComm::writeSerialData(int port, const std::string& data, QUdpSocket *sock)
{
    std::vector<uint8_t> data_bytes;
    UdpMessage msg;

    for (size_t i = 0; i < data.size(); i += 2)
    {
        data_bytes.push_back(std::stoi(data.substr(i, 2), nullptr, 16));
    }

    create_message(msg, data_bytes.size(), data_bytes);

    send_udp_message(IP_ADDRESS, port, msg, sock);
}

/*
SERIAL READ : Data in hex string with length
<FE><MESSAGE LENGTH><MESSAGE><CHECKSUM-1BYTE><E7>
*/
std::string FCUCCUComm::readSerialData(int port, QUdpSocket *sock)
{
    std::string data;

    UdpMessage response = receive_udp_message(sock);
    for (uint8_t byte : response.data)
    {
        data += std::to_string(byte);
    }

    return data;
}

// getDIFromFCUCCU

bool FCUCCUComm::getDIFromFCUCCU(int chNo)
{
    return FCU_CCU_DIRead[chNo];
}

// getAIFromFCUCCU
float FCUCCUComm::getAIFromFCUCCU(int chNo)
{
    return FCU_CCU_AIRead[chNo];
}

// writeDOToFCUCCU
void FCUCCUComm::writeDOToFCUCCU(int chNo, bool value)
{
    FCU_CCU_DOWrite[chNo] = value;
}

// writeAOToFCUCCU
void FCUCCUComm::writeAOToFCUCCU(int chNo, float value)
{
    FCU_CCU_AOWrite[chNo] = value;
}

// initReadWriteTimers
#if 1
void FCUCCUComm::initReadWriteTimers()
{
    AIReadTimer = new QTimer(this);
    connect(AIReadTimer, SIGNAL(timeout()), this, SLOT(readAIChannels()));
    AIReadTimer->start(10);

    DIReadTimer = new QTimer(this);
    connect(DIReadTimer, SIGNAL(timeout()), this, SLOT(readDIChannels()));
    DIReadTimer->start(10);

    DOReadTimer = new QTimer(this);
    connect(DOReadTimer, SIGNAL(timeout()), this, SLOT(writeDOChannels()));
    DOReadTimer->start(10);

    AOReadTimer = new QTimer(this);
    connect(AOReadTimer, SIGNAL(timeout()), this, SLOT(writeAOChannels()));
    AOReadTimer->start(10);
}
#endif


