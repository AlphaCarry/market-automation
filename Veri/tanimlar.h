#ifndef TANIMLAR_H
#define TANIMLAR_H

#include<QtCore>
#include<QString>
#include<QDate>
#include<QTime>
#include<QDateTime>
#include<QByteArray>

typedef quint64 IdTuru;
typedef qint32 TamSayi ;

typedef double ReelSayi;

typedef int StokAdeti;

typedef float ParaBirimi ;

typedef QString Metin ;

typedef QDate Tarih;
typedef QTime Saat;
typedef QDateTime TarihSaat;

typedef  enum {
    AlkolluIcecek = 1,
    AlkolsuzIcecek = 2,
    SebzeMeyve = 4,
    TemelGida = 8,
    Atistirmalik = 16,
    KisiselBakim = 32,
    Elektronik = 64,
    Deterjan = 128,
    Yiyecek = 256,
    Saglik = 512,


}UrunTuru ;

typedef QByteArray Resim ;
//Pointer Tanımları

class MAlisFaturasi;
class MMusteriBilgileri;
class MSatisFaturasi;
class MTedarikci;
class MUrunAlisBilgileri;
class MUrunBilgileri;
class MUrunSatisBilgileri;
class MGenelVeriYoneticisi;
class MVeriYoneticisi;

#include<memory>

typedef std::shared_ptr<MAlisFaturasi> MAlisFaturasiPtr ;
typedef std::shared_ptr<MMusteriBilgileri> MMusteriBilgileriPtr ;
typedef std::shared_ptr<MSatisFaturasi> MSatisFaturasiPtr ;
typedef std::shared_ptr<MTedarikci> MTedarikciPtr ;
typedef std::shared_ptr<MUrunAlisBilgileri> MUrunAlisBilgileriPtr ;
typedef std::shared_ptr<MUrunBilgileri> MUrunBilgileriPtr ;
typedef std::shared_ptr<MUrunSatisBilgileri> MUrunSatisBilgileriPtr ;
typedef std::shared_ptr<MGenelVeriYoneticisi> MGenelVeriYoneticisiPtr ;

QDataStream &operator<<(QDataStream &a, const MAlisFaturasiPtr &b);
QDataStream &operator>>(QDataStream &a, MAlisFaturasiPtr &b);

QDataStream &operator<<(QDataStream &a, const MMusteriBilgileriPtr &b);
QDataStream &operator>>(QDataStream &a, MMusteriBilgileriPtr &b);

QDataStream &operator<<(QDataStream &a, const MSatisFaturasiPtr &b);
QDataStream &operator>>(QDataStream &a, MSatisFaturasiPtr &b);

QDataStream &operator<<(QDataStream &a, const MTedarikciPtr &b);
QDataStream &operator>>(QDataStream &a, MTedarikciPtr &b);

QDataStream &operator<<(QDataStream &a, const MUrunAlisBilgileriPtr &b);
QDataStream &operator>>(QDataStream &a, MUrunAlisBilgileriPtr &b);

QDataStream &operator<<(QDataStream &a, const MUrunBilgileriPtr &b);
QDataStream &operator>>(QDataStream &a, MUrunBilgileriPtr &b);

QDataStream &operator<<(QDataStream &a, const MUrunSatisBilgileriPtr &b);
QDataStream &operator>>(QDataStream &a, MUrunSatisBilgileriPtr &b);

//QDataStream &operator<<(QDataStream &a, const MGenelVeriYoneticisi &b);
//QDataStream &operator>>(QDataStream &a, MGenelVeriYoneticisiPtr &b);

#endif // TANIMLAR_H
