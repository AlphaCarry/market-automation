#ifndef MSATISFATURASI_H
#define MSATISFATURASI_H

#include <QObject>
#include<Veri/tanimlar.h>

class MSatisFaturasi : public QObject
{
    Q_OBJECT
public:
    explicit MSatisFaturasi(QObject *parent = nullptr);

    Q_PROPERTY(IdTuru id READ getId WRITE setId NOTIFY idDegisti)
    Q_PROPERTY(Tarih urunSatisTarihi READ getUrunSatisTarihi WRITE setUrunSatisTarihi NOTIFY urunSatisTarihiDegisti)
    Q_PROPERTY(Metin satisFaturaNo READ getSatisFaturaNo WRITE setSatisFaturaNo NOTIFY satisFaturaNoDegisti)

    IdTuru getId() const;
    Tarih getUrunSatisTarihi() const;
    Metin getSatisFaturaNo() const;


signals:

    void idDegisti(const IdTuru &value);
    void urunSatisTarihiDegisti(const Tarih &value);
    void satisFaturaNoDegisti(const Metin &value);

public slots:
    void setId(const IdTuru &value);
    void setUrunSatisTarihi(const Tarih &value);
    void setSatisFaturaNo(const Metin &value);

private:
    IdTuru urunSatisFaturaId;
    Tarih urunSatisTarihi;
    Metin satisFaturaNo;


};

QDataStream &operator<<(QDataStream &a, const MSatisFaturasiPtr &b);
QDataStream &operator>>(QDataStream &a, MSatisFaturasiPtr &b);


#endif // MSATISFATURASI_H
