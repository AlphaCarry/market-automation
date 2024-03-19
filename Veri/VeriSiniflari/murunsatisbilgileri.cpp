#include "murunsatisbilgileri.h"
#include "Veri/mgenelveriyoneticisi.h"
#include <QtMath>

MUrunSatisBilgileri::MUrunSatisBilgileri(QObject *parent) : QObject(parent)
{

}

IdTuru MUrunSatisBilgileri::getId() const
{
    return urunSatisId;
}

void MUrunSatisBilgileri::setId(const IdTuru &value)
{
    if(value==urunSatisId)
        return;
    urunSatisId = value;
    emit idDegisti(urunSatisId);
}

TamSayi MUrunSatisBilgileri::getUrunSatisMiktari() const
{
    return urunSatisMiktari;
}

void MUrunSatisBilgileri::setUrunSatisMiktari(const TamSayi &value)
{
    if(value==urunSatisMiktari)
        return;
    urunSatisMiktari = value;
    emit urunSatisMiktariDegisti(urunSatisMiktari);
}

ParaBirimi MUrunSatisBilgileri::getUrunSatisFiyati() const
{
    return urunSatisFiyati;
}

ParaBirimi MUrunSatisBilgileri::getToplam() const
{
    return urunSatisFiyati*urunSatisMiktari;
}

void MUrunSatisBilgileri::setUrunSatisFiyati(const ParaBirimi &value)
{
    if (value==urunSatisFiyati)
        return;
    urunSatisFiyati = value;
    emit urunSatisFiyatiDegisti(urunSatisFiyati);
}

QDataStream &operator<<(QDataStream &a, const MUrunSatisBilgileriPtr &b)
{
       a << b->getId() << b->getUrunSatisMiktari() << b->getUrunSatisFiyati();
       return a;
}
QDataStream &operator>>(QDataStream &a, MUrunSatisBilgileriPtr &b)
{
    IdTuru urunSatisId;
    TamSayi urunSatisMiktari;
    ParaBirimi urunSatisFiyati;

    a>> urunSatisId >> urunSatisMiktari >> urunSatisFiyati;

    b = std::make_shared<MUrunSatisBilgileri>();

    b->setId(urunSatisId);
    b->setUrunSatisMiktari(urunSatisMiktari);
    b->setUrunSatisFiyati(urunSatisFiyati);

    return a ;
}


