#ifndef TEMEL_VERI_YONETICISI_H
#define TEMEL_VERI_YONETICISI_H

#include<Veri/tanimlar.h>

template <class V, class P>
class TemelVeriYoneticisi {
public:
    typedef V Veri  ;
    typedef P Ptr;
    typedef QList<Ptr> VeriListesi ;
    typedef std::function<bool(Ptr)> Sart;

    explicit TemelVeriYoneticisi()
    {
        enSonId = 0;
    }



    Ptr yeni() const
    {
        Ptr yeni = std::make_shared<Veri>();
        return yeni;
    }



    void ekle(Ptr urun){
        urun->setId(enSonId++);
        veriler.append(urun);
    }


    Ptr sil(IdTuru urunId)
{
    for( int i=0; i < veriler.size(); i++){
        if(veriler[i]->getId() == urunId){
            Ptr sonuc = veriler.takeAt(i);
            return sonuc;
        }
     }

    throw "Aranılan veri bulunamadı! Silme işlemi iptal edildi!";
}
Ptr sil(Ptr urun){
return sil(urun->getId());
}


Ptr ilkiniBul(Sart f){
for( int i=0; i < veriler.size(); i++){
    auto veri_i =veriler[i];
    if(f(veri_i)){
        return veri_i;
    }
    throw "Aranılan veri bulunamadı";
}
}
Ptr sonuncuyuBul(Sart f){
for( int i=veriler.size() - 1 ;  i >=0 ; i--){
    auto veri_i =veriler[i];
    if(f(veri_i)){
        return veri_i;
    }
    throw "Aranılan ürün bulunamadı";
    }
}
VeriListesi tumunuBul(Sart f){
VeriListesi sonuc;
for (int i = 0; i < veriler.size(); i++) {
Ptr veri_i = veriler[i];
if (f(veri_i)) {
sonuc.append(veri_i);
}
}
return sonuc;
}


protected:

    VeriListesi veriler;

    IdTuru enSonId;

    template<class H, class M>
    friend QDataStream &operator<<(QDataStream &a, TemelVeriYoneticisi<H, M> &b);

    template<class F, class B >
    friend QDataStream &operator>>(QDataStream &a, TemelVeriYoneticisi<F, B> &b);

};

template<class V, class P>
QDataStream&operator<<(QDataStream &a, TemelVeriYoneticisi<V, P> &b)
{
    a << b.enSonId <<b.veriler;
    return a;
}

template<class V, class P >
QDataStream&operator>>(QDataStream &a, TemelVeriYoneticisi<V, P> &b)
{
    a >> b.enSonId >> b.veriler;
    return a;
}
#endif // TEMEL_VERI_YONETICISI_H
