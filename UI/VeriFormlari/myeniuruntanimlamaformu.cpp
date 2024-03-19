#include "myeniuruntanimlamaformu.h"
#include "ui_myeniuruntanimlamaformu.h"
#include<Veri/VeriSiniflari/murunbilgileri.h>

MYeniUrunTanimlamaFormu::MYeniUrunTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MYeniUrunTanimlamaFormu)
{
    ui->setupUi(this);
}

MYeniUrunTanimlamaFormu::~MYeniUrunTanimlamaFormu()
{
    delete ui;
}

MUrunBilgileriPtr MYeniUrunTanimlamaFormu::getVeri() const
{

    veri->setUrunAdi(ui->leUrunAdi->text());
    if(ui->rbAlkolluIcecek->isChecked()) {
        veri->setUrunTuru(AlkolluIcecek);

    } else if (ui->rbKisiselBakim->isChecked()) {
        veri->setUrunTuru(KisiselBakim);

    } else if (ui->rbAlkolsuzIcecek->isChecked()) {
        veri->setUrunTuru((AlkolsuzIcecek));

    }else if (ui->rbSebzeMeyve->isChecked()) {
        veri->setUrunTuru((SebzeMeyve));

     }else if (ui->rbTemelGida->isChecked()){
        veri->setUrunTuru((TemelGida));

     }else if (ui->rbAtistirmalik->isChecked()){
        veri->setUrunTuru((Atistirmalik));

     }else if (ui->rbElektronik->isChecked()){
        veri->setUrunTuru((Elektronik));

     }else if(ui->rbSaglik->isChecked()){
        veri->setUrunTuru((Saglik));

     }else if(ui->rbDeterjan->isChecked()){
        veri->setUrunTuru((Deterjan));

     }else if(ui->rbYiyecek->isChecked()){
        veri->setUrunTuru((Yiyecek));
     }
    veri->setUrunDetayi(ui->pteUrunDetayi->toPlainText());
    veri->setUrunFiyati(ui->dsbUrunFiyati->value());
    veri->setIndirimOrani(ui->dsbIndirimOrani->value());
    veri->setStokAdeti(ui->sbStokAdeti->value());


    return veri;
}

void MYeniUrunTanimlamaFormu::setVeri(const MUrunBilgileriPtr &value)
{
    veri = value;

    ui->leUrunAdi->setText(veri->getUrunAdi());

    switch (veri->getUrunTuru()){

   case AlkolluIcecek:
    ui->rbAlkolluIcecek->setChecked(true);
    break;

   case AlkolsuzIcecek:
        ui->rbAlkolsuzIcecek->setChecked(true);
        break;

   case SebzeMeyve:
        ui->rbSebzeMeyve->setChecked(true);
        break;

    case TemelGida:
        ui->rbTemelGida->setChecked(true);
        break;

    case Atistirmalik:
        ui->rbAtistirmalik->setChecked(true);
        break;

    case KisiselBakim:
        ui->rbKisiselBakim->setChecked(true);
        break;

    case Elektronik:
        ui->rbElektronik->setChecked(true);
        break;

    case Deterjan:
        ui->rbDeterjan->setChecked(true);
        break;

    case Saglik:
        ui->rbSaglik->setChecked(true);
        break;

    default:
        ui->rbYiyecek->setChecked(true);

    }

    ui->pteUrunDetayi->document()->setPlainText(veri->getUrunDetayi());
    ui->dsbUrunFiyati->setValue(veri->getUrunFiyati());
    ui->dsbIndirimOrani->setValue(veri->getIndirimOrani());
    ui->sbStokAdeti->setValue(veri->getStokAdeti());






}
