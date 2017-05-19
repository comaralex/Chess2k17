#include "options.h"
#include "ui_options.h"

#include <QDebug>

Options::Options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormOptions)
{
    ui->setupUi(this);

    buttonGroupOfChess = new QButtonGroup(this);
    buttonGroupOfChess->addButton(ui->toolButtonPawn,   1);
    buttonGroupOfChess->addButton(ui->toolButtonRook,   2);
    buttonGroupOfChess->addButton(ui->toolButtonKnight, 3);
    buttonGroupOfChess->addButton(ui->toolButtonBishop, 4);
    buttonGroupOfChess->addButton(ui->toolButtonKing,   5);
    buttonGroupOfChess->addButton(ui->toolButtonQueen,  6);
    buttonGroupOfChess->setExclusive(true);

    connect(buttonGroupOfChess, SIGNAL(buttonClicked(int)), this, SLOT(rankChess(int)));
}

Options::~Options()
{
    delete ui;
}

void Options::on_checkBoxBlackWhite_toggled(bool checked)
{
    if ( checked ) {
        ui->checkBoxBlackWhite->setText("Белые/Черные");
        ui->toolButtonPawn->setStyleSheet("border-image: url(:/res/images/pawn_white);");
        ui->toolButtonRook->setStyleSheet("border-image: url(:/res/images//rook_white);");
        ui->toolButtonKnight->setStyleSheet("border-image: url(:/res/images/knight_white);");
        ui->toolButtonBishop->setStyleSheet("border-image: url(:/res/images/bishop_white);");
        ui->toolButtonKing->setStyleSheet("border-image: url(:/res/images/king_white);");
        ui->toolButtonQueen->setStyleSheet("border-image: url(:/res/images/queen_white);");
    } else {
        ui->checkBoxBlackWhite->setText("Черные/Белые");
        ui->toolButtonPawn->setStyleSheet("border-image: url(:/res/images/pawn_black);");
        ui->toolButtonRook->setStyleSheet("border-image: url(:/res/images/rook_black);");
        ui->toolButtonKnight->setStyleSheet("border-image: url(:/res/images/knight_black);");
        ui->toolButtonBishop->setStyleSheet("border-image: url(:/res/images/bishop_black);");
        ui->toolButtonKing->setStyleSheet("border-image: url(:/res/images/king_black);");
        ui->toolButtonQueen->setStyleSheet("border-image: url(:/res/images/queen_black);");
    }
}

void Options::rankChess(int idChess)
{
    qDebug() << "I'm here";
    bool isWhite = ui->checkBoxBlackWhite->isChecked();
    ChessID chess = static_cast<ChessID>(idChess);
    qDebug() << chess;

    QList<QTableWidgetItem*> selectedItems = ui->tableWidgetChessRanking->selectedItems();
    qDebug() << selectedItems;

    QItemSelectionModel *model = ui->tableWidgetChessRanking->selectionModel();
    QModelIndexList indexList = model->selectedIndexes();
    qDebug() << "IndexList Count" << indexList.count();

    QTableWidgetItem *item;
    for ( auto indexItem : indexList ) {
        int row = indexItem.row();
        int column = indexItem.column();
        qDebug() << "Row = " << row << " Column = " << column;

        item = new QTableWidgetItem();
        if ( isWhite ) {
            switch ( chess ) {
            case CHESS_PAWN:
                item->setIcon(QIcon(":/res/images/pawn_white"));
                break;
            case CHESS_ROOK:
                item->setIcon(QIcon(":/res/images/rook_white"));
                break;
            case CHESS_KNIGHT:
                item->setIcon(QIcon(":/res/images/knight_white"));
                break;
            case CHESS_BISHOP:
                item->setIcon(QIcon(":/res/images/bishop_white"));
                break;
            case CHESS_KING:
                item->setIcon(QIcon(":/res/images/king_white"));
                break;
            case CHESS_QUEEN:
                item->setIcon(QIcon(":/res/images/queen_white"));
                break;
            default:
                qDebug() << "OMG. I don't know that chess id = " << chess;
                break;
            }
        } else {
            switch ( chess ) {
            case CHESS_PAWN:
                item->setIcon(QIcon(":/res/images/pawn_black"));
                break;
            case CHESS_ROOK:
                item->setIcon(QIcon(":/res/images/rook_black"));
                break;
            case CHESS_KNIGHT:
                item->setIcon(QIcon(":/res/images/knight_black"));
                break;
            case CHESS_BISHOP:
                item->setIcon(QIcon(":/res/images/bishop_black"));
                break;
            case CHESS_KING:
                item->setIcon(QIcon(":/res/images/king_black"));
                break;
            case CHESS_QUEEN:
                item->setIcon(QIcon(":/res/images/queen_black"));
                break;
            default:
                qDebug() << "OMG. I don't know that chess id = " << chess;
                break;
            }
        }

        ui->tableWidgetChessRanking->setItem(row, column, item);
    }
}
