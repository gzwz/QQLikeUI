#include "loginform.h"
#include "ui_loginform.h"


#include "mainform.h"

#include <QGridLayout>


LoginForm::LoginForm(QWidget *parent) :
    MoveableFramelessWindow(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    //关联登录按钮点击
    connect(ui->pushButton_login,SIGNAL(clicked()),this,SLOT(doLoginButClick()));

}

LoginForm::~LoginForm()
{
    delete ui;
}

QWidget *LoginForm::getDragnWidget()
{
    return ui->login_top_widget;
}



void LoginForm::doLoginButClick()
{

    MainForm*m=new MainForm;
    m->show();
    this->hide();

}
