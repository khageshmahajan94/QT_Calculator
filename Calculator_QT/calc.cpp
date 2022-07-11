#include "calc.h"
#include "./ui_calc.h"

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

    labelNumber = (ui->label_1->text() + button->text()).toDouble();
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

