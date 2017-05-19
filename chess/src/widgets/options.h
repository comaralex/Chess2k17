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

private:
    Ui::FormOptions *ui;
};

#endif // OPTIONS_H
