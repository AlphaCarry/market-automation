#include "manapencere.h"
#include "UI/VeriFormlari/Widgetlar/tedarikciduzenleme.h"
#include "UI/VeriFormlari/myenimusteriformu.h"
#include "ui_manapencere.h"
#include "ui_murunlistesi.h"
#include "ui_myeniuruntanimlamaformu.h"
#include<Veri/mgenelveriyoneticisi.h>
#include<UI/VeriFormlari/myeniuruntanimlamaformu.h>
#include<Veri/VeriSiniflari/murunbilgileri.h>
#include<UI/VeriFormlari/mtedarikciformu.h>
#include<UI/ListeFormlari/murunlistesi.h>

#include<QDir>
#include<QFile>
#include<QDataStream>
#include <QStandardPaths>



MAnaPencere::MAnaPencere(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MAnaPencere)
{
    ui->setupUi(this);

    QString dosya_yolu=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
        QDir dosya_klasoru(dosya_yolu);

        if (dosya_klasoru.exists("market.db")) {
            QFile dosya(dosya_yolu + "/market.db");

          if(dosya.open(QIODevice::ReadOnly))  {
            QDataStream oku(&dosya);

            oku >> MGenelVeriYoneticisi::mfa();

            dosya.close();
          }


        }


    //ui->menuYeni_r_n_Tan_mlama->setupUi(Ui_MYeniUrunTanimlamaFormu)
    //ui->menuMevcut_r_nler->addAction(Ui::MUrunListesi());


}

MAnaPencere::~MAnaPencere()
{
    delete ui;

}


/*void MAnaPencere::on_actionTedarikciler_triggered()
{



}

void MAnaPencere::on_actionMevcuturunler_triggered()
{
    MUrunListesi form;

    form.exec();
}

void MAnaPencere::on_actionYeni_Tedarikci_Ekleme_triggered()
{
    MTedarikciFormu form;
    form.exec();
}


void MAnaPencere::on_actionYeni_Tedarikci_Tanimla_triggered()
{
    MTedarikciFormu form;
    form.exec();
}

void MAnaPencere::on_actionYeni_Tedarikci_Tanimlar_triggered()
{
    MTedarikciFormu form;
    form.exec();
}

void MAnaPencere::on_actionYeniurun_Tanimlama_triggered()
{
    MYeniUrunTanimlamaFormu form;
    auto veri=MGenelVeriYoneticisi::mfa().getUrunBilgileri().yeni();

    form.setVeri(veri);
    form.setWindowTitle(tr("Yeni Ürün Ekleme"));

    if(form.exec()==QDialog::Accepted) {
        form.getVeri();

        MGenelVeriYoneticisi::mfa().getUrunBilgileri().ekle(veri);
    }
}*/

void MAnaPencere::on_actionTedarik_iler_triggered()
{


    MTedarikciFormu form;
    form.setWindowTitle(tr("Tedarikçiler"));
    form.exec();
}


void MAnaPencere::on_actionYeni_Tedarik_i_Tan_mla_triggered()
{

    TedarikciDuzenleme form;
    form.setWindowTitle(tr("Yeni Tedarikçi Tanımla"));
    form.exec();

}


void MAnaPencere::on_actionYeni_r_n_Tan_mlama_triggered()
{
    MYeniUrunTanimlamaFormu form;
    auto veri=MGenelVeriYoneticisi::mfa().getUrunBilgileri().yeni();

    form.setVeri(veri);
    form.setWindowTitle(tr("Yeni Ürün Ekleme"));

    if(form.exec()==QDialog::Accepted) {
        form.getVeri();

        MGenelVeriYoneticisi::mfa().getUrunBilgileri().ekle(veri);
    }
}



void MAnaPencere::on_actionMevcut_r_nler_triggered()
{
    MUrunListesi form;
    form.setWindowTitle(tr("Mevcut Ürünler"));
    form.exec();
}
