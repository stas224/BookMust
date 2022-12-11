#include "adding_book.h"
#include "ui_adding_book.h"
#include <QPushButton>


Adding_book::Adding_book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adding_book)
{
    ui->setupUi(this);
}

Adding_book::~Adding_book()
{
    delete ui;
}

std::tuple<QString,QString,QString,QString> Adding_book::value()
{
    return std::tuple<QString,QString,QString,QString>(ui->lineEdit->text(),ui->lineEdit_2->text(),ratingab,QDate::currentDate().toString("dd.MM.yyyy"));
}



void Adding_book::on_pushButton_clicked()
{
    ratingab = "1";
    ui->Rating->setText("Оценка: 1");
    ui->pushButton->setDown(true);
    ui->pushButton2->setDown(false);
    ui->pushButton3->setDown(false);
    ui->pushButton4->setDown(false);
    ui->pushButton5->setDown(false);
}


void Adding_book::on_pushButton2_clicked()
{
    ratingab = "2";
    ui->Rating->setText("Оценка: 2");
    ui->pushButton2->setDown(true);
    ui->pushButton->setDown(false);
    ui->pushButton3->setDown(false);
    ui->pushButton4->setDown(false);
    ui->pushButton5->setDown(false);
}


void Adding_book::on_pushButton3_clicked()
{
    ratingab = "3";
    ui->Rating->setText("Оценка: 3");
    ui->pushButton3->setDown(true);
    ui->pushButton->setDown(false);
    ui->pushButton2->setDown(false);
    ui->pushButton4->setDown(false);
    ui->pushButton5->setDown(false);
}


void Adding_book::on_pushButton4_clicked()
{
    ratingab = "4";
    ui->Rating->setText("Оценка: 4");
    ui->pushButton4->setDown(true);
    ui->pushButton->setDown(false);
    ui->pushButton2->setDown(false);
    ui->pushButton3->setDown(false);
    ui->pushButton5->setDown(false);
}


void Adding_book::on_pushButton5_clicked()
{
    ratingab = "5";
    ui->Rating->setText("Оценка: 5");
    ui->pushButton5->setDown(true);
    ui->pushButton->setDown(false);
    ui->pushButton2->setDown(false);
    ui->pushButton3->setDown(false);
    ui->pushButton4->setDown(false);
}

