#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = new Database();
    ui->tabWidget->tabBar()->hide();
    ui->lineEdit->hide();
    ui->deleteButton->hide();
    ui->Compare_button->hide();
    ui->widget_up->hide();
    ui->Error_label->hide();
    ui->Error_label_2->hide();
    ui->widget_right->hide();
    ui->Layout_3->setAlignment(Qt::AlignTop);
    ui->Layout_4->setAlignment(Qt::AlignTop);
    ui->tabWidget->setGeometry(0,0,1000,600);
    ui->lineEdit_pass->setEchoMode(QLineEdit::Password);
    ui->lineEdit_number->setPlaceholderText("+7-ХХХ-ХХХ-ХХ-ХХ");
    ui->lineEdit_pass->setPlaceholderText("********");
    ui->lineEdit_number_2->setPlaceholderText("+7-ХХХ-ХХХ-ХХ-ХХ");
    ui->lineEdit_pass_2->setPlaceholderText("Придумайте пароль");
    ui->lineEdit_name_2->setPlaceholderText("Введите ваше имя");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    Qdynamicbutton *button = new Qdynamicbutton(this);
    if (ui->tabWidget->currentIndex()== 1)
    {
        ui->Layout_3->addWidget(button);

    }
    else
    {
        ui->Layout_4->addWidget(button);
    }

    Adding_book dialog;
    if (dialog.exec())
    {

        button->setText( "\"" + std::get<0>(dialog.value()) + "\" " + std::get<1>(dialog.value()));
        button->name = std::get<0>(dialog.value());
        button->autor = std::get<1>(dialog.value());
        button->rating = std::get<2>(dialog.value());
        if (ui->tabWidget->currentIndex()== 1){
            button->date = std::get<3>(dialog.value());
        }
        else
        {
            button->date = "скоро будет прочитана!";
        }
        QSqlQuery query;
        QString str_select = "select id_book from Book;";
        query.exec(str_select);
        QString id;
        while (query.next())
        {
            id = query.value(0).toString();
        }
        int ID = id.toInt() + 1;
        button->IDbook = ID;
        int st = ui->tabWidget->currentIndex();
        QString insert_book_0 = "insert into Book (id_book,number_user,name,autor,rating,dates,status) values ('%1', '%2', '%3', '%4', '%5', '%6', '%7');";
        QString insert_book = insert_book_0.arg(ID).arg(MainWindow::user).arg(std::get<0>(dialog.value())).arg(std::get<1>(dialog.value())).arg(std::get<2>(dialog.value())).arg(std::get<3>(dialog.value())).arg(st);
        query.exec(insert_book);
    }
    connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
    if (button->name == "" and button->autor == "")
    {
        button->hide();
        delete button;
    }
    ui->Count_it->setText(QString::number(ui->Layout_3->count()));
    ui->Count_will->setText(QString::number(ui->Layout_4->count()));
}

/* Метод для удаления динамической кнопки по её номеру
 * */
void MainWindow::on_deleteButton_clicked()
{
    /* Выполняем перебор всех элементов слоя, где располагаются динамические кнопки
     * */
    if (ui->tabWidget->currentIndex()== 1)
    {
        for(int i = 0; i < ui->Layout_3->count(); i++){
            /* Производим каст элемента слоя в объект динамической кнопки
             * */
            Qdynamicbutton *button = qobject_cast<Qdynamicbutton*>(ui->Layout_3->itemAt(i)->widget());
            /* Если номер кнопки соответствует числу, которое установлено
             * в lineEdit, то производим удаление данной кнопки
             * */
            if(button->text() == ui->lineEdit->text()){
                button->hide();
                delete button;
            }
        }
    }
    else
    {
        for(int i = 0; i < ui->Layout_4->count(); i++){
            /* Производим каст элемента слоя в объект динамической кнопки
             * */
            Qdynamicbutton *button = qobject_cast<Qdynamicbutton*>(ui->Layout_4->itemAt(i)->widget());
            /* Если номер кнопки соответствует числу, которое установлено
             * в lineEdit, то производим удаление данной кнопки
             * */
            if(button->text() == ui->lineEdit->text()){
                button->hide();
                delete button;
            }
        }
    }
    ui->Count_it->setText(QString::number(ui->Layout_3->count()));
    ui->Count_will->setText(QString::number(ui->Layout_4->count()));
}

/* СЛОТ для получения номера кнопки.
 * */
void MainWindow::slotGetNumber()
{
    /* Определяем объект, который вызвал сигнал
     * */
    Qdynamicbutton *button = (Qdynamicbutton*) sender();
    /* После чего устанавливаем название книги в lineEdit,
     * который содержится в данной динамической кнопке
     * */
    ui->lineEdit->setText(button->text());
    /* То есть название книги устанавливается в поле lineEdit только тогда,
     * когда мы нажимаем одну из динамических кнопок,
     * */
    View_book dialog;
    dialog.setLabel(button->name,button->autor,button->rating,button->date);
    QSqlQuery query;
    if (dialog.exec())
    {
        QString operation = std::get<3>(dialog.value());
        if (operation == "Del")
        {
          MainWindow::on_deleteButton_clicked();
          QString delete_template = "delete from Book where id_book='%1'";
          QString deleted = delete_template.arg(button->IDbook);
          query.exec(deleted);
        }
        if (operation == "Swap")
        {
          MainWindow::on_Compare_button_clicked();
        }
        if (operation == "Change"){

        button->setText( "\"" + std::get<0>(dialog.value()) + "\" " +std::get<1>(dialog.value()));
        button->name = std::get<0>(dialog.value());
        button->autor = std::get<1>(dialog.value());
        button->rating = std::get<2>(dialog.value());

        QString update_template = "update Book set name = '%1', autor = '%2', rating = '%3' where id_book='%4';";
        QString update = update_template.arg(button->name).arg(button->autor).arg(button->rating).arg(button->IDbook);
        query.exec(update);
        }
    }
    ui->lineEdit->setText("<><>");
}


void MainWindow::on_Read_it_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}


void MainWindow::on_Read_will_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}


void MainWindow::on_Compare_button_clicked()
{
    QSqlQuery query;
    if (ui->tabWidget->currentIndex()== 1)
    {
        for(int i = 0; i < ui->Layout_3->count(); i++){
            /* Производим каст элемента слоя в объект динамической кнопки
             * */
            Qdynamicbutton *button = qobject_cast<Qdynamicbutton*>(ui->Layout_3->itemAt(i)->widget());
            /* Если номер кнопки соответствует числу, которое установлено
             * в lineEdit, то производим удаление данной кнопки
             * */
            if(button->text() == ui->lineEdit->text()){
                QString update_template = "update Book set dates = '%1',status = '%2'where id_book='%3';";
                QString update = update_template.arg("Скоро будет прочитана!").arg(2).arg(button->IDbook);
                button->date = "Скоро будет прочитана!";
                query.exec(update);
                ui->Layout_4->addWidget(button);
            }
        }
    }
    else
    {
        for(int i = 0; i < ui->Layout_4->count(); i++){
            /* Производим каст элемента слоя в объект динамической кнопки
             * */
            Qdynamicbutton *button = qobject_cast<Qdynamicbutton*>(ui->Layout_4->itemAt(i)->widget());
            /* Если номер кнопки соответствует числу, которое установлено
             * в lineEdit, то производим удаление данной кнопки
             * */
            if(button->text() == ui->lineEdit->text()){
                QString update_template = "update Book set dates = '%1',status = '%2'where id_book='%3';";
                QString update = update_template.arg(QDate::currentDate().toString("dd.MM.yyyy")).arg(2).arg(button->IDbook);
                button->date = QDate::currentDate().toString("dd.MM.yyyy");
               query.exec(update);
               ui->Layout_3->addWidget(button);
            }
        }
    }
    ui->Count_it->setText(QString::number(ui->Layout_3->count()));
    ui->Count_will->setText(QString::number(ui->Layout_4->count()));
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (index == 1)
    {
        ui->label->setText("Раздел: Прочитал");
    }
    else if (index == 2)
    {
        ui->label->setText("Раздел: Прочитаю");
    }
}


void MainWindow::on_help_button_clicked()
{
    help_window dialog;
    if (dialog.exec())
    {

    }
}


void MainWindow::on_enter_button_clicked()
{
  QSqlQuery query;
  QString number = ui->lineEdit_number->text();
  QString pass = ui->lineEdit_pass->text();
  if(pass.isEmpty() || number.count() != 16) {
          ui->Error_label->show();
          return;
  }
  QString select_log = "select number,password,name from Users where number='" + number + "';";
  query.exec(select_log);
  while(query.next())
  {
      if (number == query.value(0).toString() && pass == query.value(1).toString())
      {
          ui->tabWidget->setCurrentIndex(1);
          ui->tabWidget->setGeometry(20,180,700,370);
          ui->widget_up->show();
          ui->widget_right->show();
          QString name = query.value(2).toString();
          MainWindow::user = number;
          ui->Welcome_label->setText("Добро Пожаловать, " + name + "!");
          completion();
        }
  }
  ui->Error_label->show();
}


void MainWindow::on_reg_button_clicked()
{
  ui->tabWidget->setCurrentIndex(3);
}


void MainWindow::on_reg_button_2_clicked()
{
  QSqlQuery query;
  QString number = ui->lineEdit_number_2->text();
  QString name = ui->lineEdit_name_2->text();
  QString pass = ui->lineEdit_pass_2->text();

  if(pass.isEmpty() || number.count() != 16) {
          ui->Error_label_2->show();
          return;
  }

  QString insert_template = "insert into Users (number, name, password) values ('%1', '%2', '%3');";
  QString str = insert_template.arg(number).arg(name).arg(pass);
  bool b = query.exec(str);
  if (!b) {
      ui->Error_label_2->show();
  }
  else
  {
     ui->tabWidget->setCurrentIndex(0);
  }
}

void MainWindow::completion()
{
    QSqlQuery query;
    QString select_all_template = "select id_book,name,autor,rating,dates,status from Book where number_user='%1';";
    QString select_all = select_all_template.arg(MainWindow::user);
    query.exec(select_all);
    while (query.next())
    {
      Qdynamicbutton *button = new Qdynamicbutton(this);
      button->IDbook = query.value(0).toInt();
      button->name = query.value(1).toString();
      button->autor = query.value(2).toString();
      button->rating = query.value(3).toString();
      button->date = query.value(4).toString();
      button->setText( "\"" + button->name + "\" " + button->autor);
      connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
      if (query.value(5).toInt() == 1){

         ui->Layout_3->addWidget(button);
      }
      else{
         ui->Layout_4->addWidget(button);
      }
    }
    ui->Count_it->setText(QString::number(ui->Layout_3->count()));
    ui->Count_will->setText(QString::number(ui->Layout_4->count()));
}


void MainWindow::on_lineEdit_number_textChanged(const QString &arg1)
{
    QString b = ui->lineEdit_number->text();
    if(!(ui->lineEdit_number->text().startsWith("+7"))) {
        ui->lineEdit_number->setText("+7-" + b);
        return;
    }
    qsizetype a = b.size();
    QString c = b.at(a - 1);
    if(!(b.at(a - 1).isDigit() || b.at(a - 1) == '-')) {
        b.remove(a - 1, 1);
        ui->lineEdit_number->setText(b);
        return;
    }
    if(a == 2 || a == 6 || a == 10 || a == 13)
        ui->lineEdit_number->setText(b + '-');
    ui->Error_label->hide();

}


void MainWindow::on_lineEdit_name_2_textChanged(const QString &arg1)
{
    QString b = ui->lineEdit_name_2->text();
    qsizetype a = b.size();
    if (a > 0 && !(b.at(a - 1 ).isLetter())) {
        b.remove(a - 1, 1);
        ui->lineEdit_name_2->setText(b);
        return;
    }
    if (a > 0 && b.at(0).isLower()) {
        ui->lineEdit_name_2->setText(b.at(0).toUpper());
        return;
    }
    ui->Error_label_2->hide();
}


void MainWindow::on_lineEdit_number_2_textChanged(const QString &arg1)
{
    QString b = ui->lineEdit_number_2->text();
    if(!(ui->lineEdit_number_2->text().startsWith("+7"))) {
        ui->lineEdit_number_2->setText("+7-" + b);
        return;
    }
    qsizetype a = b.size();
    QString c = b.at(a - 1);
    if(!(b.at(a - 1).isDigit() || b.at(a - 1) == '-')) {
        b.remove(a - 1, 1);
        ui->lineEdit_number_2->setText(b);
        return;
    }
    if(a == 2 || a == 6 || a == 10 || a == 13)
        ui->lineEdit_number_2->setText(b + '-');
    ui->Error_label_2->hide();
}


void MainWindow::on_button_back_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

