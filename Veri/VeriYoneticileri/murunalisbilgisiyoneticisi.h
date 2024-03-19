#ifndef MURUNALISBILGISIYONETICISI_H
#define MURUNALISBILGISIYONETICISI_H

#include <QObject>
#include<Veri/tanimlar.h>
#include<Veri/VeriYoneticileri/temel_veri_yoneticisi.h>

class MUrunAlisBilgisiYoneticisi : public QObject  , public TemelVeriYoneticisi<MUrunAlisBilgileri , MUrunAlisBilgileriPtr>
{
    Q_OBJECT
public:
    explicit MUrunAlisBilgisiYoneticisi(QObject *parent = nullptr);



    Ptr kopyaOlustur(Ptr kaynak) const;

signals:

};

#endif // MURUNALISBILGISIYONETICISI_H
