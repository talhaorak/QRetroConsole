/*
   QRetroConsoleWidget.h

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

#ifndef QRETROCONSOLELIB_GLOBAL_H
#define QRETROCONSOLELIB_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QWidget>
#include <QColor>

#if defined(QRETROCONSOLELIB_LIBRARY)
#  define QRETROCONSOLELIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QRETROCONSOLELIBSHARED_EXPORT Q_DECL_IMPORT
#endif

class QRetroConsoleWidgetPrivate;

class QRETROCONSOLELIBSHARED_EXPORT QRetroConsoleWidget : public QWidget
{
    Q_OBJECT

    Q_DECLARE_PRIVATE(QRetroConsoleWidget)
public:
    Q_PROPERTY(bool soundEnabled READ IsSoundEnabled WRITE EnableSound)
    Q_PROPERTY(QColor backgroundColor READ BackgroundColor WRITE SetBackgroundColor)
    Q_PROPERTY(QColor textColor READ TextColor WRITE SetTextColor)
    Q_PROPERTY(QFont font READ Font WRITE SetFont)

    QRetroConsoleWidget(QWidget *parent = nullptr);
    ~QRetroConsoleWidget();

    bool IsSoundEnabled() const;
    QColor BackgroundColor() const;
    QColor TextColor() const;
    QFont Font() const;

signals:
    void NewCommand(const QString & str);

public slots:
    void EnableSound(bool sSoundEnabled = true);
    void SetBackgroundColor(QColor sBackgroundColor);
    void SetTextColor(QColor sTextColor);
    void SetFont(QFont font);

private:
    QRetroConsoleWidgetPrivate *d_ptr;
    QFont m_font;
};

#endif // QRETROCONSOLELIB_GLOBAL_H
