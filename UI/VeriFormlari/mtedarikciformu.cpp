#include "mtedarikciformu.h"
#include "ui_mtedarikciformu.h"
#include<UI/VeriFormlari/Widgetlar/tedarikciduzenleme.h>
#include<UI/ListeFormlari/mtedarikcilistewidget.h>
#include<Veri/mgenelveriyoneticisi.h>

#include <Veri/VeriSiniflari/mtedarikci.h>


MTedarikciFormu::MTedarikciFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MTedarikciFormu)
{
    ui->setupUi(this);



    MTedarikciListeWidget*widget1=new MTedarikciListeWidget(this);
    ui->tabTedarikciIslemleri->addTab(widget1,tr("Tanımlı Tedarikçiler"));

}

MTedarikciFormu::~MTedarikciFormu()
{
    delete ui;
}


void MTedarikciFormu::on_tabTedarikciIslemleri_tabCloseRequested(int index)
{
    if (index<2){
        return;
    }
}

void MTedarikciFormu::on_btnYeniTedarikci_clicked(int index)
{
    TedarikciDuzenleme*widget=new TedarikciDuzenleme(this);
    ui->tabTedarikciIslemleri->addTab(widget,tr("Yeni Tedarikçi Ekle"));
    auto veri=MGenelVeriYoneticisi::mfa().getTedarikciBilgileri().yeni();

    widget->setVeri(veri);
    ui->tabTedarikciIslemleri->setCurrentIndex(index);

   connect(widget,&TedarikciDuzenleme::iptalKapat,[this,widget](){
        for (auto i=0;i<this->ui->tabTedarikciIslemleri->count();i++){
        if(this->ui->tabTedarikciIslemleri->widget(i)== widget){
            this->ui->tabTedarikciIslemleri->removeTab(i);
            return;
        }
        }

    });

    connect(widget,&TedarikciDuzenleme::kaydetKapat,[this,widget](){

        MGenelVeriYoneticisi::mfa().getTedarikciBilgileri().ekle(widget->getVeri());

        for (auto i=0;i<this->ui->tabTedarikciIslemleri->count();i++){
        if(this->ui->tabTedarikciIslemleri->widget(i)== widget){
            this->ui->tabTedarikciIslemleri->removeTab(i);
            return;
}

    }

});
}
