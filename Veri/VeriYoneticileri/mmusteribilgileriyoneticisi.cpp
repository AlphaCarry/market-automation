#include "mmusteribilgileriyoneticisi.h"
#include<Veri/VeriSiniflari/mmusteribilgileri.h>

MMusteriBilgileriYoneticisi::MMusteriBilgileriYoneticisi(QObject *parent) : QObject(parent)
{

}

MMusteriBilgileriYoneticisi::Ptr MMusteriBilgileriYoneticisi::kopyaOlustur(MMusteriBilgileriYoneticisi::Ptr kaynak) const
{

    Ptr kopya = yeni();

    kopya->setId(kaynak->getId());
    kopya->setMusteriAdSoyad(kaynak->getMusteriAdSoyad());
    kopya->setMusteriTelefonNumarasi(kaynak->getMusteriTelefonNumarasi());
    kopya->setMusteriMailAdresi(kaynak->getMusteriMailAdresi());
    kopya->setMusteriAdresi(kaynak->getMusteriAdresi());


    return kopya;
}
