/*
   QRetroConsoleWidgetPrivate.h

Copyright (c) 2015 Talha ORAK<talhaorak at gmail.com>
                   talhaorak.net


Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef QRETROCONSOLEWIDGETPRIVATE_H
#define QRETROCONSOLEWIDGETPRIVATE_H

#include <QPlainTextEdit>
#include <QSound>

class QIODevice;
class QTimer;

class QRetroConsoleWidget;

class QRetroConsoleWidgetPrivate : public QPlainTextEdit
{
    Q_OBJECT

    Q_DECLARE_PUBLIC(QRetroConsoleWidget)
public:
    QRetroConsoleWidgetPrivate(QRetroConsoleWidget *parent);
    ~QRetroConsoleWidgetPrivate();

    void SetDevice(QIODevice *sDevice);
    void AppendData(const QString & str);
    QString GetText()const;
    void SetText(const QString & str);
    void AppendByte(QChar c);


    bool IsSoundEnabled() const;
    QColor BackgroundColor() const;
    QColor TextColor() const;

    void EnableSound(bool sSoundEnabled = true);
    void SetBackgroundColor(QColor sBackgroundColor);
    void SetTextColor(QColor sTextColor);



signals:
    void NewCommand(const QString & str);

private:
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void CommitBuffer();
    void Beep();
    void UpdateStylesheet();

    QList<Qt::Key> ignoredKeys;
    QString buffer;

    quint64 lastBeepTime = 0;
    QSound *beepSound = nullptr;


    bool soundEnabled = true;
    QColor backgroundColor, textColor;
    QRetroConsoleWidget *q_ptr;
    QIODevice *device = nullptr;
    QTimer *appendTimer = nullptr;
    QString appendBuffer;
};

#endif // QRETROCONSOLEWIDGETPRIVATE_H
