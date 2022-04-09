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

    if (ui->keyLineEdit->text() == "")
    {
        ui->textBrowser->setText("File found");
        file.close();
        return;
    }

    bool key_found = find_key(file, ui->matchCheckBox->checkState());

    if (key_found)
    {
        ui->textBrowser->setText("Word found");
    } else
    {
        ui->textBrowser->setText("Word not found");
    }
    file.close();

}

bool MainWindow::find_key(std::ifstream& file, bool match_case)
{
    std::string line = "";
    std::string key = ui->keyLineEdit->text().toStdString();
    if (!match_case)
    {
        for (auto & c : key) c = toupper(c);
    }
    while(std::getline(file, line))
    {
        if (!match_case)
        {
            for (auto & c : line) c = toupper(c);
        }
        if (line.find(key) != std::string::npos)
        {
            return true;
        }
    }
    return false;
}

