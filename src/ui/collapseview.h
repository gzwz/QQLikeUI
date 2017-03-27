#ifndef COLLAPSEVIEW_H
#define COLLAPSEVIEW_H

#include <QWidget>

namespace Ui {
class CollapseView;
}

class CollapseView : public QWidget
{
    Q_OBJECT

public:
    explicit CollapseView(QWidget *parent = 0);
    ~CollapseView();

private slots:
    void butClick();
private:
    Ui::CollapseView *ui;
};

#endif // COLLAPSEVIEW_H
