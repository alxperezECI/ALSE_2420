#ifndef DIA_DIV_H
#define DIA_DIV_H

#include <QDialog>

namespace Ui {
class dia_div;
}

class dia_div : public QDialog
{
    Q_OBJECT

public:
    explicit dia_div(QWidget *parent = nullptr);
    ~dia_div();

signals:
    void emitir_datos(int tipo, double escalar);

private slots:
    void on_rb_AE_clicked(bool checked);

    void on_rb_BA_clicked();

    void on_rb_AE_clicked();

    void on_rb_BE_clicked();

    void on_buttonBox_accepted();

private:
    Ui::dia_div *ui;
};

#endif // DIA_DIV_H
