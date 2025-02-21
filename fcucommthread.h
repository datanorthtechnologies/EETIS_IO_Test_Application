#ifndef FCUCOMMTHREAD_H
#define FCUCOMMTHREAD_H

#include <QThread>
#include "fcuccucomm.h"

extern FCUCCUComm  *fcuCommObj;

class fcuCommThread : public QThread
{
    Q_OBJECT

protected:
    void run() override
    {
        fcuCommObj = new FCUCCUComm(this);

        fcuCommObj->setIPAddress("192.168.0.10");
        //fcuCommObj->setIPAddress("127.0.0.1");

        while (!fcuCommObj->connectUDPSocket())
        {
            qDebug() << "Failed to connect to FCU. Retrying...";
            sleep(5);
        }

        fcuCommObj->initReadWriteTimers();

        exec();
    }


signals:

};

#endif // FCUCOMMTHREAD_H
