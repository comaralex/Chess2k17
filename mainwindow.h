#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "options.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::MainWindow  *ui;
    Options         *uiOptions;
};

#endif // MAINWINDOW_H
