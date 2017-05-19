#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_timer()
{
    styleSheetOptions();

    ui->setupUi(this);

    uiOptions = new Options();

    m_timer = new QTimer(this);
    m_timer->setInterval(1);
    m_timer->setSingleShot(false);

    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateGui()));

    m_timer->start();
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

void MainWindow::updateGui()
{
    static float steps = 5.0f;

    static QPoint initLeft = ui->layoutWidget->pos();
    static QPoint initRight = ui->layoutWidget_2->pos();

    static QPoint hideLeft = QPoint(initLeft.x() - 240, initLeft.y());
    static QPoint hideRight = QPoint(initRight.x() + 240, initRight.y());

    static float leftStep = (initLeft.x() - hideLeft.x()) / steps;
    static float rightStep = (hideRight.x() - initRight.x()) / steps;

    auto leftMenu = ui->layoutWidget;
    auto rightMenu = ui->layoutWidget_2;

    if ( m_hideMenu && leftMenu->x() > hideLeft.x() ) {
        leftMenu->move(leftMenu->x() - leftStep, leftMenu->y());
        rightMenu->move(rightMenu->x() + rightStep, rightMenu->y());
    } else if ( !m_hideMenu && leftMenu->x() < initLeft.x() ) {
        leftMenu->move(leftMenu->x() + leftStep, leftMenu->y());
        rightMenu->move(rightMenu->x() - rightStep, rightMenu->y());
    }
}

void MainWindow::styleSheetOptions()
{
    //TODO Add styleSheet using params
//    qApp->setStyleSheet("QLabel { color: yellow 50; }"
//                        "QGroupBox::title { color: yellow 50; }");
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    ui->openGLWidget->mouseMoveEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    ui->openGLWidget->keyPressEvent(event);

    switch(event->key()) {
    case Qt::Key_M:
        m_hideMenu = !m_hideMenu;
        break;
    default:
        break;
    }
}
