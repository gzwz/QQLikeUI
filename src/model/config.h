#ifndef CONFIG_H
#define CONFIG_H

#include "singleton.h"


#include <QString>
#include <QVector>
#include <QDebug>


class Config:public Singleton<Config>
{
public:
    ~Config(){

        qDebug()<<"~Config";
    }

    //系统定义的皮肤背景颜色
    QVector<QString>skinColors;


protected:
      friend class Singleton<Config>;
      Config();

private:
      void initColors();
};

//宏定义来获取配置
#define SYSTEM_CONFIG  Config::getInstance()

#endif // CONFIG_H
