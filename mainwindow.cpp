#include "mainwindow.h"
#include "ui_mainwindow.h"

plcComm *plcCommObj;
FCUCCUComm *fcuCommObj;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addToList();
    addCCUToList();
    addDOToList();
    addDOCCUToList();
    addAIToList();
    addAIToListFCU();
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100); // Update every 1 second


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addToList()
{

    DIList.append(ui->DI1);
    DIList.append(ui->DI2);
    DIList.append(ui->DI3);
    DIList.append(ui->DI4);
    DIList.append(ui->DI5);
    DIList.append(ui->DI6);
    DIList.append(ui->DI7);
    DIList.append(ui->DI8);
    DIList.append(ui->DI9);
    DIList.append(ui->DI10);
    DIList.append(ui->DI11);
    DIList.append(ui->DI12);
    DIList.append(ui->DI13);
    DIList.append(ui->DI14);
    DIList.append(ui->DI15);
    DIList.append(ui->DI16);
    DIList.append(ui->DI17);
    DIList.append(ui->DI18);
    DIList.append(ui->DI19);
    DIList.append(ui->DI20);
    DIList.append(ui->DI21);
    DIList.append(ui->DI22);
    DIList.append(ui->DI23);
    DIList.append(ui->DI24);
    DIList.append(ui->DI25);
    DIList.append(ui->DI26);
    DIList.append(ui->DI27);
    DIList.append(ui->DI28);
    DIList.append(ui->DI29);
    DIList.append(ui->DI30);
    DIList.append(ui->DI31);
    DIList.append(ui->DI32);
    DIList.append(ui->DI33);
    DIList.append(ui->DI34);
    DIList.append(ui->DI35);
    DIList.append(ui->DI36);
    DIList.append(ui->DI37);
    DIList.append(ui->DI38);
    DIList.append(ui->DI39);
    DIList.append(ui->DI40);
    DIList.append(ui->DI41);
    DIList.append(ui->DI42);
    DIList.append(ui->DI43);
    DIList.append(ui->DI44);
    DIList.append(ui->DI45);
    DIList.append(ui->DI46);
    DIList.append(ui->DI47);
    DIList.append(ui->DI48);
    DIList.append(ui->DI49);
    DIList.append(ui->DI50);
    DIList.append(ui->DI51);
    DIList.append(ui->DI52);
    DIList.append(ui->DI53);
    DIList.append(ui->DI54);
    DIList.append(ui->DI55);
    DIList.append(ui->DI56);
    DIList.append(ui->DI57);
    DIList.append(ui->DI58);
    DIList.append(ui->DI59);
    DIList.append(ui->DI60);
    DIList.append(ui->DI61);
    DIList.append(ui->DI62);
    DIList.append(ui->DI63);
    DIList.append(ui->DI64);

}

void MainWindow::addCCUToList()
{
    CCUDIList.append(ui->DI1_2);
    CCUDIList.append(ui->DI2_2);
    CCUDIList.append(ui->DI3_2);
    CCUDIList.append(ui->DI4_2);
    CCUDIList.append(ui->DI5_2);
    CCUDIList.append(ui->DI6_2);
    CCUDIList.append(ui->DI7_2);
    CCUDIList.append(ui->DI8_2);
    CCUDIList.append(ui->DI9_2);
    CCUDIList.append(ui->DI10_2);
    CCUDIList.append(ui->DI11_2);
    CCUDIList.append(ui->DI12_2);
    CCUDIList.append(ui->DI13_2);
    CCUDIList.append(ui->DI14_2);
    CCUDIList.append(ui->DI15_2);
    CCUDIList.append(ui->DI16_2);
    CCUDIList.append(ui->DI17_2);
    CCUDIList.append(ui->DI18_2);
    CCUDIList.append(ui->DI19_2);
    CCUDIList.append(ui->DI20_2);
    CCUDIList.append(ui->DI21_2);
    CCUDIList.append(ui->DI22_2);
    CCUDIList.append(ui->DI23_2);
    CCUDIList.append(ui->DI24_2);
    CCUDIList.append(ui->DI25_2);
    CCUDIList.append(ui->DI26_2);
    CCUDIList.append(ui->DI27_2);
    CCUDIList.append(ui->DI28_2);
    CCUDIList.append(ui->DI29_2);
    CCUDIList.append(ui->DI30_2);
    CCUDIList.append(ui->DI31_2);
    CCUDIList.append(ui->DI32_2);
    CCUDIList.append(ui->DI33_2);
    CCUDIList.append(ui->DI34_2);
    CCUDIList.append(ui->DI35_2);
    CCUDIList.append(ui->DI36_2);
    CCUDIList.append(ui->DI37_2);
    CCUDIList.append(ui->DI38_2);
    CCUDIList.append(ui->DI39_2);
    CCUDIList.append(ui->DI40_2);
    CCUDIList.append(ui->DI41_2);
    CCUDIList.append(ui->DI42_2);
    CCUDIList.append(ui->DI43_2);
    CCUDIList.append(ui->DI44_2);
    CCUDIList.append(ui->DI45_2);
    CCUDIList.append(ui->DI46_2);
    CCUDIList.append(ui->DI47_2);
    CCUDIList.append(ui->DI48_2);
    CCUDIList.append(ui->DI49_2);
    CCUDIList.append(ui->DI50_2);
    CCUDIList.append(ui->DI51_2);
    CCUDIList.append(ui->DI52_2);
    CCUDIList.append(ui->DI53_2);
    CCUDIList.append(ui->DI54_2);
    CCUDIList.append(ui->DI55_2);
    CCUDIList.append(ui->DI56_2);
    CCUDIList.append(ui->DI57_2);
    CCUDIList.append(ui->DI58_2);
    CCUDIList.append(ui->DI59_2);
    CCUDIList.append(ui->DI60_2);
    CCUDIList.append(ui->DI61_2);
    CCUDIList.append(ui->DI62_2);
    CCUDIList.append(ui->DI63_2);
    CCUDIList.append(ui->DI64_2);
}

void MainWindow::addDOToList()
{
    DOList.append(ui->DO1);
    DOList.append(ui->DO2);
    DOList.append(ui->DO3);
    DOList.append(ui->DO4);
    DOList.append(ui->DO5);
    DOList.append(ui->DO6);
    DOList.append(ui->DO7);
    DOList.append(ui->DO8);
    DOList.append(ui->DO9);
    DOList.append(ui->DO10);
    DOList.append(ui->DO11);
    DOList.append(ui->DO12);
    DOList.append(ui->DO13);
    DOList.append(ui->DO14);
    DOList.append(ui->DO15);
    DOList.append(ui->DO16);
    DOList.append(ui->DO17);
    DOList.append(ui->DO18);
    DOList.append(ui->DO19);
    DOList.append(ui->DO20);
    DOList.append(ui->DO21);
    DOList.append(ui->DO22);
    DOList.append(ui->DO23);
    DOList.append(ui->DO24);
    DOList.append(ui->DO25);
    DOList.append(ui->DO26);
    DOList.append(ui->DO27);
    DOList.append(ui->DO28);
    DOList.append(ui->DO29);
    DOList.append(ui->DO30);
    DOList.append(ui->DO31);
    DOList.append(ui->DO32);
    DOList.append(ui->DO33);
    DOList.append(ui->DO34);
    DOList.append(ui->DO35);
    DOList.append(ui->DO36);
    DOList.append(ui->DO37);
    DOList.append(ui->DO38);
    DOList.append(ui->DO39);
    DOList.append(ui->DO40);
    DOList.append(ui->DO41);
    DOList.append(ui->DO42);
    DOList.append(ui->DO43);
    DOList.append(ui->DO44);
    DOList.append(ui->DO45);
    DOList.append(ui->DO46);
    DOList.append(ui->DO47);
    DOList.append(ui->DO48);
    DOList.append(ui->DO49);
    DOList.append(ui->DO50);
    DOList.append(ui->DO51);
    DOList.append(ui->DO52);
    DOList.append(ui->DO53);
    DOList.append(ui->DO54);
    DOList.append(ui->DO55);
    DOList.append(ui->DO56);
    DOList.append(ui->DO57);
    DOList.append(ui->DO58);
    DOList.append(ui->DO59);
    DOList.append(ui->DO60);
    DOList.append(ui->DO61);
    DOList.append(ui->DO62);
    DOList.append(ui->DO63);
    DOList.append(ui->DO64);

}

void MainWindow::addDOCCUToList()
{
    DOListCCU.append(ui->DO1_2);
    DOListCCU.append(ui->DO2_2);
    DOListCCU.append(ui->DO3_2);
    DOListCCU.append(ui->DO4_2);
    DOListCCU.append(ui->DO5_2);
    DOListCCU.append(ui->DO6_2);
    DOListCCU.append(ui->DO7_2);
    DOListCCU.append(ui->DO8_2);
    DOListCCU.append(ui->DO9_2);
    DOListCCU.append(ui->DO10_2);
    DOListCCU.append(ui->DO11_2);
    DOListCCU.append(ui->DO12_2);
    DOListCCU.append(ui->DO13_2);
    DOListCCU.append(ui->DO14_2);
    DOListCCU.append(ui->DO15_2);
    DOListCCU.append(ui->DO16_2);
    DOListCCU.append(ui->DO17_2);
    DOListCCU.append(ui->DO18_2);
    DOListCCU.append(ui->DO19_2);
    DOListCCU.append(ui->DO20_2);
    DOListCCU.append(ui->DO21_2);
    DOListCCU.append(ui->DO22_2);
    DOListCCU.append(ui->DO23_2);
    DOListCCU.append(ui->DO24_2);
    DOListCCU.append(ui->DO25_2);
    DOListCCU.append(ui->DO26_2);
    DOListCCU.append(ui->DO27_2);
    DOListCCU.append(ui->DO28_2);
    DOListCCU.append(ui->DO29_2);
    DOListCCU.append(ui->DO30_2);
    DOListCCU.append(ui->DO31_2);
    DOListCCU.append(ui->DO32_2);
    DOListCCU.append(ui->DO33_2);
    DOListCCU.append(ui->DO34_2);
    DOListCCU.append(ui->DO35_2);
    DOListCCU.append(ui->DO36_2);
    DOListCCU.append(ui->DO37_2);
    DOListCCU.append(ui->DO38_2);
    DOListCCU.append(ui->DO39_2);
    DOListCCU.append(ui->DO40_2);
    DOListCCU.append(ui->DO41_2);
    DOListCCU.append(ui->DO42_2);
    DOListCCU.append(ui->DO43_2);
    DOListCCU.append(ui->DO44_2);
    DOListCCU.append(ui->DO45_2);
    DOListCCU.append(ui->DO46_2);
    DOListCCU.append(ui->DO47_2);
    DOListCCU.append(ui->DO48_2);
    DOListCCU.append(ui->DO49_2);
    DOListCCU.append(ui->DO50_2);
    DOListCCU.append(ui->DO51_2);
    DOListCCU.append(ui->DO52_2);
    DOListCCU.append(ui->DO53_2);
    DOListCCU.append(ui->DO54_2);
    DOListCCU.append(ui->DO55_2);
    DOListCCU.append(ui->DO56_2);
    DOListCCU.append(ui->DO57_2);
    DOListCCU.append(ui->DO58_2);
    DOListCCU.append(ui->DO59_2);
    DOListCCU.append(ui->DO60_2);
    DOListCCU.append(ui->DO61_2);
    DOListCCU.append(ui->DO62_2);
    DOListCCU.append(ui->DO63_2);
    DOListCCU.append(ui->DO64_2);
}

void MainWindow::addAIToList()
{
    AIList.append(ui->txtAI1);
    AIList.append(ui->txtAI2);
    AIList.append(ui->txtAI3);
    AIList.append(ui->txtAI4);
    AIList.append(ui->txtAI5);
    AIList.append(ui->txtAI6);
    AIList.append(ui->txtAI7);
    AIList.append(ui->txtAI8);
    AIList.append(ui->txtAI9);
    AIList.append(ui->txtAI10);
}

void MainWindow::addAIToListFCU()
{
    FCUAIList.append(ui->txtAI1_2);
    FCUAIList.append(ui->txtAI2_2);
    FCUAIList.append(ui->txtAI3_2);
    FCUAIList.append(ui->txtAI4_2);
    FCUAIList.append(ui->txtAI5_2);
    FCUAIList.append(ui->txtAI6_2);
    FCUAIList.append(ui->txtAI7_2);
    FCUAIList.append(ui->txtAI8_2);

}

void MainWindow::update()
{
    updateDI();
    updateDO();
    updateAI();
    updateCCUFCUDI();
    updateAIFCUCCU();

}

void MainWindow::updateDO()
{
    for(int i= 0;i<DOList.count();i++)
    {
        if(plcCommObj->getDoValue(i) == 1)
        {
            DOList[i]->setStyleSheet("background-color: green;border-radius:20px;");
        }
        else
        {
            DOList[i]->setStyleSheet("background-color: red;border-radius:20px;");
        }
    }
}

void MainWindow::updateCCUFCUDO()
{

}

void MainWindow::updateDI()
{
    for(int i= 0;i<DIList.count();i++)
    {
        if(plcCommObj->getDiValue(i) == 1)
        {
            DIList[i]->setStyleSheet("background-color: green;border-radius:20px;");
        }
        else
        {
            DIList[i]->setStyleSheet("background-color: red;border-radius:20px;");
        }
    }
}

void MainWindow::updateCCUFCUDI()
{
    for(int i= 0;i<CCUDIList.count();i++)
    {
        if(fcuCommObj->getDIFromFCUCCU(i) == 1)
        {
            CCUDIList[i]->setStyleSheet("background-color: green;border-radius:20px;");
        }
        else
        {
            CCUDIList[i]->setStyleSheet("background-color: red;border-radius:20px;");
        }
    }
}

void MainWindow::updateAI()
{
    QString val;
    for(int i= 0;i<AIList.count();i++)
    {
        val = QString::number(plcCommObj->getAiValue(i));
        AIList[i]->setText(val);
    }
}

void MainWindow::updateAIFCUCCU()
{
    QString val;
    for(int i= 0;i<FCUAIList.count();i++)
    {
        val = QString::number(fcuCommObj->getAIFromFCUCCU(i));
        FCUAIList[i]->setText(val);
        qDebug()<<"val"<<fcuCommObj->getAIFromFCUCCU(i);
    }

    for(int i = 0; i < 8; i++)
    {
        qDebug() <<"val" <<fcuCommObj->getAIFromFCUCCU(i);
    }

}

void MainWindow::on_btnDO1_clicked()
{
    if(plcCommObj->getDoValue(1) == 0)
    {
        plcCommObj->setDoValue(1,1);
        ui->btnDO1->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(1,0);
        ui->btnDO1->setText("OFF");
    }
}

void MainWindow::on_btnDO2_clicked()
{
    if(plcCommObj->getDoValue(2) == 0)
    {
        plcCommObj->setDoValue(2,1);
        ui->btnDO2->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(2,0);
        ui->btnDO2->setText("OFF");
    }
}

void MainWindow::on_btnDO3_clicked()
{
    if(plcCommObj->getDoValue(3) == 0)
    {
        plcCommObj->setDoValue(3,1);
        ui->btnDO3->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(3,0);
        ui->btnDO3->setText("OFF");
    }
}

void MainWindow::on_btnDO4_clicked()
{
    if(plcCommObj->getDoValue(4) == 0)
    {
        plcCommObj->setDoValue(4,1);
        ui->btnDO4->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(4,0);
        ui->btnDO4->setText("OFF");
    }
}

// Functions from 5 to 64

void MainWindow::on_btnDO5_clicked()
{
    if(plcCommObj->getDoValue(5) == 0)
    {
        plcCommObj->setDoValue(5,1);
        ui->btnDO5->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(5,0);
        ui->btnDO5->setText("OFF");
    }
}

void MainWindow::on_btnDO6_clicked()
{
    if(plcCommObj->getDoValue(6) == 0)
    {
        plcCommObj->setDoValue(6,1);
        ui->btnDO6->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(6,0);
        ui->btnDO6->setText("OFF");
    }
}

void MainWindow::on_btnDO7_clicked()
{
    if(plcCommObj->getDoValue(7) == 0)
    {
        plcCommObj->setDoValue(7,1);
        ui->btnDO7->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(7,0);
        ui->btnDO7->setText("OFF");
    }
}

void MainWindow::on_btnDO8_clicked()
{
    if(plcCommObj->getDoValue(8) == 0)
    {
        plcCommObj->setDoValue(8,1);
        ui->btnDO8->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(8,0);
        ui->btnDO8->setText("OFF");
    }
}

void MainWindow::on_btnDO9_clicked()
{
    if(plcCommObj->getDoValue(9) == 0)
    {
        plcCommObj->setDoValue(9,1);
        ui->btnDO9->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(9,0);
        ui->btnDO9->setText("OFF");
    }
}

void MainWindow::on_btnDO10_clicked()
{
    if(plcCommObj->getDoValue(10) == 0)
    {
        plcCommObj->setDoValue(10,1);
        ui->btnDO10->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(10,0);
        ui->btnDO10->setText("OFF");
    }
}
void MainWindow::on_btnDO11_clicked()
{
    if(plcCommObj->getDoValue(11) == 0)
    {
        plcCommObj->setDoValue(11,1);
        ui->btnDO11->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(11,0);
        ui->btnDO11->setText("OFF");
    }
}

void MainWindow::on_btnDO12_clicked()
{
    if(plcCommObj->getDoValue(12) == 0)
    {
        plcCommObj->setDoValue(12,1);
        ui->btnDO12->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(12,0);
        ui->btnDO12->setText("OFF");
    }
}

void MainWindow::on_btnDO13_clicked()
{
    if(plcCommObj->getDoValue(13) == 0)
    {
        plcCommObj->setDoValue(13,1);
        ui->btnDO13->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(13,0);
        ui->btnDO13->setText("OFF");
    }
}

void MainWindow::on_btnDO14_clicked()
{
    if(plcCommObj->getDoValue(14) == 0)
    {
        plcCommObj->setDoValue(14,1);
        ui->btnDO14->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(14,0);
        ui->btnDO14->setText("OFF");
    }
}

void MainWindow::on_btnDO15_clicked()
{
    if(plcCommObj->getDoValue(15) == 0)
    {
        plcCommObj->setDoValue(15,1);
        ui->btnDO15->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(15,0);
        ui->btnDO15->setText("OFF");
    }
}

void MainWindow::on_btnDO16_clicked()
{
    if(plcCommObj->getDoValue(16) == 0)
    {
        plcCommObj->setDoValue(16,1);
        ui->btnDO16->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(16,0);
        ui->btnDO16->setText("OFF");
    }
}

void MainWindow::on_btnDO17_clicked()
{
    if(plcCommObj->getDoValue(17) == 0)
    {
        plcCommObj->setDoValue(17,1);
        ui->btnDO17->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(17,0);
        ui->btnDO17->setText("OFF");
    }
}

void MainWindow::on_btnDO18_clicked()
{
    if(plcCommObj->getDoValue(18) == 0)
    {
        plcCommObj->setDoValue(18,1);
        ui->btnDO18->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(18,0);
        ui->btnDO18->setText("OFF");
    }
}

void MainWindow::on_btnDO19_clicked()
{
    if(plcCommObj->getDoValue(19) == 0)
    {
        plcCommObj->setDoValue(19,1);
        ui->btnDO19->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(19,0);
        ui->btnDO19->setText("OFF");
    }
}

void MainWindow::on_btnDO20_clicked()
{
    if(plcCommObj->getDoValue(20) == 0)
    {
        plcCommObj->setDoValue(20,1);
        ui->btnDO20->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(20,0);
        ui->btnDO20->setText("OFF");
    }
}
void MainWindow::on_btnDO21_clicked()
{
    if(plcCommObj->getDoValue(21) == 0)
    {
        plcCommObj->setDoValue(21,1);
        ui->btnDO21->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(21,0);
        ui->btnDO21->setText("OFF");
    }
}

void MainWindow::on_btnDO22_clicked()
{
    if(plcCommObj->getDoValue(22) == 0)
    {
        plcCommObj->setDoValue(22,1);
        ui->btnDO22->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(22,0);
        ui->btnDO22->setText("OFF");
    }
}

void MainWindow::on_btnDO23_clicked()
{
    if(plcCommObj->getDoValue(23) == 0)
    {
        plcCommObj->setDoValue(23,1);
        ui->btnDO23->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(23,0);
        ui->btnDO23->setText("OFF");
    }
}

void MainWindow::on_btnDO24_clicked()
{
    if(plcCommObj->getDoValue(24) == 0)
    {
        plcCommObj->setDoValue(24,1);
        ui->btnDO24->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(24,0);
        ui->btnDO24->setText("OFF");
    }
}

void MainWindow::on_btnDO25_clicked()
{
    if(plcCommObj->getDoValue(25) == 0)
    {
        plcCommObj->setDoValue(25,1);
        ui->btnDO25->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(25,0);
        ui->btnDO25->setText("OFF");
    }
}

void MainWindow::on_btnDO26_clicked()
{
    if(plcCommObj->getDoValue(26) == 0)
    {
        plcCommObj->setDoValue(26,1);
        ui->btnDO26->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(26,0);
        ui->btnDO26->setText("OFF");
    }
}

void MainWindow::on_btnDO27_clicked()
{
    if(plcCommObj->getDoValue(27) == 0)
    {
        plcCommObj->setDoValue(27,1);
        ui->btnDO27->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(27,0);
        ui->btnDO27->setText("OFF");
    }
}

void MainWindow::on_btnDO28_clicked()
{
    if(plcCommObj->getDoValue(28) == 0)
    {
        plcCommObj->setDoValue(28,1);
        ui->btnDO28->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(28,0);
        ui->btnDO28->setText("OFF");
    }
}

void MainWindow::on_btnDO29_clicked()
{
    if(plcCommObj->getDoValue(29) == 0)
    {
        plcCommObj->setDoValue(29,1);
        ui->btnDO29->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(29,0);
        ui->btnDO29->setText("OFF");
    }
}

void MainWindow::on_btnDO30_clicked()
{
    if(plcCommObj->getDoValue(30) == 0)
    {
        plcCommObj->setDoValue(30,1);
        ui->btnDO30->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(30,0);
        ui->btnDO30->setText("OFF");
    }
}
void MainWindow::on_btnDO31_clicked()
{
    if(plcCommObj->getDoValue(31) == 0)
    {
        plcCommObj->setDoValue(31,1);
        ui->btnDO31->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(31,0);
        ui->btnDO31->setText("OFF");
    }
}

void MainWindow::on_btnDO32_clicked()
{
    if(plcCommObj->getDoValue(32) == 0)
    {
        plcCommObj->setDoValue(32,1);
        ui->btnDO32->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(32,0);
        ui->btnDO32->setText("OFF");
    }
}

void MainWindow::on_btnDO33_clicked()
{
    if(plcCommObj->getDoValue(33) == 0)
    {
        plcCommObj->setDoValue(33,1);
        ui->btnDO33->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(33,0);
        ui->btnDO33->setText("OFF");
    }
}

void MainWindow::on_btnDO34_clicked()
{
    if(plcCommObj->getDoValue(34) == 0)
    {
        plcCommObj->setDoValue(34,1);
        ui->btnDO34->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(34,0);
        ui->btnDO34->setText("OFF");
    }
}

void MainWindow::on_btnDO35_clicked()
{
    if(plcCommObj->getDoValue(35) == 0)
    {
        plcCommObj->setDoValue(35,1);
        ui->btnDO35->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(35,0);
        ui->btnDO35->setText("OFF");
    }
}

void MainWindow::on_btnDO36_clicked()
{
    if(plcCommObj->getDoValue(36) == 0)
    {
        plcCommObj->setDoValue(36,1);
        ui->btnDO36->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(36,0);
        ui->btnDO36->setText("OFF");
    }
}

void MainWindow::on_btnDO37_clicked()
{
    if(plcCommObj->getDoValue(37) == 0)
    {
        plcCommObj->setDoValue(37,1);
        ui->btnDO37->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(37,0);
        ui->btnDO37->setText("OFF");
    }
}

void MainWindow::on_btnDO38_clicked()
{
    if(plcCommObj->getDoValue(38) == 0)
    {
        plcCommObj->setDoValue(38,1);
        ui->btnDO38->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(38,0);
        ui->btnDO38->setText("OFF");
    }
}

void MainWindow::on_btnDO39_clicked()
{
    if(plcCommObj->getDoValue(39) == 0)
    {
        plcCommObj->setDoValue(39,1);
        ui->btnDO39->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(39,0);
        ui->btnDO39->setText("OFF");
    }
}

void MainWindow::on_btnDO40_clicked()
{
    if(plcCommObj->getDoValue(40) == 0)
    {
        plcCommObj->setDoValue(40,1);
        ui->btnDO40->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(40,0);
        ui->btnDO40->setText("OFF");
    }
}


void MainWindow::on_pushButton_clicked()
{
    QString AO1 = ui->txtAO1->text();
    int AO1send = AO1.toInt();
    plcCommObj->setAoValue(0, AO1send);

    QString AO2 = ui->txtAO2->text();
    int AO2send = AO2.toInt();
    plcCommObj->setAoValue(1, AO2send);

    QString AO3 = ui->txtAO3->text();
    int AO3send = AO3.toInt();
    plcCommObj->setAoValue(2, AO3send);

    QString AO4 = ui->txtAO4->text();
    int AO4send = AO4.toInt();
    plcCommObj->setAoValue(3, AO4send);

    QString AO5 = ui->txtAO5->text();
    int AO5send = AO5.toInt();
    plcCommObj->setAoValue(4, AO5send);

    QString AO6 = ui->txtAO6->text();
    int AO6send = AO6.toInt();
    plcCommObj->setAoValue(5, AO6send);

    QString AO7 = ui->txtAO7->text();
    int AO7send = AO7.toInt();
    plcCommObj->setAoValue(6, AO7send);

    QString AO8 = ui->txtAO8->text();
    int AO8send = AO8.toInt();
    plcCommObj->setAoValue(7, AO8send);

    QString AO9 = ui->txtAO9->text();
    int AO9send = AO9.toInt();
    plcCommObj->setAoValue(8, AO9send);

    QString AO10 = ui->txtAO10->text();
    int AO10send = AO10.toInt();
    plcCommObj->setAoValue(9, AO10send);
}





void MainWindow::on_btn41_clicked()
{
    if(plcCommObj->getDoValue(41) == 0)
    {
        plcCommObj->setDoValue(41,1);
        ui->btn41->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(41,0);
        ui->btn41->setText("OFF");
    }
}

void MainWindow::on_btn42_clicked()
{
    if(plcCommObj->getDoValue(42) == 0)
    {
        plcCommObj->setDoValue(42,1);
        ui->btn42->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(42,0);
        ui->btn42->setText("OFF");
    }
}

void MainWindow::on_btn43_clicked()
{
    if(plcCommObj->getDoValue(43) == 0)
    {
        plcCommObj->setDoValue(43,1);
        ui->btn43->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(43,0);
        ui->btn43->setText("OFF");
    }
}

void MainWindow::on_btn44_clicked()
{
    if(plcCommObj->getDoValue(44) == 0)
    {
        plcCommObj->setDoValue(44,1);
        ui->btn44->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(44,0);
        ui->btn44->setText("OFF");
    }
}

void MainWindow::on_btn45_clicked()
{
    if(plcCommObj->getDoValue(45) == 0)
    {
        plcCommObj->setDoValue(45,1);
        ui->btn45->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(45,0);
        ui->btn45->setText("OFF");
    }
}

void MainWindow::on_btn46_clicked()
{
    if(plcCommObj->getDoValue(46) == 0)
    {
        plcCommObj->setDoValue(46,1);
        ui->btn46->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(46,0);
        ui->btn46->setText("OFF");
    }
}

void MainWindow::on_btn47_clicked()
{
    if(plcCommObj->getDoValue(47) == 0)
    {
        plcCommObj->setDoValue(47,1);
        ui->btn47->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(47,0);
        ui->btn47->setText("OFF");
    }
}

void MainWindow::on_btn48_clicked()
{
    if(plcCommObj->getDoValue(48) == 0)
    {
        plcCommObj->setDoValue(48,1);
        ui->btn48->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(48,0);
        ui->btn48->setText("OFF");
    }
}

void MainWindow::on_btn49_clicked()
{
    if(plcCommObj->getDoValue(49) == 0)
    {
        plcCommObj->setDoValue(49,1);
        ui->btn49->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(49,0);
        ui->btn49->setText("OFF");
    }
}

void MainWindow::on_btn50_clicked()
{
    if(plcCommObj->getDoValue(50) == 0)
    {
        plcCommObj->setDoValue(50,1);
        ui->btn50->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(50,0);
        ui->btn50->setText("OFF");
    }
}

void MainWindow::on_btn51_clicked()
{
    if(plcCommObj->getDoValue(51) == 0)
    {
        plcCommObj->setDoValue(51,1);
        ui->btn51->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(51,0);
        ui->btn51->setText("OFF");
    }
}

void MainWindow::on_btn52_clicked()
{
    if(plcCommObj->getDoValue(52) == 0)
    {
        plcCommObj->setDoValue(52,1);
        ui->btn52->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(52,0);
        ui->btn52->setText("OFF");
    }
}

void MainWindow::on_btn53_clicked()
{
    if(plcCommObj->getDoValue(53) == 0)
    {
        plcCommObj->setDoValue(53,1);
        ui->btn53->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(53,0);
        ui->btn53->setText("OFF");
    }
}

void MainWindow::on_btn54_clicked()
{
    if(plcCommObj->getDoValue(54) == 0)
    {
        plcCommObj->setDoValue(54,1);
        ui->btn54->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(54,0);
        ui->btn54->setText("OFF");
    }
}

void MainWindow::on_btn55_clicked()
{
    if(plcCommObj->getDoValue(55) == 0)
    {
        plcCommObj->setDoValue(55,1);
        ui->btn55->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(55,0);
        ui->btn55->setText("OFF");
    }
}

void MainWindow::on_btn56_clicked()
{
    if(plcCommObj->getDoValue(56) == 0)
    {
        plcCommObj->setDoValue(56,1);
        ui->btn56->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(56,0);
        ui->btn56->setText("OFF");
    }
}

void MainWindow::on_btn57_clicked()
{
    if(plcCommObj->getDoValue(57) == 0)
    {
        plcCommObj->setDoValue(57,1);
        ui->btn57->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(57,0);
        ui->btn57->setText("OFF");
    }
}

void MainWindow::on_btn58_clicked()
{
    if(plcCommObj->getDoValue(58) == 0)
    {
        plcCommObj->setDoValue(58,1);
        ui->btn58->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(58,0);
        ui->btn58->setText("OFF");
    }
}

void MainWindow::on_btn59_clicked()
{
    if(plcCommObj->getDoValue(59) == 0)
    {
        plcCommObj->setDoValue(59,1);
        ui->btn59->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(59,0);
        ui->btn59->setText("OFF");
    }
}

void MainWindow::on_btn60_clicked()
{
    if(plcCommObj->getDoValue(60) == 0)
    {
        plcCommObj->setDoValue(60,1);
        ui->btn60->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(60,0);
        ui->btn60->setText("OFF");
    }
}
void MainWindow::on_btn61_clicked()
{
    if(plcCommObj->getDoValue(61) == 0)
    {
        plcCommObj->setDoValue(61,1);
        ui->btn61->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(61,0);
        ui->btn61->setText("OFF");
    }
}

void MainWindow::on_btn62_clicked()
{
    if(plcCommObj->getDoValue(62) == 0)
    {
        plcCommObj->setDoValue(62,1);
        ui->btn62->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(62,0);
        ui->btn62->setText("OFF");
    }
}

void MainWindow::on_btn63_clicked()
{
    if(plcCommObj->getDoValue(63) == 0)
    {
        plcCommObj->setDoValue(63,1);
        ui->btn63->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(63,0);
        ui->btn63->setText("OFF");
    }
}

void MainWindow::on_btn64_clicked()
{
    if(plcCommObj->getDoValue(64) == 0)
    {
        plcCommObj->setDoValue(64,1);
        ui->btn64->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(64,0);
        ui->btn64->setText("OFF");
    }
}

void MainWindow::updateBtn(int plcDoChno, QPushButton *btn)
{
    if(btn->text() == "OFF")
    {
        fcuCommObj->writeDOToFCUCCU(plcDoChno,1);
        DOListCCU[plcDoChno]->setStyleSheet("background-color: green;border-radius:20px;");
        btn->setText("ON");

    }
    else
    {
        fcuCommObj->writeDOToFCUCCU(plcDoChno,0);
        btn->setText("OFF");
        DOListCCU[plcDoChno]->setStyleSheet("background-color: red;border-radius:20px;");

    }

}

void MainWindow::on_btnDO1_2_clicked()
{
    updateBtn(0,ui->btnDO1_2);
}

void MainWindow::on_btnDO2_2_clicked()
{
    updateBtn(1,ui->btnDO2_2);

}

void MainWindow::on_btnDO3_2_clicked()
{
    updateBtn(2,ui->btnDO3_2);

    //    if(ui->btnDO3->text() == "OFF")
    //    {
    //        fcuCommObj->writeDOToFCUCCU(3,1);
    //        ui->btnDO3->setText("ON");
    //    }
    //    else
    //    {
    //        fcuCommObj->writeDOToFCUCCU(3,0);
    //        ui->btnDO3->setText("OFF");
    //    }
}

void MainWindow::on_btnDO4_2_clicked()
{
    updateBtn(3,ui->btnDO4_2);
}

void MainWindow::on_btnDO5_2_clicked()
{
    updateBtn(4,ui->btnDO5_2);
}

void MainWindow::on_btnDO6_2_clicked()
{
    updateBtn(5,ui->btnDO6_2);

}

void MainWindow::on_btnDO7_2_clicked()
{
    updateBtn(6,ui->btnDO7_2);
}

void MainWindow::on_btnDO8_2_clicked()
{
    updateBtn(7,ui->btnDO8_2);
}

void MainWindow::on_btnDO9_2_clicked()
{
    updateBtn(8,ui->btnDO9_2);
}

void MainWindow::on_btnDO10_2_clicked()
{
    updateBtn(9,ui->btnDO10_2);

}
void MainWindow::on_btnDO11_2_clicked()
{
    updateBtn(10,ui->btnDO11_2);
}

void MainWindow::on_btnDO12_2_clicked()
{
    updateBtn(11,ui->btnDO12_2);
}

void MainWindow::on_btnDO13_2_clicked()
{
    updateBtn(12,ui->btnDO13_2);
}

void MainWindow::on_btnDO14_2_clicked()
{
    updateBtn(13,ui->btnDO14_2);
}

void MainWindow::on_btnDO15_2_clicked()
{
    updateBtn(14,ui->btnDO15_2);
}

void MainWindow::on_btnDO16_2_clicked()
{
    updateBtn(15,ui->btnDO16_2);
}

void MainWindow::on_btnDO17_2_clicked()
{
    updateBtn(16,ui->btnDO17_2);
}

void MainWindow::on_btnDO18_2_clicked()
{
    updateBtn(17,ui->btnDO18_2);
}

void MainWindow::on_btnDO19_2_clicked()
{
    updateBtn(18,ui->btnDO19_2);

}

void MainWindow::on_btnDO20_2_clicked()
{
    updateBtn(19,ui->btnDO20_2);

}
void MainWindow::on_btnDO21_2_clicked()
{
    updateBtn(20,ui->btnDO21_2);
}

void MainWindow::on_btnDO22_2_clicked()
{
    updateBtn(21,ui->btnDO22_2);
}

void MainWindow::on_btnDO23_2_clicked()
{
    updateBtn(22,ui->btnDO23_2);
}

void MainWindow::on_btnDO24_2_clicked()
{
    updateBtn(23,ui->btnDO24_2);
}

void MainWindow::on_btnDO25_2_clicked()
{
    updateBtn(24,ui->btnDO25_2);
}

void MainWindow::on_btnDO26_2_clicked()
{
    updateBtn(25,ui->btnDO26_2);
}

void MainWindow::on_btnDO27_2_clicked()
{
    updateBtn(26,ui->btnDO27_2);
}

void MainWindow::on_btnDO28_2_clicked()
{
    updateBtn(27,ui->btnDO28_2);
}

void MainWindow::on_btnDO29_2_clicked()
{
    updateBtn(28,ui->btnDO29_2);
}

void MainWindow::on_btnDO30_2_clicked()
{
    updateBtn(29,ui->btnDO30_2);
}
void MainWindow::on_btnDO31_2_clicked()
{
    updateBtn(30,ui->btnDO31_2);
}

void MainWindow::on_btnDO32_2_clicked()
{
    updateBtn(31,ui->btnDO32_2);
}

void MainWindow::on_btnDO33_2_clicked()
{
    updateBtn(32,ui->btnDO33_2);
}

void MainWindow::on_btnDO34_2_clicked()
{
    updateBtn(33,ui->btnDO34_2);
}

void MainWindow::on_btnDO35_2_clicked()
{
    updateBtn(34,ui->btnDO35_2);
}

void MainWindow::on_btnDO36_2_clicked()
{
    updateBtn(35,ui->btnDO36_2);
}

void MainWindow::on_btnDO37_2_clicked()
{
    updateBtn(36,ui->btnDO37_2);
}

void MainWindow::on_btnDO38_2_clicked()
{
    updateBtn(37,ui->btnDO38_2);
}

void MainWindow::on_btnDO39_2_clicked()
{
    updateBtn(38,ui->btnDO39_2);
}


void MainWindow::on_btnDO40_2_clicked()
{
    updateBtn(39,ui->btnDO40_2);
}
void MainWindow::on_btnDO41_2_clicked()
{
    updateBtn(40,ui->btn41_2);
}

void MainWindow::on_btnDO42_2_clicked()
{
    updateBtn(41,ui->btn42_2);
}

void MainWindow::on_btnDO43_2_clicked()
{
    updateBtn(42,ui->btn43_2);
}

void MainWindow::on_btnDO44_2_clicked()
{
    updateBtn(43,ui->btn44_2);
}

void MainWindow::on_btnDO45_2_clicked()
{
    updateBtn(44,ui->btn45_2);
}

void MainWindow::on_btnDO46_2_clicked()
{
    updateBtn(45,ui->btn46_2);
}

void MainWindow::on_btnDO47_2_clicked()
{
    updateBtn(46,ui->btn47_2);
}

void MainWindow::on_btnDO48_2_clicked()
{
    updateBtn(47,ui->btn48_2);
}

void MainWindow::on_btnDO49_2_clicked()
{
    updateBtn(48,ui->btn49_2);
}



void MainWindow::on_btn50_2_clicked()
{
    updateBtn(49,ui->btn50_2);
}
void MainWindow::on_btn51_2_clicked()
{
    updateBtn(50,ui->btn51_2);
}

void MainWindow::on_btn52_2_clicked()
{
    updateBtn(51,ui->btn52_2);
}

void MainWindow::on_btn53_2_clicked()
{
    updateBtn(52,ui->btn53_2);
}

void MainWindow::on_btn54_2_clicked()
{
    updateBtn(53,ui->btn54_2);
}

void MainWindow::on_btn55_2_clicked()
{
    updateBtn(54,ui->btn55_2);
}

void MainWindow::on_btn56_2_clicked()
{
    updateBtn(55,ui->btn56_2);
}

void MainWindow::on_btn57_2_clicked()
{
    updateBtn(56,ui->btn57_2);
}

void MainWindow::on_btn58_2_clicked()
{
    updateBtn(57,ui->btn58_2);
}

void MainWindow::on_btn59_2_clicked()
{
    updateBtn(58,ui->btn59_2);
}

void MainWindow::on_btn60_2_clicked()
{
    updateBtn(59,ui->btn60_2);
}
void MainWindow::on_btn61_2_clicked()
{
    updateBtn(60,ui->btn61_2);
}
void MainWindow::on_btn62_2_clicked()
{
    updateBtn(61,ui->btn62_2);
}
void MainWindow::on_btn63_2_clicked()
{
    updateBtn(62,ui->btn63_2);
}
void MainWindow::on_btn64_2_clicked()
{
    updateBtn(63,ui->btn64_2);
}


void MainWindow::on_pushButton_2_clicked()
{

    QString AO1 = ui->txtAO1_2->text();
    int AO1send = AO1.toInt();
    fcuCommObj->writeAOToFCUCCU(0, AO1send);

    QString AO2 = ui->txtAO2_2->text();
    int AO2send = AO2.toInt();
    fcuCommObj->writeAOToFCUCCU(1, AO2send);

    QString AO3 = ui->txtAO3_2->text();
    int AO3send = AO3.toInt();
    fcuCommObj->writeAOToFCUCCU(2, AO3send);

    QString AO4 = ui->txtAO4_2->text();
    int AO4send = AO4.toInt();
    fcuCommObj->writeAOToFCUCCU(3, AO4send);

    QString AO5 = ui->txtAO5_2->text();
    int AO5send = AO5.toInt();
    fcuCommObj->writeAOToFCUCCU(4, AO5send);

    QString AO6 = ui->txtAO6_2->text();
    int AO6send = AO6.toInt();
    fcuCommObj->writeAOToFCUCCU(5, AO6send);

    QString AO7 = ui->txtAO7_2->text();
    int AO7send = AO7.toInt();
    fcuCommObj->writeAOToFCUCCU(6, AO7send);

    QString AO8 = ui->txtAO8_2->text();
    int AO8send = AO8.toInt();
    fcuCommObj->writeAOToFCUCCU(7, AO8send);


}

void MainWindow::on_btnDO1_3_clicked()
{

}
