#include "msatisfaturasiyoneticisi.h"
#include<Veri/VeriSiniflari/msatisfaturasi.h>

MSatisFaturasiYoneticisi::MSatisFaturasiYoneticisi(QObject *parent) : QObject(parent)
{

}

MSatisFaturasiYoneticisi::Ptr MSatisFaturasiYoneticisi::kopyaOlustur(MSatisFaturasiYoneticisi::Ptr kaynak) const
{
    Ptr kopya = yeni();

    kopya->setId(kaynak->getId());
    kopya->setSatisFaturaNo(kaynak->getSatisFaturaNo());
    kopya->setUrunSatisTarihi(kaynak->getUrunSatisTarihi());


    return kopya;

}
