#ifndef PILLBUTTON_H
#define PILLBUTTON_H

#include <QLabel>

class PillButton : public QLabel
{
    Q_OBJECT
public:
    explicit PillButton(QWidget *parent = 0);
    explicit PillButton(QWidget *parent, QPixmap px);

signals:
    void clicked();

public slots:

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

private:
    QPixmap pixmap;
};

#endif // PILLBUTTON_H
