#ifndef MMUSTERIBILGILERIYONETICISI_H
#define MMUSTERIBILGILERIYONETICISI_H

#include "Veri/VeriSiniflari/mmusteribilgileri.h"
#include <QObject>
#include<Veri/tanimlar.h>
#include<Veri/VeriYoneticileri/temel_veri_yoneticisi.h>

class MMusteriBilgileriYoneticisi : public QObject , public TemelVeriYoneticisi<MMusteriBilgileri , MMusteriBilgileriPtr>
{
    Q_OBJECT
public:
    explicit MMusteriBilgileriYoneticisi(QObject *parent = nullptr);



    Ptr kopyaOlustur(Ptr kaynak) const;

signals:

};

#endif // MMUSTERIBILGILERIYONETICISI_H
