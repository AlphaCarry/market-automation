#ifndef MURUNLISTESI_H
#define MURUNLISTESI_H

#include <QDialog>

#include<Veri/VeriYoneticileri/murunbilgisiyoneticisi.h>

namespace Ui {
class MUrunListesi;
}

class MUrunListesi : public QDialog
{
    Q_OBJECT

public:
    explicit MUrunListesi(QWidget *parent = nullptr);
    ~MUrunListesi();

private slots:
    void on_btnAra_clicked();
    void ara();
    void on_btnKapat_clicked();

private:
    void listeGuncelle();
    void arama_yap();

    Ui::MUrunListesi *ui;
    MUrunBilgisiYoneticisi::VeriListesi liste;
};

#endif // MURUNLISTESI_H
