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
        KatakanaMode = 2,
        KiridziMode = 4,
        RomadziMode = 8
    };

    QString Convert(const QString source);
    void SetConvertMode(ConvertMode mode);
    void SetPossibility(int possibility);
private:
    QString ConvertPattern(QString pattern);
    QString ConvertTrigramm(QChar one, QChar two, QChar three, int &amount);
    QMap <QString, QString> hiragana_kiridzi;
    QMap <QString, QString> hiragana_romadzi;
    QMap <QString, QString> katakana_kiridzi;
    QMap <QString, QString> katakana_romadzi;
    ConvertMode _currentConvertMode;
    int _currentPossibility;
    QString FindSymbolInMap(const QMap <QString, QString> map, QString pattern);
};

#endif // CONVERTER_H
