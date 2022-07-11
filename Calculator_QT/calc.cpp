#include "calc.h"
#include "./ui_calc.h"

double firstNum;
bool userIsTypingSecondNum = false;

Calc::Calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calc)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digit_pressed()));

    connect(ui->pushButton_plusMinus, SIGNAL(released()), this, SLOT(unary_operation_button_released()));
    connect(ui->pushButton_percent, SIGNAL(released()), this, SLOT(unary_operation_button_released()));

    connect(ui->pushButton_equalTo, SIGNAL(released()), this, SLOT(on_pushBotton_equalTo_released()));

    connect(ui->pushButton_addition, SIGNAL(released()), this, SLOT(binary_operation_button_released()));
    connect(ui->pushButton_subtract, SIGNAL(released()), this, SLOT(binary_operation_button_released()));
    connect(ui->pushButton_multiply, SIGNAL(released()), this, SLOT(binary_operation_button_released()));
    connect(ui->pushButton_division, SIGNAL(released()), this, SLOT(binary_operation_button_released()));

    ui->pushButton_addition->setCheckable(true);
    ui->pushButton_subtract->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_division->setCheckable(true);


}

Calc::~Calc()
{
    delete ui;
}

void Calc::digit_pressed()
{
    QPushButton* button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;

    if((ui->pushButton_addition->isChecked() || ui->pushButton_subtract->isChecked() ||
            ui->pushButton_multiply->isChecked() || ui->pushButton_division->isChecked()) && !userIsTypingSecondNum)
    {
        labelNumber = (button->text()).toDouble();
        userIsTypingSecondNum = true;
    }
    else
    {
        labelNumber = (ui->label_1->text() + button->text()).toDouble();
    }


    newLabel = QString::number(labelNumber, 'g', 15);

    ui->label_1->setText(newLabel);
}


void Calc::on_pushButton_decimal_released()
{
    if(!(ui->label_1->text().contains('.')))
    {
        ui->label_1->setText(ui->label_1->text() + '.');
    }
}

void Calc::unary_operation_button_released()
{
    double labelNumber;
    QString newLabel;
    QPushButton* button = (QPushButton*) sender();
    if(button->text() == "+/-")
    {
        labelNumber = ui->label_1->text().toDouble();
        labelNumber = labelNumber * (-1);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label_1->setText(newLabel);
    }
    if(button->text() == '%')
    {
        labelNumber = ui->label_1->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label_1->setText(newLabel);
    }
}

void Calc::binary_operation_button_released()
{
    QPushButton* button = (QPushButton*) sender();

    firstNum = ui->label_1->text().toDouble();

    button->setChecked(true);
}

void Calc::on_pushBotton_equalTo_released()
{
    double labelNumber, secondNum;
    QString newLabel;
    secondNum = ui->label_1->text().toDouble();
    if(ui->pushButton_addition->isChecked())
    {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label_1->setText(newLabel);
        ui->pushButton_addition->setChecked(false);
    }
    if(ui->pushButton_subtract->isChecked())
    {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label_1->setText(newLabel);
        ui->pushButton_addition->setChecked(false);
    }
    if(ui->pushButton_multiply->isChecked())
    {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label_1->setText(newLabel);
        ui->pushButton_addition->setChecked(false);
    }
    if(ui->pushButton_division->isChecked())
    {
        if(secondNum != 0)
        {
            labelNumber = firstNum / secondNum;
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->label_1->setText(newLabel);
        }
        else
        {
            ui->label_1->setText("Cannot Divide By Zero");
        }

        ui->pushButton_addition->setChecked(false);
    }

    userIsTypingSecondNum = false;
}

