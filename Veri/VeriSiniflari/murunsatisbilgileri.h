#ifndef MURUNSATISBILGILERI_H
#define MURUNSATISBILGILERI_H

#include <QObject>
#include<Veri/tanimlar.h>

class MUrunSatisBilgileri : public QObject
{
    Q_OBJECT
public:
    explicit MUrunSatisBilgileri(QObject *parent = nullptr);

    Q_PROPERTY(IdTuru id READ getId WRITE setId NOTIFY idDegisti)
    Q_PROPERTY(TamSayi urunSatisMiktari READ getUrunSatisMiktari WRITE setUrunSatisMiktari NOTIFY urunSatisMiktariDegisti)
    Q_PROPERTY(ParaBirimi urunSatisFiyati READ getUrunSatisFiyati WRITE setUrunSatisFiyati NOTIFY urunSatisFiyatiDegisti)

    IdTuru getId() const;
    TamSayi getUrunSatisMiktari() const;
    ParaBirimi getUrunSatisFiyati() const;
    ParaBirimi getToplam() const;



signals:

    void idDegisti(const IdTuru &value);
    void urunSatisMiktariDegisti(const TamSayi &value);
    void urunSatisFiyatiDegisti(const ParaBirimi &value);

public slots:
    void setId(const IdTuru &value);
    void setUrunSatisMiktari(const TamSayi &value);
    void setUrunSatisFiyati(const ParaBirimi &value);


private:
    IdTuru urunSatisId;
    TamSayi urunSatisMiktari;
    ParaBirimi urunSatisFiyati;


};

QDataStream &operator<<(QDataStream &a, const MUrunSatisBilgileriPtr &b);
QDataStream &operator>>(QDataStream &a, MUrunSatisBilgileriPtr &b);

#endif // MURUNSATISBILGILERI_H
