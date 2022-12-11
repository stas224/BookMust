#include "view_book.h"
#include "ui_view_book.h"
#include <QPushButton>



View_book::View_book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::View_book)
{
    ui->setupUi(this);
}

View_book::~View_book()
{
    delete ui;
}

void View_book::setLabel (QString& name, QString& autor,QString& ratingab,QString& date)
{
    ui->lineEdit->setText(name);
    ui->lineEdit_2->setText(autor);
    ui->label_3->setText(date);
    View_book::rating = ratingab;
    if (ratingab == "1"){
        ui->pushButton_3->setDown(true);
    }
    if (ratingab == "2"){
        ui->pushButton_4->setDown(true);
    }
    if (ratingab == "3"){
        ui->pushButton_6->setDown(true);
    }
    if (ratingab == "4"){
        ui->pushButton_7->setDown(true);
    }
    if (ratingab == "5"){
        ui->pushButton_5->setDown(true);
    }
    View_book::buttonname = name+autor;
}

std::tuple<QString,QString,QString,QString> View_book::value()
{
    return std::tuple<QString,QString,QString,QString>(ui->lineEdit->text(),ui->lineEdit_2->text(),rating,click);
}



void View_book::on_Delete_button_clicked()
{
    click = "Del";
    ui->label->setText("Нажмите OK для удаления");
}


void View_book::on_pushButton_2_clicked()
{
    click = "Swap";
    ui->label->setText("Нажмите OK для перемещения");
}


void View_book::on_pushButton_clicked()
{
    click = "None";
    ui->label->setText("Нажмите OK для сохранения");
}


void View_book::on_pushButton_3_clicked()
{
    rating = ui->pushButton_3->text();
    ui->Rating->setText("Оценка: 1");
    ui->pushButton_3->setDown(true);
    ui->pushButton_4->setDown(false);
    ui->pushButton_5->setDown(false);
    ui->pushButton_6->setDown(false);
    ui->pushButton_7->setDown(false);
}


void View_book::on_pushButton_4_clicked()
{
    rating = ui->pushButton_4->text();
    ui->Rating->setText("Оценка: " + rating);
    ui->pushButton_4->setDown(true);
    ui->pushButton_3->setDown(false);
    ui->pushButton_5->setDown(false);
    ui->pushButton_6->setDown(false);
    ui->pushButton_7->setDown(false);
}


void View_book::on_pushButton_6_clicked()
{
    rating = ui->pushButton_6->text();
    ui->Rating->setText("Оценка: " + rating);
    ui->pushButton_6->setDown(true);
    ui->pushButton_3->setDown(false);
    ui->pushButton_5->setDown(false);
    ui->pushButton_4->setDown(false);
    ui->pushButton_7->setDown(false);
}


void View_book::on_pushButton_7_clicked()
{
    rating = ui->pushButton_7->text();
    ui->Rating->setText("Оценка: " + rating);
    ui->pushButton_7->setDown(true);
    ui->pushButton_3->setDown(false);
    ui->pushButton_5->setDown(false);
    ui->pushButton_4->setDown(false);
    ui->pushButton_6->setDown(false);
}


void View_book::on_pushButton_5_clicked()
{
   rating = ui->pushButton_5->text();
   ui->Rating->setText("Оценка: " + rating);
   ui->pushButton_5->setDown(true);
   ui->pushButton_3->setDown(false);
   ui->pushButton_6->setDown(false);
   ui->pushButton_4->setDown(false);
   ui->pushButton_7->setDown(false);
}

