#include "msatisfaturasi.h"

MSatisFaturasi::MSatisFaturasi(QObject *parent) : QObject(parent)
{

}

IdTuru MSatisFaturasi::getId() const
{
    return urunSatisFaturaId;
}

void MSatisFaturasi::setId(const IdTuru &value)
{
    if(value==urunSatisFaturaId)
        return;
    urunSatisFaturaId = value;
   emit idDegisti(urunSatisFaturaId);
}

Tarih MSatisFaturasi::getUrunSatisTarihi() const
{
    return urunSatisTarihi;
}

void MSatisFaturasi::setUrunSatisTarihi(const Tarih &value)
{
    if(value==urunSatisTarihi)
        return;
    urunSatisTarihi = value;
    emit urunSatisTarihiDegisti(urunSatisTarihi);
}

Metin MSatisFaturasi::getSatisFaturaNo() const
{
    return satisFaturaNo;
}

void MSatisFaturasi::setSatisFaturaNo(const Metin &value)
{
    if(value==satisFaturaNo)
        return;
    satisFaturaNo = value;
    emit satisFaturaNoDegisti(satisFaturaNo);
}

QDataStream &operator<<(QDataStream &a, const MSatisFaturasiPtr &b)
{
    a << b->getId() << b->getUrunSatisTarihi() << b->getSatisFaturaNo();
    return a;
}
QDataStream &operator>>(QDataStream &a, MSatisFaturasiPtr &b)
{
    IdTuru urunSatisFaturaId;
    Tarih urunSatisTarihi;
    Metin satisFaturaNo;

    a >> urunSatisFaturaId >> urunSatisTarihi >> satisFaturaNo;

    b = std::make_shared<MSatisFaturasi>();

    b->setId(urunSatisFaturaId);
    b->setUrunSatisTarihi(urunSatisTarihi);
    b->setSatisFaturaNo(satisFaturaNo);

    return a;
}


