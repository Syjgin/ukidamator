#include <QErrorMessage>
#include <QClipboard>
#include <QMimeData>
#include <QApplication>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include "programwindow.h"
#include "ui_programwindow.h"

const char *EMPTY_TEXT_ERROR = "No text to save found";
const char *INCORRECT_FILE = "Incorrect file type";
const char *SAVE_CAPTION = "Where you want to save yukidama?";
const char *OPEN_CAPTION = "Open .txt file";
const char *FILE_TYPE = "Text Files (*.txt);;All Files (*)";

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
    ui->action_Hiragana->setChecked(ui->hiraganaCheckBox->isChecked());
    ui->action_Katakana->setChecked(ui->katakanaCheckBox->isChecked());
    ui->action_Kiridzi->setChecked(ui->kiridziCheckBox->isChecked());
    ui->action_Romadzi->setChecked(ui->romadziCheckBox->isChecked());
}

ProgramWindow::~ProgramWindow()
{
    delete ui;
}

void ProgramWindow::on_closeButton_clicked()
{
    this->close();
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
    QString textToChange = ui->textEdit->toPlainText();
    int possibility = ui->chanceSlider->value();
    int mode = Converter::Nothing;
    if(ui->hiraganaCheckBox->isChecked())
        mode += Converter::HiraganaMode;
    if(ui->katakanaCheckBox->isChecked())
        mode += Converter::KatakanaMode;
    if(mode != Converter::Nothing)
    {
        if(ui->kiridziCheckBox->isChecked())
            mode += Converter::KiridziMode;
        if(ui->romadziCheckBox->isChecked())
            mode += Converter::RomadziMode;
    }
    if(mode != Converter::Nothing)
    {
        _converter->SetConvertMode((Converter::ConvertMode)mode);
        _converter->SetPossibility(possibility);
        QString result = _converter->Convert(textToChange);
        ui->textEdit->setText(result);
    }
}

void ProgramWindow::on_chanceSlider_valueChanged(int value)
{
    ui->possibilityLabel->setText(QString("%1\%").arg(QString::number(value)));
}

void ProgramWindow::on_textEdit_textChanged()
{
    QString textToChange = ui->textEdit->toPlainText();
    if(!textToChange.isEmpty() && textToChange.length() > 3)
    {
        ui->ukidamateButton->setEnabled(true);
    }
    else
        ui->ukidamateButton->setEnabled(false);
}

void ProgramWindow::on_action_Open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr(SAVE_CAPTION), "", tr(FILE_TYPE));
    if(!fileName.endsWith(".txt"))
    {
        QErrorMessage *emptyTextErrorDialog = new QErrorMessage(this);
        emptyTextErrorDialog->showMessage(tr(INCORRECT_FILE));
        return;
    }
    QFile input(fileName);
    input.open(QIODevice::ReadOnly);
    QTextStream fileStream(&input);
    QString fileContent = fileStream.readAll();
    ui->textEdit->setPlainText(fileContent);
}

void ProgramWindow::on_action_Save_triggered()
{
    QString textToSave = ui->textEdit->toPlainText();
    if(textToSave.isEmpty())
    {
        QErrorMessage *emptyTextErrorDialog = new QErrorMessage(this);
        emptyTextErrorDialog->showMessage(tr(EMPTY_TEXT_ERROR));
        return;
    }
    QString fileName = QFileDialog::getSaveFileName(this, tr(SAVE_CAPTION), "", tr(FILE_TYPE));
    QFile output(fileName);
    output.open(QIODevice::WriteOnly);
    QTextStream outStream(&output);
    outStream << textToSave;
    output.close();
}

void ProgramWindow::on_action_Copy_triggered()
{
    on_copyButton_clicked();
}

void ProgramWindow::on_action_Paste_triggered()
{
    on_pasteButton_clicked();
}

void ProgramWindow::on_action_Hiragana_triggered()
{
    ui->hiraganaCheckBox->setChecked(ui->action_Hiragana->isChecked());
}

void ProgramWindow::on_action_Katakana_triggered()
{
    ui->katakanaCheckBox->setChecked(ui->action_Katakana->isChecked());
}

void ProgramWindow::on_action_Romadzi_triggered()
{
    ui->romadziCheckBox->setChecked(ui->action_Romadzi->isChecked());
}

void ProgramWindow::on_action_Kiridzi_triggered()
{
    ui->kiridziCheckBox->setChecked(ui->action_Kiridzi->isChecked());
}

void ProgramWindow::on_action_Close_triggered()
{
    on_closeButton_clicked();
}

void ProgramWindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

void ProgramWindow::on_actionAbout_ukidamator_triggered()
{
    QMessageBox *aboutBox = new QMessageBox();
    aboutBox->setText(tr("Ukidamator is small education program. Put text into main text field and press \"2yukidama\" button, and as result you can see, that some of symbols are converted to hiragana or katakana. Now you can learn yourself by reading this mixed text. Enjoy:)"));
    aboutBox->show();
}

void ProgramWindow::on_actionDonate_triggered()
{
    QDesktopServices::openUrl(QUrl("https://money.yandex.ru/embed/shop.xml?uid=41001840047851&amp;writer=seller&amp;targets=Ukidamator+donation&amp;default-sum=50&amp;button-text=01&amp;comment=on&amp;hint=&amp;mail=on\""));
}
