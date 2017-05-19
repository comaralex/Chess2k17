#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>

namespace Ui {
class FormOptions;
}

class Options : public QWidget
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = 0);
    ~Options();

private slots:
    void on_checkBoxBlackWhite_toggled(bool checked);

private:
    Ui::FormOptions *ui;
};

#endif // OPTIONS_H
