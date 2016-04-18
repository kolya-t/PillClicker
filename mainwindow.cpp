#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRect>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _timer(new QTimer(this)),
    _pillsCount(0), _step(1)
{
    connect (_timer, SIGNAL(timeout()), this, SLOT(nullMultiplier()));
    /*----------------УСТАНОВКА ИНТЕРФЕЙСА-НАЧАЛО-------------------*/
    ui->setupUi(this);
    nullMultiplier();
    /* размеры приложения */
    // на десктопе
    QRect screenGeometry = geometry();
    // на андроиде
//    QRect screenGeometry = qApp->desktop()->availableGeometry(ui->pushButton);

    // установка размеров кнопки
    _pillSize = screenGeometry.width() / 2;
    ui->pillButton->resize(_pillSize, _pillSize);
    ui->pillButton->setIconSize(QSize(_pillSize, _pillSize));

    // центрирование кнопки
    QPoint center(centerXBetweenAB(_pillSize, 0, screenGeometry.width()),
                  centerXBetweenAB(_pillSize, 0, screenGeometry.height()));
    ui->pillButton->move(center);

    // центрирование счетчика
    QRect widgetGeometry = ui->counterLabel->geometry();
    center = QPoint(centerXBetweenAB(widgetGeometry.width(), 0, screenGeometry.width()),
                    centerXBetweenAB(widgetGeometry.height(), 0, ui->pillButton->y()));
    ui->counterLabel->move(center);

    // центрирование шага
    widgetGeometry = ui->stepLabel->geometry();
    center = QPoint(centerXBetweenAB(widgetGeometry.width(), 0, screenGeometry.width()),
                   centerXBetweenAB(widgetGeometry.height(), _pillSize + ui->pillButton->y(), screenGeometry.height()));
    ui->stepLabel->move(center);
    /*----------------УСТАНОВКА ИНТЕРФЕЙСА-КОНЕЦ--------------------*/
}

MainWindow::~MainWindow() {
    delete ui;
}

/* Возвращает такую координату, чтобы отрезок,
 * длиной x оказался ровно по центру между begin и end */
int MainWindow::centerXBetweenAB(int x, int begin, int end) {
    return begin + (end - begin - x) / 2;
}

void MainWindow::on_pillButton_clicked() {
    // получение таблеточек
    _pillsCount += _step * _multiplier;
    // вывод информации на экран
    ui->counterLabel->setText(QString::number(_pillsCount));
    ui->stepLabel->setText(tr("+") + QString::number(_step * _multiplier));

    /* временный множитель, пропадающий через 2 секунды
     * после прекращения кликания. увеличивает свое значение
     * каждые 5 кликов на 10 процентов */
    ++_clicksCount; // был произведен клик
    // если 2 секунды еще не прошло
    if (_timer->isActive()) {
        if (_clicksCount == CLICKS_TO_INC_MULTIPLIER) {
            _multiplier += _step * MULTIPLIER_INCREMENT;
            _clicksCount = 0;
        }
    }
    // если прошло 2 секунды после последнего клика
    else {
        nullMultiplier();
    }
    _timer->start(TIME_TO_NULL_MULTIPLIER);
}

void MainWindow::on_pillButton_pressed() {
    ui->pillButton->setIconSize(QSize(_pillSize / 2, _pillSize));
}

void MainWindow::on_pillButton_released() {
    ui->pillButton->setIconSize(QSize(_pillSize, _pillSize));
}

// обнуление количества кликов подряд и установка множителя = 1
void MainWindow::nullMultiplier() {
    _clicksCount = 0;
    _multiplier = 1;
    ui->stepLabel->setText("");
}
