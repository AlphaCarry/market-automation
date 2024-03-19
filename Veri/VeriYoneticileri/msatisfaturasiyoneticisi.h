#ifndef MSATISFATURASIYONETICISI_H
#define MSATISFATURASIYONETICISI_H

#include <QObject>
#include<Veri/tanimlar.h>
#include<Veri/VeriYoneticileri/temel_veri_yoneticisi.h>


class MSatisFaturasiYoneticisi : public QObject ,public TemelVeriYoneticisi<MSatisFaturasi , MSatisFaturasiPtr>
{
    Q_OBJECT
public:
    explicit MSatisFaturasiYoneticisi(QObject *parent = nullptr);


    Ptr kopyaOlustur(Ptr kaynak) const;

signals:

};

#endif // MSATISFATURASIYONETICISI_H
