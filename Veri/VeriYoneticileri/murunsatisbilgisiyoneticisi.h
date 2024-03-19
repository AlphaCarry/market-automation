#ifndef MURUNSATISBILGISIYONETICISI_H
#define MURUNSATISBILGISIYONETICISI_H

#include <QObject>
#include<Veri/tanimlar.h>
#include<Veri/VeriYoneticileri/temel_veri_yoneticisi.h>

class MUrunSatisBilgisiYoneticisi : public QObject , public TemelVeriYoneticisi<MUrunSatisBilgileri , MUrunSatisBilgileriPtr>
{
    Q_OBJECT
public:
    explicit MUrunSatisBilgisiYoneticisi(QObject *parent = nullptr);



    Ptr kopyaOlustur(Ptr kaynak) const;

signals:

};

#endif // MURUNSATISBILGISIYONETICISI_H
