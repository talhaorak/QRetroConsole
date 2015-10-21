#-------------------------------------------------
#
# Project created by QtCreator 2015-10-21T16:00:17
#
#-------------------------------------------------

QT       += multimedia widgets

TARGET = QRetroConsoleLib
TEMPLATE = lib

DEFINES += QRETROCONSOLELIB_LIBRARY

DESTDIR = build/

CONFIG(debug, debug|release) {
    TARGET = $$join(TARGET,,,d)
}

INCLUDEPATH += include/

SOURCES += \
    src/QRetroConsoleWidget.cpp \
    src/QRetroConsoleWidgetPrivate.cpp

HEADERS += \
    include/QRetroConsoleWidget.h \
    src/QRetroConsoleWidgetPrivate.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

RESOURCES += \
    src/resources/res.qrc
