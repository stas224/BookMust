#ifndef VIEW_BOOK_H
#define VIEW_BOOK_H

#include <QDialog>

#include <qdynamicbutton.h>
#include "mainwindow.h"

namespace Ui {
class View_book;
}
/*!
* @brief Класс для диаологового окна редактирования книги
*
*/

class View_book : public QDialog
{
    Q_OBJECT

public:
    explicit View_book(QWidget *parent = nullptr);
    ~View_book();
    /**
    @brief Функция для установки данных полученных с основного окна
    */
    void setLabel (QString& name, QString& autor,QString& rating,QString& date);
    QString rating = "";
    /**
    @brief Функция для возврата данных в основное диалоговое окно
    */
    std::tuple <QString,QString,QString,QString> value();
    QString buttonname;
    QString click = "Change";

private slots:

    /**
    @brief Функция для удаления книги, когда пользователь нажимает на кнопку удаления, оператор click меняет свое значения,
    и после возвращения данных в основное окно, книга удалиться с графического интерфейса и базы данных.
    */
    void on_Delete_button_clicked();
    /**
    @brief Функция для изменения раздела книги, когда пользователь нажимает на кнопку перемещения, оператор click
     меняет свое значения,  и после возвращения данных в основное окно, книга переместится в графическом интерфейсе
     и изменит свои раздел в базе данных.
    */
    void on_pushButton_2_clicked();
    /**
    @brief Функция для сброса изменений раздела книги, когда пользователь нажимает на кнопку отмены, оператор click
     меняет свое значения,  и после возвращения данных в основное окно, ничего из изменений не применится.
    */
    void on_pushButton_clicked();
    /**
    @brief Функция для фиксирования кнопки с оценкой в диалоговом окне.
    Данная и последующие функции с номерами 4,6,7,5 фиксируют нажатой опреденную кнопку с оценкой, которую выбрал пользователь.
    */
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::View_book *ui;
};

#endif // VIEW_BOOK_H
