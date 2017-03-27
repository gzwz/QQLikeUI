#ifndef MAINFORM_H
#define MAINFORM_H


#include "moveableframelesswindow.h"

#include <QWidget>

namespace Ui {
class MainForm;
}

class MainForm : public MoveableFramelessWindow
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();

private slots:

    void doChangeColor();
    void onThemeColorChange(QString colorStr);
    void on_pushButton_p_clicked();

protected:
      QWidget*getDragnWidget();
private:
    Ui::MainForm *ui;
};

#endif // MAINFORM_H
