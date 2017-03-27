#include "moveableframelesswindow.h"


#include <QKeyEvent>
#include <QMouseEvent>
#include <QRect>
#include <QPoint>
#include <QGridLayout>


MoveableFramelessWindow::MoveableFramelessWindow(QWidget *parent) :
    QWidget(parent),
    isMove(false)
{
    //设置窗体为无边框
    this->setWindowFlags(Qt::FramelessWindowHint);

    //设置底层背景透明
    setAttribute(Qt::WA_TranslucentBackground);

}

void MoveableFramelessWindow::mousePressEvent(QMouseEvent *event)
{
    //判断位置
    bool shouldMove=isPointInDragnWidget(getDragnWidget(),event->pos());

    if(shouldMove){
          pressedPoint=event->pos();
          isMove=true;
    }

    event->ignore();

}

void MoveableFramelessWindow::mouseMoveEvent(QMouseEvent *event)
{
    if((event->buttons()==Qt::LeftButton) && isMove==true){

            QPoint currPoint=this->pos();
            currPoint.setX(currPoint.x()+event->x()-pressedPoint.x());
            currPoint.setY(currPoint.y()+event->y()-pressedPoint.y());
            this->move(currPoint);
     }
}

void MoveableFramelessWindow::mouseReleaseEvent(QMouseEvent *event)
{
    isMove=false;

}

bool MoveableFramelessWindow::isPointInDragnWidget(const QWidget *widget, const QPoint &point)
{
    //判断位置
    QRect rect=widget->rect();

    bool isIn=point.x()>=rect.left()&&point.x()<=rect.right()&&point.y()>=rect.top()&&point.y()<=rect.bottom();

    return isIn;
}
