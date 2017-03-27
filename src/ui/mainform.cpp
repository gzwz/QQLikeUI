#include "mainform.h"
#include "ui_mainform.h"

#include "collapseview.h"
#include "colorpickform.h"


#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>

//主串口与屏幕边缘的距离
int MAIN_FORM_OADDING =10;

MainForm::MainForm(QWidget *parent) :
    MoveableFramelessWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    //加入联系人列表
    ui->page_4->layout()->addWidget(new CollapseView());

    //关联切换皮肤颜色按钮事件
    connect(ui->pushButton_skin,SIGNAL(clicked()),this,SLOT(doChangeColor()));

    //获取屏幕
    QDesktopWidget* desktopWidget = QApplication::desktop();

    //得到屏幕宽度
    int screenWidth = desktopWidget->width();

    //转移到右边
    this->move(screenWidth-MAIN_FORM_OADDING-this->width(),MAIN_FORM_OADDING);



}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::doChangeColor()
{

    MY_COLOR_PICK_FORM.show();
    MY_COLOR_PICK_FORM.raise();
    MY_COLOR_PICK_FORM.setFocus();

    ColorPickForm*f=&(MY_COLOR_PICK_FORM);

    connect(f,SIGNAL(themColorChanged(QString)),this,SLOT(onThemeColorChange(QString)));

}

void MainForm::onThemeColorChange(QString colorStr)
{
    //组合成qcc样式表
    QString style=QString("#%1{background-color:%2;}").arg(ui->centralwidget->objectName(),colorStr);
    //定义样式
    ui->centralwidget->setStyleSheet(style);

}

QWidget *MainForm::getDragnWidget()
{
    return ui->main_top;
}
