#ifndef ADDING_BOOK_H
#define ADDING_BOOK_H

#include <QDialog>
#include <QTime>
#include <qdynamicbutton.h>

namespace Ui {
class Adding_book;
}
/*!
* @brief Класс для диаологового окна добавления книги
*
*/

class Adding_book : public QDialog
{
    Q_OBJECT

public:
    explicit Adding_book(QWidget *parent = nullptr);
    ~Adding_book();
    QString ratingab = "";
    /**
    @brief Функция для возврата данных в основное диалоговое окно
    */
    std::tuple <QString,QString,QString,QString> value();

private slots:

    /**
    @brief Функция для фиксирования кнопки с оценкой в диалоговом окне.
    Данная и последующие функции фиксируют нажатой опреденную кнопку с оценкой, которую выбрал пользователь.
    */
    void on_pushButton_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

private:
    Ui::Adding_book *ui;
};

#endif // ADDING_BOOK_H
