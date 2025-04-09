#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector.h"
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_create_clicked();
    void on_pushButton_pushBack_clicked();
    void on_pushButton_popBack_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_resize_clicked();
    void on_pushButton_at_clicked();


private:
    Ui::MainWindow *ui;
    myStd::vector<int> vec;
    void updateVectorDisplay();
    void showStatus(const QString &message);
};
#endif // MAINWINDOW_H
