#ifndef CALC_H
#define CALC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calc; }
QT_END_NAMESPACE

class Calc : public QMainWindow
{
    Q_OBJECT

public:
    Calc(QWidget *parent = nullptr);
    ~Calc();

private:
    Ui::Calc *ui;

private slots:
    void digit_pressed();
    void on_pushButton_decimal_released();
    void unary_operation_button_released();
    void binary_operation_button_released();
    void on_pushBotton_equalTo_released();
    void on_pushButton_clear_released();
};
#endif // CALC_H
