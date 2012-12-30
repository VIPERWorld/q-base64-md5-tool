#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    clipboard = QApplication::clipboard();
    ui->setupUi(this);
    abtdlg = new AboutDialog(this);
    connect(ui->bCopy, SIGNAL(clicked()), this, SLOT(copyText()));
    connect(ui->bPaste, SIGNAL(clicked()), this, SLOT(pasteText()));
    connect(ui->bEncode, SIGNAL(clicked()), this, SLOT(encodeText()));
    connect(ui->bDecode, SIGNAL(clicked()), this, SLOT(decodeText()));
    connect(ui->bmd5, SIGNAL(clicked()), this, SLOT(getmd5()));
    connect(ui->bAbout, SIGNAL(clicked()), abtdlg, SLOT(show()));
    connect(ui->bExit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

Window::~Window()
{
    delete ui;
}

void Window::encodeText()
{
    if(validateInput())
        return;
    ui->output->setPlainText(QByteArray(ui->input->toPlainText().toAscii()).toBase64());
}

void Window::decodeText()
{
    if(validateInput())
        return;
    ui->output->setPlainText(QByteArray::fromBase64(ui->input->toPlainText().toAscii()));
}

void Window::getmd5()
{
    if(validateInput())
        return;
    ui->output->setPlainText(QCryptographicHash::hash((ui->input->toPlainText().toAscii()),QCryptographicHash::Md5).toHex());
}

void Window::copyText()
{
    clipboard->setText(ui->output->toPlainText());
}

void Window::pasteText()
{
    ui->input->setPlainText(clipboard->text());
}

bool Window::validateInput()
{
    if(ui->input->toPlainText().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please write some text...", QMessageBox::Ok);
        return true;
    }
    else
        return false;
}
