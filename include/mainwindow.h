#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollBar>
#include <QTime>
#include "QTabBar"

#include "qdynamicbutton.h"
#include "adding_book.h"
#include "view_book.h"
#include "help_window.h"
#include "database.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}
/*!
* @brief Класс для главной страницы
*
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    /**
    @brief Функция для открытия дилогового окна для добавление книги.
    Данная функция открывает диалоговое окно, а после полученные данные с окна вставляет
    в новую кнопку, которую останавливает в нужную вкладку
    */
    void on_addButton_clicked();
    /**
    @brief Функция для удаления книги.
    Данная функция активируется, когда после радактирования книги присылается оператор del в slotGetNumber
   она по имени перебирает книги в списке и удаляет, когда находит соответсвие
    */
    void on_deleteButton_clicked();
    /**
    @brief Функция для редактирования книги.
    Данная функция открывает диалоговое окно для редактирования книги, после чего берет с него
    информацию, и совершает необоходимые операции
    */
    void slotGetNumber();
private slots:
    /**
    @brief Функция меняет вкладку с книгами на Прочитано
    */
    void on_Read_it_clicked();
    /**
    @brief Функция меняет вкладку с книгами на Прочитаю
    */
    void on_Read_will_clicked();
    /**
    @brief Функция перемещает книги в другой список, попутно изменяя ее параметры
    */
    void on_Compare_button_clicked();
    /**
    @brief Функция информирет юзера в каком он сейчас разделе
    */
    void on_tabWidget_currentChanged(int index);
    /**
    @brief Функция для открытия диалогового окна помоши
    */
    void on_help_button_clicked();
    /**
    @brief Функция для проверки авторизации пользователя.
    Данная функция проверяет на валидность введеные данные и совпадение с уже имеющимися в базе
    */
    void on_enter_button_clicked();
    /**
    @brief Функция открывает окно регистрации
    */
    void on_reg_button_clicked();
    /**
    @brief Функция для регистрации юзера.
     Данная функция проверяет данные на валидность и заносит данные пользователя в базу данных
    */
    void on_reg_button_2_clicked();

    /**
    @brief Функция проверяет на корректность введенный номер при авторизации
    */
    void on_lineEdit_number_textChanged(const QString &arg1);
    /**
    @brief Функция проверяет на корректность введенное имя при авторизации
    */
    void on_lineEdit_name_2_textChanged(const QString &arg1);
    /**
    @brief Функция проверяет на корректность введенный номер при регистрации
    */
    void on_lineEdit_number_2_textChanged(const QString &arg1);
    /**
    @brief Функция возвращает на окно авторизации
    */
    void on_button_back_clicked();

private:
    Ui::MainWindow *ui;
    Database *db;
    QString user;
    /**
    @brief Функция открывает данные о книгах из базы данных после успешной авторизации
    */
    void completion();
};
#endif // MAINWINDOW_H
