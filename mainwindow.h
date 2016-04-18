#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSvg/QSvgWidget>
#include <QtSvg/QSvgRenderer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//    void centerWidgetOnParent(QWidget* widget, const QWidget* parent);
//    void centerWidgetOnRect(QWidget* widget, const QRect& rect);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    double count;
    double step;
};

#endif // MAINWINDOW_H
