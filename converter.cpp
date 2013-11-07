#include "converter.h"

Converter::Converter(QObject *parent) :
    QObject(parent)
{
    _currentConvertMode = Nothing;
    _currentPossibility = 10;
    hiragana_romadzi[QString::fromUtf8("а")] = QString::fromUtf8("あ");
    hiragana_kiridzi[QString::fromUtf8("й")] = QString::fromUtf8("い");
    hiragana_kiridzi[QString::fromUtf8("и")] = QString::fromUtf8("い");
    hiragana_kiridzi[QString::fromUtf8("у")] = QString::fromUtf8("う");
    hiragana_kiridzi[QString::fromUtf8("э")] = QString::fromUtf8("え");
    hiragana_kiridzi[QString::fromUtf8("е")] = QString::fromUtf8("え");
    hiragana_kiridzi[QString::fromUtf8("о")] = QString::fromUtf8("お");

    hiragana_kiridzi[QString::fromUtf8("ка")] = QString::fromUtf8("か");
    hiragana_kiridzi[QString::fromUtf8("ки")] = QString::fromUtf8("き");
    hiragana_kiridzi[QString::fromUtf8("ку")] = QString::fromUtf8("く");
    hiragana_kiridzi[QString::fromUtf8("кэ")] = QString::fromUtf8("け");
    hiragana_kiridzi[QString::fromUtf8("ке")] = QString::fromUtf8("け");
    hiragana_kiridzi[QString::fromUtf8("ко")] = QString::fromUtf8("こ");

    hiragana_kiridzi[QString::fromUtf8("кя")] = QString::fromUtf8("きゃ");
    hiragana_kiridzi[QString::fromUtf8("кю")] = QString::fromUtf8("きゅ");
    hiragana_kiridzi[QString::fromUtf8("кё")] = QString::fromUtf8("きょ");

    hiragana_kiridzi[QString::fromUtf8("га")] = QString::fromUtf8("が");
    hiragana_kiridzi[QString::fromUtf8("ги")] = QString::fromUtf8("ぎ");
    hiragana_kiridzi[QString::fromUtf8("гу")] = QString::fromUtf8("ぐ");
    hiragana_kiridzi[QString::fromUtf8("гэ")] = QString::fromUtf8("げ");
    hiragana_kiridzi[QString::fromUtf8("ге")] = QString::fromUtf8("げ");
    hiragana_kiridzi[QString::fromUtf8("го")] = QString::fromUtf8("ご");

    hiragana_kiridzi[QString::fromUtf8("гя")] = QString::fromUtf8("ぎゃ");
    hiragana_kiridzi[QString::fromUtf8("гю")] = QString::fromUtf8("ぎゅ");
    hiragana_kiridzi[QString::fromUtf8("гё")] = QString::fromUtf8("ぎょ");

    hiragana_kiridzi[QString::fromUtf8("са")] = QString::fromUtf8("さ");
    hiragana_kiridzi[QString::fromUtf8("си")] = QString::fromUtf8("し");
    hiragana_kiridzi[QString::fromUtf8("ши")] = QString::fromUtf8("し");
    hiragana_kiridzi[QString::fromUtf8("щи")] = QString::fromUtf8("し");
    hiragana_kiridzi[QString::fromUtf8("су")] = QString::fromUtf8("す");
    hiragana_kiridzi[QString::fromUtf8("сэ")] = QString::fromUtf8("せ");
    hiragana_kiridzi[QString::fromUtf8("се")] = QString::fromUtf8("せ");
    hiragana_kiridzi[QString::fromUtf8("со")] = QString::fromUtf8("そ");

    hiragana_kiridzi[QString::fromUtf8("ся")] = QString::fromUtf8("しゃ");
    hiragana_kiridzi[QString::fromUtf8("сю")] = QString::fromUtf8("しゅ");
    hiragana_kiridzi[QString::fromUtf8("сё")] = QString::fromUtf8("しょ");

    hiragana_kiridzi[QString::fromUtf8("за")] = QString::fromUtf8("ざ");
    hiragana_kiridzi[QString::fromUtf8("зи")] = QString::fromUtf8("じ");
    hiragana_kiridzi[QString::fromUtf8("жи")] = QString::fromUtf8("じ");
    hiragana_kiridzi[QString::fromUtf8("зу")] = QString::fromUtf8("ず");
    hiragana_kiridzi[QString::fromUtf8("зэ")] = QString::fromUtf8("ぜ");
    hiragana_kiridzi[QString::fromUtf8("зе")] = QString::fromUtf8("ぜ");
    hiragana_kiridzi[QString::fromUtf8("зо")] = QString::fromUtf8("ぞ");

    hiragana_kiridzi[QString::fromUtf8("зя")] = QString::fromUtf8("じゃ");
    hiragana_kiridzi[QString::fromUtf8("зю")] = QString::fromUtf8("じゅ");
    hiragana_kiridzi[QString::fromUtf8("зё")] = QString::fromUtf8("じょ");

    hiragana_kiridzi[QString::fromUtf8("та")] = QString::fromUtf8("た");
    hiragana_kiridzi[QString::fromUtf8("ти")] = QString::fromUtf8("ち");
    hiragana_kiridzi[QString::fromUtf8("чи")] = QString::fromUtf8("ち");
    hiragana_kiridzi[QString::fromUtf8("цу")] = QString::fromUtf8("つ");
    hiragana_kiridzi[QString::fromUtf8("тэ")] = QString::fromUtf8("て");
    hiragana_kiridzi[QString::fromUtf8("те")] = QString::fromUtf8("て");
    hiragana_kiridzi[QString::fromUtf8("то")] = QString::fromUtf8("と");

    hiragana_kiridzi[QString::fromUtf8("чя")] = QString::fromUtf8("ちゃ");
    hiragana_kiridzi[QString::fromUtf8("чу")] = QString::fromUtf8("ちゅ");
    hiragana_kiridzi[QString::fromUtf8("тя")] = QString::fromUtf8("ちゃ");
    hiragana_kiridzi[QString::fromUtf8("тю")] = QString::fromUtf8("ちゅ");
    hiragana_kiridzi[QString::fromUtf8("чё")] = QString::fromUtf8("ちょ");
    hiragana_kiridzi[QString::fromUtf8("тё")] = QString::fromUtf8("ちょ");

    hiragana_kiridzi[QString::fromUtf8("да")] = QString::fromUtf8("だ");
    hiragana_kiridzi[QString::fromUtf8("ди")] = QString::fromUtf8("ぢ");
    hiragana_kiridzi[QString::fromUtf8("ду")] = QString::fromUtf8("づ");
    hiragana_kiridzi[QString::fromUtf8("дэ")] = QString::fromUtf8("で");
    hiragana_kiridzi[QString::fromUtf8("де")] = QString::fromUtf8("で");
    hiragana_kiridzi[QString::fromUtf8("до")] = QString::fromUtf8("ど");

    hiragana_kiridzi[QString::fromUtf8("дя")] = QString::fromUtf8("ぢゃ");
    hiragana_kiridzi[QString::fromUtf8("дю")] = QString::fromUtf8("ぢゅ");
    hiragana_kiridzi[QString::fromUtf8("дё")] = QString::fromUtf8("ぢょ");

    hiragana_kiridzi[QString::fromUtf8("на")] = QString::fromUtf8("な");
    hiragana_kiridzi[QString::fromUtf8("ни")] = QString::fromUtf8("に");
    hiragana_kiridzi[QString::fromUtf8("ну")] = QString::fromUtf8("ぬ");
    hiragana_kiridzi[QString::fromUtf8("нэ")] = QString::fromUtf8("ね");
    hiragana_kiridzi[QString::fromUtf8("не")] = QString::fromUtf8("ね");
    hiragana_kiridzi[QString::fromUtf8("но")] = QString::fromUtf8("の");

    hiragana_kiridzi[QString::fromUtf8("ня")] = QString::fromUtf8("にゃ");
    hiragana_kiridzi[QString::fromUtf8("ню")] = QString::fromUtf8("にゅ");
    hiragana_kiridzi[QString::fromUtf8("нё")] = QString::fromUtf8("にょ");

    hiragana_kiridzi[QString::fromUtf8("ха")] = QString::fromUtf8("は");
    hiragana_kiridzi[QString::fromUtf8("хи")] = QString::fromUtf8("ひ");
    hiragana_kiridzi[QString::fromUtf8("ху")] = QString::fromUtf8("ふ");
    hiragana_kiridzi[QString::fromUtf8("фу")] = QString::fromUtf8("ふ");
    hiragana_kiridzi[QString::fromUtf8("хэ")] = QString::fromUtf8("へ");
    hiragana_kiridzi[QString::fromUtf8("хе")] = QString::fromUtf8("へ");
    hiragana_kiridzi[QString::fromUtf8("хо")] = QString::fromUtf8("ほ");

    hiragana_kiridzi[QString::fromUtf8("хя")] = QString::fromUtf8("ひゃ");
    hiragana_kiridzi[QString::fromUtf8("хю")] = QString::fromUtf8("ひゅ");
    hiragana_kiridzi[QString::fromUtf8("хё")] = QString::fromUtf8("ひょ");

    hiragana_kiridzi[QString::fromUtf8("па")] = QString::fromUtf8("ぱ");
    hiragana_kiridzi[QString::fromUtf8("пи")] = QString::fromUtf8("ぴ");
    hiragana_kiridzi[QString::fromUtf8("пу")] = QString::fromUtf8("ぷ");
    hiragana_kiridzi[QString::fromUtf8("пэ")] = QString::fromUtf8("ぺ");
    hiragana_kiridzi[QString::fromUtf8("пе")] = QString::fromUtf8("ぺ");
    hiragana_kiridzi[QString::fromUtf8("по")] = QString::fromUtf8("ぽ");

    hiragana_kiridzi[QString::fromUtf8("пя")] = QString::fromUtf8("ぴゃ");
    hiragana_kiridzi[QString::fromUtf8("пю")] = QString::fromUtf8("ぴゅ");
    hiragana_kiridzi[QString::fromUtf8("пё")] = QString::fromUtf8("ぴょ");

    hiragana_kiridzi[QString::fromUtf8("ба")] = QString::fromUtf8("ば");
    hiragana_kiridzi[QString::fromUtf8("би")] = QString::fromUtf8("び");
    hiragana_kiridzi[QString::fromUtf8("бу")] = QString::fromUtf8("ぶ");
    hiragana_kiridzi[QString::fromUtf8("бэ")] = QString::fromUtf8("べ");
    hiragana_kiridzi[QString::fromUtf8("бе")] = QString::fromUtf8("べ");
    hiragana_kiridzi[QString::fromUtf8("бо")] = QString::fromUtf8("ぼ");

    hiragana_kiridzi[QString::fromUtf8("бя")] = QString::fromUtf8("びゃ");
    hiragana_kiridzi[QString::fromUtf8("бю")] = QString::fromUtf8("びゅ");
    hiragana_kiridzi[QString::fromUtf8("бё")] = QString::fromUtf8("びょ");

    hiragana_kiridzi[QString::fromUtf8("ма")] = QString::fromUtf8("ま");
    hiragana_kiridzi[QString::fromUtf8("ми")] = QString::fromUtf8("み");
    hiragana_kiridzi[QString::fromUtf8("му")] = QString::fromUtf8("む");
    hiragana_kiridzi[QString::fromUtf8("мэ")] = QString::fromUtf8("め");
    hiragana_kiridzi[QString::fromUtf8("ме")] = QString::fromUtf8("め");
    hiragana_kiridzi[QString::fromUtf8("мо")] = QString::fromUtf8("も");

    hiragana_kiridzi[QString::fromUtf8("мя")] = QString::fromUtf8("みゃ");
    hiragana_kiridzi[QString::fromUtf8("мю")] = QString::fromUtf8("みゅ");
    hiragana_kiridzi[QString::fromUtf8("мё")] = QString::fromUtf8("みょ");

    hiragana_kiridzi[QString::fromUtf8("я")] = QString::fromUtf8("や");
    hiragana_kiridzi[QString::fromUtf8("ю")] = QString::fromUtf8("ゆ");
    hiragana_kiridzi[QString::fromUtf8("ё")] = QString::fromUtf8("よ");
    hiragana_kiridzi[QString::fromUtf8("йо")] = QString::fromUtf8("よ");

    hiragana_kiridzi[QString::fromUtf8("ра")] = QString::fromUtf8("ら");
    hiragana_kiridzi[QString::fromUtf8("ри")] = QString::fromUtf8("り");
    hiragana_kiridzi[QString::fromUtf8("ру")] = QString::fromUtf8("る");
    hiragana_kiridzi[QString::fromUtf8("рэ")] = QString::fromUtf8("れ");
    hiragana_kiridzi[QString::fromUtf8("ре")] = QString::fromUtf8("れ");
    hiragana_kiridzi[QString::fromUtf8("ро")] = QString::fromUtf8("ろ");

    hiragana_kiridzi[QString::fromUtf8("ря")] = QString::fromUtf8("りゃ");
    hiragana_kiridzi[QString::fromUtf8("рю")] = QString::fromUtf8("りゅ");
    hiragana_kiridzi[QString::fromUtf8("рё")] = QString::fromUtf8("りょ");

    hiragana_kiridzi[QString::fromUtf8("ва")] = QString::fromUtf8("わ");
    hiragana_kiridzi[QString::fromUtf8("н")] = QString::fromUtf8("ん");


    hiragana_romadzi[QString::fromUtf8("a")] = QString::fromUtf8("あ");
    hiragana_romadzi[QString::fromUtf8("i")] = QString::fromUtf8("い");
    hiragana_romadzi[QString::fromUtf8("u")] = QString::fromUtf8("う");
    hiragana_romadzi[QString::fromUtf8("e")] = QString::fromUtf8("え");
    hiragana_romadzi[QString::fromUtf8("o")] = QString::fromUtf8("お");

    hiragana_romadzi[QString::fromUtf8("ka")] = QString::fromUtf8("か");
    hiragana_romadzi[QString::fromUtf8("ki")] = QString::fromUtf8("き");
    hiragana_romadzi[QString::fromUtf8("ku")] = QString::fromUtf8("く");
    hiragana_romadzi[QString::fromUtf8("ke")] = QString::fromUtf8("け");
    hiragana_romadzi[QString::fromUtf8("ko")] = QString::fromUtf8("こ");

    hiragana_romadzi[QString::fromUtf8("kya")] = QString::fromUtf8("きゃ");
    hiragana_romadzi[QString::fromUtf8("kyu")] = QString::fromUtf8("きゅ");
    hiragana_romadzi[QString::fromUtf8("kyo")] = QString::fromUtf8("きょ");

    hiragana_romadzi[QString::fromUtf8("ga")] = QString::fromUtf8("が");
    hiragana_romadzi[QString::fromUtf8("gi")] = QString::fromUtf8("ぎ");
    hiragana_romadzi[QString::fromUtf8("gu")] = QString::fromUtf8("ぐ");
    hiragana_romadzi[QString::fromUtf8("ge")] = QString::fromUtf8("げ");
    hiragana_romadzi[QString::fromUtf8("go")] = QString::fromUtf8("ご");

    hiragana_romadzi[QString::fromUtf8("gya")] = QString::fromUtf8("ぎゃ");
    hiragana_romadzi[QString::fromUtf8("gyu")] = QString::fromUtf8("ぎゅ");
    hiragana_romadzi[QString::fromUtf8("gyo")] = QString::fromUtf8("ぎょ");

    hiragana_romadzi[QString::fromUtf8("sa")] = QString::fromUtf8("さ");
    hiragana_romadzi[QString::fromUtf8("shi")] = QString::fromUtf8("し");
    hiragana_romadzi[QString::fromUtf8("si")] = QString::fromUtf8("し");
    hiragana_romadzi[QString::fromUtf8("su")] = QString::fromUtf8("す");
    hiragana_romadzi[QString::fromUtf8("se")] = QString::fromUtf8("せ");
    hiragana_romadzi[QString::fromUtf8("so")] = QString::fromUtf8("そ");

    hiragana_romadzi[QString::fromUtf8("sya")] = QString::fromUtf8("しゃ");
    hiragana_romadzi[QString::fromUtf8("syu")] = QString::fromUtf8("しゅ");
    hiragana_romadzi[QString::fromUtf8("syo")] = QString::fromUtf8("しょ");

    hiragana_romadzi[QString::fromUtf8("za")] = QString::fromUtf8("ざ");
    hiragana_romadzi[QString::fromUtf8("zi")] = QString::fromUtf8("じ");
    hiragana_romadzi[QString::fromUtf8("zu")] = QString::fromUtf8("ず");
    hiragana_romadzi[QString::fromUtf8("ze")] = QString::fromUtf8("ぜ");
    hiragana_romadzi[QString::fromUtf8("zo")] = QString::fromUtf8("ぞ");

    hiragana_romadzi[QString::fromUtf8("zya")] = QString::fromUtf8("じゃ");
    hiragana_romadzi[QString::fromUtf8("zyu")] = QString::fromUtf8("じゅ");
    hiragana_romadzi[QString::fromUtf8("zyo")] = QString::fromUtf8("じょ");

    hiragana_romadzi[QString::fromUtf8("ta")] = QString::fromUtf8("た");
    hiragana_romadzi[QString::fromUtf8("ti")] = QString::fromUtf8("ち");
    hiragana_romadzi[QString::fromUtf8("chi")] = QString::fromUtf8("ち");
    hiragana_romadzi[QString::fromUtf8("tsu")] = QString::fromUtf8("つ");
    hiragana_romadzi[QString::fromUtf8("te")] = QString::fromUtf8("て");
    hiragana_romadzi[QString::fromUtf8("to")] = QString::fromUtf8("と");

    hiragana_romadzi[QString::fromUtf8("tya")] = QString::fromUtf8("ちゃ");
    hiragana_romadzi[QString::fromUtf8("tyu")] = QString::fromUtf8("ちゅ");
    hiragana_romadzi[QString::fromUtf8("chya")] = QString::fromUtf8("ちゃ");
    hiragana_romadzi[QString::fromUtf8("chu")] = QString::fromUtf8("ちゅ");
    hiragana_romadzi[QString::fromUtf8("chyo")] = QString::fromUtf8("ちょ");
    katakana_romadzi[QString::fromUtf8("tyo")] = QString::fromUtf8("ちょ");

    hiragana_romadzi[QString::fromUtf8("da")] = QString::fromUtf8("だ");
    hiragana_romadzi[QString::fromUtf8("ji")] = QString::fromUtf8("ぢ");
    hiragana_romadzi[QString::fromUtf8("di")] = QString::fromUtf8("ぢ");
    hiragana_romadzi[QString::fromUtf8("ju")] = QString::fromUtf8("づ");
    hiragana_romadzi[QString::fromUtf8("de")] = QString::fromUtf8("で");
    hiragana_romadzi[QString::fromUtf8("do")] = QString::fromUtf8("ど");

    hiragana_romadzi[QString::fromUtf8("dya")] = QString::fromUtf8("ぢゃ");
    hiragana_romadzi[QString::fromUtf8("dyu")] = QString::fromUtf8("ぢゅ");
    hiragana_romadzi[QString::fromUtf8("dyo")] = QString::fromUtf8("ぢょ");

    hiragana_romadzi[QString::fromUtf8("na")] = QString::fromUtf8("な");
    hiragana_romadzi[QString::fromUtf8("ni")] = QString::fromUtf8("に");
    hiragana_romadzi[QString::fromUtf8("nu")] = QString::fromUtf8("ぬ");
    hiragana_romadzi[QString::fromUtf8("ne")] = QString::fromUtf8("ね");
    hiragana_romadzi[QString::fromUtf8("no")] = QString::fromUtf8("の");

    hiragana_romadzi[QString::fromUtf8("nya")] = QString::fromUtf8("にゃ");
    hiragana_romadzi[QString::fromUtf8("nyu")] = QString::fromUtf8("にゅ");
    hiragana_romadzi[QString::fromUtf8("nyo")] = QString::fromUtf8("にょ");

    hiragana_romadzi[QString::fromUtf8("ha")] = QString::fromUtf8("は");
    hiragana_romadzi[QString::fromUtf8("hi")] = QString::fromUtf8("ひ");
    hiragana_romadzi[QString::fromUtf8("hu")] = QString::fromUtf8("ふ");
    hiragana_romadzi[QString::fromUtf8("fu")] = QString::fromUtf8("ふ");
    hiragana_romadzi[QString::fromUtf8("he")] = QString::fromUtf8("へ");
    hiragana_romadzi[QString::fromUtf8("ho")] = QString::fromUtf8("ほ");

    hiragana_romadzi[QString::fromUtf8("hya")] = QString::fromUtf8("ひゃ");
    hiragana_romadzi[QString::fromUtf8("hyu")] = QString::fromUtf8("ひゅ");
    hiragana_romadzi[QString::fromUtf8("hyo")] = QString::fromUtf8("ひょ");

    hiragana_romadzi[QString::fromUtf8("pa")] = QString::fromUtf8("ぱ");
    hiragana_romadzi[QString::fromUtf8("pi")] = QString::fromUtf8("ぴ");
    hiragana_romadzi[QString::fromUtf8("pu")] = QString::fromUtf8("ぷ");
    hiragana_romadzi[QString::fromUtf8("pe")] = QString::fromUtf8("ぺ");
    hiragana_romadzi[QString::fromUtf8("po")] = QString::fromUtf8("ぽ");

    hiragana_romadzi[QString::fromUtf8("pya")] = QString::fromUtf8("ぴゃ");
    hiragana_romadzi[QString::fromUtf8("pyu")] = QString::fromUtf8("ぴゅ");
    hiragana_romadzi[QString::fromUtf8("pyo")] = QString::fromUtf8("ぴょ");

    hiragana_romadzi[QString::fromUtf8("ba")] = QString::fromUtf8("ば");
    hiragana_romadzi[QString::fromUtf8("bi")] = QString::fromUtf8("び");
    hiragana_romadzi[QString::fromUtf8("bu")] = QString::fromUtf8("ぶ");
    hiragana_romadzi[QString::fromUtf8("be")] = QString::fromUtf8("べ");
    hiragana_romadzi[QString::fromUtf8("bo")] = QString::fromUtf8("ぼ");

    hiragana_romadzi[QString::fromUtf8("bya")] = QString::fromUtf8("びゃ");
    hiragana_romadzi[QString::fromUtf8("byu")] = QString::fromUtf8("びゅ");
    hiragana_romadzi[QString::fromUtf8("byo")] = QString::fromUtf8("びょ");

    hiragana_romadzi[QString::fromUtf8("ma")] = QString::fromUtf8("ま");
    hiragana_romadzi[QString::fromUtf8("mi")] = QString::fromUtf8("み");
    hiragana_romadzi[QString::fromUtf8("mu")] = QString::fromUtf8("む");
    hiragana_romadzi[QString::fromUtf8("me")] = QString::fromUtf8("め");
    hiragana_romadzi[QString::fromUtf8("mo")] = QString::fromUtf8("も");

    hiragana_romadzi[QString::fromUtf8("mya")] = QString::fromUtf8("みゃ");
    hiragana_romadzi[QString::fromUtf8("myu")] = QString::fromUtf8("みゅ");
    hiragana_romadzi[QString::fromUtf8("myo")] = QString::fromUtf8("みょ");

    hiragana_romadzi[QString::fromUtf8("ya")] = QString::fromUtf8("や");
    hiragana_romadzi[QString::fromUtf8("yu")] = QString::fromUtf8("ゆ");
    hiragana_romadzi[QString::fromUtf8("yo")] = QString::fromUtf8("よ");

    hiragana_romadzi[QString::fromUtf8("ra")] = QString::fromUtf8("ら");
    hiragana_romadzi[QString::fromUtf8("ri")] = QString::fromUtf8("り");
    hiragana_romadzi[QString::fromUtf8("ru")] = QString::fromUtf8("る");
    hiragana_romadzi[QString::fromUtf8("re")] = QString::fromUtf8("れ");
    hiragana_romadzi[QString::fromUtf8("ro")] = QString::fromUtf8("ろ");

    hiragana_romadzi[QString::fromUtf8("rya")] = QString::fromUtf8("りゃ");
    hiragana_romadzi[QString::fromUtf8("ryu")] = QString::fromUtf8("りゅ");
    hiragana_romadzi[QString::fromUtf8("ryo")] = QString::fromUtf8("りょ");

    hiragana_romadzi[QString::fromUtf8("wa")] = QString::fromUtf8("わ");
    hiragana_romadzi[QString::fromUtf8("n")] = QString::fromUtf8("ん");


    katakana_kiridzi[QString::fromUtf8("а")] = QString::fromUtf8("ア");
    katakana_kiridzi[QString::fromUtf8("и")] = QString::fromUtf8("イ");
    katakana_kiridzi[QString::fromUtf8("й")] = QString::fromUtf8("イ");
    katakana_kiridzi[QString::fromUtf8("у")] = QString::fromUtf8("ウ");
    katakana_kiridzi[QString::fromUtf8("э")] = QString::fromUtf8("エ");
    katakana_kiridzi[QString::fromUtf8("е")] = QString::fromUtf8("エ");
    katakana_kiridzi[QString::fromUtf8("о")] = QString::fromUtf8("オ");

    katakana_kiridzi[QString::fromUtf8("ка")] = QString::fromUtf8("カ");
    katakana_kiridzi[QString::fromUtf8("ки")] = QString::fromUtf8("キ");
    katakana_kiridzi[QString::fromUtf8("ку")] = QString::fromUtf8("ク");
    katakana_kiridzi[QString::fromUtf8("кэ")] = QString::fromUtf8("ケ");
    katakana_kiridzi[QString::fromUtf8("ке")] = QString::fromUtf8("ケ");
    katakana_kiridzi[QString::fromUtf8("ко")] = QString::fromUtf8("コ");

    katakana_kiridzi[QString::fromUtf8("кя")] = QString::fromUtf8("キャ");
    katakana_kiridzi[QString::fromUtf8("кю")] = QString::fromUtf8("キュ");
    katakana_kiridzi[QString::fromUtf8("кё")] = QString::fromUtf8("キョ");

    katakana_kiridzi[QString::fromUtf8("га")] = QString::fromUtf8("ガ");
    katakana_kiridzi[QString::fromUtf8("ги")] = QString::fromUtf8("ギ");
    katakana_kiridzi[QString::fromUtf8("гу")] = QString::fromUtf8("グ");
    katakana_kiridzi[QString::fromUtf8("гэ")] = QString::fromUtf8("ゲ");
    katakana_kiridzi[QString::fromUtf8("ге")] = QString::fromUtf8("ゲ");
    katakana_kiridzi[QString::fromUtf8("го")] = QString::fromUtf8("ゴ");

    katakana_kiridzi[QString::fromUtf8("гя")] = QString::fromUtf8("ギャ");
    katakana_kiridzi[QString::fromUtf8("гю")] = QString::fromUtf8("ギュ");
    katakana_kiridzi[QString::fromUtf8("гё")] = QString::fromUtf8("ギョ");

    katakana_kiridzi[QString::fromUtf8("са")] = QString::fromUtf8("サ");
    katakana_kiridzi[QString::fromUtf8("си")] = QString::fromUtf8("シ");
    katakana_kiridzi[QString::fromUtf8("ши")] = QString::fromUtf8("シ");
    katakana_kiridzi[QString::fromUtf8("щи")] = QString::fromUtf8("シ");
    katakana_kiridzi[QString::fromUtf8("су")] = QString::fromUtf8("ス");
    katakana_kiridzi[QString::fromUtf8("сэ")] = QString::fromUtf8("セ");
    katakana_kiridzi[QString::fromUtf8("се")] = QString::fromUtf8("セ");
    katakana_kiridzi[QString::fromUtf8("со")] = QString::fromUtf8("ソ");

    katakana_kiridzi[QString::fromUtf8("ся")] = QString::fromUtf8("シャ");
    katakana_kiridzi[QString::fromUtf8("сю")] = QString::fromUtf8("シュ");
    katakana_kiridzi[QString::fromUtf8("сё")] = QString::fromUtf8("ショ");

    katakana_kiridzi[QString::fromUtf8("за")] = QString::fromUtf8("ザ");
    katakana_kiridzi[QString::fromUtf8("зи")] = QString::fromUtf8("ジ");
    katakana_kiridzi[QString::fromUtf8("жи")] = QString::fromUtf8("ジ");
    katakana_kiridzi[QString::fromUtf8("зу")] = QString::fromUtf8("ズ");
    katakana_kiridzi[QString::fromUtf8("зэ")] = QString::fromUtf8("ゼ");
    katakana_kiridzi[QString::fromUtf8("зе")] = QString::fromUtf8("ゼ");
    katakana_kiridzi[QString::fromUtf8("зо")] = QString::fromUtf8("ゾ");

    katakana_kiridzi[QString::fromUtf8("зя")] = QString::fromUtf8("ジャ");
    katakana_kiridzi[QString::fromUtf8("зю")] = QString::fromUtf8("ジュ");
    katakana_kiridzi[QString::fromUtf8("зё")] = QString::fromUtf8("ジョ");

    katakana_kiridzi[QString::fromUtf8("та")] = QString::fromUtf8("タ");
    katakana_kiridzi[QString::fromUtf8("ти")] = QString::fromUtf8("チ");
    katakana_kiridzi[QString::fromUtf8("чи")] = QString::fromUtf8("チ");
    katakana_kiridzi[QString::fromUtf8("ту")] = QString::fromUtf8("ツ");
    katakana_kiridzi[QString::fromUtf8("цу")] = QString::fromUtf8("ツ");
    katakana_kiridzi[QString::fromUtf8("тэ")] = QString::fromUtf8("テ");
    katakana_kiridzi[QString::fromUtf8("те")] = QString::fromUtf8("テ");
    katakana_kiridzi[QString::fromUtf8("то")] = QString::fromUtf8("ト");

    katakana_kiridzi[QString::fromUtf8("чя")] = QString::fromUtf8("チャ");
    katakana_kiridzi[QString::fromUtf8("чу")] = QString::fromUtf8("チュ");
    katakana_kiridzi[QString::fromUtf8("тя")] = QString::fromUtf8("チャ");
    katakana_kiridzi[QString::fromUtf8("тю")] = QString::fromUtf8("チュ");
    katakana_kiridzi[QString::fromUtf8("чё")] = QString::fromUtf8("チョ");
    katakana_kiridzi[QString::fromUtf8("тё")] = QString::fromUtf8("チョ");

    katakana_kiridzi[QString::fromUtf8("да")] = QString::fromUtf8("ダ");
    katakana_kiridzi[QString::fromUtf8("ди")] = QString::fromUtf8("ヂ");
    katakana_kiridzi[QString::fromUtf8("ду")] = QString::fromUtf8("ヅ");
    katakana_kiridzi[QString::fromUtf8("дэ")] = QString::fromUtf8("デ");
    katakana_kiridzi[QString::fromUtf8("де")] = QString::fromUtf8("デ");
    katakana_kiridzi[QString::fromUtf8("до")] = QString::fromUtf8("ド");

    katakana_kiridzi[QString::fromUtf8("дя")] = QString::fromUtf8("ヂャ");
    katakana_kiridzi[QString::fromUtf8("дю")] = QString::fromUtf8("ヂュ");
    katakana_kiridzi[QString::fromUtf8("дё")] = QString::fromUtf8("ヂョ");

    katakana_kiridzi[QString::fromUtf8("на")] = QString::fromUtf8("ナ");
    katakana_kiridzi[QString::fromUtf8("ни")] = QString::fromUtf8("ニ");
    katakana_kiridzi[QString::fromUtf8("ну")] = QString::fromUtf8("ヌ");
    katakana_kiridzi[QString::fromUtf8("нэ")] = QString::fromUtf8("ネ");
    katakana_kiridzi[QString::fromUtf8("не")] = QString::fromUtf8("ネ");
    katakana_kiridzi[QString::fromUtf8("но")] = QString::fromUtf8("ノ");

    katakana_kiridzi[QString::fromUtf8("ня")] = QString::fromUtf8("ニャ");
    katakana_kiridzi[QString::fromUtf8("ню")] = QString::fromUtf8("ニュ");
    katakana_kiridzi[QString::fromUtf8("нё")] = QString::fromUtf8("ニョ");

    katakana_kiridzi[QString::fromUtf8("ха")] = QString::fromUtf8("ハ");
    katakana_kiridzi[QString::fromUtf8("хи")] = QString::fromUtf8("ヒ");
    katakana_kiridzi[QString::fromUtf8("ху")] = QString::fromUtf8("フ");
    katakana_kiridzi[QString::fromUtf8("фу")] = QString::fromUtf8("フ");
    katakana_kiridzi[QString::fromUtf8("хэ")] = QString::fromUtf8("ヘ");
    katakana_kiridzi[QString::fromUtf8("хе")] = QString::fromUtf8("ヘ");
    katakana_kiridzi[QString::fromUtf8("хо")] = QString::fromUtf8("ホ");

    katakana_kiridzi[QString::fromUtf8("хя")] = QString::fromUtf8("ヒャ");
    katakana_kiridzi[QString::fromUtf8("хю")] = QString::fromUtf8("ヒュ");
    katakana_kiridzi[QString::fromUtf8("хё")] = QString::fromUtf8("ヒョ");

    katakana_kiridzi[QString::fromUtf8("па")] = QString::fromUtf8("パ");
    katakana_kiridzi[QString::fromUtf8("пи")] = QString::fromUtf8("ピ");
    katakana_kiridzi[QString::fromUtf8("пу")] = QString::fromUtf8("プ");
    katakana_kiridzi[QString::fromUtf8("пэ")] = QString::fromUtf8("ペ");
    katakana_kiridzi[QString::fromUtf8("пе")] = QString::fromUtf8("ペ");
    katakana_kiridzi[QString::fromUtf8("по")] = QString::fromUtf8("ポ");

    katakana_kiridzi[QString::fromUtf8("пя")] = QString::fromUtf8("ピャ");
    katakana_kiridzi[QString::fromUtf8("пю")] = QString::fromUtf8("ピュ");
    katakana_kiridzi[QString::fromUtf8("пё")] = QString::fromUtf8("ピョ");

    katakana_kiridzi[QString::fromUtf8("ба")] = QString::fromUtf8("バ");
    katakana_kiridzi[QString::fromUtf8("би")] = QString::fromUtf8("ビ");
    katakana_kiridzi[QString::fromUtf8("бу")] = QString::fromUtf8("ブ");
    katakana_kiridzi[QString::fromUtf8("бэ")] = QString::fromUtf8("ベ");
    katakana_kiridzi[QString::fromUtf8("бе")] = QString::fromUtf8("ベ");
    katakana_kiridzi[QString::fromUtf8("бо")] = QString::fromUtf8("ボ");

    katakana_kiridzi[QString::fromUtf8("бя")] = QString::fromUtf8("ビャ");
    katakana_kiridzi[QString::fromUtf8("бю")] = QString::fromUtf8("ビュ");
    katakana_kiridzi[QString::fromUtf8("бё")] = QString::fromUtf8("ビョ");

    katakana_kiridzi[QString::fromUtf8("ма")] = QString::fromUtf8("マ");
    katakana_kiridzi[QString::fromUtf8("ми")] = QString::fromUtf8("ミ");
    katakana_kiridzi[QString::fromUtf8("му")] = QString::fromUtf8("ム");
    katakana_kiridzi[QString::fromUtf8("мэ")] = QString::fromUtf8("メ");
    katakana_kiridzi[QString::fromUtf8("ме")] = QString::fromUtf8("メ");
    katakana_kiridzi[QString::fromUtf8("мо")] = QString::fromUtf8("モ");

    katakana_kiridzi[QString::fromUtf8("мя")] = QString::fromUtf8("ミャ");
    katakana_kiridzi[QString::fromUtf8("мю")] = QString::fromUtf8("ミュ");
    katakana_kiridzi[QString::fromUtf8("мё")] = QString::fromUtf8("ミョ");

    katakana_kiridzi[QString::fromUtf8("я")] = QString::fromUtf8("ヤ");
    katakana_kiridzi[QString::fromUtf8("ю")] = QString::fromUtf8("ユ");
    katakana_kiridzi[QString::fromUtf8("ё")] = QString::fromUtf8("ヨ");
    katakana_kiridzi[QString::fromUtf8("йо")] = QString::fromUtf8("ヨ");

    katakana_kiridzi[QString::fromUtf8("ра")] = QString::fromUtf8("ラ");
    katakana_kiridzi[QString::fromUtf8("ри")] = QString::fromUtf8("リ");
    katakana_kiridzi[QString::fromUtf8("ру")] = QString::fromUtf8("ル");
    katakana_kiridzi[QString::fromUtf8("рэ")] = QString::fromUtf8("レ");
    katakana_kiridzi[QString::fromUtf8("ре")] = QString::fromUtf8("レ");
    katakana_kiridzi[QString::fromUtf8("ро")] = QString::fromUtf8("ロ");

    katakana_kiridzi[QString::fromUtf8("ря")] = QString::fromUtf8("リャ");
    katakana_kiridzi[QString::fromUtf8("рю")] = QString::fromUtf8("リュ");
    katakana_kiridzi[QString::fromUtf8("рё")] = QString::fromUtf8("リョ");

    katakana_kiridzi[QString::fromUtf8("ва")] = QString::fromUtf8("ワ");
    katakana_kiridzi[QString::fromUtf8("н")] = QString::fromUtf8("ン");



    katakana_romadzi[QString::fromUtf8("a")] = QString::fromUtf8("ア");
    katakana_romadzi[QString::fromUtf8("i")] = QString::fromUtf8("イ");
    katakana_romadzi[QString::fromUtf8("u")] = QString::fromUtf8("ウ");
    katakana_romadzi[QString::fromUtf8("e")] = QString::fromUtf8("エ");
    katakana_romadzi[QString::fromUtf8("o")] = QString::fromUtf8("オ");

    katakana_romadzi[QString::fromUtf8("ka")] = QString::fromUtf8("カ");
    katakana_romadzi[QString::fromUtf8("ki")] = QString::fromUtf8("キ");
    katakana_romadzi[QString::fromUtf8("ku")] = QString::fromUtf8("ク");
    katakana_romadzi[QString::fromUtf8("ke")] = QString::fromUtf8("ケ");
    katakana_romadzi[QString::fromUtf8("ko")] = QString::fromUtf8("コ");

    katakana_romadzi[QString::fromUtf8("kya")] = QString::fromUtf8("キャ");
    katakana_romadzi[QString::fromUtf8("kyu")] = QString::fromUtf8("キュ");
    katakana_romadzi[QString::fromUtf8("kyo")] = QString::fromUtf8("キョ");

    katakana_romadzi[QString::fromUtf8("ga")] = QString::fromUtf8("ガ");
    katakana_romadzi[QString::fromUtf8("gi")] = QString::fromUtf8("ギ");
    katakana_romadzi[QString::fromUtf8("gu")] = QString::fromUtf8("グ");
    katakana_romadzi[QString::fromUtf8("ge")] = QString::fromUtf8("ゲ");
    katakana_romadzi[QString::fromUtf8("go")] = QString::fromUtf8("ゴ");

    katakana_romadzi[QString::fromUtf8("gya")] = QString::fromUtf8("ギャ");
    katakana_romadzi[QString::fromUtf8("gyu")] = QString::fromUtf8("ギュ");
    katakana_romadzi[QString::fromUtf8("gyo")] = QString::fromUtf8("ギョ");

    katakana_romadzi[QString::fromUtf8("sa")] = QString::fromUtf8("サ");
    katakana_romadzi[QString::fromUtf8("shi")] = QString::fromUtf8("シ");
    katakana_romadzi[QString::fromUtf8("si")] = QString::fromUtf8("シ");
    katakana_romadzi[QString::fromUtf8("su")] = QString::fromUtf8("ス");
    katakana_romadzi[QString::fromUtf8("se")] = QString::fromUtf8("セ");
    katakana_romadzi[QString::fromUtf8("so")] = QString::fromUtf8("ソ");

    katakana_romadzi[QString::fromUtf8("sya")] = QString::fromUtf8("シャ");
    katakana_romadzi[QString::fromUtf8("syu")] = QString::fromUtf8("シュ");
    katakana_romadzi[QString::fromUtf8("syo")] = QString::fromUtf8("ショ");

    katakana_romadzi[QString::fromUtf8("za")] = QString::fromUtf8("ザ");
    katakana_romadzi[QString::fromUtf8("zi")] = QString::fromUtf8("ジ");
    katakana_romadzi[QString::fromUtf8("zu")] = QString::fromUtf8("ズ");
    katakana_romadzi[QString::fromUtf8("ze")] = QString::fromUtf8("ゼ");
    katakana_romadzi[QString::fromUtf8("zo")] = QString::fromUtf8("ゾ");

    katakana_romadzi[QString::fromUtf8("zya")] = QString::fromUtf8("ジャ");
    katakana_romadzi[QString::fromUtf8("zyu")] = QString::fromUtf8("ジュ");
    katakana_romadzi[QString::fromUtf8("zyo")] = QString::fromUtf8("ジョ");

    katakana_romadzi[QString::fromUtf8("ta")] = QString::fromUtf8("タ");
    katakana_romadzi[QString::fromUtf8("ti")] = QString::fromUtf8("チ");
    katakana_romadzi[QString::fromUtf8("chi")] = QString::fromUtf8("チ");
    katakana_romadzi[QString::fromUtf8("tu")] = QString::fromUtf8("ツ");
    katakana_romadzi[QString::fromUtf8("tsu")] = QString::fromUtf8("ツ");
    katakana_romadzi[QString::fromUtf8("te")] = QString::fromUtf8("テ");
    katakana_romadzi[QString::fromUtf8("to")] = QString::fromUtf8("ト");

    katakana_romadzi[QString::fromUtf8("chya")] = QString::fromUtf8("チャ");
    katakana_romadzi[QString::fromUtf8("chu")] = QString::fromUtf8("チュ");
    katakana_romadzi[QString::fromUtf8("chyo")] = QString::fromUtf8("チョ");

    katakana_romadzi[QString::fromUtf8("da")] = QString::fromUtf8("ダ");
    katakana_romadzi[QString::fromUtf8("ji")] = QString::fromUtf8("ヂ");
    katakana_romadzi[QString::fromUtf8("di")] = QString::fromUtf8("ヂ");
    katakana_romadzi[QString::fromUtf8("ju")] = QString::fromUtf8("ヅ");
    katakana_romadzi[QString::fromUtf8("de")] = QString::fromUtf8("デ");
    katakana_romadzi[QString::fromUtf8("do")] = QString::fromUtf8("ド");

    katakana_romadzi[QString::fromUtf8("dya")] = QString::fromUtf8("ヂャ");
    katakana_romadzi[QString::fromUtf8("dyu")] = QString::fromUtf8("ヂュ");
    katakana_romadzi[QString::fromUtf8("dyo")] = QString::fromUtf8("ヂョ");

    katakana_romadzi[QString::fromUtf8("na")] = QString::fromUtf8("ナ");
    katakana_romadzi[QString::fromUtf8("ni")] = QString::fromUtf8("ニ");
    katakana_romadzi[QString::fromUtf8("nu")] = QString::fromUtf8("ヌ");
    katakana_romadzi[QString::fromUtf8("ne")] = QString::fromUtf8("ネ");
    katakana_romadzi[QString::fromUtf8("no")] = QString::fromUtf8("ノ");

    katakana_romadzi[QString::fromUtf8("nya")] = QString::fromUtf8("ニャ");
    katakana_romadzi[QString::fromUtf8("nyu")] = QString::fromUtf8("ニュ");
    katakana_romadzi[QString::fromUtf8("nyo")] = QString::fromUtf8("ニョ");

    katakana_romadzi[QString::fromUtf8("ha")] = QString::fromUtf8("ハ");
    katakana_romadzi[QString::fromUtf8("hi")] = QString::fromUtf8("ヒ");
    katakana_romadzi[QString::fromUtf8("hu")] = QString::fromUtf8("フ");
    katakana_romadzi[QString::fromUtf8("fu")] = QString::fromUtf8("フ");
    katakana_romadzi[QString::fromUtf8("he")] = QString::fromUtf8("ヘ");
    katakana_romadzi[QString::fromUtf8("ho")] = QString::fromUtf8("ホ");

    katakana_romadzi[QString::fromUtf8("hya")] = QString::fromUtf8("ヒャ");
    katakana_romadzi[QString::fromUtf8("hyu")] = QString::fromUtf8("ヒュ");
    katakana_romadzi[QString::fromUtf8("hyo")] = QString::fromUtf8("ヒョ");

    katakana_romadzi[QString::fromUtf8("pa")] = QString::fromUtf8("パ");
    katakana_romadzi[QString::fromUtf8("pi")] = QString::fromUtf8("ピ");
    katakana_romadzi[QString::fromUtf8("pu")] = QString::fromUtf8("プ");
    katakana_romadzi[QString::fromUtf8("pe")] = QString::fromUtf8("ペ");
    katakana_romadzi[QString::fromUtf8("po")] = QString::fromUtf8("ポ");

    katakana_romadzi[QString::fromUtf8("pya")] = QString::fromUtf8("ピャ");
    katakana_romadzi[QString::fromUtf8("pyu")] = QString::fromUtf8("ピュ");
    katakana_romadzi[QString::fromUtf8("pyo")] = QString::fromUtf8("ピョ");

    katakana_romadzi[QString::fromUtf8("ba")] = QString::fromUtf8("バ");
    katakana_romadzi[QString::fromUtf8("bi")] = QString::fromUtf8("ビ");
    katakana_romadzi[QString::fromUtf8("bu")] = QString::fromUtf8("ブ");
    katakana_romadzi[QString::fromUtf8("be")] = QString::fromUtf8("ベ");
    katakana_romadzi[QString::fromUtf8("bo")] = QString::fromUtf8("ボ");

    katakana_romadzi[QString::fromUtf8("bya")] = QString::fromUtf8("ビャ");
    katakana_romadzi[QString::fromUtf8("byu")] = QString::fromUtf8("ビュ");
    katakana_romadzi[QString::fromUtf8("byo")] = QString::fromUtf8("ビョ");

    katakana_romadzi[QString::fromUtf8("ma")] = QString::fromUtf8("マ");
    katakana_romadzi[QString::fromUtf8("mi")] = QString::fromUtf8("ミ");
    katakana_romadzi[QString::fromUtf8("mu")] = QString::fromUtf8("ム");
    katakana_romadzi[QString::fromUtf8("me")] = QString::fromUtf8("メ");
    katakana_romadzi[QString::fromUtf8("mo")] = QString::fromUtf8("モ");

    katakana_romadzi[QString::fromUtf8("mya")] = QString::fromUtf8("ミャ");
    katakana_romadzi[QString::fromUtf8("myu")] = QString::fromUtf8("ミュ");
    katakana_romadzi[QString::fromUtf8("myo")] = QString::fromUtf8("ミョ");

    katakana_romadzi[QString::fromUtf8("ya")] = QString::fromUtf8("ヤ");
    katakana_romadzi[QString::fromUtf8("yu")] = QString::fromUtf8("ユ");
    katakana_romadzi[QString::fromUtf8("yo")] = QString::fromUtf8("ヨ");

    katakana_romadzi[QString::fromUtf8("ra")] = QString::fromUtf8("ラ");
    katakana_romadzi[QString::fromUtf8("ri")] = QString::fromUtf8("リ");
    katakana_romadzi[QString::fromUtf8("ru")] = QString::fromUtf8("ル");
    katakana_romadzi[QString::fromUtf8("re")] = QString::fromUtf8("レ");
    katakana_romadzi[QString::fromUtf8("ro")] = QString::fromUtf8("ロ");

    katakana_romadzi[QString::fromUtf8("rya")] = QString::fromUtf8("リャ");
    katakana_romadzi[QString::fromUtf8("ryu")] = QString::fromUtf8("リュ");
    katakana_romadzi[QString::fromUtf8("ryo")] = QString::fromUtf8("リョ");

    katakana_romadzi[QString::fromUtf8("wa")] = QString::fromUtf8("ワ");
    katakana_romadzi[QString::fromUtf8("n")] = QString::fromUtf8("ン");
}

QString Converter::Convert(const QString source)
{
    QString result;
    int currentIndex = 0;
    for(int i=0; i < source.length()-3; i++)
    {
        int amount = 0;
        QString converted = ConvertTrigramm(source[i], source[i+1], source[i+2], amount);
        if(converted != "")
        {
            result+=converted;
            i+=amount;
            currentIndex+=amount;
        }
        else
        {
            result+=source[i];
        }
        currentIndex++;
    }
    int dist = source.length() - currentIndex;
    if(dist == 3)
    {
        int amount = 0;
        QString ps = ConvertTrigramm(source[currentIndex], source[currentIndex+1], source[currentIndex+2], amount);
        if(ps != "")
        {
            result += ps;
            if(amount == 1)
            {
                QString ps2 = ConvertPattern(source[currentIndex+2]);
                if(ps2 != "")
                    result+=ps2;
                else
                    result+=source[currentIndex+2];
            }
            if(amount==0)
            {
                QString both = source[currentIndex+1];
                both += source[currentIndex+2];
                QString ps2 = ConvertPattern(both);
                if(ps2 != "")
                    result+=ps2;
                else
                    result+=source[currentIndex+1];
                QString ps3 = ConvertPattern(source[currentIndex+2]);
                if(ps3 != "")
                    result+=ps3;
                else
                    result+=source[currentIndex+2];
            }
        }
        else
        {
            result+=source[currentIndex];
            result+=source[currentIndex+1];
            result+=source[currentIndex+2];
        }
    }
    if(dist == 2)
    {
        QString both = source[currentIndex];
        both += source[currentIndex+1];
        QString ps = ConvertPattern(both);
        if(ps != "")
            result+=ps;
        else
            result+=source[currentIndex];
        QString ps2 = ConvertPattern(source[currentIndex+1]);
        if(ps2 != "")
            result+=ps2;
        else
            result+=source[currentIndex+1];
    }
    if(dist == 1)
    {
        QString ps = ConvertPattern(source[currentIndex]);
        if(ps != "")
            result+=ps;
        else
            result+=source[currentIndex];
    }
    return result;
}

void Converter::SetConvertMode(Converter::ConvertMode mode)
{
    _currentConvertMode = mode;
}

void Converter::SetPossibility(int possibility)
{
    _currentPossibility = possibility;
}

QString Converter::ConvertTrigramm(QChar one, QChar two, QChar three, int &amount)
{
    QString result = "";
    QString trigramm = "";
    trigramm += one.toLower();
    trigramm += two.toLower();
    trigramm += three.toLower();

    QString convertedTrigramm = ConvertPattern(trigramm);
    if(convertedTrigramm != "")
    {
        result = convertedTrigramm;
        amount = 2;
        return result;
    }

    QString dugramm = "";
    dugramm += one.toLower();
    dugramm += two.toLower();

    QString convertedDugramm = ConvertPattern(dugramm);
    if(convertedDugramm != "")
    {
        result = convertedDugramm;
        amount=1;
        return result;
    }

    QString currentSymbol = one.toLower();
    QString convertedSymbol = ConvertPattern(currentSymbol);
    if(convertedSymbol != "")
    {
        result = convertedSymbol;
    }
    return result;
}

QString Converter::FindSymbolInMap(const QMap<QString, QString> map, QString pattern)
{
    QMap<QString, QString>::const_iterator i = map.constBegin();
    while (i != map.constEnd()) {
        if(i.key() == pattern)
            return i.value();
        ++i;
    }
    return "";
}

QString Converter::ConvertPattern(QString pattern)
{
    QString converted;
    if((_currentConvertMode & KiridziMode) != 0)
    {
        bool rand = qrand()%2;
        if(rand)
        {
            converted = GetConvertedSymbol(HiraganaMode, hiragana_kiridzi, pattern);
            if(!converted.isEmpty())
                return converted;
            converted = GetConvertedSymbol(KatakanaMode, katakana_kiridzi, pattern);
            if(!converted.isEmpty())
                return converted;
        }
        else
        {
            converted = GetConvertedSymbol(KatakanaMode, katakana_kiridzi, pattern);
            if(!converted.isEmpty())
                return converted;
            converted = GetConvertedSymbol(HiraganaMode, hiragana_kiridzi, pattern);
            if(!converted.isEmpty())
                return converted;
        }
    }
    if((_currentConvertMode & RomadziMode) != 0)
    {
        int rand0 = qrand()%100;
        if(rand0 >= _currentPossibility)
            return "";
        bool rand1 = qrand()%2;
        if(rand1)
        {
            converted = GetConvertedSymbol(HiraganaMode, hiragana_romadzi, pattern);
            if(!converted.isEmpty())
                return converted;
            converted = GetConvertedSymbol(KatakanaMode, katakana_romadzi, pattern);
            if(!converted.isEmpty())
                return converted;
        }
        else
        {
            converted = GetConvertedSymbol(KatakanaMode, katakana_romadzi, pattern);
            if(!converted.isEmpty())
                return converted;
            converted = GetConvertedSymbol(HiraganaMode, hiragana_romadzi, pattern);
            if(!converted.isEmpty())
                return converted;
        }
    }
    return "";
}

QString Converter::GetConvertedSymbol(Converter::ConvertMode mode, QMap<QString, QString> map, QString pattern)
{
    if((_currentConvertMode & mode) != 0)
    {
        QString converted = FindSymbolInMap(map, pattern);
        if(!converted.isEmpty())
            return converted;
    }
    return "";
}
