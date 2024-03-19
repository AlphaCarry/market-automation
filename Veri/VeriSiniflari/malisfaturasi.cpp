#include "malisfaturasi.h"

MAlisFaturasi::MAlisFaturasi(QObject *parent) : QObject(parent)
{

}

IdTuru MAlisFaturasi::getId() const
{
    return urunAlisFaturaId;
}

void MAlisFaturasi::setId(const IdTuru &value)
{
    if(value==urunAlisFaturaId)
        return;
    urunAlisFaturaId = value;
    emit idDegisti(urunAlisFaturaId);
}

Tarih MAlisFaturasi::getUrunAlisTarihi() const
{
    return urunAlisTarihi;
}

void MAlisFaturasi::setUrunAlisTarihi(const Tarih &value)
{
    if(value==urunAlisTarihi)
        return;
    urunAlisTarihi = value;
    emit urunAlisTarihiDegisti(urunAlisTarihi);
}

Metin MAlisFaturasi::getFaturaNo() const
{
    return faturaNo;
}

void MAlisFaturasi::setFaturaNo(const Metin &value)
{
    if(value==faturaNo)
        return;
    faturaNo = value;
    emit faturaNoDegisti(faturaNo);
}

QDataStream &operator<<(QDataStream &a, const MAlisFaturasiPtr &b)
{
    a << b->getId() << b->getFaturaNo() << b->getUrunAlisTarihi();
    return a;
}

QDataStream &operator>>(QDataStream &a, MAlisFaturasiPtr &b)
{
    IdTuru urunAlisFaturaId;
    Tarih urunAlisTarihi;
    Metin faturaNo;

    a >> urunAlisFaturaId >> urunAlisTarihi >> faturaNo;

    b = std::make_shared<MAlisFaturasi>();

    b->setId(urunAlisFaturaId);
    b->setUrunAlisTarihi(urunAlisTarihi);
    b->setFaturaNo(faturaNo);

    return a;
}


