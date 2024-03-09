#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->temp->setText(ui->comboBox->currentText());

    for (int i=0; i<ui->comboBox->count();i++){
        ui->listWidget->addItem(QString(ui->comboBox->itemText(i)));
    }
    ui->listWidget->setCurrentItem(ui->listWidget->item(0));
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (ui->listWidget->currentRow()>=0){
      ui->temp->setText(ui->comboBox->currentText());
      ui->listWidget->setCurrentRow(index);
    }

}




void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    if (ui->listWidget->currentRow()>=0){
      ui->comboBox->setCurrentIndex(currentRow);
      ui->temp->setText(ui->comboBox->currentText());
    }

}


void MainWindow::on_pushButton_clicked()
{
    int index = ui->listWidget->currentRow();
    ui->listWidget->takeItem(index);
    ui->comboBox->removeItem(index);
    if (ui->listWidget->currentRow()<0) ui->temp->setText("");

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->addItem(ui->lineEdit->text());
    ui->comboBox->addItem(ui->lineEdit->text());
    ui->lineEdit->setText("");
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->listWidget->item(ui->listWidget->currentRow())->setText(ui->lineEdit->text());
    ui->comboBox->setItemText(ui->comboBox->currentIndex(),ui->lineEdit->text());
    ui->lineEdit->setText("");
}


void MainWindow::on_pushButton_5_clicked()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_3_clicked()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setText(ui->lineEdit->text());
    if (ui->listWidget->currentRow()<ui->listWidget->count()-1)
        ui->listWidget->insertItem(ui->listWidget->currentRow()+1,item);
    else
         ui->listWidget->insertItem(ui->listWidget->count(),item);
    ui->comboBox->insertItem(ui->comboBox->currentIndex()+1, ui->lineEdit->text());
    ui->lineEdit->setText("");
}

