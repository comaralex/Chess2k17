#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormOptions)
{
    ui->setupUi(this);
}

Options::~Options()
{
    delete ui;
}
