#ifndef MALISFATURASI_H
#define MALISFATURASI_H

#include <QObject>
#include<Veri/tanimlar.h>


class MAlisFaturasi : public QObject
{
    Q_OBJECT
public:
    explicit MAlisFaturasi(QObject *parent = nullptr);
    Q_PROPERTY(IdTuru id READ getId WRITE setId NOTIFY idDegisti);
    Q_PROPERTY(Tarih urunAlisTarihi READ getUrunAlisTarihi WRITE setUrunAlisTarihi NOTIFY urunAlisTarihiDegisti);
    Q_PROPERTY(Metin faturaNo READ getFaturaNo WRITE setFaturaNo NOTIFY faturaNoDegisti);

    IdTuru getId() const;
    Tarih getUrunAlisTarihi() const;
    Metin getFaturaNo() const;


signals:
    void faturaNoDegisti(const Metin &value);
    void urunAlisTarihiDegisti(const Tarih &value);
    void idDegisti(const IdTuru &value);

public slots:
    void setId(const IdTuru &value);
    void setFaturaNo(const Metin &value);
    void setUrunAlisTarihi(const Tarih &value);

private:
    IdTuru urunAlisFaturaId;
    Tarih urunAlisTarihi;
    Metin faturaNo;


};
QDataStream &operator<<(QDataStream &a, const MAlisFaturasiPtr &b);
QDataStream &operator>>(QDataStream &a, MAlisFaturasiPtr &b);

#endif // MALISFATURASI_H
