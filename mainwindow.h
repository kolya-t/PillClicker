#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSvg/QSvgWidget>
#include <QtSvg/QSvgRenderer>
#include <QTimer>

/* параметры множителя */
// время в миллисекундах до обнуления временного множителя
#define TIME_TO_NULL_MULTIPLIER     2000
// кликов до увеличения множителя
#define CLICKS_TO_INC_MULTIPLIER    5
// на сколько увеличивается множитель
// через CLICKS_TO_INC_MULTIPLIER кликов
#define MULTIPLIER_INCREMENT        0.1


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /* Возвращает такую координату, чтобы отрезок,
     * длиной x оказался ровно по центру между begin и end */
    static int centerXBetweenAB(int x, int begin, int end);
private slots:
    void on_pillButton_clicked();

    void on_pillButton_pressed();

    void on_pillButton_released();

    void nullMultiplier();
private:
    Ui::MainWindow *ui;
    // размер кнопки в пикселях
    int _pillSize;
    // таймер
    QTimer* _timer;

    // количество таблеток
    double _pillsCount;
    // количество получения таблеток за клик
    double _step;
    // временный множитель при множественном клике
    double _multiplier;
    // количество кликов по таблетке подряд
    int    _clicksCount;
};

#endif // MAINWINDOW_H
