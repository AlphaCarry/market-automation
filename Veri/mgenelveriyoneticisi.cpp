
#include "Veri/VeriYoneticileri/malisfaturasiyoneticisi.h"
#include "Veri/VeriYoneticileri/mmusteribilgileriyoneticisi.h"
#include "Veri/VeriYoneticileri/mtedarikciyoneticisi.h"
#include "Veri/mgenelveriyoneticisi.h"

MGenelVeriYoneticisi::MGenelVeriYoneticisi(QObject *parent) : QObject(parent)
{

}

MGenelVeriYoneticisi &MGenelVeriYoneticisi::mfa()
{
    static MGenelVeriYoneticisi nesne;
    return nesne;
}

MAlisFaturasiYoneticisi &MGenelVeriYoneticisi::getAlisFaturalari()
{
    return alisFaturalari;
}

MMusteriBilgileriYoneticisi &MGenelVeriYoneticisi::getMusteriBilgileri()
{
    return musteriBilgileri;
}

MSatisFaturasiYoneticisi &MGenelVeriYoneticisi::getSatisFaturalari()
{
    return satisFaturalari;
}

MTedarikciYoneticisi &MGenelVeriYoneticisi::getTedarikciBilgileri()
{
    return tedarikciBilgileri;
}

MUrunAlisBilgisiYoneticisi &MGenelVeriYoneticisi::getAlisBilgileri()
{
    return alisBilgileri;
}

MUrunBilgisiYoneticisi &MGenelVeriYoneticisi::getUrunBilgileri()
{
    return urunBilgileri;
}

MUrunSatisBilgisiYoneticisi &MGenelVeriYoneticisi::getSatisBilgileri()
{
    return satisBilgileri;
}

QDataStream &operator<<(QDataStream &a, MGenelVeriYoneticisi &b)
{
    a << b.alisFaturalari << b.musteriBilgileri << b.satisFaturalari << b.tedarikciBilgileri << b.alisBilgileri << b.urunBilgileri << b.satisBilgileri;

    return a;
}

QDataStream &operator>>(QDataStream &a, MGenelVeriYoneticisi &b)
{
    a >> b.alisFaturalari >> b.musteriBilgileri >> b.satisFaturalari >> b.tedarikciBilgileri >> b.alisBilgileri >> b.urunBilgileri >> b.satisBilgileri;

    return a;
}

