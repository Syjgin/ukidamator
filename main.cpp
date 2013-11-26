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
    qApp->installTranslator(qtTranslator);
    QTranslator *appTranslator = new QTranslator(qApp);
    appTranslator->load(QDir::currentPath() + "/ukidamator_" + QLocale::system().name());
#ifdef Q_OS_LINUX
    appTranslator->load("/usr/share/ukidamator/translations/ukidamator_" + QLocale::system().name());
#endif
    a.installTranslator(appTranslator);
    a.installTranslator(qtTranslator);
    ProgramWindow w;
    w.show();
    
    return a.exec();
}
