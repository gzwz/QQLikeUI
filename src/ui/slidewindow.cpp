#include "slidewindow.h"
#include "ui_slidewindow.h"

#include "collapseview.h"

SlideWindow::SlideWindow(QWidget *parent) :
    QMainWindow(parent),
    MoveableFramelessWindow(parent),
    ui(new Ui::SlideWindow)
{
    ui->setupUi(this);

    ui->page->layout()->addWidget(new CollapseView());

   //ui->main_center->layout()->addWidget(new CollapseView());
   //tableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);

}

SlideWindow::~SlideWindow()
{
    delete ui;
}

void SlideWindow::show()
{

}

QWidget *SlideWindow::getDragnWidget()
{
    return ui->main_top;
}
