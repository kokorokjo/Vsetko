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
    ui->label->setText("strlacene");
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1!=0)
    ui->label_2->setText("checked");
    if(arg1==0)
        ui->label_2->setText("unchecked");
}




