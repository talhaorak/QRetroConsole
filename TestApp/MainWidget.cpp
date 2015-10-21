/*
 *
 * Copyright (c) 2015 Talha ORAK<talhaorak at gmail.com>
 *                    talhaorak.net
 *
 */
 
#include "MainWidget.h"
#include "ui_MainWidget.h"
#include "QRetroConsoleWidget.h"
#include <QFontDialog>
#include <QColorDialog>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_pushButton_Font_clicked()
{
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok, ui->pushButton_Font->font(), this);
    if (ok)
    {
        ui->pushButton_Font->setFont(font);
        ui->pushButton_Font->setText(font.family());
        ui->console->SetFont(font);
        ui->console->update();
    }
}

void MainWidget::on_pushButton_TextColor_clicked()
{
    QColor col = QColorDialog::getColor(ui->console->TextColor(), this);
    ui->console->SetTextColor(col);
    ui->pushButton_TextColor->setStyleSheet(QString("#pushButton_TextColor{ border: 1px solid gray; background-color: %1;}").arg(col.name()));
    ui->console->update();
}

void MainWidget::on_pushButton_BackgroundColor_clicked()
{
    QColor col = QColorDialog::getColor(ui->console->BackgroundColor(), this);
    ui->console->SetBackgroundColor(col);
    ui->pushButton_BackgroundColor->setStyleSheet(QString("#pushButton_BackgroundColor{ border: 1px solid gray; background-color: %1;}").arg(col.name()));
    ui->console->update();
}

void MainWidget::on_checkBox_Sound_toggled(bool checked)
{
    ui->console->EnableSound(checked);
}
