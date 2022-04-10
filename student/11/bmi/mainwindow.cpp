#include "mainwindow.hh"
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


void MainWindow::on_countButton_clicked()
{
    if (ui->weightLineEdit->text() == "" or
            ui->heightLineEdit->text() == "")
    {
        ui->resultLabel->setText(QString::fromStdString("Cannot count."));
        ui->infoTextBrowser->setText("");
        return;
    }

    double height = std::stod(ui->heightLineEdit->text().toStdString());
    double weight = std::stod(ui->weightLineEdit->text().toStdString());

    if (height == 0)
    {
        ui->resultLabel->setText(QString::fromStdString("Cannot count."));
        ui->infoTextBrowser->setText("");
        return;
    }

    height *= 0.01;

    double bmi = weight / (height * height);

    std::string text = std::to_string(bmi);

    ui->resultLabel->setText(QString::fromStdString(text));

    if (bmi < 18.5)
    {
        ui->infoTextBrowser->setText("You are underweight.");
        return;
    }

    if (bmi > 25)
    {
        ui->infoTextBrowser->setText("You are overweight.");
        return;
    }

    ui->infoTextBrowser->setText("Your weight is normal.");


}

