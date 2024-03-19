#include "tedarikciduzenleme.h"
#include "ui_tedarikciduzenleme.h"
#include<Veri/VeriSiniflari/mtedarikci.h>

TedarikciDuzenleme::TedarikciDuzenleme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TedarikciDuzenleme)
{
    ui->setupUi(this);
}

TedarikciDuzenleme::~TedarikciDuzenleme()
{
    delete ui;
}

void TedarikciDuzenleme::on_btnKaydet_clicked()
{
    emit iptalKapat();
}

MTedarikciPtr TedarikciDuzenleme::getVeri() const
{
    veri->setTedarikciAdresi(ui->pteTedarikciAdresi->toPlainText());
    veri->setTedarikciAdi(ui->lblTedarikciAdi->text());
    veri->setTedarikciTelefon(ui->leTedarikciTelefon->text());
    veri->setTedarikciYetkiliKisi(ui->leTeadrikciYetkiliKisi->text());


    return veri;
}

void TedarikciDuzenleme::setVeri(const MTedarikciPtr &value)
{
    veri = value;

    ui->leTedarikciAdi->setText(veri->getTedarikciAdi());
    ui->leTedarikciTelefon->setText(veri->getTedarikciTelefon());
    ui->leTeadrikciYetkiliKisi->setText(veri->getTedarikciYetkiliKisi());
    ui->pteTedarikciAdresi->setPlainText(veri->getTedarikciAdresi());

}

void TedarikciDuzenleme::on_btnIptal_clicked()
{
    emit iptalKapat();
}
