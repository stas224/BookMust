#ifndef QDYNAMICBUTTON_H
#define QDYNAMICBUTTON_H

#include <QPushButton>
#include <QTime>

#include "view_book.h"
#include "adding_book.h"

/*!
* @brief Класс для книги
*
*/
class Qdynamicbutton : public QPushButton
{
    /*!
    * @brief Класс для книги
    *
    */
    Q_OBJECT
public:
    explicit Qdynamicbutton (QWidget *parent = 0);
    ~Qdynamicbutton();
    static int ResID;
    int getID();
    QString getName();
    QString name = "";
    QString autor = "";
    QString rating = "";
    QString date = "";
    int IDbook = 0;
    int Deleted = 0;

public slots:
    void on_qdymicbutton_clicked();

private:
    int buttonID = 0;
};

#endif // QDYNAMICBUTTON_H
