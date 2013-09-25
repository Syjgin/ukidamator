#include "converter.h"

Converter::Converter(QObject *parent) :
    QObject(parent)
{
    hiragana_replacements[QString::fromUtf8("а")] = QString::fromUtf8("あ");
        hiragana_replacements[QString::fromUtf8("и")] = QString::fromUtf8("い");
        hiragana_replacements[QString::fromUtf8("й")] = QString::fromUtf8("い");
        hiragana_replacements[QString::fromUtf8("у")] = QString::fromUtf8("う");
        hiragana_replacements[QString::fromUtf8("э")] = QString::fromUtf8("え");
        hiragana_replacements[QString::fromUtf8("е")] = QString::fromUtf8("え");
        hiragana_replacements[QString::fromUtf8("о")] = QString::fromUtf8("お");

        hiragana_replacements[QString::fromUtf8("ка")] = QString::fromUtf8("か");
        hiragana_replacements[QString::fromUtf8("ки")] = QString::fromUtf8("き");
        hiragana_replacements[QString::fromUtf8("ку")] = QString::fromUtf8("く");
        hiragana_replacements[QString::fromUtf8("кэ")] = QString::fromUtf8("け");
        hiragana_replacements[QString::fromUtf8("ке")] = QString::fromUtf8("け");
        hiragana_replacements[QString::fromUtf8("ко")] = QString::fromUtf8("こ");

        hiragana_replacements[QString::fromUtf8("кя")] = QString::fromUtf8("きゃ");
        hiragana_replacements[QString::fromUtf8("кю")] = QString::fromUtf8("きゅ");
        hiragana_replacements[QString::fromUtf8("кё")] = QString::fromUtf8("きょ");

        hiragana_replacements[QString::fromUtf8("га")] = QString::fromUtf8("が");
        hiragana_replacements[QString::fromUtf8("ги")] = QString::fromUtf8("ぎ");
        hiragana_replacements[QString::fromUtf8("гу")] = QString::fromUtf8("ぐ");
        hiragana_replacements[QString::fromUtf8("гэ")] = QString::fromUtf8("げ");
        hiragana_replacements[QString::fromUtf8("ге")] = QString::fromUtf8("げ");
        hiragana_replacements[QString::fromUtf8("го")] = QString::fromUtf8("ご");

        hiragana_replacements[QString::fromUtf8("гя")] = QString::fromUtf8("ぎゃ");
        hiragana_replacements[QString::fromUtf8("гю")] = QString::fromUtf8("ぎゅ");
        hiragana_replacements[QString::fromUtf8("гё")] = QString::fromUtf8("ぎょ");

        hiragana_replacements[QString::fromUtf8("са")] = QString::fromUtf8("さ");
        hiragana_replacements[QString::fromUtf8("си")] = QString::fromUtf8("し");
        hiragana_replacements[QString::fromUtf8("ши")] = QString::fromUtf8("し");
        hiragana_replacements[QString::fromUtf8("щи")] = QString::fromUtf8("し");
        hiragana_replacements[QString::fromUtf8("су")] = QString::fromUtf8("す");
        hiragana_replacements[QString::fromUtf8("сэ")] = QString::fromUtf8("せ");
        hiragana_replacements[QString::fromUtf8("се")] = QString::fromUtf8("せ");
        hiragana_replacements[QString::fromUtf8("со")] = QString::fromUtf8("そ");

        hiragana_replacements[QString::fromUtf8("ся")] = QString::fromUtf8("しゃ");
        hiragana_replacements[QString::fromUtf8("сю")] = QString::fromUtf8("しゅ");
        hiragana_replacements[QString::fromUtf8("сё")] = QString::fromUtf8("しょ");

        hiragana_replacements[QString::fromUtf8("за")] = QString::fromUtf8("ざ");
        hiragana_replacements[QString::fromUtf8("зи")] = QString::fromUtf8("じ");
        hiragana_replacements[QString::fromUtf8("жи")] = QString::fromUtf8("じ");
        hiragana_replacements[QString::fromUtf8("зу")] = QString::fromUtf8("ず");
        hiragana_replacements[QString::fromUtf8("зэ")] = QString::fromUtf8("ぜ");
        hiragana_replacements[QString::fromUtf8("зе")] = QString::fromUtf8("ぜ");
        hiragana_replacements[QString::fromUtf8("зо")] = QString::fromUtf8("ぞ");

        hiragana_replacements[QString::fromUtf8("зя")] = QString::fromUtf8("じゃ");
        hiragana_replacements[QString::fromUtf8("зю")] = QString::fromUtf8("じゅ");
        hiragana_replacements[QString::fromUtf8("зё")] = QString::fromUtf8("じょ");

        hiragana_replacements[QString::fromUtf8("та")] = QString::fromUtf8("た");
        hiragana_replacements[QString::fromUtf8("ти")] = QString::fromUtf8("ち");
        hiragana_replacements[QString::fromUtf8("чи")] = QString::fromUtf8("ち");
        hiragana_replacements[QString::fromUtf8("цу")] = QString::fromUtf8("つ");
        hiragana_replacements[QString::fromUtf8("тэ")] = QString::fromUtf8("て");
        hiragana_replacements[QString::fromUtf8("те")] = QString::fromUtf8("て");
        hiragana_replacements[QString::fromUtf8("то")] = QString::fromUtf8("と");

        hiragana_replacements[QString::fromUtf8("чя")] = QString::fromUtf8("ちゃ");
        hiragana_replacements[QString::fromUtf8("чу")] = QString::fromUtf8("ちゅ");
        hiragana_replacements[QString::fromUtf8("тя")] = QString::fromUtf8("ちゃ");
        hiragana_replacements[QString::fromUtf8("тю")] = QString::fromUtf8("ちゅ");
        hiragana_replacements[QString::fromUtf8("чё")] = QString::fromUtf8("ちょ");
        katakana_replacements[QString::fromUtf8("тё")] = QString::fromUtf8("ちょ");

        hiragana_replacements[QString::fromUtf8("да")] = QString::fromUtf8("だ");
        hiragana_replacements[QString::fromUtf8("ди")] = QString::fromUtf8("ぢ");
        hiragana_replacements[QString::fromUtf8("ду")] = QString::fromUtf8("づ");
        hiragana_replacements[QString::fromUtf8("дэ")] = QString::fromUtf8("で");
        hiragana_replacements[QString::fromUtf8("де")] = QString::fromUtf8("で");
        hiragana_replacements[QString::fromUtf8("до")] = QString::fromUtf8("ど");

        hiragana_replacements[QString::fromUtf8("дя")] = QString::fromUtf8("ぢゃ");
        hiragana_replacements[QString::fromUtf8("дю")] = QString::fromUtf8("ぢゅ");
        hiragana_replacements[QString::fromUtf8("дё")] = QString::fromUtf8("ぢょ");

        hiragana_replacements[QString::fromUtf8("на")] = QString::fromUtf8("な");
        hiragana_replacements[QString::fromUtf8("ни")] = QString::fromUtf8("に");
        hiragana_replacements[QString::fromUtf8("ну")] = QString::fromUtf8("ぬ");
        hiragana_replacements[QString::fromUtf8("нэ")] = QString::fromUtf8("ね");
        hiragana_replacements[QString::fromUtf8("не")] = QString::fromUtf8("ね");
        hiragana_replacements[QString::fromUtf8("но")] = QString::fromUtf8("の");

        hiragana_replacements[QString::fromUtf8("ня")] = QString::fromUtf8("にゃ");
        hiragana_replacements[QString::fromUtf8("ню")] = QString::fromUtf8("にゅ");
        hiragana_replacements[QString::fromUtf8("нё")] = QString::fromUtf8("にょ");

        hiragana_replacements[QString::fromUtf8("ха")] = QString::fromUtf8("は");
        hiragana_replacements[QString::fromUtf8("хи")] = QString::fromUtf8("ひ");
        hiragana_replacements[QString::fromUtf8("ху")] = QString::fromUtf8("ふ");
        hiragana_replacements[QString::fromUtf8("фу")] = QString::fromUtf8("ふ");
        hiragana_replacements[QString::fromUtf8("хэ")] = QString::fromUtf8("へ");
        hiragana_replacements[QString::fromUtf8("хе")] = QString::fromUtf8("へ");
        hiragana_replacements[QString::fromUtf8("хо")] = QString::fromUtf8("ほ");

        hiragana_replacements[QString::fromUtf8("хя")] = QString::fromUtf8("ひゃ");
        hiragana_replacements[QString::fromUtf8("хю")] = QString::fromUtf8("ひゅ");
        hiragana_replacements[QString::fromUtf8("хё")] = QString::fromUtf8("ひょ");

        hiragana_replacements[QString::fromUtf8("па")] = QString::fromUtf8("ぱ");
        hiragana_replacements[QString::fromUtf8("пи")] = QString::fromUtf8("ぴ");
        hiragana_replacements[QString::fromUtf8("пу")] = QString::fromUtf8("ぷ");
        hiragana_replacements[QString::fromUtf8("пэ")] = QString::fromUtf8("ぺ");
        hiragana_replacements[QString::fromUtf8("пе")] = QString::fromUtf8("ぺ");
        hiragana_replacements[QString::fromUtf8("по")] = QString::fromUtf8("ぽ");

        hiragana_replacements[QString::fromUtf8("пя")] = QString::fromUtf8("ぴゃ");
        hiragana_replacements[QString::fromUtf8("пю")] = QString::fromUtf8("ぴゅ");
        hiragana_replacements[QString::fromUtf8("пё")] = QString::fromUtf8("ぴょ");

        hiragana_replacements[QString::fromUtf8("ба")] = QString::fromUtf8("ば");
        hiragana_replacements[QString::fromUtf8("би")] = QString::fromUtf8("び");
        hiragana_replacements[QString::fromUtf8("бу")] = QString::fromUtf8("ぶ");
        hiragana_replacements[QString::fromUtf8("бэ")] = QString::fromUtf8("べ");
        hiragana_replacements[QString::fromUtf8("бе")] = QString::fromUtf8("べ");
        hiragana_replacements[QString::fromUtf8("бо")] = QString::fromUtf8("ぼ");

        hiragana_replacements[QString::fromUtf8("бя")] = QString::fromUtf8("びゃ");
        hiragana_replacements[QString::fromUtf8("бю")] = QString::fromUtf8("びゅ");
        hiragana_replacements[QString::fromUtf8("бё")] = QString::fromUtf8("びょ");

        hiragana_replacements[QString::fromUtf8("ма")] = QString::fromUtf8("ま");
        hiragana_replacements[QString::fromUtf8("ми")] = QString::fromUtf8("み");
        hiragana_replacements[QString::fromUtf8("му")] = QString::fromUtf8("む");
        hiragana_replacements[QString::fromUtf8("мэ")] = QString::fromUtf8("め");
        hiragana_replacements[QString::fromUtf8("ме")] = QString::fromUtf8("め");
        hiragana_replacements[QString::fromUtf8("мо")] = QString::fromUtf8("も");

        hiragana_replacements[QString::fromUtf8("мя")] = QString::fromUtf8("みゃ");
        hiragana_replacements[QString::fromUtf8("мю")] = QString::fromUtf8("みゅ");
        hiragana_replacements[QString::fromUtf8("мё")] = QString::fromUtf8("みょ");

        hiragana_replacements[QString::fromUtf8("я")] = QString::fromUtf8("や");
        hiragana_replacements[QString::fromUtf8("ю")] = QString::fromUtf8("ゆ");
        hiragana_replacements[QString::fromUtf8("ё")] = QString::fromUtf8("よ");
        hiragana_replacements[QString::fromUtf8("йо")] = QString::fromUtf8("よ");

        hiragana_replacements[QString::fromUtf8("ра")] = QString::fromUtf8("ら");
        hiragana_replacements[QString::fromUtf8("ри")] = QString::fromUtf8("り");
        hiragana_replacements[QString::fromUtf8("ру")] = QString::fromUtf8("る");
        hiragana_replacements[QString::fromUtf8("рэ")] = QString::fromUtf8("れ");
        hiragana_replacements[QString::fromUtf8("ре")] = QString::fromUtf8("れ");
        hiragana_replacements[QString::fromUtf8("ро")] = QString::fromUtf8("ろ");

        hiragana_replacements[QString::fromUtf8("ря")] = QString::fromUtf8("りゃ");
        hiragana_replacements[QString::fromUtf8("рю")] = QString::fromUtf8("りゅ");
        hiragana_replacements[QString::fromUtf8("рё")] = QString::fromUtf8("りょ");

        hiragana_replacements[QString::fromUtf8("ва")] = QString::fromUtf8("わ");
        hiragana_replacements[QString::fromUtf8("во")] = QString::fromUtf8("を");
        hiragana_replacements[QString::fromUtf8("н")] = QString::fromUtf8("ん");


        hiragana_replacements[QString::fromUtf8("a")] = QString::fromUtf8("あ");
        hiragana_replacements[QString::fromUtf8("i")] = QString::fromUtf8("い");
        hiragana_replacements[QString::fromUtf8("u")] = QString::fromUtf8("う");
        hiragana_replacements[QString::fromUtf8("e")] = QString::fromUtf8("え");
        hiragana_replacements[QString::fromUtf8("o")] = QString::fromUtf8("お");

        hiragana_replacements[QString::fromUtf8("ka")] = QString::fromUtf8("か");
        hiragana_replacements[QString::fromUtf8("ki")] = QString::fromUtf8("き");
        hiragana_replacements[QString::fromUtf8("ku")] = QString::fromUtf8("く");
        hiragana_replacements[QString::fromUtf8("ke")] = QString::fromUtf8("け");
        hiragana_replacements[QString::fromUtf8("ko")] = QString::fromUtf8("こ");

        hiragana_replacements[QString::fromUtf8("kya")] = QString::fromUtf8("きゃ");
        hiragana_replacements[QString::fromUtf8("kyu")] = QString::fromUtf8("きゅ");
        hiragana_replacements[QString::fromUtf8("kyo")] = QString::fromUtf8("きょ");

        hiragana_replacements[QString::fromUtf8("ga")] = QString::fromUtf8("が");
        hiragana_replacements[QString::fromUtf8("gi")] = QString::fromUtf8("ぎ");
        hiragana_replacements[QString::fromUtf8("gu")] = QString::fromUtf8("ぐ");
        hiragana_replacements[QString::fromUtf8("ge")] = QString::fromUtf8("げ");
        hiragana_replacements[QString::fromUtf8("go")] = QString::fromUtf8("ご");

        hiragana_replacements[QString::fromUtf8("gya")] = QString::fromUtf8("ぎゃ");
        hiragana_replacements[QString::fromUtf8("gyu")] = QString::fromUtf8("ぎゅ");
        hiragana_replacements[QString::fromUtf8("gyo")] = QString::fromUtf8("ぎょ");

        hiragana_replacements[QString::fromUtf8("sa")] = QString::fromUtf8("さ");
        hiragana_replacements[QString::fromUtf8("shi")] = QString::fromUtf8("し");
        hiragana_replacements[QString::fromUtf8("si")] = QString::fromUtf8("し");
        hiragana_replacements[QString::fromUtf8("su")] = QString::fromUtf8("す");
        hiragana_replacements[QString::fromUtf8("se")] = QString::fromUtf8("せ");
        hiragana_replacements[QString::fromUtf8("so")] = QString::fromUtf8("そ");

        hiragana_replacements[QString::fromUtf8("sya")] = QString::fromUtf8("しゃ");
        hiragana_replacements[QString::fromUtf8("syu")] = QString::fromUtf8("しゅ");
        hiragana_replacements[QString::fromUtf8("syo")] = QString::fromUtf8("しょ");

        hiragana_replacements[QString::fromUtf8("za")] = QString::fromUtf8("ざ");
        hiragana_replacements[QString::fromUtf8("zi")] = QString::fromUtf8("じ");
        hiragana_replacements[QString::fromUtf8("zu")] = QString::fromUtf8("ず");
        hiragana_replacements[QString::fromUtf8("ze")] = QString::fromUtf8("ぜ");
        hiragana_replacements[QString::fromUtf8("zo")] = QString::fromUtf8("ぞ");

        hiragana_replacements[QString::fromUtf8("zya")] = QString::fromUtf8("じゃ");
        hiragana_replacements[QString::fromUtf8("zyu")] = QString::fromUtf8("じゅ");
        hiragana_replacements[QString::fromUtf8("zyo")] = QString::fromUtf8("じょ");

        hiragana_replacements[QString::fromUtf8("ta")] = QString::fromUtf8("た");
        hiragana_replacements[QString::fromUtf8("ti")] = QString::fromUtf8("ち");
        hiragana_replacements[QString::fromUtf8("chi")] = QString::fromUtf8("ち");
        hiragana_replacements[QString::fromUtf8("tsu")] = QString::fromUtf8("つ");
        hiragana_replacements[QString::fromUtf8("te")] = QString::fromUtf8("て");
        hiragana_replacements[QString::fromUtf8("to")] = QString::fromUtf8("と");

        hiragana_replacements[QString::fromUtf8("tya")] = QString::fromUtf8("ちゃ");
        hiragana_replacements[QString::fromUtf8("tyu")] = QString::fromUtf8("ちゅ");
        hiragana_replacements[QString::fromUtf8("chya")] = QString::fromUtf8("ちゃ");
        hiragana_replacements[QString::fromUtf8("chu")] = QString::fromUtf8("ちゅ");
        hiragana_replacements[QString::fromUtf8("chyo")] = QString::fromUtf8("ちょ");
        katakana_replacements[QString::fromUtf8("tyo")] = QString::fromUtf8("ちょ");

        hiragana_replacements[QString::fromUtf8("da")] = QString::fromUtf8("だ");
        hiragana_replacements[QString::fromUtf8("ji")] = QString::fromUtf8("ぢ");
        hiragana_replacements[QString::fromUtf8("di")] = QString::fromUtf8("ぢ");
        hiragana_replacements[QString::fromUtf8("ju")] = QString::fromUtf8("づ");
        hiragana_replacements[QString::fromUtf8("de")] = QString::fromUtf8("で");
        hiragana_replacements[QString::fromUtf8("do")] = QString::fromUtf8("ど");

        hiragana_replacements[QString::fromUtf8("dya")] = QString::fromUtf8("ぢゃ");
        hiragana_replacements[QString::fromUtf8("dyu")] = QString::fromUtf8("ぢゅ");
        hiragana_replacements[QString::fromUtf8("dyo")] = QString::fromUtf8("ぢょ");

        hiragana_replacements[QString::fromUtf8("na")] = QString::fromUtf8("な");
        hiragana_replacements[QString::fromUtf8("ni")] = QString::fromUtf8("に");
        hiragana_replacements[QString::fromUtf8("nu")] = QString::fromUtf8("ぬ");
        hiragana_replacements[QString::fromUtf8("ne")] = QString::fromUtf8("ね");
        hiragana_replacements[QString::fromUtf8("no")] = QString::fromUtf8("の");

        hiragana_replacements[QString::fromUtf8("nya")] = QString::fromUtf8("にゃ");
        hiragana_replacements[QString::fromUtf8("nyu")] = QString::fromUtf8("にゅ");
        hiragana_replacements[QString::fromUtf8("nyo")] = QString::fromUtf8("にょ");

        hiragana_replacements[QString::fromUtf8("ha")] = QString::fromUtf8("は");
        hiragana_replacements[QString::fromUtf8("hi")] = QString::fromUtf8("ひ");
        hiragana_replacements[QString::fromUtf8("hu")] = QString::fromUtf8("ふ");
        hiragana_replacements[QString::fromUtf8("fu")] = QString::fromUtf8("ふ");
        hiragana_replacements[QString::fromUtf8("he")] = QString::fromUtf8("へ");
        hiragana_replacements[QString::fromUtf8("ho")] = QString::fromUtf8("ほ");

        hiragana_replacements[QString::fromUtf8("hya")] = QString::fromUtf8("ひゃ");
        hiragana_replacements[QString::fromUtf8("hyu")] = QString::fromUtf8("ひゅ");
        hiragana_replacements[QString::fromUtf8("hyo")] = QString::fromUtf8("ひょ");

        hiragana_replacements[QString::fromUtf8("pa")] = QString::fromUtf8("ぱ");
        hiragana_replacements[QString::fromUtf8("pi")] = QString::fromUtf8("ぴ");
        hiragana_replacements[QString::fromUtf8("pu")] = QString::fromUtf8("ぷ");
        hiragana_replacements[QString::fromUtf8("pe")] = QString::fromUtf8("ぺ");
        hiragana_replacements[QString::fromUtf8("po")] = QString::fromUtf8("ぽ");

        hiragana_replacements[QString::fromUtf8("pya")] = QString::fromUtf8("ぴゃ");
        hiragana_replacements[QString::fromUtf8("pyu")] = QString::fromUtf8("ぴゅ");
        hiragana_replacements[QString::fromUtf8("pyo")] = QString::fromUtf8("ぴょ");

        hiragana_replacements[QString::fromUtf8("ba")] = QString::fromUtf8("ば");
        hiragana_replacements[QString::fromUtf8("bi")] = QString::fromUtf8("び");
        hiragana_replacements[QString::fromUtf8("bu")] = QString::fromUtf8("ぶ");
        hiragana_replacements[QString::fromUtf8("be")] = QString::fromUtf8("べ");
        hiragana_replacements[QString::fromUtf8("bo")] = QString::fromUtf8("ぼ");

        hiragana_replacements[QString::fromUtf8("bya")] = QString::fromUtf8("びゃ");
        hiragana_replacements[QString::fromUtf8("byu")] = QString::fromUtf8("びゅ");
        hiragana_replacements[QString::fromUtf8("byo")] = QString::fromUtf8("びょ");

        hiragana_replacements[QString::fromUtf8("ma")] = QString::fromUtf8("ま");
        hiragana_replacements[QString::fromUtf8("mi")] = QString::fromUtf8("み");
        hiragana_replacements[QString::fromUtf8("mu")] = QString::fromUtf8("む");
        hiragana_replacements[QString::fromUtf8("me")] = QString::fromUtf8("め");
        hiragana_replacements[QString::fromUtf8("mo")] = QString::fromUtf8("も");

        hiragana_replacements[QString::fromUtf8("mya")] = QString::fromUtf8("みゃ");
        hiragana_replacements[QString::fromUtf8("myu")] = QString::fromUtf8("みゅ");
        hiragana_replacements[QString::fromUtf8("myo")] = QString::fromUtf8("みょ");

        hiragana_replacements[QString::fromUtf8("ya")] = QString::fromUtf8("や");
        hiragana_replacements[QString::fromUtf8("yu")] = QString::fromUtf8("ゆ");
        hiragana_replacements[QString::fromUtf8("yo")] = QString::fromUtf8("よ");

        hiragana_replacements[QString::fromUtf8("ra")] = QString::fromUtf8("ら");
        hiragana_replacements[QString::fromUtf8("ri")] = QString::fromUtf8("り");
        hiragana_replacements[QString::fromUtf8("ru")] = QString::fromUtf8("る");
        hiragana_replacements[QString::fromUtf8("re")] = QString::fromUtf8("れ");
        hiragana_replacements[QString::fromUtf8("ro")] = QString::fromUtf8("ろ");

        hiragana_replacements[QString::fromUtf8("rya")] = QString::fromUtf8("りゃ");
        hiragana_replacements[QString::fromUtf8("ryu")] = QString::fromUtf8("りゅ");
        hiragana_replacements[QString::fromUtf8("ryo")] = QString::fromUtf8("りょ");

        hiragana_replacements[QString::fromUtf8("wa")] = QString::fromUtf8("わ");
        hiragana_replacements[QString::fromUtf8("wo")] = QString::fromUtf8("を");
        hiragana_replacements[QString::fromUtf8("n")] = QString::fromUtf8("ん");


        katakana_replacements[QString::fromUtf8("а")] = QString::fromUtf8("ア");
        katakana_replacements[QString::fromUtf8("и")] = QString::fromUtf8("イ");
        katakana_replacements[QString::fromUtf8("й")] = QString::fromUtf8("イ");
        katakana_replacements[QString::fromUtf8("у")] = QString::fromUtf8("ウ");
        katakana_replacements[QString::fromUtf8("э")] = QString::fromUtf8("エ");
        katakana_replacements[QString::fromUtf8("е")] = QString::fromUtf8("エ");
        katakana_replacements[QString::fromUtf8("о")] = QString::fromUtf8("オ");

        katakana_replacements[QString::fromUtf8("ка")] = QString::fromUtf8("カ");
        katakana_replacements[QString::fromUtf8("ки")] = QString::fromUtf8("キ");
        katakana_replacements[QString::fromUtf8("ку")] = QString::fromUtf8("ク");
        katakana_replacements[QString::fromUtf8("кэ")] = QString::fromUtf8("ケ");
        katakana_replacements[QString::fromUtf8("ке")] = QString::fromUtf8("ケ");
        katakana_replacements[QString::fromUtf8("ко")] = QString::fromUtf8("コ");

        katakana_replacements[QString::fromUtf8("кя")] = QString::fromUtf8("キャ");
        katakana_replacements[QString::fromUtf8("кю")] = QString::fromUtf8("キュ");
        katakana_replacements[QString::fromUtf8("кё")] = QString::fromUtf8("キョ");

        katakana_replacements[QString::fromUtf8("га")] = QString::fromUtf8("ガ");
        katakana_replacements[QString::fromUtf8("ги")] = QString::fromUtf8("ギ");
        katakana_replacements[QString::fromUtf8("гу")] = QString::fromUtf8("グ");
        katakana_replacements[QString::fromUtf8("гэ")] = QString::fromUtf8("ゲ");
        katakana_replacements[QString::fromUtf8("ге")] = QString::fromUtf8("ゲ");
        katakana_replacements[QString::fromUtf8("го")] = QString::fromUtf8("ゴ");

        katakana_replacements[QString::fromUtf8("гя")] = QString::fromUtf8("ギャ");
        katakana_replacements[QString::fromUtf8("гю")] = QString::fromUtf8("ギュ");
        katakana_replacements[QString::fromUtf8("гё")] = QString::fromUtf8("ギョ");

        katakana_replacements[QString::fromUtf8("са")] = QString::fromUtf8("サ");
        katakana_replacements[QString::fromUtf8("си")] = QString::fromUtf8("シ");
        katakana_replacements[QString::fromUtf8("ши")] = QString::fromUtf8("シ");
        katakana_replacements[QString::fromUtf8("щи")] = QString::fromUtf8("シ");
        katakana_replacements[QString::fromUtf8("су")] = QString::fromUtf8("ス");
        katakana_replacements[QString::fromUtf8("сэ")] = QString::fromUtf8("セ");
        katakana_replacements[QString::fromUtf8("се")] = QString::fromUtf8("セ");
        katakana_replacements[QString::fromUtf8("со")] = QString::fromUtf8("ソ");

        katakana_replacements[QString::fromUtf8("ся")] = QString::fromUtf8("シャ");
        katakana_replacements[QString::fromUtf8("сю")] = QString::fromUtf8("シュ");
        katakana_replacements[QString::fromUtf8("сё")] = QString::fromUtf8("ショ");

        katakana_replacements[QString::fromUtf8("за")] = QString::fromUtf8("ザ");
        katakana_replacements[QString::fromUtf8("зи")] = QString::fromUtf8("ジ");
        katakana_replacements[QString::fromUtf8("жи")] = QString::fromUtf8("ジ");
        katakana_replacements[QString::fromUtf8("зу")] = QString::fromUtf8("ズ");
        katakana_replacements[QString::fromUtf8("зэ")] = QString::fromUtf8("ゼ");
        katakana_replacements[QString::fromUtf8("зе")] = QString::fromUtf8("ゼ");
        katakana_replacements[QString::fromUtf8("зо")] = QString::fromUtf8("ゾ");

        katakana_replacements[QString::fromUtf8("зя")] = QString::fromUtf8("ジャ");
        katakana_replacements[QString::fromUtf8("зю")] = QString::fromUtf8("ジュ");
        katakana_replacements[QString::fromUtf8("зё")] = QString::fromUtf8("ジョ");

        katakana_replacements[QString::fromUtf8("та")] = QString::fromUtf8("タ");
        katakana_replacements[QString::fromUtf8("ти")] = QString::fromUtf8("チ");
        katakana_replacements[QString::fromUtf8("чи")] = QString::fromUtf8("チ");
        katakana_replacements[QString::fromUtf8("ту")] = QString::fromUtf8("ツ");
        katakana_replacements[QString::fromUtf8("цу")] = QString::fromUtf8("ツ");
        katakana_replacements[QString::fromUtf8("тэ")] = QString::fromUtf8("テ");
        katakana_replacements[QString::fromUtf8("те")] = QString::fromUtf8("テ");
        katakana_replacements[QString::fromUtf8("то")] = QString::fromUtf8("ト");

        katakana_replacements[QString::fromUtf8("чя")] = QString::fromUtf8("チャ");
        katakana_replacements[QString::fromUtf8("чу")] = QString::fromUtf8("チュ");
        katakana_replacements[QString::fromUtf8("тя")] = QString::fromUtf8("チャ");
        katakana_replacements[QString::fromUtf8("тю")] = QString::fromUtf8("チュ");
        katakana_replacements[QString::fromUtf8("чё")] = QString::fromUtf8("チョ");
        katakana_replacements[QString::fromUtf8("тё")] = QString::fromUtf8("チョ");

        katakana_replacements[QString::fromUtf8("да")] = QString::fromUtf8("ダ");
        katakana_replacements[QString::fromUtf8("ди")] = QString::fromUtf8("ヂ");
        katakana_replacements[QString::fromUtf8("ду")] = QString::fromUtf8("ヅ");
        katakana_replacements[QString::fromUtf8("дэ")] = QString::fromUtf8("デ");
        katakana_replacements[QString::fromUtf8("де")] = QString::fromUtf8("デ");
        katakana_replacements[QString::fromUtf8("до")] = QString::fromUtf8("ド");

        katakana_replacements[QString::fromUtf8("дя")] = QString::fromUtf8("ヂャ");
        katakana_replacements[QString::fromUtf8("дю")] = QString::fromUtf8("ヂュ");
        katakana_replacements[QString::fromUtf8("дё")] = QString::fromUtf8("ヂョ");

        katakana_replacements[QString::fromUtf8("на")] = QString::fromUtf8("ナ");
        katakana_replacements[QString::fromUtf8("ни")] = QString::fromUtf8("ニ");
        katakana_replacements[QString::fromUtf8("ну")] = QString::fromUtf8("ヌ");
        katakana_replacements[QString::fromUtf8("нэ")] = QString::fromUtf8("ネ");
        katakana_replacements[QString::fromUtf8("не")] = QString::fromUtf8("ネ");
        katakana_replacements[QString::fromUtf8("но")] = QString::fromUtf8("ノ");

        katakana_replacements[QString::fromUtf8("ня")] = QString::fromUtf8("ニャ");
        katakana_replacements[QString::fromUtf8("ню")] = QString::fromUtf8("ニュ");
        katakana_replacements[QString::fromUtf8("нё")] = QString::fromUtf8("ニョ");

        katakana_replacements[QString::fromUtf8("ха")] = QString::fromUtf8("ハ");
        katakana_replacements[QString::fromUtf8("хи")] = QString::fromUtf8("ヒ");
        katakana_replacements[QString::fromUtf8("ху")] = QString::fromUtf8("フ");
        katakana_replacements[QString::fromUtf8("фу")] = QString::fromUtf8("フ");
        katakana_replacements[QString::fromUtf8("хэ")] = QString::fromUtf8("ヘ");
        katakana_replacements[QString::fromUtf8("хе")] = QString::fromUtf8("ヘ");
        katakana_replacements[QString::fromUtf8("хо")] = QString::fromUtf8("ホ");

        katakana_replacements[QString::fromUtf8("хя")] = QString::fromUtf8("ヒャ");
        katakana_replacements[QString::fromUtf8("хю")] = QString::fromUtf8("ヒュ");
        katakana_replacements[QString::fromUtf8("хё")] = QString::fromUtf8("ヒョ");

        katakana_replacements[QString::fromUtf8("па")] = QString::fromUtf8("パ");
        katakana_replacements[QString::fromUtf8("пи")] = QString::fromUtf8("ピ");
        katakana_replacements[QString::fromUtf8("пу")] = QString::fromUtf8("プ");
        katakana_replacements[QString::fromUtf8("пэ")] = QString::fromUtf8("ペ");
        katakana_replacements[QString::fromUtf8("пе")] = QString::fromUtf8("ペ");
        katakana_replacements[QString::fromUtf8("по")] = QString::fromUtf8("ポ");

        katakana_replacements[QString::fromUtf8("пя")] = QString::fromUtf8("ピャ");
        katakana_replacements[QString::fromUtf8("пю")] = QString::fromUtf8("ピュ");
        katakana_replacements[QString::fromUtf8("пё")] = QString::fromUtf8("ピョ");

        katakana_replacements[QString::fromUtf8("ба")] = QString::fromUtf8("バ");
        katakana_replacements[QString::fromUtf8("би")] = QString::fromUtf8("ビ");
        katakana_replacements[QString::fromUtf8("бу")] = QString::fromUtf8("ブ");
        katakana_replacements[QString::fromUtf8("бэ")] = QString::fromUtf8("ベ");
        katakana_replacements[QString::fromUtf8("бе")] = QString::fromUtf8("ベ");
        katakana_replacements[QString::fromUtf8("бо")] = QString::fromUtf8("ボ");

        katakana_replacements[QString::fromUtf8("бя")] = QString::fromUtf8("ビャ");
        katakana_replacements[QString::fromUtf8("бю")] = QString::fromUtf8("ビュ");
        katakana_replacements[QString::fromUtf8("бё")] = QString::fromUtf8("ビョ");

        katakana_replacements[QString::fromUtf8("ма")] = QString::fromUtf8("マ");
        katakana_replacements[QString::fromUtf8("ми")] = QString::fromUtf8("ミ");
        katakana_replacements[QString::fromUtf8("му")] = QString::fromUtf8("ム");
        katakana_replacements[QString::fromUtf8("мэ")] = QString::fromUtf8("メ");
        katakana_replacements[QString::fromUtf8("ме")] = QString::fromUtf8("メ");
        katakana_replacements[QString::fromUtf8("мо")] = QString::fromUtf8("モ");

        katakana_replacements[QString::fromUtf8("мя")] = QString::fromUtf8("ミャ");
        katakana_replacements[QString::fromUtf8("мю")] = QString::fromUtf8("ミュ");
        katakana_replacements[QString::fromUtf8("мё")] = QString::fromUtf8("ミョ");

        katakana_replacements[QString::fromUtf8("я")] = QString::fromUtf8("ヤ");
        katakana_replacements[QString::fromUtf8("ю")] = QString::fromUtf8("ユ");
        katakana_replacements[QString::fromUtf8("ё")] = QString::fromUtf8("ヨ");
        katakana_replacements[QString::fromUtf8("йо")] = QString::fromUtf8("ヨ");

        katakana_replacements[QString::fromUtf8("ра")] = QString::fromUtf8("ラ");
        katakana_replacements[QString::fromUtf8("ри")] = QString::fromUtf8("リ");
        katakana_replacements[QString::fromUtf8("ру")] = QString::fromUtf8("ル");
        katakana_replacements[QString::fromUtf8("рэ")] = QString::fromUtf8("レ");
        katakana_replacements[QString::fromUtf8("ре")] = QString::fromUtf8("レ");
        katakana_replacements[QString::fromUtf8("ро")] = QString::fromUtf8("ロ");

        katakana_replacements[QString::fromUtf8("ря")] = QString::fromUtf8("リャ");
        katakana_replacements[QString::fromUtf8("рю")] = QString::fromUtf8("リュ");
        katakana_replacements[QString::fromUtf8("рё")] = QString::fromUtf8("リョ");

        katakana_replacements[QString::fromUtf8("ва")] = QString::fromUtf8("ワ");
        katakana_replacements[QString::fromUtf8("во")] = QString::fromUtf8("ヲ");
        katakana_replacements[QString::fromUtf8("н")] = QString::fromUtf8("ン");


        katakana_replacements[QString::fromUtf8("a")] = QString::fromUtf8("ア");
        katakana_replacements[QString::fromUtf8("i")] = QString::fromUtf8("イ");
        katakana_replacements[QString::fromUtf8("u")] = QString::fromUtf8("ウ");
        katakana_replacements[QString::fromUtf8("e")] = QString::fromUtf8("エ");
        katakana_replacements[QString::fromUtf8("o")] = QString::fromUtf8("オ");

        katakana_replacements[QString::fromUtf8("ka")] = QString::fromUtf8("カ");
        katakana_replacements[QString::fromUtf8("ki")] = QString::fromUtf8("キ");
        katakana_replacements[QString::fromUtf8("ku")] = QString::fromUtf8("ク");
        katakana_replacements[QString::fromUtf8("ke")] = QString::fromUtf8("ケ");
        katakana_replacements[QString::fromUtf8("ko")] = QString::fromUtf8("コ");

        katakana_replacements[QString::fromUtf8("kya")] = QString::fromUtf8("キャ");
        katakana_replacements[QString::fromUtf8("kyu")] = QString::fromUtf8("キュ");
        katakana_replacements[QString::fromUtf8("kyo")] = QString::fromUtf8("キョ");

        katakana_replacements[QString::fromUtf8("ga")] = QString::fromUtf8("ガ");
        katakana_replacements[QString::fromUtf8("gi")] = QString::fromUtf8("ギ");
        katakana_replacements[QString::fromUtf8("gu")] = QString::fromUtf8("グ");
        katakana_replacements[QString::fromUtf8("ge")] = QString::fromUtf8("ゲ");
        katakana_replacements[QString::fromUtf8("go")] = QString::fromUtf8("ゴ");

        katakana_replacements[QString::fromUtf8("gya")] = QString::fromUtf8("ギャ");
        katakana_replacements[QString::fromUtf8("gyu")] = QString::fromUtf8("ギュ");
        katakana_replacements[QString::fromUtf8("gyo")] = QString::fromUtf8("ギョ");

        katakana_replacements[QString::fromUtf8("sa")] = QString::fromUtf8("サ");
        katakana_replacements[QString::fromUtf8("shi")] = QString::fromUtf8("シ");
        katakana_replacements[QString::fromUtf8("si")] = QString::fromUtf8("シ");
        katakana_replacements[QString::fromUtf8("su")] = QString::fromUtf8("ス");
        katakana_replacements[QString::fromUtf8("se")] = QString::fromUtf8("セ");
        katakana_replacements[QString::fromUtf8("so")] = QString::fromUtf8("ソ");

        katakana_replacements[QString::fromUtf8("sya")] = QString::fromUtf8("シャ");
        katakana_replacements[QString::fromUtf8("syu")] = QString::fromUtf8("シュ");
        katakana_replacements[QString::fromUtf8("syo")] = QString::fromUtf8("ショ");

        katakana_replacements[QString::fromUtf8("za")] = QString::fromUtf8("ザ");
        katakana_replacements[QString::fromUtf8("zi")] = QString::fromUtf8("ジ");
        katakana_replacements[QString::fromUtf8("zu")] = QString::fromUtf8("ズ");
        katakana_replacements[QString::fromUtf8("ze")] = QString::fromUtf8("ゼ");
        katakana_replacements[QString::fromUtf8("zo")] = QString::fromUtf8("ゾ");

        katakana_replacements[QString::fromUtf8("zya")] = QString::fromUtf8("ジャ");
        katakana_replacements[QString::fromUtf8("zyu")] = QString::fromUtf8("ジュ");
        katakana_replacements[QString::fromUtf8("zyo")] = QString::fromUtf8("ジョ");

        katakana_replacements[QString::fromUtf8("ta")] = QString::fromUtf8("タ");
        katakana_replacements[QString::fromUtf8("ti")] = QString::fromUtf8("チ");
        katakana_replacements[QString::fromUtf8("chi")] = QString::fromUtf8("チ");
        katakana_replacements[QString::fromUtf8("tu")] = QString::fromUtf8("ツ");
        katakana_replacements[QString::fromUtf8("tsu")] = QString::fromUtf8("ツ");
        katakana_replacements[QString::fromUtf8("te")] = QString::fromUtf8("テ");
        katakana_replacements[QString::fromUtf8("to")] = QString::fromUtf8("ト");

        katakana_replacements[QString::fromUtf8("chya")] = QString::fromUtf8("チャ");
        katakana_replacements[QString::fromUtf8("chu")] = QString::fromUtf8("チュ");
        katakana_replacements[QString::fromUtf8("chyo")] = QString::fromUtf8("チョ");

        katakana_replacements[QString::fromUtf8("da")] = QString::fromUtf8("ダ");
        katakana_replacements[QString::fromUtf8("ji")] = QString::fromUtf8("ヂ");
        katakana_replacements[QString::fromUtf8("di")] = QString::fromUtf8("ヂ");
        katakana_replacements[QString::fromUtf8("ju")] = QString::fromUtf8("ヅ");
        katakana_replacements[QString::fromUtf8("de")] = QString::fromUtf8("デ");
        katakana_replacements[QString::fromUtf8("do")] = QString::fromUtf8("ド");

        katakana_replacements[QString::fromUtf8("dya")] = QString::fromUtf8("ヂャ");
        katakana_replacements[QString::fromUtf8("dyu")] = QString::fromUtf8("ヂュ");
        katakana_replacements[QString::fromUtf8("dyo")] = QString::fromUtf8("ヂョ");

        katakana_replacements[QString::fromUtf8("na")] = QString::fromUtf8("ナ");
        katakana_replacements[QString::fromUtf8("ni")] = QString::fromUtf8("ニ");
        katakana_replacements[QString::fromUtf8("nu")] = QString::fromUtf8("ヌ");
        katakana_replacements[QString::fromUtf8("ne")] = QString::fromUtf8("ネ");
        katakana_replacements[QString::fromUtf8("no")] = QString::fromUtf8("ノ");

        katakana_replacements[QString::fromUtf8("nya")] = QString::fromUtf8("ニャ");
        katakana_replacements[QString::fromUtf8("nyu")] = QString::fromUtf8("ニュ");
        katakana_replacements[QString::fromUtf8("nyo")] = QString::fromUtf8("ニョ");

        katakana_replacements[QString::fromUtf8("ha")] = QString::fromUtf8("ハ");
        katakana_replacements[QString::fromUtf8("hi")] = QString::fromUtf8("ヒ");
        katakana_replacements[QString::fromUtf8("hu")] = QString::fromUtf8("フ");
        katakana_replacements[QString::fromUtf8("fu")] = QString::fromUtf8("フ");
        katakana_replacements[QString::fromUtf8("he")] = QString::fromUtf8("ヘ");
        katakana_replacements[QString::fromUtf8("ho")] = QString::fromUtf8("ホ");

        katakana_replacements[QString::fromUtf8("hya")] = QString::fromUtf8("ヒャ");
        katakana_replacements[QString::fromUtf8("hyu")] = QString::fromUtf8("ヒュ");
        katakana_replacements[QString::fromUtf8("hyo")] = QString::fromUtf8("ヒョ");

        katakana_replacements[QString::fromUtf8("pa")] = QString::fromUtf8("パ");
        katakana_replacements[QString::fromUtf8("pi")] = QString::fromUtf8("ピ");
        katakana_replacements[QString::fromUtf8("pu")] = QString::fromUtf8("プ");
        katakana_replacements[QString::fromUtf8("pe")] = QString::fromUtf8("ペ");
        katakana_replacements[QString::fromUtf8("po")] = QString::fromUtf8("ポ");

        katakana_replacements[QString::fromUtf8("pya")] = QString::fromUtf8("ピャ");
        katakana_replacements[QString::fromUtf8("pyu")] = QString::fromUtf8("ピュ");
        katakana_replacements[QString::fromUtf8("pyo")] = QString::fromUtf8("ピョ");

        katakana_replacements[QString::fromUtf8("ba")] = QString::fromUtf8("バ");
        katakana_replacements[QString::fromUtf8("bi")] = QString::fromUtf8("ビ");
        katakana_replacements[QString::fromUtf8("bu")] = QString::fromUtf8("ブ");
        katakana_replacements[QString::fromUtf8("be")] = QString::fromUtf8("ベ");
        katakana_replacements[QString::fromUtf8("bo")] = QString::fromUtf8("ボ");

        katakana_replacements[QString::fromUtf8("bya")] = QString::fromUtf8("ビャ");
        katakana_replacements[QString::fromUtf8("byu")] = QString::fromUtf8("ビュ");
        katakana_replacements[QString::fromUtf8("byo")] = QString::fromUtf8("ビョ");

        katakana_replacements[QString::fromUtf8("ma")] = QString::fromUtf8("マ");
        katakana_replacements[QString::fromUtf8("mi")] = QString::fromUtf8("ミ");
        katakana_replacements[QString::fromUtf8("mu")] = QString::fromUtf8("ム");
        katakana_replacements[QString::fromUtf8("me")] = QString::fromUtf8("メ");
        katakana_replacements[QString::fromUtf8("mo")] = QString::fromUtf8("モ");

        katakana_replacements[QString::fromUtf8("mya")] = QString::fromUtf8("ミャ");
        katakana_replacements[QString::fromUtf8("myu")] = QString::fromUtf8("ミュ");
        katakana_replacements[QString::fromUtf8("myo")] = QString::fromUtf8("ミョ");

        katakana_replacements[QString::fromUtf8("ya")] = QString::fromUtf8("ヤ");
        katakana_replacements[QString::fromUtf8("yu")] = QString::fromUtf8("ユ");
        katakana_replacements[QString::fromUtf8("yo")] = QString::fromUtf8("ヨ");

        katakana_replacements[QString::fromUtf8("ra")] = QString::fromUtf8("ラ");
        katakana_replacements[QString::fromUtf8("ri")] = QString::fromUtf8("リ");
        katakana_replacements[QString::fromUtf8("ru")] = QString::fromUtf8("ル");
        katakana_replacements[QString::fromUtf8("re")] = QString::fromUtf8("レ");
        katakana_replacements[QString::fromUtf8("ro")] = QString::fromUtf8("ロ");

        katakana_replacements[QString::fromUtf8("rya")] = QString::fromUtf8("リャ");
        katakana_replacements[QString::fromUtf8("ryu")] = QString::fromUtf8("リュ");
        katakana_replacements[QString::fromUtf8("ryo")] = QString::fromUtf8("リョ");

        katakana_replacements[QString::fromUtf8("wa")] = QString::fromUtf8("ワ");
        katakana_replacements[QString::fromUtf8("wo")] = QString::fromUtf8("ヲ");
        katakana_replacements[QString::fromUtf8("n")] = QString::fromUtf8("ン");}

QString Converter::Convert(const QString source, ConvertMode mode)
{
    QString result;
    int currentIndex = 0;
    for(int i=0; i < source.length()-3; i++)
    {
        int amount = 0;
        QString converted = ConvertTrigramm(source[i], source[i+1], source[i+2], amount, mode);
        if(converted != "")
        {
            result+=converted;
            i+=amount;
            currentIndex+=amount;
        }
        else
        {
            result+=source[i];
            result+=source[i+1];
            result+=source[i+2];
            i+=2;
            currentIndex+=2;
        }
        currentIndex++;
    }
    int dist = source.length() - currentIndex;
    if(dist == 3)
    {
        int unneeded = 0;
        QString ps = ConvertTrigramm(source[currentIndex], source[currentIndex+1], source[currentIndex+2], unneeded, mode);
        if(ps !="")
            result+=ps;
        else
        {
            result+=source[currentIndex];
            result+=source[currentIndex+1];
            result+=source[currentIndex+2];
        }
    }
    if(dist == 2)
    {
        QString pattern = source[currentIndex];
        pattern +=  source[currentIndex+1];
        QString ps = ConvertPattern(pattern, mode);
        if(ps !="")
            result+=ps;
        else
        {
            result+=source[currentIndex];
            result+=source[currentIndex+1];
        }
    }
    if(dist == 1)
    {
        QString pattern = source[currentIndex];
        QString ps = ConvertPattern(pattern, mode);
        if(ps !="")
            result+=ps;
        else
        {
            result+=source[currentIndex];
        }
    }
    return result;
}

QString Converter::ConvertTrigramm(QChar one, QChar two, QChar three, int &amount, ConvertMode mode)
{
    QString result = "";
    QString trigramm = "";
    trigramm += one.toLower();
    trigramm += two.toLower();
    trigramm += three.toLower();

    QString convertedTrigramm = ConvertPattern(trigramm, mode);
    if(convertedTrigramm != "")
    {
        result = convertedTrigramm;
        amount = 2;
        return result;
    }

    QString dugramm = "";
    dugramm += one.toLower();
    dugramm += two.toLower();

    QString convertedDugramm = ConvertPattern(dugramm, mode);
    if(convertedDugramm != "")
    {
        result = convertedDugramm;
        amount=1;
        return result;
    }

    QString currentSymbol = one.toLower();
    QString convertedSymbol = ConvertPattern(currentSymbol, mode);
    if(convertedSymbol != "")
    {
        result = convertedSymbol;
    }
    return result;
}

QString Converter::ConvertPattern(QString pattern, ConvertMode mode)
{
    if(mode == (HiraganaMode|KatakanaMode))
    {
        bool rand = qrand()%2;
        if(rand)
        {
            return FindKatakanaByPattern(pattern);
        }
        return FindHiraganaByPattern(pattern);
    }
    if(mode == HiraganaMode)
    {
        return FindHiraganaByPattern(pattern);
    }

    if(mode == KatakanaMode)
    {
        return FindKatakanaByPattern(pattern);
    }
    return "";
}

QString Converter::FindHiraganaByPattern(QString pattern)
{
    bool rand = qrand()%2;
    if(!rand)
        return "";
    QMap<QString, QString>::const_iterator i = hiragana_replacements.constBegin();
    while (i != hiragana_replacements.constEnd()) {
        if(i.key() == pattern)
            return i.value();
        ++i;
    }
    return "";
}

QString Converter::FindKatakanaByPattern(QString pattern)
{
    bool rand = qrand()%2;
    if(!rand)
        return "";
    QMap<QString, QString>::const_iterator i = katakana_replacements.constBegin();
    while (i != katakana_replacements.constEnd()) {
        if(i.key() == pattern)
            return i.value();
        ++i;
    }
    return "";
}
