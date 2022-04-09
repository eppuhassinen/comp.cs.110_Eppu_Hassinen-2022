#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <fstream>
#include <cstring>

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

    void on_findPushButton_clicked();

private:
    Ui::MainWindow *ui;

     QString file_name_;

     bool find_key(std::ifstream& file, bool match_case);

};
#endif // MAINWINDOW_HH
