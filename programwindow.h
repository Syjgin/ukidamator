#ifndef PROGRAMWINDOW_H
#define PROGRAMWINDOW_H

#include <QMainWindow>
#include <QShortcut>
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

    void on_saveButton_clicked();

    void on_pasteButton_clicked();

    void on_copyButton_clicked();

    void on_ukidamateButton_clicked();

private:
    Ui::ProgramWindow *ui;
    QShortcut *_pasteShortcut;
    QShortcut *_exitShortcut;
    Converter *_converter;
};

#endif // PROGRAMWINDOW_H
