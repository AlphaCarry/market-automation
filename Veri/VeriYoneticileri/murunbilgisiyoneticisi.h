#ifndef MURUNBILGISIYONETICISI_H
#define MURUNBILGISIYONETICISI_H

#include <QObject>
#include<Veri/tanimlar.h>
#include<Veri/VeriYoneticileri/temel_veri_yoneticisi.h>

class MUrunBilgisiYoneticisi : public QObject , public TemelVeriYoneticisi<MUrunBilgileri , MUrunBilgileriPtr>
{
    Q_OBJECT
public:
    explicit MUrunBilgisiYoneticisi(QObject *parent = nullptr);



    Ptr kopyaOlustur(Ptr kaynak) const;

signals:

private:

};

#endif // MURUNBILGISIYONETICISI_H
