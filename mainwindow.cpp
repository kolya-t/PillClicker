#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRect>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    count(0), step(1.1)
{
    ui->setupUi(this);

    // установка размеров кнопки
    pillSize = geometry().width() / 2;
    ui->pushButton->resize(pillSize, pillSize);
    ui->pushButton->setIconSize(QSize(pillSize, pillSize));

    // центрирование кнопки
    QPoint center((geometry().width() - pillSize) / 2,
                  (geometry().height() - pillSize) / 2);
    ui->pushButton->move(center);

    // центрирование счетчика
    QRect widgetGeometry = ui->label->geometry();
    center = QPoint((geometry().width() - widgetGeometry.width()) / 2,
                    (ui->pushButton->geometry().y() - widgetGeometry.height()) / 2);
    ui->label->move(center);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::centerWidgetOnParent(QWidget* widget, const QWidget* parent) {
//    QRect parentGeometry = parent->geometry();
//    QRect widgetGeometry = ui->pushButton->geometry();
//    QPoint center((parentGeometry.width() - widgetGeometry.width()) / 2,
//                  (parentGeometry.height() - widgetGeometry.height()) / 2);
//    widget->move(center);
//}

//void MainWindow::centerWidgetOnRect(QWidget* widget, const QRect& rect) {
//    QRect widgetGeometry = widget->geometry();
//    QPoint center((rect->width() - widget->width()) / 2,
//                  (rect->height() - widget->height()) / 2);
//    widget->move(center);
//}

void MainWindow::on_pushButton_clicked() {
    count += step;
    ui->label->setText(QString::number(count));
}


void MainWindow::on_pushButton_pressed() {
    ui->pushButton->setIconSize(QSize(pillSize / 2, pillSize));
}


void MainWindow::on_pushButton_released() {
    ui->pushButton->setIconSize(QSize(pillSize, pillSize));
}
