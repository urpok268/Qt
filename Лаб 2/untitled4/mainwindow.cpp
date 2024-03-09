#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   float vrem;
   vrem = ui->ch1->text().toFloat()+ui->ch2->text().toFloat();
   QString str;
   str.setNum(vrem);
   ui->result->setText(str);
}


void MainWindow::on_pushButton_2_clicked()
{
    float vrem;
    vrem = ui->ch1->text().toFloat()-ui->ch2->text().toFloat();
    QString str;
    str.setNum(vrem);
    ui->result->setText(str);
}


void MainWindow::on_pushButton_3_clicked()
{
    float vrem;
    vrem = ui->ch1->text().toFloat()/ui->ch2->text().toFloat();
    QString str;
    str.setNum(vrem);
    ui->result->setText(str);
}


void MainWindow::on_pushButton_4_clicked()
{
    float vrem;
    vrem = ui->ch1->text().toFloat()*ui->ch2->text().toFloat();
    QString str;
    str.setNum(vrem);
    ui->result->setText(str);
}

