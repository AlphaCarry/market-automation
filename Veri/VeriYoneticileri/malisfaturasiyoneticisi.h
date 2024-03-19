#ifndef MALISFATURASIYONETICISI_H
#define MALISFATURASIYONETICISI_H

#include <QObject>
#include<Veri/VeriYoneticileri/temel_veri_yoneticisi.h>
#include<Veri/tanimlar.h>

class MAlisFaturasiYoneticisi : public QObject , public TemelVeriYoneticisi<MAlisFaturasi,MAlisFaturasiPtr>
{
    Q_OBJECT
public:
    explicit MAlisFaturasiYoneticisi(QObject *parent = nullptr);



    Ptr kopyaOlustur(Ptr kaynak) const;

signals:

};

#endif // MALISFATURASIYONETICISI_H
