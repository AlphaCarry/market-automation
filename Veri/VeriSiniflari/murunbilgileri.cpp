#include "murunbilgileri.h"

MUrunBilgileri::MUrunBilgileri(QObject *parent) : QObject(parent)
{

}

IdTuru MUrunBilgileri::getId() const
{
    return urunId;
}

void MUrunBilgileri::setId(const IdTuru &value)
{
    if(value==urunId)
        return;
    urunId = value;
    emit idDegisti(urunId);
}

Metin MUrunBilgileri::getUrunAdi() const
{
    return urunAdi;
}

void MUrunBilgileri::setUrunAdi(const Metin &value)
{
    if(value==urunAdi)
        return;
    urunAdi = value;
    emit urunAdiDegisti(urunAdi);
}

UrunTuru MUrunBilgileri::getUrunTuru() const
{
    return urunTuru;
}

void MUrunBilgileri::setUrunTuru(const UrunTuru &value)
{
    if(value==urunTuru)
        return;
    urunTuru = value;
    emit urunTuruDegisti(urunTuru);
}

Metin MUrunBilgileri::getUrunDetayi() const
{
    return urunDetayi;
}

void MUrunBilgileri::setUrunDetayi(const Metin &value)
{
    if(value==urunDetayi)
        return;
    urunDetayi = value;
    emit urunDetayiDegisti(urunDetayi);
}

ReelSayi MUrunBilgileri::getUrunFiyati() const
{
    return urunFiyati;
}

void MUrunBilgileri::setUrunFiyati(const ReelSayi &value)
{
    if(qFuzzyCompare( urunFiyati , value))
        return;
    urunFiyati = value;
    emit urunFiyatiDegisti(urunFiyati);
}

TamSayi MUrunBilgileri::getStokAdeti() const
{
    return stokAdeti;
}

void MUrunBilgileri::setStokAdeti(const TamSayi &value)
{
    if(value==stokAdeti)
        return;
    stokAdeti = value;
    emit stokAdetiDegisti(stokAdeti);
}

ReelSayi MUrunBilgileri::getIndirimOrani() const
{
    return indirimOrani;
}

void MUrunBilgileri::setIndirimOrani(const ReelSayi &value)
{
    if(qFuzzyCompare( indirimOrani , value ))
        return;
    indirimOrani = value;
    emit indirimOraniDegisti(indirimOrani);
}

QDataStream &yaz(QDataStream &a, MUrunBilgileriPtr b)
{
    a<< b->getId() <<b->getUrunAdi() << b->getUrunDetayi() << b->getUrunFiyati() << b->getUrunTuru() << b->getIndirimOrani() << b->getStokAdeti();
    return a;
}

QDataStream &operator<<(QDataStream &a, const MUrunBilgileriPtr &b)
{
    a<< b->getId() << b->getUrunAdi() << b->getUrunTuru() << b->getUrunDetayi() << b->getUrunFiyati() << b->getUrunFiyati() << b->getStokAdeti() << b->getIndirimOrani();
    return a;

 }
QDataStream &operator>>(QDataStream &a, MUrunBilgileriPtr &b)
{
    IdTuru urunId;
    Metin urunAdi;
    UrunTuru urunTuru;
    Metin urunDetayi;
    ReelSayi urunFiyati;
    TamSayi stokAdeti;
    ReelSayi indirimOrani;

    a>> urunId >> urunAdi >> urunTuru >> urunDetayi>> urunFiyati>> stokAdeti >> indirimOrani;

    b = std::make_shared<MUrunBilgileri>();

    b->setId(urunId);
    b->setUrunAdi(urunAdi);
    b->setUrunTuru(urunTuru);
    b->setUrunDetayi(urunDetayi);
    b->setUrunFiyati(urunFiyati);
    b->setStokAdeti(stokAdeti);
    b->setIndirimOrani(indirimOrani);

    return a;


}
