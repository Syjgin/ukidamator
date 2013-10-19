#include <QErrorMessage>
#include <QClipboard>
#include <QMimeData>
#include <QApplication>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "programwindow.h"
#include "ui_programwindow.h"
#include <QTime>

const char *EMPTY_TEXT_ERROR = "No text to save found";
const char *SAVE_CAPTION = "Where you want to save yukidama?";

ProgramWindow::ProgramWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProgramWindow)
{
    ui->setupUi(this);
    _pasteShortcut = new QShortcut(QKeySequence::Save, this, SLOT(on_saveButton_clicked()), SLOT(on_saveButton_clicked()), Qt::ApplicationShortcut);
    _exitShortcut = new QShortcut(QKeySequence(Qt::Key_Escape), this, SLOT(on_closeButton_clicked()), SLOT(on_closeButton_clicked()), Qt::ApplicationShortcut);
    _converter = new Converter(this);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
}

ProgramWindow::~ProgramWindow()
{
    delete ui;
}

void ProgramWindow::on_closeButton_clicked()
{
    this->close();
}

void ProgramWindow::on_saveButton_clicked()
{
    QString textToSave = ui->textEdit->toPlainText();
    if(textToSave.isEmpty())
    {
        QErrorMessage *emptyTextErrorDialog = new QErrorMessage(this);
        emptyTextErrorDialog->showMessage(tr(EMPTY_TEXT_ERROR));
        return;
    }
    QString fileName = QFileDialog::getSaveFileName(this, SAVE_CAPTION, "", tr("Text Files (*.txt);;All Files (*)"));
    QFile output(fileName);
    output.open(QIODevice::WriteOnly);
    QTextStream outStream(&output);
    outStream << textToSave;
    output.close();
}

void ProgramWindow::on_pasteButton_clicked()
{
    const QClipboard *clipboard = QApplication::clipboard();
    if(clipboard->mimeData()->hasText())
        ui->textEdit->setText(clipboard->text());
}

void ProgramWindow::on_copyButton_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    QString textToSave = ui->textEdit->toPlainText();
    if(!textToSave.isEmpty())
        clipboard->setText(textToSave);
}

void ProgramWindow::on_ukidamateButton_clicked()
{
    int possibility = ui->chanceSlider->value();
    QString textToChange = ui->textEdit->toPlainText();
    if(!textToChange.isEmpty() && textToChange.length() > 3)
    {
        int mode = Converter::Nothing;
        if(ui->hiraganaCheckBox->isChecked())
            mode += Converter::HiraganaMode;
        if(ui->katakanaCheckBox->isChecked())
            mode += Converter::KatakanaMode;
        if(mode != Converter::Nothing)
        {
            _converter->SetConvertMode((Converter::ConvertMode)mode);
            _converter->SetPossibility(possibility);
            QString result = _converter->Convert(textToChange);
            ui->textEdit->setText(result);
        }
    }
}
