#ifndef DATABASE_H
#define DATABASE_H


#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

/*!
* @brief Класс для базы данных
*
*/
class Database
{
    /*!
    * @brief Класс для базы данных
    *
    */
public:
    QSqlDatabase db;
    /**
    @brief Функция открывает базу данных, если такой нет по пути запуска программы, тогда создает новую.
    */
    Database();
private:
};

#endif // DATABASE_H
