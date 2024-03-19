#ifndef MTEDARIKCILISTEWIDGET_H
#define MTEDARIKCILISTEWIDGET_H

#include <QWidget>

namespace Ui {
class MTedarikciListeWidget;
}

class MTedarikciListeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MTedarikciListeWidget(QWidget *parent = nullptr);
    ~MTedarikciListeWidget();

private:
    Ui::MTedarikciListeWidget *ui;
};

#endif // MTEDARIKCILISTEWIDGET_H
