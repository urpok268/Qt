#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QListView>
#include <QStringListModel>
#include <QPushButton>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_currentIndexChanged(int index);


    void on_listView_clicked(const QModelIndex &index);

    void on_listView_indexesMoved(const QModelIndexList &indexes);

    void on_listWidget_currentTextChanged(const QString &currentText);

    void on_listWidget_currentRowChanged(int currentRow);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QGridLayout *myLayout;
    QLabel *ListCount, *ListLabel;
    QStringListModel *Model;
    QListView *ListView;
    QPushButton *AddButton, *EditButton, *DeleteButton, *SortButton;
    QStringList List;
};
#endif // MAINWINDOW_H
