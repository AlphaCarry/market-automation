#include "mtedarikcilistewidget.h"
#include "ui_mtedarikcilistewidget.h"

MTedarikciListeWidget::MTedarikciListeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MTedarikciListeWidget)
{
    ui->setupUi(this);
}

MTedarikciListeWidget::~MTedarikciListeWidget()
{
    delete ui;
}
