# BookMust

Предназначение
-----------------
Смысл приложения в отслеживании книг, которые были прочитаны, и которые пользователь хочет прочитать. Пользователь после авторизации может добавлять свои книги в два раздела «Прочитал» и «Прочитаю», тем самым имея так называемые «чеклист» и «мастлист» (отсюда и название приложения) с книгами пользователя. Он сможет сохранять, редактировать, перемещать между разделами и оценивать введение им книги.

Установка
-----------------
необходимо скачать все файлы. После этого необходимо собрать проект с помощью CMake (версия должна быть 3.14 или выше), далее требуется задать путь CMAKE_INSTALL_PREFIX, куда установится файл с расширением  “.exe”, после сборки INSTALL через Visual Studio или командную строку.
 *Примечание: 1. Qt6 должен быть установлен перед сборкой. 2.Если у вас возникли проблемы со сборкой, то попробуйте добавить системную переменную (на Windows: Этот компьютер > Свойства >  Дополнительные параметры системы > Переменные среды >  Системные переменные) QTDIR со значением C:\Qt\6.0.0\msvc2019_64 (или с любым другим компилятором), а также в Path добавить  %QTDIR%\lib и %QTDIR%\bin. 
