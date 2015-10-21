/*
 *
 * Copyright (c) 2015 Talha ORAK<talhaorak at gmail.com>
 *                    talhaorak.net
 *
 */

#include "QRetroConsoleWidget.h"
#include "QRetroConsoleWidgetPrivate.h"
#include <QtWidgets/QVBoxLayout>


QRetroConsoleWidget::QRetroConsoleWidget(QWidget *parent)
    :QWidget(parent)
{
    d_ptr = new QRetroConsoleWidgetPrivate(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(1,1,1,1);
    layout->addWidget(d_ptr);
    setLayout(layout);

    SetBackgroundColor(Qt::black);
    SetTextColor(QColor(0, 170, 0));
    setFont(QFont("Lucida Console", 8));

    connect(d_ptr, &QRetroConsoleWidgetPrivate::NewCommand, this, &QRetroConsoleWidget::NewCommand);
}

QRetroConsoleWidget::~QRetroConsoleWidget()
{
    delete d_ptr;
}

bool QRetroConsoleWidget::IsSoundEnabled() const
{
    return d_ptr->IsSoundEnabled();
}

QColor QRetroConsoleWidget::BackgroundColor() const
{
    return d_ptr->BackgroundColor();
}

QColor QRetroConsoleWidget::TextColor() const
{
    return d_ptr->TextColor();
}

QFont QRetroConsoleWidget::Font() const
{
    return d_ptr->font();
}

void QRetroConsoleWidget::EnableSound(bool sSoundEnabled)
{
    d_ptr->EnableSound(sSoundEnabled);
}

void QRetroConsoleWidget::SetBackgroundColor(QColor sBackgroundColor)
{
    d_ptr->SetBackgroundColor(sBackgroundColor);
}

void QRetroConsoleWidget::SetTextColor(QColor sTextColor)
{
    d_ptr->SetTextColor(sTextColor);
}

void QRetroConsoleWidget::SetFont(QFont font)
{
    d_ptr->setFont(font);
}
