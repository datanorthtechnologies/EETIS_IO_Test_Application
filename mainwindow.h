#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "plcComm.h"
#include "fcuccucomm.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addToList();
    void addCCUToList();
    void addDOToList();
    void addDOCCUToList();
    void addDOHarnessToList();
    void addDIHarnessToList();
    void addAIToList();
    void addAIToListFCU();
    void toggleDo(int channel, QPushButton* button);

protected slots:
     void update();
     void updateDO();
     void updateDOHarness();
     void updateCCUFCUDO();
     void updateDI();
     void updateDIHarness();
     void updateCCUFCUDI();
     void updateAI();
     void updateAIFCUCCU();
     void updateLink();

private slots:
     void on_btnDO1_clicked();

     void on_btnDO2_clicked();

     void on_btnDO3_clicked();

     void on_btnDO4_clicked();

     void on_btnDO5_clicked();

     void on_btnDO6_clicked();

     void on_btnDO7_clicked();

     void on_btnDO8_clicked();

     void on_btnDO9_clicked();

     void on_btnDO10_clicked();

     void on_btnDO11_clicked();

     void on_btnDO12_clicked();

     void on_btnDO13_clicked();

     void on_btnDO14_clicked();

     void on_btnDO15_clicked();

     void on_btnDO16_clicked();

     void on_btnDO17_clicked();

     void on_btnDO18_clicked();

     void on_btnDO19_clicked();

     void on_btnDO20_clicked();

     void on_btnDO21_clicked();

     void on_btnDO22_clicked();

     void on_btnDO23_clicked();

     void on_btnDO24_clicked();

     void on_btnDO25_clicked();

     void on_btnDO26_clicked();

     void on_btnDO27_clicked();

     void on_btnDO28_clicked();

     void on_btnDO29_clicked();

     void on_btnDO30_clicked();

     void on_btnDO31_clicked();

     void on_btnDO32_clicked();

     void on_btnDO33_clicked();

     void on_btnDO34_clicked();

     void on_btnDO35_clicked();

     void on_btnDO36_clicked();

     void on_btnDO37_clicked();

     void on_btnDO38_clicked();

     void on_btnDO39_clicked();

     void on_btnDO40_clicked();


     void on_pushButton_clicked();

     void on_btn41_clicked();
     void on_btn42_clicked();
     void on_btn43_clicked();
     void on_btn44_clicked();
     void on_btn45_clicked();
     void on_btn46_clicked();
     void on_btn47_clicked();
     void on_btn48_clicked();
     void on_btn49_clicked();
     void on_btn50_clicked();
     void on_btn51_clicked();
     void on_btn52_clicked();
     void on_btn53_clicked();
     void on_btn54_clicked();
     void on_btn55_clicked();
     void on_btn56_clicked();
     void on_btn57_clicked();
     void on_btn58_clicked();
     void on_btn59_clicked();
     void on_btn60_clicked();
     void on_btn61_clicked();
     void on_btn62_clicked();
     void on_btn63_clicked();
     void on_btn64_clicked();
     void on_btn65_clicked();
     void on_btn66_clicked();
     void on_btn67_clicked();
     void on_btn68_clicked();
     void on_btn69_clicked();
     void on_btn70_clicked();
     void on_btn71_clicked();
     void on_btn72_clicked();
     void on_btn73_clicked();
     void on_btn74_clicked();
     void on_btn75_clicked();
     void on_btn76_clicked();
     void on_btn77_clicked();
     void on_btn78_clicked();
     void on_btn79_clicked();
     void on_btn80_clicked();
     void on_btn81_clicked();
     void on_btn82_clicked();
     void on_btn83_clicked();
     void on_btn84_clicked();
     void on_btn85_clicked();
     void on_btn86_clicked();
     void on_btn87_clicked();
     void on_btn88_clicked();
     void on_btn89_clicked();
     void on_btn90_clicked();
     void on_btn91_clicked();
     void on_btn92_clicked();
     void on_btn93_clicked();
     void on_btn94_clicked();
     void on_btn95_clicked();
     void on_btn96_clicked();
     void on_btn97_clicked();
     void on_btn98_clicked();
     void on_btn99_clicked();
     void on_btn100_clicked();
     void on_btn101_clicked();
     void on_btn102_clicked();
     void on_btn103_clicked();
     void on_btn104_clicked();
     void on_btn105_clicked();
     void on_btn106_clicked();
     void on_btn107_clicked();
     void on_btn108_clicked();
     void on_btn109_clicked();
     void on_btn110_clicked();
     void on_btn111_clicked();
     void on_btn112_clicked();
     void on_btn113_clicked();
     void on_btn114_clicked();
     void on_btn115_clicked();
     void on_btn116_clicked();
     void on_btn117_clicked();
     void on_btn118_clicked();
     void on_btn119_clicked();
     void on_btn120_clicked();
     void on_btn121_clicked();
     void on_btn122_clicked();
     void on_btn123_clicked();
     void on_btn124_clicked();
     void on_btn125_clicked();
     void on_btn126_clicked();
     void on_btn127_clicked();
     void on_btn128_clicked();



     void on_btnDO1_2_clicked();
     void on_btnDO2_2_clicked();
     void on_btnDO3_2_clicked();
     void on_btnDO4_2_clicked();
     void on_btnDO5_2_clicked();
     void on_btnDO6_2_clicked();
     void on_btnDO7_2_clicked();
     void on_btnDO8_2_clicked();
     void on_btnDO9_2_clicked();
     void on_btnDO10_2_clicked();
     void on_btnDO11_2_clicked();
     void on_btnDO12_2_clicked();
     void on_btnDO13_2_clicked();
     void on_btnDO14_2_clicked();
     void on_btnDO15_2_clicked();
     void on_btnDO16_2_clicked();
     void on_btnDO17_2_clicked();
     void on_btnDO18_2_clicked();
     void on_btnDO19_2_clicked();
     void on_btnDO20_2_clicked();
     void on_btnDO21_2_clicked();
     void on_btnDO22_2_clicked();
     void on_btnDO23_2_clicked();
     void on_btnDO24_2_clicked();
     void on_btnDO25_2_clicked();
     void on_btnDO26_2_clicked();
     void on_btnDO27_2_clicked();
     void on_btnDO28_2_clicked();
     void on_btnDO29_2_clicked();
     void on_btnDO30_2_clicked();
     void on_btnDO31_2_clicked();
     void on_btnDO32_2_clicked();
     void on_btnDO33_2_clicked();
     void on_btnDO34_2_clicked();
     void on_btnDO35_2_clicked();
     void on_btnDO36_2_clicked();
     void on_btnDO37_2_clicked();
     void on_btnDO38_2_clicked();
     void on_btnDO39_2_clicked();
     void on_btnDO40_2_clicked();
     void on_btnDO41_2_clicked();
     void on_btnDO42_2_clicked();
     void on_btnDO43_2_clicked();
     void on_btnDO44_2_clicked();
     void on_btnDO45_2_clicked();
     void on_btnDO46_2_clicked();
     void on_btnDO47_2_clicked();
     void on_btnDO48_2_clicked();
     void on_btnDO49_2_clicked();
     void on_btn50_2_clicked();
     void on_btn51_2_clicked();
     void on_btn52_2_clicked();
     void on_btn53_2_clicked();
     void on_btn54_2_clicked();
     void on_btn55_2_clicked();
     void on_btn56_2_clicked();
     void on_btn57_2_clicked();
     void on_btn58_2_clicked();
     void on_btn59_2_clicked();
     void on_btn60_2_clicked();
     void on_btn61_2_clicked();
     void on_btn62_2_clicked();
     void on_btn63_2_clicked();
     void on_btn64_2_clicked();

     void updateBtn(int plcDoChno, QPushButton *btn);
     void updateBtnHarness(int plcDoChno, QPushButton *btn);


     void on_pushButton_2_clicked();

     void on_btnDO1_3_clicked();





     void on_btnHarnessDO1_clicked();
     
     void on_btnHarnessDO2_clicked();
     
     void on_btnHarnessDO3_clicked();

     void on_btnHarnessDO4_clicked();

     void on_btnHarnessDO5_clicked();

     void on_btnHarnessDO6_clicked();

     void on_btnHarnessDO7_clicked();

     void on_btnHarnessDO8_clicked();

     void on_btnHarnessDO9_clicked();

     void on_btnHarnessDO10_clicked();

     void on_btnHarnessDO11_clicked();

     void on_btnHarnessDO12_clicked();

     void on_btnHarnessDO13_clicked();

     void on_btnHarnessDO14_clicked();

     void on_btnHarnessDO15_clicked();

     void on_btnHarnessDO16_clicked();

     void on_btnHarnessDO17_clicked();

     void on_btnHarnessDO18_clicked();

     void on_btnHarnessDO19_clicked();

     void on_btnHarnessDO20_clicked();

     void on_btnHarnessDO21_clicked();

     void on_btnHarnessDO22_clicked();

     void on_btnHarnessDO23_clicked();

     void on_btnHarnessDO24_clicked();

     void on_btnHarnessDO25_clicked();

     void on_btnHarnessDO26_clicked();

     void on_btnHarnessDO27_clicked();

     void on_btnHarnessDO28_clicked();

     void on_btnHarnessDO29_clicked();

     void on_btnHarnessDO30_clicked();

     void on_btnHarnessDO31_clicked();

     void on_btnHarnessDO32_clicked();

     void on_btnHarnessDO33_clicked();

     void on_btnHarnessDO34_clicked();

     void on_btnHarnessDO35_clicked();

     void on_btnHarnessDO36_clicked();

     void on_btnHarnessDO37_clicked();

     void on_btnHarnessDO38_clicked();

     void on_btnHarnessDO39_clicked();

     void on_btnHarnessDO40_clicked();

     void on_btnHarnessDO41_clicked();

     void on_btnHarnessDO42_clicked();

     void on_btnHarnessDO43_clicked();

     void on_btnHarnessDO44_clicked();

     void on_btnHarnessDO45_clicked();

     void on_btnHarnessDO46_clicked();

     void on_btnHarnessDO47_clicked();

     void on_btnHarnessDO48_clicked();

     void on_btnHarnessDO49_clicked();

     void on_btnHarnessDO50_clicked();

     void on_btnHarnessDO51_clicked();

     void on_btnHarnessDO52_clicked();

     void on_btnHarnessDO53_clicked();

     void on_btnHarnessDO54_clicked();

     void on_btnHarnessDO55_clicked();

     void on_btnHarnessDO56_clicked();

     void on_btnHarnessDO57_clicked();

     void on_btnHarnessDO58_clicked();

     void on_btnHarnessDO59_clicked();

     void on_btnHarnessDO60_clicked();

     void on_btnHarnessDO61_clicked();

     void on_btnHarnessDO62_clicked();

     void on_btnHarnessDO63_clicked();

     void on_btnHarnessDO64_clicked();

     void on_btnHarnessDO65_clicked();

     void on_btnHarnessDO66_clicked();

     void on_btnHarnessDO67_clicked();

     void on_btnHarnessDO68_clicked();

     void on_btnHarnessDO69_clicked();

     void on_btnHarnessDO670_clicked();

     void on_btnHarnessDO71_clicked();

     void on_btnHarnessDO72_clicked();

     void on_btnHarnessDO73_clicked();

     void on_btnHarnessDO74_clicked();

     void on_btnHarnessDO75_clicked();

     void on_btnHarnessDO76_clicked();

     void on_btnHarnessDO77_clicked();

     void on_btnHarnessDO78_clicked();

     void on_btnHarnessDO79_clicked();

     void on_btnHarnessDO80_clicked();

     void on_btnHarnessDO81_clicked();

     void on_btnHarnessDO82_clicked();

     void on_btnHarnessDO83_clicked();

     void on_btnHarnessDO84_clicked();

     void on_btnHarnessDO85_clicked();

     void on_btnHarnessDO88_clicked();

     void on_btnHarnessDO87_clicked();

     void on_btnHarnessDO88_2_clicked();

     void on_btnHarnessDO89_clicked();

     void on_btnHarnessDO90_clicked();

     void on_btnHarnessDO91_clicked();

     void on_btnHarnessDO92_clicked();

     void on_btnHarnessDO94_clicked();

     void on_btnHarnessDO95_clicked();

     void on_btnHarnessDO96_clicked();

     void on_btnHarnessDO97_clicked();

     void on_btnHarnessDO94_2_clicked();

private:
    Ui::MainWindow *ui;
     QList<QLabel*>DIList;
     QList<QLabel*>DIListHarness;
     QList<QLabel*>CCUDIList;
     QList<QLabel*>DOList;
     QList<QLabel*>DOListCCU;
     QList<QLabel*>DOListHarness;
     QList<QLabel*>CCUList;
     QList<QLineEdit*>AIList;
     QList<QLineEdit*>AIRowList;
     QList<QLineEdit*>FCUAIList;
};

#endif // MAINWINDOW_H
