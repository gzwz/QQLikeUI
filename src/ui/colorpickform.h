#ifndef COLORPICKFORM_H
#define COLORPICKFORM_H


#include "moveableframelesswindow.h"

#include "src/model/singleton.h"


#include <QPushButton>
#include <QWidget>


namespace Ui {
class ColorPickForm;
}

/**
 * @brief 主题颜色选择窗口
 */
class ColorPickForm : public MoveableFramelessWindow,public Singleton<ColorPickForm>
{
    Q_OBJECT
public:
    ~ColorPickForm();
signals:
    /**
     * @brief 主题颜色改变事件
     * @param colorStr
     */
    void themColorChanged(QString colorStr);
protected:
      friend class Singleton<ColorPickForm>;
      ColorPickForm(QWidget *parent = 0);

      QWidget*getDragnWidget();
      //主题改变

private slots:
      void onColorButClick(QPushButton *pub);
      //定义事件过滤，用来扑捉主题颜色点击事件
      bool eventFilter(QObject *sender, QEvent *e);

      void onThemeColorChange(QString colorStr);

      //调色盘按钮点击
      void onColorPanleClick();

private:
    Ui::ColorPickForm *ui;
};

#define MY_COLOR_PICK_FORM ColorPickForm::getInstance()

#endif // COLORPICKFORM_H
