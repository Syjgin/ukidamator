#include "programwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QLibraryInfo>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator *qtTranslator = new QTranslator(qApp);
    qtTranslator->load("qt_" + QLocale::system().name(),
    QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    QTranslator *appTranslator = new QTranslator(qApp);
    appTranslator->load(":/translations/ukidamator_"+ QLocale::system().name());
    qApp->installTranslator(appTranslator);
    ProgramWindow w;
    w.show();
    
    return a.exec();
}
