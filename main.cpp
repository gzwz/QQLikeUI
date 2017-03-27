#include "mainwindow.h"
#include "src/ui/loginform.h"

#include "src/ui/mainform.h"\

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    //SlideWindow l;

    //MainForm l;

    LoginForm l;
    l.show();

    return a.exec();
}
