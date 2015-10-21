/*
 *
 * Copyright (c) 2015 Talha ORAK<talhaorak at gmail.com>
 *                    talhaorak.net
 *
 */

#include "QRetroConsoleWidgetPrivate.h"
#include "QRetroConsoleWidget.h"
#include <QTimer>
#include <QDateTime>
#include <QTextStream>
#include <QPalette>

QRetroConsoleWidgetPrivate::QRetroConsoleWidgetPrivate(QRetroConsoleWidget *parent)
    :QPlainTextEdit(parent), q_ptr(parent)
{        
    setObjectName("console");
    appendTimer = new QTimer(this);
    appendTimer->setInterval(1);
    connect(appendTimer, &QTimer::timeout,[this]{
        if(appendBuffer.size()>0)
        {
            AppendByte(appendBuffer.at(0));
            appendBuffer.remove(0,1);
        }
        else
        {
            setFocus();
            appendTimer->stop();
        }
    });


    setCursorWidth(8);
    setFont(QFont("Lucida Console",8));

    ignoredKeys << Qt::Key_Delete << Qt::Key_Left << Qt::Key_Right << Qt::Key_Up << Qt::Key_Down << Qt::Key_Home << Qt::Key_End << Qt::Key_Insert << Qt::Key_PageDown << Qt::Key_PageUp << Qt::Key_Tab;
    beepSound = new QSound(":/sfx/beep");
}

QRetroConsoleWidgetPrivate::~QRetroConsoleWidgetPrivate()
{
    delete appendTimer;
    delete device;
}

void QRetroConsoleWidgetPrivate::SetDevice(QIODevice *sDevice)
{
    device = sDevice;
}

void QRetroConsoleWidgetPrivate::AppendData(const QString &str)
{
    appendBuffer = str;
    appendTimer->start();
}

QString QRetroConsoleWidgetPrivate::GetText() const
{
    return toPlainText();
}

void QRetroConsoleWidgetPrivate::SetText(const QString &str)
{
    setPlainText(str);
}

void QRetroConsoleWidgetPrivate::AppendByte(QChar c)
{
    insertPlainText(QString(c));
    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::End);
    setTextCursor(cursor);
    if(soundEnabled)Beep();
}

bool QRetroConsoleWidgetPrivate::IsSoundEnabled() const
{
    return soundEnabled;
}

QColor QRetroConsoleWidgetPrivate::BackgroundColor() const
{
    return backgroundColor;
}

QColor QRetroConsoleWidgetPrivate::TextColor() const
{
    return textColor;
}

void QRetroConsoleWidgetPrivate::EnableSound(bool sSoundEnabled)
{
    soundEnabled = sSoundEnabled;
}

void QRetroConsoleWidgetPrivate::SetBackgroundColor(QColor sBackgroundColor)
{
    backgroundColor = sBackgroundColor;
    UpdateStylesheet();
}

void QRetroConsoleWidgetPrivate::SetTextColor(QColor sTextColor)
{
    textColor = sTextColor;
    UpdateStylesheet();
}

void QRetroConsoleWidgetPrivate::keyPressEvent(QKeyEvent *e)
{
    bool accept = false;
    QString txt = e->text();
    if(txt.isEmpty())
    {
        if(e->key() == Qt::Key_Tab)
        {
            accept = true;
        }
    }
    else
    {
        if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return)
        {
            CommitBuffer();
            accept = true;
        }
        else if(e->key() == Qt::Key_Backspace)
        {
            if(buffer.size() == 0)accept = false;
            else accept = true;
            buffer = buffer.left(buffer.size()-1);
        }
        else
        {
            buffer.append(txt);
            accept = true;
        }
    }
    if(accept)
    {
        if(soundEnabled)Beep();
        QPlainTextEdit::keyPressEvent(e);
    }
    else e->ignore();
}

void QRetroConsoleWidgetPrivate::mousePressEvent(QMouseEvent *e)
{
    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::End);
    setTextCursor(cursor);
    if(e->button() == Qt::RightButton)e->ignore();
    else e->accept();
}

void QRetroConsoleWidgetPrivate::CommitBuffer()
{
    emit NewCommand(buffer);
    buffer.clear();
}

void QRetroConsoleWidgetPrivate::Beep()
{
    quint64 curtime = QDateTime::currentMSecsSinceEpoch();
    if(curtime - lastBeepTime >100)
    {
        lastBeepTime = curtime;
        beepSound->play();
    }
}

void QRetroConsoleWidgetPrivate::UpdateStylesheet()
{
    QString styleSheet;
    QTextStream stream(&styleSheet);
    stream << "#console{ background-color: " << backgroundColor.name() << "; color: " << textColor.name() << "; }";
    setStyleSheet(styleSheet);
}

