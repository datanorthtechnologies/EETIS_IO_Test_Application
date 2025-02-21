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
    void addAIToList();
    void addAIToListFCU();

protected slots:
     void update();
     void updateDO();
     void updateCCUFCUDO();
     void updateDI();
     void updateCCUFCUDI();
     void updateAI();
     void updateAIFCUCCU();

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


     void on_pushButton_2_clicked();

     void on_btnDO1_3_clicked();

private:
    Ui::MainWindow *ui;
     QList<QLabel*>DIList;
     QList<QLabel*>CCUDIList;
     QList<QLabel*>DOList;
     QList<QLabel*>DOListCCU;
     QList<QLabel*>CCUList;
     QList<QLineEdit*>AIList;
     QList<QLineEdit*>FCUAIList;
};

#endif // MAINWINDOW_H
