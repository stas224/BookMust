#include "qdynamicbutton.h"


Qdynamicbutton::Qdynamicbutton(QWidget *parent) : QPushButton(parent)
{
    ResID++;
    buttonID = ResID;
}


Qdynamicbutton::~Qdynamicbutton()
{

}

int Qdynamicbutton::getID()
{
    return buttonID;
}

void Qdynamicbutton::on_qdymicbutton_clicked()
{

}

int Qdynamicbutton::ResID = 0;
