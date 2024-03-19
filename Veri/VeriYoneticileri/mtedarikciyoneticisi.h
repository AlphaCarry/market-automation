#ifndef MTEDARIKCIYONETICISI_H
#define MTEDARIKCIYONETICISI_H

#include <QObject>
#include<Veri/tanimlar.h>
#include<Veri/VeriYoneticileri/temel_veri_yoneticisi.h>

class MTedarikciYoneticisi : public QObject ,public TemelVeriYoneticisi<MTedarikci , MTedarikciPtr>
{
    Q_OBJECT
public:
    explicit MTedarikciYoneticisi(QObject *parent = nullptr);



    Ptr kopyaOlustur(Ptr kaynak) const;

signals:

};

#endif // MTEDARIKCIYONETICISI_H
