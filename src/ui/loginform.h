#ifndef LOGINFORM_H
#define LOGINFORM_H


#include "moveableframelesswindow.h"

#include <QWidget>

namespace Ui {
class LoginForm;
}

class LoginForm :public MoveableFramelessWindow
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = 0);
    ~LoginForm();

protected:

      QWidget*getDragnWidget();
private slots:
    /**
     * @brief 登录按钮点击
     */
    void doLoginButClick();
private:
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
