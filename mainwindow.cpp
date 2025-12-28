#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

double nf;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->q0, SIGNAL(clicked()),this,SLOT(num()));
    connect(ui->q1, SIGNAL(clicked()),this,SLOT(num()));
    connect(ui->q2, SIGNAL(clicked()),this,SLOT(num()));
    connect(ui->q3, SIGNAL(clicked()),this,SLOT(num()));
    connect(ui->q4, SIGNAL(clicked()),this,SLOT(num()));
    connect(ui->q5, SIGNAL(clicked()),this,SLOT(num()));
    connect(ui->q6, SIGNAL(clicked()),this,SLOT(num()));
    connect(ui->q7, SIGNAL(clicked()),this,SLOT(num()));
    connect(ui->q8, SIGNAL(clicked()),this,SLOT(num()));
    connect(ui->q9, SIGNAL(clicked()),this,SLOT(num()));
    connect(ui->dot, SIGNAL(clicked()),this,SLOT(operPlus()));
    connect(ui->AC, SIGNAL(clicked()),this,SLOT(operPlus()));
    connect(ui->plus, SIGNAL(clicked()),this,SLOT(slog()));
    connect(ui->minus, SIGNAL(clicked()),this,SLOT(slog()));
    connect(ui->delit, SIGNAL(clicked()),this,SLOT(slog()));
    connect(ui->pushButton_1, SIGNAL(clicked()),this,SLOT(operPlus()));
    connect(ui->persent, SIGNAL(clicked()),this,SLOT(operPlus()));
    connect(ui->x, SIGNAL(clicked()),this,SLOT(slog()));

    ui->ravno->setCheckable(true);
    ui->plus->setCheckable(true);
    ui->minus->setCheckable(true);
    ui->x->setCheckable(true);
    ui->delit->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::num()
{
    QPushButton *button = (QPushButton *)sender();

    double all;
    QString new_lable;
    all = (ui->label->text() + button->text()).toDouble();
    new_lable = QString::number(all, 'g', 14);

    ui->label->setText(new_lable);
}

void MainWindow::on_dot_clicked()
{
    if(!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text() + ".");
}
void MainWindow::operPlus()
{
    QPushButton *button = (QPushButton *)sender();

    double all;
    QString new_lable;
    if(button->text() == "+/-"){
        all = (ui->label->text()).toDouble();
        all = all * -1;
        new_lable = QString::number(all, 'g', 14);

        ui->label->setText(new_lable);
    }else if(button->text() == "%"){
        all = (ui->label->text()).toDouble();
        all = all * 0.01;
        new_lable = QString::number(all, 'g', 14);

        ui->label->setText(new_lable);
    }
}
void MainWindow::slog()
{
    QPushButton *button = (QPushButton *)sender();
    nf = ui->label->text(). toDouble();
    ui->label->setText("");

    button->setChecked(true);
}


void MainWindow::on_ravno_clicked()
{
    double labelNumber, num_Se;
    QString new_lable;
    num_Se = ui->label-> text(). toDouble();

    if(ui->plus->isChecked()){
        labelNumber = nf + num_Se;
        new_lable = QString::number(labelNumber, 'g', 14);

        ui->label->setText(new_lable);
        ui->plus->setChecked(false);
    } else if(ui->minus->isChecked()){
        labelNumber = nf - num_Se;
        new_lable = QString::number(labelNumber, 'g', 14);

        ui->label->setText(new_lable);
        ui->plus->setChecked(false);
    } else if(ui->delit->isChecked()){
        labelNumber = nf / num_Se;
        new_lable = QString::number(labelNumber, 'g', 14);

        ui->label->setText(new_lable);
        ui->plus->setChecked(false);
    } else if(ui->x->isChecked()){
        labelNumber = nf * num_Se;
        new_lable = QString::number(labelNumber, 'g', 14);

        ui->label->setText(new_lable);
        ui->plus->setChecked(false);
    }
}


void MainWindow::on_AC_clicked()
{
    ui->label->setText("0");
    ui->plus->setChecked(false);
    ui->minus->setChecked(false);
    ui->delit->setChecked(false);
    ui->x->setChecked(false);
    nf = 0;
}

