#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , n_points(0), g_points(0), p_points(0), e_grade(0)
{
    ui->setupUi(this);

    ui->spinBoxN->setRange(0,760);

    ui->spinBoxG->setRange(0, 120);

    ui->spinBoxP->setRange(0, 250);

    ui->spinBoxE->setRange(0, 5);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_countPushButton_clicked()
{
    int grade = count_final_grade(n_points, g_points, p_points, e_grade);
    std::string text = std::to_string(grade);

    QString qtext = QString::fromStdString(text);

    ui->textBrowser->setText("Total grade: " + qtext);
}


void MainWindow::on_spinBoxN_valueChanged(int arg1)
{
    n_points = arg1;
}


void MainWindow::on_spinBoxG_valueChanged(int arg1)
{
    g_points = arg1;
}


void MainWindow::on_spinBoxP_valueChanged(int arg1)
{
    p_points = arg1;
}


void MainWindow::on_spinBoxE_valueChanged(int arg1)
{
    e_grade = arg1;
}

