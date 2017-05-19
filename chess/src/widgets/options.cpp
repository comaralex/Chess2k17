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

void Options::on_checkBoxBlackWhite_toggled(bool checked)
{
    if ( checked ) {
        ui->checkBoxBlackWhite->setText("Белые/Черные");
        ui->toolButtonPawn->setStyleSheet("border-image: url(:/res/images/images/pawn_white.svg);");
        ui->toolButtonRook->setStyleSheet("border-image: url(:/res/images/images/rook_white.svg);");
        ui->toolButtonKnight->setStyleSheet("border-image: url(:/res/images/images/knight_white.svg);");
        ui->toolButtonBishop->setStyleSheet("border-image: url(:/res/images/images/bishop_white.svg);");
        ui->toolButtonKing->setStyleSheet("border-image: url(:/res/images/images/king_white.svg);");
        ui->toolButtonQueen->setStyleSheet("border-image: url(:/res/images/images/queen_white.svg);");
    } else {
        ui->checkBoxBlackWhite->setText("Черные/Белые");
        ui->toolButtonPawn->setStyleSheet("border-image: url(:/res/images/images/pawn_black.svg);");
        ui->toolButtonRook->setStyleSheet("border-image: url(:/res/images/images/rook_black.svg);");
        ui->toolButtonKnight->setStyleSheet("border-image: url(:/res/images/images/knight_black.svg);");
        ui->toolButtonBishop->setStyleSheet("border-image: url(:/res/images/images/bishop_black.svg);");
        ui->toolButtonKing->setStyleSheet("border-image: url(:/res/images/images/king_black.svg);");
        ui->toolButtonQueen->setStyleSheet("border-image: url(:/res/images/images/queen_black.svg);");
    }
}
