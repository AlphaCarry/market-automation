#include "murunsatisbilgisiyoneticisi.h"
#include<Veri/VeriSiniflari/murunsatisbilgileri.h>

MUrunSatisBilgisiYoneticisi::MUrunSatisBilgisiYoneticisi(QObject *parent) : QObject(parent)
{

}

MUrunSatisBilgisiYoneticisi::Ptr MUrunSatisBilgisiYoneticisi::kopyaOlustur(MUrunSatisBilgisiYoneticisi::Ptr kaynak) const
{
    Ptr kopya = yeni();

    kopya->setId(kaynak->getId());
    kopya->setUrunSatisFiyati(kaynak->getUrunSatisFiyati());
    kopya->setUrunSatisMiktari(kaynak->getUrunSatisMiktari());


    return kopya;
}
