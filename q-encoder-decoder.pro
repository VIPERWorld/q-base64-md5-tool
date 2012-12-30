QT       += core gui

CONFIG += static

TARGET = q-encoder-decoder

TEMPLATE = app

SOURCES += main.cpp window.cpp aboutdialog.cpp

HEADERS  += window.h aboutdialog.h

FORMS    += window.ui aboutdialog.ui

RESOURCES += icon.qrc

win32: RC_FILE += q-encoder-decoder.rc
