#include "mtedarikciyoneticisi.h"
#include<Veri/VeriSiniflari/mtedarikci.h>

MTedarikciYoneticisi::MTedarikciYoneticisi(QObject *parent) : QObject(parent)
{

}

MTedarikciYoneticisi::Ptr MTedarikciYoneticisi::kopyaOlustur(MTedarikciYoneticisi::Ptr kaynak) const
{
    Ptr kopya = yeni();

    kopya->setId(kaynak->getId());
    kopya->setTedarikciAdi(kaynak->getTedarikciAdi());
    kopya->setTedarikciYetkiliKisi(kaynak->getTedarikciYetkiliKisi());
    kopya->setTedarikciTelefon(kaynak->getTedarikciTelefon());
    kopya->setTedarikciMailAdresi(kaynak->getTedarikciMailAdresi());
    kopya->setTedarikciAdresi(kaynak->getTedarikciAdresi());


    return kopya;
}


