#include "collapseviewitem.h"
#include "ui_collapseviewitem.h"

#include "litteriem.h"

#include <QDebug>
#include <QTime>

int MAX_PERSON_PIC_NUM=9;

CollapseViewItem::CollapseViewItem(QString titleText, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollapseViewItem)
{
    ui->setupUi(this);
    ui->label->setProperty("slected",!ui->item_con->isVisible());


    //根据时间制作随机种子
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);


    //随机产生好友数目
    int personNumber=qrand()%(MAX_PERSON_PIC_NUM-1)+1;

    for(int i=0;i<personNumber;i++){
        //随机选择好友头像
        QString picPath=QString(":/media/person/media/person/%1.jpg")
                .arg(QString::number(qrand()%(MAX_PERSON_PIC_NUM-1)+1));
        addSubItem(new LitterIem(picPath,this));
    }


    qDebug()<<"personNumber:"<<personNumber;

    //随机产生未上线好友数目
    int offlinPerson=qrand()%personNumber;

    titleText=QString("%1 (%2/%3)")
            .arg(titleText,QString::number(offlinPerson),QString::number(personNumber));

    this->setTitleText(titleText);


    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(onCollapseButClick()));

}

CollapseViewItem::~CollapseViewItem()
{
    delete ui;
}

void CollapseViewItem::setTitleText(QString titleText)
{
    ui->pushButton->setText(titleText);
}

void CollapseViewItem::addSubItems(QList<QWidget *> widgets)
{
    foreach (QWidget *var, widgets) {
        addSubItem(var);
    }
}

void CollapseViewItem::addSubItem(QWidget *widget)
{
    ui->item_con->layout()->addWidget(widget);
}

void CollapseViewItem::onCollapseButClick()
{
    //设置为相反的显示状态
    ui->item_con->setVisible(!ui->item_con->isVisible());

    ui->label->setProperty("slected",ui->item_con->isVisible());

    ui->label->update();

}
