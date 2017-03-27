#ifndef LITTERIEM_H
#define LITTERIEM_H

#include <QWidget>

namespace Ui {
class LitterIem;
}

class LitterIem : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief LitterIem
     * @param picPath 头像的文件路径
     * @param parent
     */
    explicit LitterIem(QString picPath,QWidget *parent = 0);
    ~LitterIem();

private:
    Ui::LitterIem *ui;
};

#endif // LITTERIEM_H
