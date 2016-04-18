#include "pillbutton.h"
#include <QPainter>

PillButton::PillButton(QWidget *parent) :
    QLabel(parent)
{}

PillButton::PillButton(QWidget *parent, QPixmap px)
    : QLabel(parent)
{
    pixmap=px;
    this->setPixmap(pixmap);


}

void PillButton::mousePressEvent(QMouseEvent *ev) {

    this->move(x()+1,y()+1);
    emit clicked();
}

void PillButton::mouseReleaseEvent(QMouseEvent *ev)
{

    this->move(x()-1,y()-1);

}

void PillButton::enterEvent(QEvent *)
{
    QPixmap px(pixmap);
    QPainter p(& px );
    p.setBrush( QColor(  118,225,209, 127  ) ); // highligh a bit
    p.setPen( Qt::NoPen );
    p.drawRect( px.rect() );
    p.end();
    this->setPixmap(px);

}

void PillButton::leaveEvent(QEvent *)
{
    setPixmap(pixmap);
}
