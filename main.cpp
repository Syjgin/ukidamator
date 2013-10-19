#include "programwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QTranslator translator(0);
    translator.load("ukidamator_ru_RU");
    QApplication a(argc, argv);
    a.installTranslator(&translator);
    ProgramWindow w;
    w.show();
    
    return a.exec();
}
