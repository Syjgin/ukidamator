#include "programwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QString localeName = QLocale::system().name();
    QTranslator translator(0);
    translator.load(QString("ukidamator_") + localeName, "../ukidamator");
    QApplication a(argc, argv);
    a.installTranslator(&translator);
    ProgramWindow w;
    w.show();
    
    return a.exec();
}
