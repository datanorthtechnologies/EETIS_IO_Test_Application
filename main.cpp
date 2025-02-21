#include "mainwindow.h"
#include <QApplication>
#include "plccommthread.h"
#include "fcucommthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    plcCommThread *thread = new plcCommThread();
    thread->start();

    fcuCommThread *fcuThread = new fcuCommThread();
    fcuThread->start();

    while(plcCommObj == NULL)
    {
        QThread::sleep(1);
        qDebug()<<"Wait for PLC connection";
    }
    return a.exec();
}
