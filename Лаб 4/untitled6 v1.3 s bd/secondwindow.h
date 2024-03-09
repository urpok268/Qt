#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();
    //метод возвращающий строку
    QString* value();
    void setchanges(QString familia, QString name, QString otch, QString gr, bool pol, bool grajd);
private:
    Ui::secondwindow *ui;
};

#endif // SECONDWINDOW_H
