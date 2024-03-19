#include "mtedarikci.h"

MTedarikci::MTedarikci(QObject *parent) : QObject(parent)
{

}

IdTuru MTedarikci::getId() const
{
    return tedarikciId;
}

void MTedarikci::setId(const IdTuru &value)
{
    if(value==tedarikciId)
        return;
    tedarikciId = value;
    emit idDegisti(tedarikciId);
}

Metin MTedarikci::getTedarikciAdi() const
{
    return tedarikciAdi;
}

void MTedarikci::setTedarikciAdi(const Metin &value)
{
    if(value==tedarikciAdi)
        return;
    tedarikciAdi = value;
    emit tedarikciAdiDegisti(tedarikciAdi);
}

Metin MTedarikci::getTedarikciAdresi() const
{
    return tedarikciAdresi;
}

void MTedarikci::setTedarikciAdresi(const Metin &value)
{
    if(value==tedarikciAdresi)
        return;
    tedarikciAdresi = value;
    emit tedarikciAdresiDegisti(tedarikciAdresi);
}

Metin MTedarikci::getTedarikciTelefon() const
{
    return tedarikciTelefon;
}

void MTedarikci::setTedarikciTelefon(const Metin &value)
{
    if(value==tedarikciTelefon)
        return;
    tedarikciTelefon = value;
    emit tedarikciTelefonDegisti(tedarikciTelefon);
}

Metin MTedarikci::getTedarikciYetkiliKisi() const
{
    return tedarikciYetkiliKisi;
}

void MTedarikci::setTedarikciYetkiliKisi(const Metin &value)
{
    if(value==tedarikciYetkiliKisi)
        return;
    tedarikciYetkiliKisi = value;
    emit tedarikciYetkiliKisiDegisti(tedarikciYetkiliKisi);
}

Metin MTedarikci::getTedarikciMailAdresi() const
{
    return tedarikciMailAdresi;
}

void MTedarikci::setTedarikciMailAdresi(const Metin &value)
{
    if(value==tedarikciMailAdresi)
        return;
    tedarikciMailAdresi = value;
    emit tedarikciMailAdresiDegisti(tedarikciMailAdresi);
}

QDataStream &operator<<(QDataStream &a, const MTedarikciPtr &b)
{
    a << b->getId() << b->getTedarikciAdi()<< b->getTedarikciAdresi() << b->getTedarikciTelefon() << b->getTedarikciYetkiliKisi()<< b->getTedarikciMailAdresi();
    return a;
}
QDataStream &operator>>(QDataStream &a, MTedarikciPtr &b)
{
    IdTuru tedarikciId;
    Metin tedarikciAdi;
    Metin tedarikciAdresi;
    Metin tedarikciTelefon;
    Metin tedarikciYetkiliKisi;
    Metin tedarikciMailAdresi;

    a >> tedarikciId >> tedarikciAdi >> tedarikciAdresi >> tedarikciTelefon>> tedarikciYetkiliKisi>> tedarikciMailAdresi;

    b = std::make_shared<MTedarikci>();

    b->setId(tedarikciId);
    b->setTedarikciAdi(tedarikciAdi);
    b->setTedarikciAdresi(tedarikciAdresi);
    b->setTedarikciTelefon(tedarikciTelefon);
    b->setTedarikciYetkiliKisi(tedarikciYetkiliKisi);
    b->setTedarikciMailAdresi(tedarikciMailAdresi);

    return a;
}
