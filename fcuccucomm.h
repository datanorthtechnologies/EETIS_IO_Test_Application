#ifndef FCUCCUCOMM_H
#define FCUCCUCOMM_H

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QException>
#include <QDebug>
#include <QTimer>

#define SOF  0xFE
#define EOT  0xE7
#define MAX_DATA_SIZE 500

// Define UDP Port Numbers as Macros
#define DI_READ_PORT        50001
#define AI_READ_PORT        50002
#define SERIAL1_READ_PORT   50003
#define SERIAL2_READ_PORT   50004
#define SERIAL3_READ_PORT   50005
#define SERIAL4_READ_PORT   50006

#define DO_WRITE_PORT       60001
#define AO_WRITE_PORT       60002
#define SERIAL1_WRITE_PORT  60003
#define SERIAL2_WRITE_PORT  60004
#define SERIAL3_WRITE_PORT  60005
#define SERIAL4_WRITE_PORT  60006

class FCUCCUComm : public QObject
{
    Q_OBJECT

public:

    typedef struct
    {
        uint8_t sof;                      // Start of Frame (0xFE)
        uint16_t data_size;               // Data Size
        std::vector<uint8_t> data;        // Data field
        uint8_t checksum;                 // Checksum
        uint8_t eot;                      // End of Transmission (0xE7)
    }UdpMessage;

    explicit FCUCCUComm(QObject *parent = nullptr);
    virtual ~FCUCCUComm();

    bool FCU_CCU_DOWrite[64];
    bool FCU_CCU_DIRead[64];
    float FCU_CCU_AIRead[8];
    float FCU_CCU_AOWrite[8];

    QUdpSocket *AIReadSocket;
    QUdpSocket *DIReadSocket;
    QUdpSocket *DOWriteSocket;
    QUdpSocket *AOWriteSocket;
    QUdpSocket *Serial1WriteSocket;
    QUdpSocket *Serial2WriteSocket;
    QUdpSocket *Serial3WriteSocket;
    QUdpSocket *Serial4WriteSocket;

    std::string IP_ADDRESS;
    void setIPAddress(std::string ip);
    bool connectUDPSocket();

    void create_message(UdpMessage &msg, uint16_t size, const std::vector<uint8_t>& input_data);

    uint8_t calculate_checksum(const UdpMessage &msg);

    std::vector<uint8_t> serialize_message(const UdpMessage &msg);
    UdpMessage deserialize_message(const std::vector<uint8_t>& buffer);

    QUdpSocket* create_udp_socket(int port);
    void send_udp_message(const std::string& ip, int port, const UdpMessage& msg, QUdpSocket *sock);
    UdpMessage receive_udp_message(QUdpSocket *sock);

    void writeSerialData(int port, const std::string& data, QUdpSocket *sock);
    std::string readSerialData(int port, QUdpSocket *sock);

    bool getDIFromFCUCCU(int chNo);
    float getAIFromFCUCCU(int chNo);
    void writeDOToFCUCCU(int chNo, bool value);
    void writeAOToFCUCCU(int chNo, float value);

    void initReadWriteTimers();
    QTimer *AIReadTimer;
    QTimer *DIReadTimer;
    QTimer *DOReadTimer;
    QTimer *AOReadTimer;

public slots:
    void readAIChannels();
    void readDIChannels();
    void writeDOChannels();
    void writeAOChannels();

};

#endif // FCUCCUCOMM_H
