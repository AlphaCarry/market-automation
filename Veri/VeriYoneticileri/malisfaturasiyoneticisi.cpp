#include "malisfaturasiyoneticisi.h"
#include<Veri/VeriSiniflari/malisfaturasi.h>

MAlisFaturasiYoneticisi::MAlisFaturasiYoneticisi(QObject *parent) : QObject(parent)
{

}

MAlisFaturasiYoneticisi::Ptr MAlisFaturasiYoneticisi::kopyaOlustur(MAlisFaturasiYoneticisi::Ptr kaynak) const
{

    Ptr kopya = yeni();

    kopya->setId(kaynak->getId());
    kopya->setFaturaNo(kaynak->getFaturaNo());
    kopya->setUrunAlisTarihi(kaynak->getUrunAlisTarihi());


    return kopya;
}
