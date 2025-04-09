#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels({"Индекс", "Значения"});
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setVisible(false);

    updateVectorDisplay();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateVectorDisplay()
{
    ui->tableWidget->setRowCount(vec.size());

    for (size_t i = 0; i < vec.size(); ++i) {
        QTableWidgetItem *indexItem = new QTableWidgetItem(QString::number(i));
        QTableWidgetItem *valueItem = new QTableWidgetItem(QString::number(vec[i]));

        ui->tableWidget->setItem(i, 0, indexItem);
        ui->tableWidget->setItem(i, 1, valueItem);
    }

    ui->label_size->setText(QString("Размер: %1").arg(vec.size()));
    ui->label_capacity->setText(QString("Емкость: %1").arg(vec.capacity()));
}

void MainWindow::showStatus(const QString &message)
{
    ui->statusbar->showMessage(message, 3000);
}

void MainWindow::on_pushButton_create_clicked()
{
    int size = ui->spinBox_size->value();
    vec = myStd::vector<int>(size);
    updateVectorDisplay();
    showStatus(QString("Создан вектор с размером %1").arg(size));
}

void MainWindow::on_pushButton_pushBack_clicked()
{
    int value = ui->spinBox_value->value();
    vec.push_back(value);
    updateVectorDisplay();
    showStatus(QString("Pushed back: %1").arg(value));
}

void MainWindow::on_pushButton_popBack_clicked()
{
    if (!vec.empty()) {
        vec.pop_back();
        updateVectorDisplay();
        showStatus("Popped last element");
    } else {
        QMessageBox::warning(this, "Осторожно", "Vector is empty!");
    }
}

void MainWindow::on_pushButton_clear_clicked()
{
    vec.clear();
    updateVectorDisplay();
    showStatus("Vector cleared");
}

void MainWindow::on_pushButton_resize_clicked()
{
    int newSize = ui->spinBox_newSize->value();
    vec.resize(newSize);
    updateVectorDisplay();
    showStatus(QString("Vector resized to %1").arg(newSize));
}

void MainWindow::on_pushButton_at_clicked()
{
    if (vec.empty()) {
        QMessageBox::warning(this, "Осторожно", "Vector is empty!");
        return;
    }

    try {
        int index = ui->spinBox_index->value();
        int value = vec.at(index);
        QMessageBox::information(this, "Element",
                                 QString("Element at index %1: %2").arg(index).arg(value));
    } catch (...) {
        QMessageBox::critical(this, "Error", "Index out of range!");
    }
}


