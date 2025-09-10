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
    addDOHarnessToList();
    addDIHarnessToList();
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

void MainWindow::addDOHarnessToList()
{
    DOListHarness.append(ui->lblHarnessDO1);
    DOListHarness.append(ui->lblHarnessDO2);
    DOListHarness.append(ui->lblHarnessDO2);
    DOListHarness.append(ui->lblHarnessDO3 );
    DOListHarness.append(ui->lblHarnessDO4 );
    DOListHarness.append(ui->lblHarnessDO5 );
    DOListHarness.append(ui->lblHarnessDO6 );
    DOListHarness.append(ui->lblHarnessDO7 );
    DOListHarness.append(ui->lblHarnessDO8 );
    DOListHarness.append(ui->lblHarnessDO9 );
    DOListHarness.append(ui->lblHarnessDO10);
    DOListHarness.append(ui->lblHarnessDO11);
    DOListHarness.append(ui->lblHarnessDO12);
    DOListHarness.append(ui->lblHarnessDO13);
    DOListHarness.append(ui->lblHarnessDO14);
    DOListHarness.append(ui->lblHarnessDO15);
    DOListHarness.append(ui->lblHarnessDO16);
    DOListHarness.append(ui->lblHarnessDO17);
    DOListHarness.append(ui->lblHarnessDO18);
    DOListHarness.append(ui->lblHarnessDO19);
    DOListHarness.append(ui->lblHarnessDO20);
    DOListHarness.append(ui->lblHarnessDO21);
    DOListHarness.append(ui->lblHarnessDO22);
    DOListHarness.append(ui->lblHarnessDO23);
    DOListHarness.append(ui->lblHarnessDO24);
    DOListHarness.append(ui->lblHarnessDO25);
    DOListHarness.append(ui->lblHarnessDO26);
    DOListHarness.append(ui->lblHarnessDO27);
    DOListHarness.append(ui->lblHarnessDO28);
    DOListHarness.append(ui->lblHarnessDO29);
    DOListHarness.append(ui->lblHarnessDO30);
    DOListHarness.append(ui->lblHarnessDO31);
    DOListHarness.append(ui->lblHarnessDO32);
    DOListHarness.append(ui->lblHarnessDO33);
    DOListHarness.append(ui->lblHarnessDO34);
    DOListHarness.append(ui->lblHarnessDO35);
    DOListHarness.append(ui->lblHarnessDO36);
    DOListHarness.append(ui->lblHarnessDO37);
    DOListHarness.append(ui->lblHarnessDO38);
    DOListHarness.append(ui->lblHarnessDO39);
    DOListHarness.append(ui->lblHarnessDO40);
    DOListHarness.append(ui->lblHarnessDO41);
    DOListHarness.append(ui->lblHarnessDO42);
    DOListHarness.append(ui->blHarnessDO43);
    DOListHarness.append(ui->blHarnessDO44);
    DOListHarness.append(ui->blHarnessDO45);
    DOListHarness.append(ui->blHarnessDO46);
    DOListHarness.append(ui->blHarnessDO47);
    DOListHarness.append(ui->blHarnessDO48);
    DOListHarness.append(ui->blHarnessDO49);
    DOListHarness.append(ui->blHarnessDO50);
    DOListHarness.append(ui->blHarnessDO51);
    DOListHarness.append(ui->blHarnessDO52);
    DOListHarness.append(ui->blHarnessDO53);
    DOListHarness.append(ui->blHarnessDO54);
    DOListHarness.append(ui->blHarnessDO55);
    DOListHarness.append(ui->blHarnessDO56);
    DOListHarness.append(ui->blHarnessDO57);
    DOListHarness.append(ui->blHarnessDO58);
    DOListHarness.append(ui->blHarnessDO59);
    DOListHarness.append(ui->blHarnessDO60);
    DOListHarness.append(ui->blHarnessDO61);
    DOListHarness.append(ui->blHarnessDO62);
    DOListHarness.append(ui->blHarnessDO63);
    DOListHarness.append(ui->blHarnessDO64);
    DOListHarness.append(ui->blHarnessDO65);
    DOListHarness.append(ui->blHarnessDO66);
    DOListHarness.append(ui->blHarnessDO67);
    DOListHarness.append(ui->blHarnessDO68);
    DOListHarness.append(ui->blHarnessDO69);
    DOListHarness.append(ui->blHarnessDO70);
    DOListHarness.append(ui->blHarnessDO71);
    DOListHarness.append(ui->blHarnessDO72);
    DOListHarness.append(ui->blHarnessDO73);
    DOListHarness.append(ui->blHarnessDO74);
    DOListHarness.append(ui->blHarnessDO75);
    DOListHarness.append(ui->blHarnessDO76);
    DOListHarness.append(ui->blHarnessDO77);
    DOListHarness.append(ui->blHarnessDO78);
    DOListHarness.append(ui->blHarnessDO79);
    DOListHarness.append(ui->blHarnessDO80);
    DOListHarness.append(ui->blHarnessDO81);
    DOListHarness.append(ui->blHarnessDO82);
    DOListHarness.append(ui->blHarnessDO83);
    DOListHarness.append(ui->blHarnessDO84);
    DOListHarness.append(ui->blHarnessDO85);
    DOListHarness.append(ui->blHarnessDO86);
    DOListHarness.append(ui->blHarnessDO87);
    DOListHarness.append(ui->blHarnessDO88);
    DOListHarness.append(ui->blHarnessDO89);
    DOListHarness.append(ui->blHarnessDO90);
    DOListHarness.append(ui->blHarnessDO91);
    DOListHarness.append(ui->blHarnessDO92);
    DOListHarness.append(ui->blHarnessDO94);
    DOListHarness.append(ui->blHarnessDO95);
    DOListHarness.append(ui->blHarnessDO96);
    DOListHarness.append(ui->blHarnessDO97);

}

void MainWindow::addDIHarnessToList()
{
    DIListHarness.append(ui->lblHarnessDI1);
    DIListHarness.append(ui->lblHarnessDI2);
    DIListHarness.append(ui->lblHarnessDI3);
    DIListHarness.append(ui->lblHarnessDI4);
    DIListHarness.append(ui->lblHarnessDI5);
    DIListHarness.append(ui->lblHarnessDI6);
    DIListHarness.append(ui->lblHarnessDI7);
    DIListHarness.append(ui->lblHarnessDI8);
    DIListHarness.append(ui->lblHarnessDI9);
    DIListHarness.append(ui->lblHarnessDI10);
    DIListHarness.append(ui->lblHarnessDI11);
    DIListHarness.append(ui->lblHarnessDI12);
    DIListHarness.append(ui->lblHarnessDI13);
    DIListHarness.append(ui->lblHarnessDI14);
    DIListHarness.append(ui->lblHarnessDI15);
    DIListHarness.append(ui->lblHarnessDI16);
    DIListHarness.append(ui->lblHarnessDI17);
    DIListHarness.append(ui->lblHarnessDI18);
    DIListHarness.append(ui->lblHarnessDI19);
    DIListHarness.append(ui->lblHarnessDI20);
    DIListHarness.append(ui->lblHarnessDI21);
    DIListHarness.append(ui->lblHarnessDI22);
    DIListHarness.append(ui->lblHarnessDI23);
    DIListHarness.append(ui->lblHarnessDI24);
    DIListHarness.append(ui->lblHarnessDI25);
    DIListHarness.append(ui->lblHarnessDI26);
    DIListHarness.append(ui->lblHarnessDI27);
    DIListHarness.append(ui->lblHarnessDI28);
    DIListHarness.append(ui->lblHarnessDI29);
    DIListHarness.append(ui->lblHarnessDI30);
    DIListHarness.append(ui->lblHarnessDI31);
    DIListHarness.append(ui->lblHarnessDI32);
    DIListHarness.append(ui->lblHarnessDI33);
    DIListHarness.append(ui->lblHarnessDI34);
    DIListHarness.append(ui->lblHarnessDI35);
    DIListHarness.append(ui->lblHarnessDI36);
    DIListHarness.append(ui->lblHarnessDI37);
    DIListHarness.append(ui->lblHarnessDI38);
    DIListHarness.append(ui->lblHarnessDI39);
    DIListHarness.append(ui->lblHarnessDI40);
    DIListHarness.append(ui->lblHarnessDI41);
    DIListHarness.append(ui->lblHarnessDI42);
    DIListHarness.append(ui->lblHarnessDI43);
    DIListHarness.append(ui->lblHarnessDI44);
    DIListHarness.append(ui->lblHarnessDI45);
    DIListHarness.append(ui->lblHarnessDI46);
    DIListHarness.append(ui->lblHarnessDI47);
    DIListHarness.append(ui->lblHarnessDI48);
    DIListHarness.append(ui->lblHarnessDI49);
    DIListHarness.append(ui->lblHarnessDI50);
    DIListHarness.append(ui->lblHarnessDI51);
    DIListHarness.append(ui->lblHarnessDI52);
    DIListHarness.append(ui->lblHarnessDI53);
    DIListHarness.append(ui->lblHarnessDI54);
    DIListHarness.append(ui->lblHarnessDI55);
    DIListHarness.append(ui->lblHarnessDI56);
    DIListHarness.append(ui->lblHarnessDI57);
    DIListHarness.append(ui->lblHarnessDI58);
    DIListHarness.append(ui->lblHarnessDI59);
    DIListHarness.append(ui->lblHarnessDI60);
    DIListHarness.append(ui->lblHarnessDI61);
    DIListHarness.append(ui->lblHarnessDI62);
    DIListHarness.append(ui->lblHarnessDI63);
    DIListHarness.append(ui->lblHarnessDI64);
    DIListHarness.append(ui->lblHarnessDI65);
    DIListHarness.append(ui->lblHarnessDI66);
    DIListHarness.append(ui->lblHarnessDI67);
    DIListHarness.append(ui->lblHarnessDI68);
    DIListHarness.append(ui->lblHarnessDI69);
    DIListHarness.append(ui->lblHarnessDI70);
    DIListHarness.append(ui->lblHarnessDI71);
    DIListHarness.append(ui->lblHarnessDI72);
    DIListHarness.append(ui->lblHarnessDI73);
    DIListHarness.append(ui->lblHarnessDI74);
    DIListHarness.append(ui->lblHarnessDI75);
    DIListHarness.append(ui->lblHarnessDI76);
    DIListHarness.append(ui->lblHarnessDI77);
    DIListHarness.append(ui->lblHarnessDI78);
    DIListHarness.append(ui->lblHarnessDI79);
    DIListHarness.append(ui->lblHarnessDI80);
    DIListHarness.append(ui->lblHarnessDI81);
    DIListHarness.append(ui->lblHarnessDI82);
    DIListHarness.append(ui->lblHarnessDI83);
    DIListHarness.append(ui->lblHarnessDI84);
    DIListHarness.append(ui->lblHarnessDI85);
    DIListHarness.append(ui->lblHarnessDI86);
    DIListHarness.append(ui->lblHarnessDI87);
    DIListHarness.append(ui->lblHarnessDI88);
    DIListHarness.append(ui->lblHarnessDI89);
    DIListHarness.append(ui->lblHarnessDI90);
    DIListHarness.append(ui->lblHarnessDI91);
    DIListHarness.append(ui->lblHarnessDI92);
    DIListHarness.append(ui->lblHarnessDI93);
    DIListHarness.append(ui->lblHarnessDI94);
    DIListHarness.append(ui->lblHarnessDI95);
    DIListHarness.append(ui->lblHarnessDI96);
    DIListHarness.append(ui->lblHarnessDI97);

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

    AIRowList.append(ui->txtAI1_3);
    AIRowList.append(ui->txtAI1_4);
    AIRowList.append(ui->txtAI1_5);
    AIRowList.append(ui->txtAI1_6);
    AIRowList.append(ui->txtAI1_7);
    AIRowList.append(ui->txtAI1_8);
    AIRowList.append(ui->txtAI1_9);
    AIRowList.append(ui->txtAI1_10);
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
    updateDIHarness();
    updateLink();
    //updateDOHarness();

}

void MainWindow::updateDO()
{
    for(int i= 1;i<DOList.count() + 1;i++)
    {
        if(plcCommObj->getDoValue(i) == 1)
        {
            DOList[i -1]->setStyleSheet("background-color: green;border-radius:20px;");
        }
        else
        {
            DOList[i - 1]->setStyleSheet("background-color: red;border-radius:20px;");
        }
    }
}

void MainWindow::updateDOHarness()
{
    for(int i= 0;i<DOListHarness.count();i++)
    {
        if(plcCommObj->getDoValue(i) == 1)
        {
            DOListHarness[i]->setStyleSheet("background-color: green;border-radius:20px;");
        }
        else
        {
            DOListHarness[i]->setStyleSheet("background-color: red;border-radius:20px;");
        }
    }
}

void MainWindow::updateCCUFCUDO()
{

}

void MainWindow::updateDI()
{
    for(int i= 1;i<DIList.count() + 1 ;i++)
    {
        if(plcCommObj->getDiValue(i) == 1)
        {
            DIList[i -1]->setStyleSheet("background-color: green;border-radius:20px;");
        }
        else
        {
            DIList[i -1]->setStyleSheet("background-color: red;border-radius:20px;");
        }
    }
}

void MainWindow::updateDIHarness()
{
    for(int i= 1;i<DIListHarness.count() + 1 ;i++)
    {
        if(plcCommObj->getDiValue(i) == 1)
        {
            DIListHarness[i -1]->setStyleSheet("background-color: green;border-radius:20px;");
        }
        else
        {
            DIListHarness[i -1]->setStyleSheet("background-color: red;border-radius:20px;");
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
    for(int i= 1;i<AIList.count();i++)
    {
      //  val = QString::number(plcCommObj->getAiValue(i));
        int channel4 = plcCommObj->getAiValue(i);
        qDebug()<<"channel4"<<channel4;

        if(i == 7)
        {
            //float voltagechannel4 = (30.0 / 28000.0) * channel4 ;// ((0.0003607 * channel4) - 0.963) * 3;
            float voltagechannel4 = (1.0 / 28000.0) * channel4 * 10 * 3;// ((0.0003607 * channel4) - 0.963) * 3;
            qDebug()<<"voltagechannel4"<<voltagechannel4;
            AIList[i - 1]->setText(QString::number(voltagechannel4));
        }else
        {
            float voltagechannel4 = (1.0 / 28000.0) * channel4 * 10 * 2;
            AIList[i - 1]->setText(QString::number(voltagechannel4));
        }

    }

    for(int i= 1;i<AIRowList.count();i++)
    {
        val = QString::number(plcCommObj->getAiValue(i));
        AIRowList[i - 1]->setText(val);
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

void MainWindow::updateLink()
{
    if (plcCommObj->linkStatus == 1)
    {
        ui->lblUTMConnection->setText(
            "<div style='font-family:\"Roboto\"; text-align:center;'>"
            "<p style='font-size:16px; line-height:20px; margin:0;'>Connected</p>"
            "</div>"
        );
        ui->lblUTMConnection->setStyleSheet("background-color: rgb(73, 202, 66); color: white; border-bottom-right-radius: 10px; border-top-left-radius: 10px;");
    }
    else if (plcCommObj->linkStatus == 0)
    {
        ui->lblUTMConnection->setText(
            "<div style='font-family:\"Roboto\"; text-align:center;'>"
            "<p style='font-size:16px; line-height:20px; margin:0;'>Test Jig</p>"
            "</div>"
        );
        ui->lblUTMConnection->setStyleSheet("background-color: rgb(233, 69, 69); color: white; border-bottom-right-radius: 10px; border-top-left-radius: 10px;");
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
    plcCommObj->setAoValue(1, AO1send);

    QString AO2 = ui->txtAO2->text();
    int AO2send = AO2.toInt();
    plcCommObj->setAoValue(2, AO2send);

    QString AO3 = ui->txtAO3->text();
    int AO3send = AO3.toInt();
    plcCommObj->setAoValue(3, AO3send);

    QString AO4 = ui->txtAO4->text();
    int AO4send = AO4.toInt();
    plcCommObj->setAoValue(4, AO4send);

    QString AO5 = ui->txtAO5->text();
    int AO5send = AO5.toInt();
    plcCommObj->setAoValue(5, AO5send);

    QString AO6 = ui->txtAO6->text();
    int AO6send = AO6.toInt();
    plcCommObj->setAoValue(6, AO6send);

    QString AO7 = ui->txtAO7->text();
    int AO7send = AO7.toInt();
    plcCommObj->setAoValue(7, AO7send);

    QString AO8 = ui->txtAO8->text();
    int AO8send = AO8.toInt();
    plcCommObj->setAoValue(8, AO8send);

    QString AO9 = ui->txtAO9->text();
    int AO9send = AO9.toInt();
    plcCommObj->setAoValue(9, AO9send);

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

void MainWindow::updateBtnHarness(int plcDoChno, QPushButton *btn)
{
    if(btn->text() == "OFF")
    {
        plcCommObj->setDoValue(plcDoChno,1);
       // DOListHarness[plcDoChno]->setStyleSheet("background-color: green;border-radius:20px;");
        btn->setText("ON");
    }
    else
    {
        plcCommObj->setDoValue(plcDoChno,0);
        btn->setText("OFF");
      //  DOListHarness[plcDoChno]->setStyleSheet("background-color: red;border-radius:20px;");
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



void MainWindow::on_btnHarnessDO1_clicked()
{
    updateBtnHarness(1,ui->btnHarnessDO1);
}

void MainWindow::on_btnHarnessDO2_clicked()
{
    updateBtnHarness(2,ui->btnHarnessDO2);
}

void MainWindow::on_btnHarnessDO3_clicked()
{
    updateBtnHarness(3,ui->btnHarnessDO3);
}

void MainWindow::on_btnHarnessDO4_clicked()
{
    updateBtnHarness(4,ui->btnHarnessDO4);
}

void MainWindow::on_btnHarnessDO5_clicked()
{
    updateBtnHarness(5,ui->btnHarnessDO5);

}

void MainWindow::on_btnHarnessDO6_clicked()
{
    updateBtnHarness(6,ui->btnHarnessDO6);

}

void MainWindow::on_btnHarnessDO7_clicked()
{
    updateBtnHarness(7,ui->btnHarnessDO7);
}

void MainWindow::on_btnHarnessDO8_clicked()
{
    updateBtnHarness(8,ui->btnHarnessDO8);

}

void MainWindow::on_btnHarnessDO9_clicked()
{
    updateBtnHarness(9,ui->btnHarnessDO9);

}

void MainWindow::on_btnHarnessDO10_clicked()
{
    updateBtnHarness(10,ui->btnHarnessDO10);

}

void MainWindow::on_btnHarnessDO11_clicked()
{
    updateBtnHarness(11,ui->btnHarnessDO11);

}

void MainWindow::on_btnHarnessDO12_clicked()
{
    updateBtnHarness(12,ui->btnHarnessDO12);

}

void MainWindow::on_btnHarnessDO13_clicked()
{
    updateBtnHarness(13,ui->btnHarnessDO13);

}

void MainWindow::on_btnHarnessDO14_clicked()
{
    updateBtnHarness(14,ui->btnHarnessDO14);
}

void MainWindow::on_btnHarnessDO15_clicked()
{
    updateBtnHarness(15,ui->btnHarnessDO15);
}

void MainWindow::on_btnHarnessDO16_clicked()
{
    updateBtnHarness(16,ui->btnHarnessDO16);
}

void MainWindow::on_btnHarnessDO17_clicked()
{
    updateBtnHarness(17,ui->btnHarnessDO17);
}

void MainWindow::on_btnHarnessDO18_clicked()
{
    updateBtnHarness(18,ui->btnHarnessDO18);
}

void MainWindow::on_btnHarnessDO19_clicked()
{
    updateBtnHarness(19,ui->btnHarnessDO19);
}

void MainWindow::on_btnHarnessDO20_clicked()
{
    updateBtnHarness(20,ui->btnHarnessDO20);

}

void MainWindow::on_btnHarnessDO21_clicked()
{
    updateBtnHarness(21,ui->btnHarnessDO21);

}

void MainWindow::on_btnHarnessDO22_clicked()
{
    updateBtnHarness(22,ui->btnHarnessDO22);

}

void MainWindow::on_btnHarnessDO23_clicked()
{
    updateBtnHarness(23,ui->btnHarnessDO23);

}

void MainWindow::on_btnHarnessDO24_clicked()
{
    updateBtnHarness(24,ui->btnHarnessDO24);

}

void MainWindow::on_btnHarnessDO25_clicked()
{
    updateBtnHarness(25,ui->btnHarnessDO25);

}

void MainWindow::on_btnHarnessDO26_clicked()
{
    updateBtnHarness(26,ui->btnHarnessDO26);

}

void MainWindow::on_btnHarnessDO27_clicked()
{
    updateBtnHarness(27,ui->btnHarnessDO27);

}

void MainWindow::on_btnHarnessDO28_clicked()
{
    updateBtnHarness(28,ui->btnHarnessDO28);

}

void MainWindow::on_btnHarnessDO29_clicked()
{
    updateBtnHarness(29,ui->btnHarnessDO29);

}

void MainWindow::on_btnHarnessDO30_clicked()
{
    updateBtnHarness(30,ui->btnHarnessDO30);

}

void MainWindow::on_btnHarnessDO31_clicked()
{
    updateBtnHarness(31,ui->btnHarnessDO31);

}

void MainWindow::on_btnHarnessDO32_clicked()
{
    updateBtnHarness(32,ui->btnHarnessDO32);

}

void MainWindow::on_btnHarnessDO33_clicked()
{
    updateBtnHarness(33,ui->btnHarnessDO33);

}

void MainWindow::on_btnHarnessDO34_clicked()
{
    updateBtnHarness(34,ui->btnHarnessDO34);

}

void MainWindow::on_btnHarnessDO35_clicked()
{
    updateBtnHarness(35,ui->btnHarnessDO35);

}

void MainWindow::on_btnHarnessDO36_clicked()
{
    updateBtnHarness(36,ui->btnHarnessDO36);

}

void MainWindow::on_btnHarnessDO37_clicked()
{
    updateBtnHarness(37,ui->btnHarnessDO37);

}

void MainWindow::on_btnHarnessDO38_clicked()
{
    updateBtnHarness(38,ui->btnHarnessDO38);

}

void MainWindow::on_btnHarnessDO39_clicked()
{
    updateBtnHarness(39,ui->btnHarnessDO39);

}

void MainWindow::on_btnHarnessDO40_clicked()
{
    updateBtnHarness(40,ui->btnHarnessDO40);

}

void MainWindow::on_btnHarnessDO41_clicked()
{
    updateBtnHarness(41,ui->btnHarnessDO41);

}

void MainWindow::on_btnHarnessDO42_clicked()
{
    updateBtnHarness(42,ui->btnHarnessDO42);

}

void MainWindow::on_btnHarnessDO43_clicked()
{
    updateBtnHarness(43,ui->btnHarnessDO43);

}

void MainWindow::on_btnHarnessDO44_clicked()
{
    updateBtnHarness(44,ui->btnHarnessDO44);
}

void MainWindow::on_btnHarnessDO45_clicked()
{
    updateBtnHarness(45,ui->btnHarnessDO45);
}

void MainWindow::on_btnHarnessDO46_clicked()
{
    updateBtnHarness(46,ui->btnHarnessDO46);

}

void MainWindow::on_btnHarnessDO47_clicked()
{
    updateBtnHarness(47,ui->btnHarnessDO47);

}

void MainWindow::on_btnHarnessDO48_clicked()
{
    updateBtnHarness(48,ui->btnHarnessDO48);

}

void MainWindow::on_btnHarnessDO49_clicked()
{
    updateBtnHarness(49,ui->btnHarnessDO49);

}

void MainWindow::on_btnHarnessDO50_clicked()
{
    updateBtnHarness(50,ui->btnHarnessDO50);

}

void MainWindow::on_btnHarnessDO51_clicked()
{
    updateBtnHarness(51,ui->btnHarnessDO51);

}

void MainWindow::on_btnHarnessDO52_clicked()
{
    updateBtnHarness(52,ui->btnHarnessDO52);

}

void MainWindow::on_btnHarnessDO53_clicked()
{
    updateBtnHarness(53,ui->btnHarnessDO53);

}

void MainWindow::on_btnHarnessDO54_clicked()
{
    updateBtnHarness(54,ui->btnHarnessDO54);

}

void MainWindow::on_btnHarnessDO55_clicked()
{
    updateBtnHarness(55,ui->btnHarnessDO55);

}

void MainWindow::on_btnHarnessDO56_clicked()
{
    updateBtnHarness(56,ui->btnHarnessDO56);

}

void MainWindow::on_btnHarnessDO57_clicked()
{
    updateBtnHarness(57,ui->btnHarnessDO57);

}

void MainWindow::on_btnHarnessDO58_clicked()
{
    updateBtnHarness(58,ui->btnHarnessDO58);

}

void MainWindow::on_btnHarnessDO59_clicked()
{
    updateBtnHarness(59,ui->btnHarnessDO59);

}

void MainWindow::on_btnHarnessDO60_clicked()
{
    updateBtnHarness(60,ui->btnHarnessDO60);

}

void MainWindow::on_btnHarnessDO61_clicked()
{
    updateBtnHarness(61,ui->btnHarnessDO61);

}

void MainWindow::on_btnHarnessDO62_clicked()
{
    updateBtnHarness(62,ui->btnHarnessDO62);

}

void MainWindow::on_btnHarnessDO63_clicked()
{
    updateBtnHarness(63,ui->btnHarnessDO63);

}

void MainWindow::on_btnHarnessDO64_clicked()
{
    updateBtnHarness(64,ui->btnHarnessDO64);

}

void MainWindow::on_btnHarnessDO65_clicked()
{
    updateBtnHarness(65,ui->btnHarnessDO65);
}

void MainWindow::on_btnHarnessDO66_clicked()
{
    updateBtnHarness(66,ui->btnHarnessDO66);

}

void MainWindow::on_btnHarnessDO67_clicked()
{
    updateBtnHarness(67,ui->btnHarnessDO67);
}

void MainWindow::on_btnHarnessDO68_clicked()
{
    updateBtnHarness(68,ui->btnHarnessDO68);
}

void MainWindow::on_btnHarnessDO69_clicked()
{
    updateBtnHarness(69,ui->btnHarnessDO69);
}

void MainWindow::on_btnHarnessDO670_clicked()
{
    updateBtnHarness(70,ui->btnHarnessDO670);
}

void MainWindow::on_btnHarnessDO71_clicked()
{
    updateBtnHarness(71,ui->btnHarnessDO71);
}

void MainWindow::on_btnHarnessDO72_clicked()
{
    updateBtnHarness(72,ui->btnHarnessDO72);
}

void MainWindow::on_btnHarnessDO73_clicked()
{
    updateBtnHarness(73,ui->btnHarnessDO73);
}

void MainWindow::on_btnHarnessDO74_clicked()
{
    updateBtnHarness(74,ui->btnHarnessDO74);
}

void MainWindow::on_btnHarnessDO75_clicked()
{
    updateBtnHarness(75,ui->btnHarnessDO75);

}

void MainWindow::on_btnHarnessDO76_clicked()
{
    updateBtnHarness(76,ui->btnHarnessDO76);

}

void MainWindow::on_btnHarnessDO77_clicked()
{
    updateBtnHarness(77,ui->btnHarnessDO77);

}

void MainWindow::on_btnHarnessDO78_clicked()
{
    updateBtnHarness(78,ui->btnHarnessDO78);

}

void MainWindow::on_btnHarnessDO79_clicked()
{
    updateBtnHarness(79,ui->btnHarnessDO79);

}

void MainWindow::on_btnHarnessDO80_clicked()
{
    updateBtnHarness(80,ui->btnHarnessDO80);

}

void MainWindow::on_btnHarnessDO81_clicked()
{
    updateBtnHarness(81,ui->btnHarnessDO81);

}

void MainWindow::on_btnHarnessDO82_clicked()
{
    updateBtnHarness(82,ui->btnHarnessDO82);

}

void MainWindow::on_btnHarnessDO83_clicked()
{
    updateBtnHarness(83,ui->btnHarnessDO83);

}

void MainWindow::on_btnHarnessDO84_clicked()
{
    updateBtnHarness(84,ui->btnHarnessDO84);

}

void MainWindow::on_btnHarnessDO85_clicked()
{
    updateBtnHarness(85,ui->btnHarnessDO85);

}

void MainWindow::on_btnHarnessDO88_clicked()
{
    updateBtnHarness(86,ui->btnHarnessDO88);

}

void MainWindow::on_btnHarnessDO87_clicked()
{
    updateBtnHarness(87,ui->btnHarnessDO87);

}

void MainWindow::on_btnHarnessDO88_2_clicked()
{
    updateBtnHarness(88,ui->btnHarnessDO88_2);

}

void MainWindow::on_btnHarnessDO89_clicked()
{
    updateBtnHarness(89,ui->btnHarnessDO89);
}

void MainWindow::on_btnHarnessDO90_clicked()
{
    updateBtnHarness(90,ui->btnHarnessDO90);
}

void MainWindow::on_btnHarnessDO91_clicked()
{
    updateBtnHarness(91,ui->btnHarnessDO91);

}

void MainWindow::on_btnHarnessDO92_clicked()
{
    updateBtnHarness(92,ui->btnHarnessDO92);

}
void MainWindow::on_btnHarnessDO94_2_clicked()
{
    updateBtnHarness(93,ui->btnHarnessDO94_2);
}

void MainWindow::on_btnHarnessDO94_clicked()
{
    updateBtnHarness(94,ui->btnHarnessDO94);
}

void MainWindow::on_btnHarnessDO95_clicked()
{
    updateBtnHarness(95,ui->btnHarnessDO95);

}

void MainWindow::on_btnHarnessDO96_clicked()
{
    updateBtnHarness(96,ui->btnHarnessDO96);

}

void MainWindow::on_btnHarnessDO97_clicked()
{
    updateBtnHarness(97,ui->btnHarnessDO97);

}



