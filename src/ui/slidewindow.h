#ifndef SLIDEWINDOW_H
#define SLIDEWINDOW_H

#include "moveableframelesswindow.h"


#include <QMainWindow>

namespace Ui {
class SlideWindow;
}

class SlideWindow : public QMainWindow,public MoveableFramelessWindow
{
    Q_OBJECT

public:
    explicit SlideWindow(QWidget *parent = 0);
    ~SlideWindow();

    void show();
protected:
     QWidget*getDragnWidget();
private:
    Ui::SlideWindow *ui;
};

#endif // SLIDEWINDOW_H
