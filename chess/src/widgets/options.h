#ifndef OPTIONS_H
#define OPTIONS_H

#include <QButtonGroup>
#include <QWidget>

namespace Ui {
class FormOptions;
}

class Options : public QWidget
{
    Q_OBJECT

    enum ChessID {
        CHESS_PAWN = 1,
        CHESS_ROOK,
        CHESS_KNIGHT,
        CHESS_BISHOP,
        CHESS_KING,
        CHESS_QUEEN
    };

public:
    explicit Options(QWidget *parent = 0);
    ~Options();


private slots:
    void on_checkBoxBlackWhite_toggled(bool checked);
    void rankChess(int idChess);

private:
    Ui::FormOptions *ui;
    QButtonGroup *buttonGroupOfChess;
};

#endif // OPTIONS_H
