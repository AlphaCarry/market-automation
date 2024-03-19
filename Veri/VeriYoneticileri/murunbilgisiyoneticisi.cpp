#include "murunbilgisiyoneticisi.h"
#include <Veri/VeriSiniflari/murunbilgileri.h>

MUrunBilgisiYoneticisi::MUrunBilgisiYoneticisi(QObject *parent) : QObject(parent) ,TemelVeriYoneticisi<MUrunBilgileri, MUrunBilgileriPtr>()
{

}

MUrunBilgisiYoneticisi::Ptr MUrunBilgisiYoneticisi::kopyaOlustur(MUrunBilgisiYoneticisi::Ptr kaynak) const
{
    Ptr kopya = yeni();

    kopya->setId(kaynak->getId());
    kopya->setUrunAdi(kaynak->getUrunAdi());
    kopya->setUrunDetayi(kaynak->getUrunDetayi());
    kopya->setUrunTuru(kaynak->getUrunTuru());
    kopya->setIndirimOrani(kaynak->getIndirimOrani());
    kopya->setStokAdeti(kaynak->getStokAdeti());
    kopya->setUrunFiyati(kaynak->getUrunFiyati());

    return kopya;
}











