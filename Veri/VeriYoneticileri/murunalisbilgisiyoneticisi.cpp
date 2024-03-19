#include "murunalisbilgisiyoneticisi.h"
#include<Veri/VeriSiniflari/murunalisbilgileri.h>

MUrunAlisBilgisiYoneticisi::MUrunAlisBilgisiYoneticisi(QObject *parent) : QObject(parent)
{

}

MUrunAlisBilgisiYoneticisi::Ptr MUrunAlisBilgisiYoneticisi::kopyaOlustur(MUrunAlisBilgisiYoneticisi::Ptr kaynak) const
{
    Ptr kopya = yeni();

    kopya->setId(kaynak->getId());
    kopya->setUrunAlisFiyati(kaynak->getUrunAlisFiyati());
    kopya->setUrunAlisMiktari(kaynak->getUrunAlisMiktari());


    return kopya;
}
