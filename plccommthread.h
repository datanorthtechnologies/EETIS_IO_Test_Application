#ifndef PLCCOMMTHREAD_H
#define PLCCOMMTHREAD_H

#include <QThread>
#include "plcComm.h"

extern plcComm *plcCommObj;

class plcCommThread : public QThread
{
    Q_OBJECT

protected:
    void run() override
    {
        plcCommObj = new plcComm(this);

        plcCommObj->initReadWriteTimers();

        exec();
    }

signals:

};

#endif // PLCCOMMTHREAD_H
