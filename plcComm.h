#ifndef PLCCOMM_H
#define PLCCOMM_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>
#include <QTimer>

//plc comm
#define IP_ADDR                     "192.168.0.10"
//#define IP_ADDR                     "127.0.0.7"
#define PORT_NUM                    502
#define SLAVE_ADDRESS               0
#define WRITE_SINGLE_REG            6
#define NO_OF_REGISTERS             125

#define NO_OF_DI_REG                8
#define NO_OF_DO_REG                8
#define NO_OF_AI_REG                16
#define NO_OF_AO_REG                16

#define BASE_DI_REG_ADDR            0
#define BASE_DO_REG_ADDR            20
#define BASE_AI_REG_ADDR            40
#define BASE_AO_REG_ADDR            60

#define NO_OF_DIs                   16*NO_OF_DI_REG
#define NO_OF_DOs                   16*NO_OF_DO_REG
#define NO_OF_BYTES_AI              2*NO_OF_AI_REG
#define NO_OF_BYTES_AO              2*NO_OF_AO_REG

#define WRITE_CYCLE_TIME_IN_MS      100
#define READ_CYCLE_TIME_IN_MS       20
#define RESPONSE_TIMEOUT            1000

/***Dont change these defines */
#define DI_CHANNEL                  1
#define AI_CHANNEL                  2
#define DO_CHANNEL                  3
#define AO_CHANNEL                  4

#define DI_TRANS_ID                 11
#define DO_TRANS_ID                 21
#define AI_TRANS_ID                 31
#define AO_TRANS_ID                 41

#define ALL_DO_REGS                 4

#define READ_HOLDING_REGS           3
#define WRITE_MULTIPLE_REGS         16

#define MAX_BITS_IN_REG             16
#define BYTES_IN_REG                2

#define HIGH                        1
#define LOW                         0

class plcComm : public QObject
{
    Q_OBJECT

public:
    explicit plcComm(QObject *parent = nullptr);
    virtual ~plcComm();

    void connectModbusTcpSocket(const QString &host, quint16 port);

    void decodeDataRecvdFrmPLC(QByteArray responseData);
    void initReadWriteTimers();

    QByteArray createModbusWriteRequest(int transId,
                                        unsigned char funcCode,
                                        unsigned short startingRegAddr,
                                        unsigned short noOfRegToWrite,
                                        short *data);

    QByteArray createModbusReadRequest( int transId,
                                        unsigned char funcCode,
                                        unsigned short startingRegAddr,
                                        unsigned short noOfRegToRead);

    void sendModbusRequest(QByteArray dataTobeSent);

    QTcpSocket *modbusTcpSocket = NULL;
    QTimer *sendReqTimer;
    QTimer *recvReqTimer;
    QTimer *responseTimer;
    QTimer *reconnectTimer;

    void setBaseAddrOfDI(unsigned short regAddr);
    void setBaseAddrOfDO(unsigned short regAddr);
    void setBaseAddrOfAI(unsigned short regAddr);
    void setBaseAddrOfAO(unsigned short regAddr);

    int writeMulHoldReg(unsigned short startRegAddr, unsigned short noOfRegToWrite, unsigned char doOrAoChannel);
    int readMulHoldReg(unsigned short startRegAddr, unsigned short noOfRegToRead,
                       unsigned char *data, unsigned char diOrAiChannel);

    int getDiValue(int diChannel);
    int getDoValue(int doChannel);
    short getAiValue(int aiChannel);
    short getAoValue(int aoChannel);
    void setDoValue(int doChannel, char data);
    void setAoValue(int aoChannel, short data);
    bool getLinkStatus();

    void storeDiData(unsigned short noOfRegToRead);
    void storeAiData(unsigned short noOfRegToRead);
    bool getBitValFrmReg(unsigned short regValue, int bitPosition);
    void simulateDoAoData(unsigned char aoOrDoChannel);
    void storeDoDataInRegArray(short *doDataInRegArray, unsigned short noOfRegToWrite, char *doData);
    char plcDOs[NO_OF_DOs] = {0};
    char plcDIs[NO_OF_DIs] = {0};
    short plcAIs[NO_OF_BYTES_AI] = {0};
    short plcAOs[NO_OF_BYTES_AO] = {0};

    int linkStatus = 0;


private:
    unsigned short baseAddrOfDI;
    unsigned short baseAddrOfDO;
    unsigned short baseAddrOfAI;
    unsigned short baseAddrOfAO;


    int cycleId = DI_CHANNEL;
    int waitingResponse = 0;

    const quint8 BIT_MASKS[8] =
    {
        0x01, // Mask for bit 0 (LSB)
        0x02, // Mask for bit 1
        0x04, // Mask for bit 2
        0x08, // Mask for bit 3
        0x10, // Mask for bit 4
        0x20, // Mask for bit 5
        0x40, // Mask for bit 6
        0x80  // Mask for bit 7 (MSB)
    };

    unsigned short inputReg[NO_OF_REGISTERS] = {0};

public slots:
    void sendModbusReadWriteRequest();
    void readModbusData();
    void respTimeOut();

protected slots:
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);
    void reconnect();
};

#endif // PLCCOMM_H
