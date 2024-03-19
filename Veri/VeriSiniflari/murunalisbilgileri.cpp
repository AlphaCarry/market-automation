#include "murunalisbilgileri.h"

MUrunAlisBilgileri::MUrunAlisBilgileri(QObject *parent) : QObject(parent)
{

}

IdTuru MUrunAlisBilgileri::getId() const
{
    return urunAlisId;
}

void MUrunAlisBilgileri::setId(const IdTuru &value)
{
    if(value==urunAlisId)
        return;
    urunAlisId = value;
    emit idDegisti(urunAlisId);
}

TamSayi MUrunAlisBilgileri::getUrunAlisMiktari() const
{
    return urunAlisMiktari;
}

void MUrunAlisBilgileri::setUrunAlisMiktari(const TamSayi &value)
{
    if(value==urunAlisMiktari)
        return;
    urunAlisMiktari = value;
    emit urunAlisMiktariDegisti(urunAlisMiktari);
}

ParaBirimi MUrunAlisBilgileri::getUrunAlisFiyati() const
{
    return urunAlisFiyati;
}

ParaBirimi MUrunAlisBilgileri::getToplam() const
{
    return urunAlisFiyati* urunAlisMiktari;
}

void MUrunAlisBilgileri::setUrunAlisFiyati(const ParaBirimi &value)
{
    if ( value==urunAlisFiyati )
        return;
    urunAlisFiyati = value;
    emit urunAlisFiyatiDegisti(urunAlisFiyati);
}

QDataStream &operator<<(QDataStream &a, const MUrunAlisBilgileriPtr &b)
{
    a << b->getId() << b->getUrunAlisMiktari() << b->getUrunAlisFiyati();
    return a;

}
QDataStream &operator>>(QDataStream &a, MUrunAlisBilgileriPtr &b)
{
    IdTuru urunAlisId;
    TamSayi urunAlisMiktari;
    ParaBirimi urunAlisFiyati;

    a >> urunAlisId >> urunAlisMiktari >> urunAlisFiyati;

    b=std::make_shared<MUrunAlisBilgileri>();

    b->setId(urunAlisId);
    b->setUrunAlisMiktari(urunAlisMiktari);
    b->setUrunAlisFiyati(urunAlisFiyati);

    return a;
}


