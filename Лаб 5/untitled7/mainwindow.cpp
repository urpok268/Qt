#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "QStandardItemModel"
#include "QStandardItem"
#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QtGui>
#include <QFileDialog>
#include <QString>

QTableWidgetItem *item;
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


void MainWindow::on_action_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::currentPath(),
                                "Файл csv (*.csv);;All files (*.*)");
    QTextStream out(stdout);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
      // Создаем объект
      QFile file(fileName);

      // С помощью метода open() открываем файл в режиме чтения
      if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
      }

      // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
      QTextStream in(&file);

      // Считываем файл строка за строкой
      while (!in.atEnd()) { // метод atEnd() возвращает true, если в потоке больше нет данных для чтения
        QString line = in.readLine(); // метод readLine() считывает одну строку из потока
        out << line;
        QStringList splited = line.split(";");
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        ui->tableWidget->setColumnCount(splited.length()-1);
        for (int i=0;i<splited.length()-1;i++)
        {
            item = new QTableWidgetItem(splited[i]);
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,i,item);


        }

      }

      // Закрываем файл
      file.close();
}


void MainWindow::on_action_2_triggered()
{
    QFile fileOut("test.csv"); // Связываем объект с файлом fileout.txt
    if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text))
    { // Если файл успешно открыт для записи в текстовом режиме
         QTextStream writeStream(&fileOut); // Создаем объект класса QTextStream
             for (int i=0;i<ui->tableWidget->rowCount();i++){
                for (int j=0;j<ui->tableWidget->columnCount();j++)
                {
                    item =  ui->tableWidget->item(i,j);
                    if (NULL != item) writeStream << item->text()+";"; // Посылаем строку в поток для записи
                        else writeStream << ";";

                }
                writeStream << "\n";
             }
         fileOut.close(); // Закрываем файл
    }


}


void MainWindow::on_action_3_triggered()
{
    qApp->quit();
}


void MainWindow::on_pushButton_clicked()
{
    //int count = ui->tableView->model()->rowCount();
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(ui->lineEdit_2->text().toInt());
    ui->tableWidget->setColumnCount(ui->lineEdit->text().toInt());

}

