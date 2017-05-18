#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    styleSheetOptions();

    ui->setupUi(this);

    uiOptions = new Options();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_options_clicked()
{
    uiOptions->hide();
    uiOptions->show();
}

void MainWindow::on_pushButton_levelAI_clicked()
{
    uiOptions->hide();
    uiOptions->show();
}

void MainWindow::on_pushButton_soundMusic_clicked()
{
    uiOptions->hide();
    uiOptions->show();
}

void MainWindow::on_pushButton_figures_clicked()
{
    uiOptions->hide();
    uiOptions->show();
}

void MainWindow::styleSheetOptions()
{
    //TODO Add styleSheet using params
//    qApp->setStyleSheet("QLabel { color: yellow 50; }"
//                        "QGroupBox::title { color: yellow 50; }");
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->mouseMoveEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    this->keyPressEvent(event);
}
