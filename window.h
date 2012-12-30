#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QCryptographicHash>
#include <QClipboard>
#include <QMessageBox>
#include "aboutdialog.h"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

public slots:
    void encodeText();
    void decodeText();
    void getmd5();
    void copyText();
    void pasteText();
    bool validateInput();

private:
    Ui::Window *ui;
    QClipboard *clipboard;
    AboutDialog *abtdlg;
};

#endif // WINDOW_H
