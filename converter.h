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

    QString Convert(const QString source, ConvertMode mode);
private:
    QString ConvertPattern(QString pattern, ConvertMode mode);
    QString FindKatakanaByPattern(QString pattern);
    QString FindHiraganaByPattern(QString pattern);
    QString ConvertTrigramm(QChar one, QChar two, QChar three, int &amount, ConvertMode mode);
    QMap <QString, QString> hiragana_replacements;
    QMap <QString, QString> katakana_replacements;
};

#endif // CONVERTER_H
