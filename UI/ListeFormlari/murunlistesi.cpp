#include "murunlistesi.h"
#include "qtablewidget.h"
#include "ui_murunlistesi.h"

#include<Veri/mgenelveriyoneticisi.h>
#include<Veri/VeriSiniflari/murunbilgileri.h>

#include<QPushButton>
#include<QMessageBox>

#include<UI/VeriFormlari/myeniuruntanimlamaformu.h>

MUrunListesi::MUrunListesi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MUrunListesi)
{
    ui->setupUi(this);
    arama_yap();

}

MUrunListesi::~MUrunListesi()
{
    delete ui;
}

void MUrunListesi::listeGuncelle()
{



ui->tblListe->clear();



ui->tblListe->setRowCount(liste.length()+1);
ui->tblListe->setColumnCount(8);



QStringList basliklar;

basliklar<<tr("Ürün ID")<<tr("Ürün Adı")<<tr("Ürün Türü")<<tr("Ürün Detayı")<<tr("Ürün Fiyatı")<<tr("Stok Adedi")<<tr("İndirim Oranı")<<tr("Ürünü Sil");
ui->tblListe->setHorizontalHeaderLabels(basliklar);


//Veri

for (int i=0; i<liste.length(); i++){
QTableWidgetItem *hucre=new QTableWidgetItem();
hucre->setText(tr("%1").arg(liste[i]->getId()));
ui->tblListe->setItem(i,0,hucre);

hucre= new QTableWidgetItem();
hucre->setText(liste[i]->getUrunAdi());
ui->tblListe->setItem(i,1,hucre);

hucre= new QTableWidgetItem();
switch(liste[i]->getUrunTuru()){
case AlkolluIcecek:
       hucre->setText("Alkollüİçecek");
    break;

case AlkolsuzIcecek:
   hucre->setText("Alkolsüzİçecek");
    break;

case TemelGida:
    hucre->setText("TemelGıda");
    break;

case Atistirmalik:
   hucre->setText("Atıştırmalık");
   break;

case KisiselBakim:
    hucre->setText("KişiselBakım");
    break;

case Elektronik:
hucre->setText("Elektronik");
    break;

case Deterjan:
    hucre->setText("DeterjanVeTemizlik");
    break;

case Yiyecek:
    hucre->setText("Yiyecek");
    break;

default:
    hucre->setText("Saglik");

}

ui->tblListe->setItem(i,2,hucre);


hucre= new QTableWidgetItem();
hucre->setText(liste[i]->getUrunDetayi());
ui->tblListe->setItem(i,3,hucre);


hucre= new QTableWidgetItem();
hucre->setText(tr("%1").arg(liste[i]->getUrunFiyati()));
ui->tblListe->setItem(i,4,hucre);


hucre= new QTableWidgetItem();
hucre->setText(tr("%1").arg(liste[i]->getStokAdeti()));
ui->tblListe->setItem(i,5,hucre);


hucre= new QTableWidgetItem();
hucre->setText(tr("%1").arg(liste[i]->getIndirimOrani()));
ui->tblListe->setItem(i,6,hucre);

QPushButton *silmeButonu = new QPushButton(this);
silmeButonu->setText(tr("Ürünü sil"));
ui->tblListe->setCellWidget(i,7,silmeButonu);

auto veri_i = liste[i];

connect(silmeButonu, &QPushButton::clicked, [veri_i,this](){
    auto cevap = QMessageBox::question(nullptr, tr("Silme Onayı"), tr("%1 isimli ürünü silmek istediğinize emin misiniz?").arg(veri_i->getUrunAdi()));
    if(cevap == QMessageBox::Yes){
    MGenelVeriYoneticisi::mfa().getUrunBilgileri().sil(veri_i->getId());
    QMessageBox::information(nullptr, tr("Kayıt Silindi") , tr("Kayıt silme işlemi tamamlandı"));
    this->arama_yap();
    }
});

QPushButton *duzeltmeButonu=new QPushButton(this);
duzeltmeButonu->setText(tr("Ürünü Düzelt"));
ui->tblListe->setCellWidget(i,7,duzeltmeButonu);

connect(duzeltmeButonu,&QPushButton::clicked,[veri_i,this](){
    MYeniUrunTanimlamaFormu form;

    form.setVeri(veri_i);

    form.setWindowTitle(tr("%1 Ürünü Düzenle").arg(veri_i->getUrunAdi()));


  if(form.exec()==QDialog::Accepted) {
      form.getVeri();
      this->listeGuncelle();
  }



  });

}
}

void MUrunListesi::arama_yap()
{
    auto ekran=this->ui;

    liste =MGenelVeriYoneticisi::mfa().getUrunBilgileri().tumunuBul(
                [ekran](MUrunBilgisiYoneticisi::Ptr veri) ->bool {
            if (ekran->leUrunAdiDegeri->text()==""&&ekran->leUrunDetayiDegeri->text()==""){

            return true;
}
            if (ekran->leUrunAdiDegeri->text() !="") {
            if (ekran->rbUrunAdiIleBaslayan->isChecked()){
            if(!veri->getUrunAdi().toLower().startsWith(ekran->leUrunAdiDegeri->text().toLower())) {
            return false;


} else if(ekran->rbUrunAdiIleBiten->isChecked()) {
              if(!veri->getUrunAdi().toLower().endsWith(ekran->leUrunAdiDegeri->text().toLower()))
            return false;
          }

}else if (ekran->rbUrunAdiIceren->isChecked())
            if(!veri->getUrunAdi().toLower().contains(ekran->leUrunAdiDegeri->text().toLower())){
            return false;
}

}
            if(ekran ->leUrunDetayiDegeri->text()!=""){
            if (ekran->rbUrunDetayiBaslayan->isChecked()){
            if(!veri->getUrunDetayi().toLower().startsWith(ekran->leUrunDetayiDegeri->text().toLower())) {
            return false;


} else if(ekran->rbUrunDetayiIleBiten->isChecked()) {
              if(!veri->getUrunDetayi().toLower().endsWith(ekran->leUrunDetayiDegeri->text().toLower()))
            return false;
          }

}else if (ekran->rbUrunDetayiIceren->isChecked())
            if(!veri->getUrunDetayi().toLower().contains(ekran->leUrunDetayiDegeri->text().toLower())){
            return false;
}

}

            return true;
});


    listeGuncelle();

}


void MUrunListesi::ara()
{
   auto ekran=this->ui;

    liste=MGenelVeriYoneticisi::mfa().getUrunBilgileri().tumunuBul(
                [ekran](MUrunBilgisiYoneticisi::Ptr veri) ->bool {
            if (ekran->leUrunAdiDegeri->text()==""&&ekran->leUrunDetayiDegeri->text()==""){

            return true;
}
            if (ekran->leUrunAdiDegeri->text() !="") {
            if (ekran->rbUrunAdiIleBaslayan->isChecked()){
            if(!veri->getUrunAdi().toLower().startsWith(ekran->leUrunAdiDegeri->text().toLower())) {
            return false;


} else if(ekran->rbUrunAdiIleBiten->isChecked()) {
              if(!veri->getUrunAdi().toLower().endsWith(ekran->leUrunAdiDegeri->text().toLower()))
            return false;
          }

}else if (ekran->rbUrunAdiIceren->isChecked())
            if(!veri->getUrunAdi().toLower().contains(ekran->leUrunAdiDegeri->text().toLower())){
            return false;
}

}
            if(ekran ->leUrunDetayiDegeri->text()!=""){
            if (ekran->rbUrunDetayiBaslayan->isChecked()){
            if(!veri->getUrunDetayi().toLower().startsWith(ekran->leUrunDetayiDegeri->text().toLower())) {
            return false;


} else if(ekran->rbUrunDetayiIleBiten->isChecked()) {
              if(!veri->getUrunDetayi().toLower().endsWith(ekran->leUrunDetayiDegeri->text().toLower()))
            return false;
          }

}else if (ekran->rbUrunDetayiIceren->isChecked())
            if(!veri->getUrunDetayi().toLower().contains(ekran->leUrunDetayiDegeri->text().toLower())){
            return false;
}

}

            return true;
});


    listeGuncelle();
    if(ui->cbYazarkenAra->isChecked()){
        arama_yap();
    }

}


void MUrunListesi::on_btnAra_clicked()
{
    arama_yap();
}
