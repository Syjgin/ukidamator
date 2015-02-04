#ifndef PROGRAMWINDOW_H
#define PROGRAMWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QMainWindow>
#include <QShortcut>
#include <QSettings>
#include "converter.h"

namespace Ui {
class ProgramWindow;
}

class ProgramWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ProgramWindow(QWidget *parent = 0);
    ~ProgramWindow();
    
private slots:
    void on_closeButton_clicked();

    void on_pasteButton_clicked();

    void on_copyButton_clicked();

    void on_ukidamateButton_clicked();

    void on_chanceSlider_valueChanged(int value);

    void on_textEdit_textChanged();

    void on_action_Open_triggered();

    void on_action_Save_triggered();

    void on_action_Copy_triggered();

    void on_action_Paste_triggered();

    void on_action_Hiragana_triggered();

    void on_action_Katakana_triggered();

    void on_action_Romadzi_triggered();

    void on_action_Kiridzi_triggered();

    void on_action_Close_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionAbout_ukidamator_triggered();

private:
    Ui::ProgramWindow *ui;
    QShortcut *_pasteShortcut;
    QShortcut *_exitShortcut;
    Converter *_converter;
    QSettings *_settings;
};

#endif // PROGRAMWINDOW_H
