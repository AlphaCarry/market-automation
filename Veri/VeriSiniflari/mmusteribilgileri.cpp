#include "mmusteribilgileri.h"

MMusteriBilgileri::MMusteriBilgileri(QObject *parent) : QObject(parent)
{

}

IdTuru MMusteriBilgileri::getId() const
{
    return musteriId;
}

void MMusteriBilgileri::setId(const IdTuru &value)
{
    if(value==musteriId)
        return;
    musteriId = value;
    emit idDegisti(musteriId);
}

Metin MMusteriBilgileri::getMusteriAdSoyad() const
{
    return musteriAdSoyad;
}

void MMusteriBilgileri::setMusteriAdSoyad(const Metin &value)
{
    if(value==musteriAdSoyad)
        return;
    musteriAdSoyad = value;
    emit musteriAdSoyadDegisti(musteriAdSoyad);
}

Metin MMusteriBilgileri::getMusteriTelefonNumarasi() const
{

    return musteriTelefonNumarasi;
}

void MMusteriBilgileri::setMusteriTelefonNumarasi(const Metin &value)
{
    if(value==musteriTelefonNumarasi)
        return;
    musteriTelefonNumarasi = value;
    emit musteriTelefonNumarasiDegisti(musteriTelefonNumarasi);
}

Metin MMusteriBilgileri::getMusteriMailAdresi() const
{
    return musteriMailAdresi;
}

void MMusteriBilgileri::setMusteriMailAdresi(const Metin &value)
{
    if(value==musteriMailAdresi)
        return;
    musteriMailAdresi = value;
    emit musteriMailAdresiDegisti(musteriMailAdresi);
}

Metin MMusteriBilgileri::getMusteriAdresi() const
{
    return musteriAdresi;
}

void MMusteriBilgileri::setMusteriAdresi(const Metin &value)
{
    if(value==musteriAdresi)
        return;
    musteriAdresi = value;
    emit musteriAdresiDegisti(musteriAdresi);
}

QDataStream &operator<<(QDataStream &a, const MMusteriBilgileriPtr &b)
{
    a<< b->getId() << b->getMusteriAdSoyad() << b->getMusteriTelefonNumarasi() << b->getMusteriMailAdresi() << b->getMusteriAdresi();
    return a;
}

QDataStream &operator>>(QDataStream &a, MMusteriBilgileriPtr &b)
{
    IdTuru musteriId;
    Metin musteriAdSoyad;
    Metin musteriTelefonNumarasi;
    Metin musteriMailAdresi;
    Metin musteriAdresi;

    a>> musteriId >> musteriAdSoyad >> musteriTelefonNumarasi>> musteriMailAdresi>> musteriAdresi;

    b = std::make_shared<MMusteriBilgileri>();

    b->setId(musteriId);
    b->setMusteriAdSoyad(musteriAdSoyad);
    b->setMusteriTelefonNumarasi(musteriTelefonNumarasi);
    b->setMusteriMailAdresi(musteriMailAdresi);
    b->setMusteriAdresi(musteriAdresi);

    return a;
}

