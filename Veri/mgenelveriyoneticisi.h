#ifndef MGENELVERIYONETICISI_H
#define MGENELVERIYONETICISI_H

#include "Veri/VeriYoneticileri/mmusteribilgileriyoneticisi.h"
#include "Veri/VeriYoneticileri/msatisfaturasiyoneticisi.h"
#include "Veri/VeriYoneticileri/mtedarikciyoneticisi.h"
#include "Veri/VeriYoneticileri/murunalisbilgisiyoneticisi.h"
#include "Veri/VeriYoneticileri/murunbilgisiyoneticisi.h"
#include "Veri/VeriYoneticileri/murunsatisbilgisiyoneticisi.h"
#include "VeriYoneticileri/malisfaturasiyoneticisi.h"
#include "VeriYoneticileri/mmusteribilgileriyoneticisi.h"
#include "VeriYoneticileri/msatisfaturasiyoneticisi.h"
#include "VeriYoneticileri/murunalisbilgisiyoneticisi.h"
#include "VeriYoneticileri/murunbilgisiyoneticisi.h"
#include <QObject>


class MGenelVeriYoneticisi : public QObject
{
    Q_OBJECT
private:
    explicit MGenelVeriYoneticisi(QObject *parent = nullptr);

public:

    static MGenelVeriYoneticisi &mfa();

    MAlisFaturasiYoneticisi &getAlisFaturalari();
    MMusteriBilgileriYoneticisi &getMusteriBilgileri();
    MSatisFaturasiYoneticisi &getSatisFaturalari();
    MTedarikciYoneticisi &getTedarikciBilgileri();
    MUrunAlisBilgisiYoneticisi &getAlisBilgileri();
    MUrunBilgisiYoneticisi &getUrunBilgileri();
    MUrunSatisBilgisiYoneticisi &getSatisBilgileri();

signals:

private:
    MAlisFaturasiYoneticisi alisFaturalari;
    MMusteriBilgileriYoneticisi musteriBilgileri;
    MSatisFaturasiYoneticisi satisFaturalari;
    MTedarikciYoneticisi tedarikciBilgileri;
    MUrunAlisBilgisiYoneticisi alisBilgileri;
    MUrunBilgisiYoneticisi urunBilgileri;
    MUrunSatisBilgisiYoneticisi satisBilgileri;

    friend QDataStream &operator<<(QDataStream &a, MGenelVeriYoneticisi &b);
    friend QDataStream &operator>>(QDataStream &a, MGenelVeriYoneticisi &b);
};

QDataStream &operator<<(QDataStream &a, MGenelVeriYoneticisi &b);
QDataStream &operator>>(QDataStream &a, MGenelVeriYoneticisi &b);
#endif // MGENELVERIYONETICISI_H
