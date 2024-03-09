#include "secondwindow.h"
#include "ui_secondwindow.h"

secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
}

secondwindow::~secondwindow()
{
    delete ui;
}

QString* secondwindow::value()
{
    QString* addtext = new QString[6];
    addtext[0] = ui->lineEdit->text();
    addtext[1] = ui->lineEdit_2->text();
    addtext[2] = ui->lineEdit_3->text();
    addtext[3] = ui->lineEdit_4->text();
    if (ui->radioButton->isChecked()){
        addtext[4] = "М";
    }
    else if (ui->radioButton_2->isChecked()){
        addtext[4] = "Ж";
    }
    else{
         addtext[4] = "Неив.";
    }
    if (ui->checkBox->isChecked()){
        addtext[5] = "Да";
    }
    else{
        addtext[5] = "Нет";
    }
    return addtext; //текст передаваемый в форму
}

void secondwindow::setchanges(QString familia, QString name, QString otch, QString gr, bool pol, bool grajd)
{
    ui->lineEdit->setText(familia);
    ui->lineEdit_2->setText(name);
    ui->lineEdit_3->setText(otch);
    ui->lineEdit_4->setText(gr);
    if (pol)
        ui->radioButton->setChecked(true);
    else
        ui->radioButton_2->setChecked(true);
    if (grajd) ui->checkBox->setChecked(true);
}

