#-------------------------------------------------
#
# Project created by QtCreator 2015-10-21T16:00:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestApp
TEMPLATE = app


SOURCES += main.cpp \
    MainWidget.cpp

HEADERS  += \
    MainWidget.h



CONFIG(release, debug|release) {
 LIBS += -L$$OUT_PWD/../QRetroConsoleLib/build -lQRetroConsoleLib
} else {
 LIBS += -L$$OUT_PWD/../QRetroConsoleLib/build -lQRetroConsoleLibd
}


INCLUDEPATH += $$PWD/../QRetroConsoleLib/include
DEPENDPATH += $$PWD/../QRetroConsoleLib/include

FORMS += \
    MainWidget.ui
