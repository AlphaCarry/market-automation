#include "Veri/mgenelveriyoneticisi.h"
#include "manapencere.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MAnaPencere w;
    w.show();
    return a.exec();
}

//#include "Veri/VeriSiniflari/murunbilgileri.h"
//#include <Veri/VeriYoneticileri/murunbilgisiyoneticisi.h>
///*
//void deneme()
//{
//    MUrunBilgisiYoneticisi yonetici;

//    auto yeni = yonetici.yeni();
//    yeni -> setUrunAdi("Omo Deterjan");
//    yeni -> setUrunDetayi("Omo 1Kg çamaşır deterjanı");

//    yonetici.ekle(yeni);

//    yeni = yonetici.yeni();
//    yeni->setUrunAdi("Makarna");
//    yeni->setUrunDetayi("Piyale makarna 700Gr");


//}
//*/
//#include <Veri/mgenelveriyoneticisi.h>
//#include<QDataStream>

//void deneme()
//{
//    auto urunler = MGenelVeriYoneticisi::mfa().getUrunBilgileri().yeni();
//    MGenelVeriYoneticisi::mfa().getUrunBilgileri().ekle(urunler);

////#include <Veri/mgenelveriyoneticisi.h>
////#include<QDataStream>


//    QDataStream dosya;

//    dosya << MGenelVeriYoneticisi::mfa();
//}


