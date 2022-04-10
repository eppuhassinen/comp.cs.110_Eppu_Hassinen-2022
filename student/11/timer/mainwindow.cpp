#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    seconds_(0)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::update_time);

    ui->lcdNumberMin->setStyleSheet("background-color:yellow");
    ui->lcdNumberSec->setStyleSheet("background-color:green");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    timer->start(1000);
}


void MainWindow::on_stopButton_clicked()
{
    timer->stop();
}

void MainWindow::update_time()
{
    ++seconds_;

    ui->lcdNumberSec->display(seconds_ % 60);
    ui->lcdNumberMin->display(seconds_ / 60);
}


void MainWindow::on_resetButton_clicked()
{
    seconds_ = 0;
    ui->lcdNumberSec->display(seconds_ % 60);
    ui->lcdNumberMin->display(seconds_ / 60);

    if (timer->isActive())
        timer->start(1000);
}

