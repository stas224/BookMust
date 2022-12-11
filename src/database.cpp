#include "database.h"

Database::Database()
{
    QString path = QDir::currentPath() + "\\database.db";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    if(!QFile(path).exists()){
        db.setDatabaseName(path);
        db.open();
        QSqlQuery query;
        query.exec("CREATE TABLE Users "
                   "(number VARCHAR(16) PRIMARY KEY,"
                   "name VARCHAR(100), "
                   "password VARCHAR(50)); ");
        query.exec("CREATE TABLE Book "
                   "(id_book INTEGER PRIMARY KEY, "
                   "number_user VARCHAR(16), "
                   "name VARCHAR(100), "
                   "autor VARCHAR(100), "
                   "rating VARCHAR(2), "
                   "status integer, "
                   " dates varchar(20), "
                   "foreign key (number_user) references Users(number));");
    }
    else
    {
        db.setDatabaseName(path);
        db.open();
    }
}
