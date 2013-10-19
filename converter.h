#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>
#include <QMap>

class Converter : public QObject
{
    Q_OBJECT
public:
    explicit Converter(QObject *parent = 0);
    
    enum ConvertMode
    {
        Nothing = 0,
        HiraganaMode = 1,
        KatakanaMode = 2
    };

    QString Convert(const QString source);
    void SetConvertMode(ConvertMode mode);
    void SetPossibility(int possibility);
private:
    QString ConvertPattern(QString pattern);
    QString FindKatakanaByPattern(QString pattern);
    QString FindHiraganaByPattern(QString pattern);
    QString ConvertTrigramm(QChar one, QChar two, QChar three, int &amount);
    QMap <QString, QString> hiragana_replacements;
    QMap <QString, QString> katakana_replacements;
    ConvertMode _currentConvertMode;
    int _currentPossibility;
};

#endif // CONVERTER_H
