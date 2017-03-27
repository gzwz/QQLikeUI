#include "colorpickform.h"
#include "ui_colorpickform.h"

#include "src/model/config.h"

#include <QPushButton>
#include <QDebug>
#include <QColorDialog>
#include <QColor>


//定义颜色标签标签宽度
int COLOR_LABLE_SIZE=40;

ColorPickForm::ColorPickForm(QWidget *parent) :
    MoveableFramelessWindow(parent),
    ui(new Ui::ColorPickForm)
{
    ui->setupUi(this);

    QVector<QString>vec=SYSTEM_CONFIG.skinColors;
    //初始化颜色
    foreach(QString color,vec){

        QPushButton*l=new QPushButton(this);

        l->setMinimumSize(COLOR_LABLE_SIZE,COLOR_LABLE_SIZE);
        l->setMaximumSize(COLOR_LABLE_SIZE,COLOR_LABLE_SIZE);

        //存入颜色值到属性中，在后来的点击中，可以获取次属性值，用来改变全局主题
        l->setProperty("color",color);

        l->installEventFilter(this);

        QString style=QString("background-color:%1;")
                .arg(color);


        l->setStyleSheet(style);

        ui->color_items->layout()->addWidget(l);

    }

    connect(this,SIGNAL(themColorChanged(QString)),this,SLOT(onThemeColorChange(QString)));
    connect(ui->color_panle_pushButton,SIGNAL(clicked()),this,SLOT(onColorPanleClick()));
}

void ColorPickForm::onColorButClick(QPushButton*pub)
{
    QString colorStr=pub->property("color").toString();

    if(colorStr.isEmpty()==false){

       emit this->themColorChanged(colorStr);

    }
}

bool ColorPickForm::eventFilter(QObject *sender, QEvent *e)
{

    if(e->type()==QEvent::MouseButtonPress){

        QPushButton*pub=(QPushButton*)sender;
        onColorButClick(pub);

    }

    return QWidget::eventFilter(sender,e);;
}

ColorPickForm::~ColorPickForm()
{
    delete ui;
}

QWidget *ColorPickForm::getDragnWidget()
{
    return ui->color_main_top;
}

void ColorPickForm::onThemeColorChange(QString colorStr)
{
    QString style=QString("#%1{background-color:%2}")
            .arg(ui->centralwidget->objectName(),colorStr);

    ui->centralwidget->setStyleSheet(style);

}

void ColorPickForm::onColorPanleClick()
{

    QColorDialog colorD;
    int rs=colorD.exec();

    //如果选择了颜色
    if(rs){
        QColor color = colorD.currentColor();
        QString colorStr=QString("rgb(%1,%2,%3)")
                .arg(QString::number(color.red()),QString::number(color.green()),QString::number(color.blue()));

        emit this->themColorChanged(colorStr);
    }

}
