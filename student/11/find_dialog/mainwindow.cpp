#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), file_name_("")
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_findPushButton_clicked()
{
    std::ifstream file;
    file.open(ui->fileLineEdit->text().toStdString());

    if (!file.is_open())
    {
        ui->textBrowser->setText("File not found");
        return;
    }

    ui->textBrowser->setText("File found");
}

