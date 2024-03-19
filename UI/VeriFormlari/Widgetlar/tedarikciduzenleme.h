#ifndef TEDARIKCIDUZENLEME_H
#define TEDARIKCIDUZENLEME_H

#include <QWidget>
#include <QDialog>
#include<Veri/tanimlar.h>

namespace Ui {
class TedarikciDuzenleme;
}

class TedarikciDuzenleme : public QDialog
{
    Q_OBJECT

public:
    explicit TedarikciDuzenleme(QWidget *parent = nullptr);
    ~TedarikciDuzenleme();

    MTedarikciPtr getVeri() const;
    void setVeri(const MTedarikciPtr &value);

signals:
    void kaydetKapat();
    void iptalKapat();

private slots:
    void on_btnKaydet_clicked();

    void on_btnIptal_clicked();

private:
    Ui::TedarikciDuzenleme *ui;
    MTedarikciPtr veri;
};

#endif // TEDARIKCIDUZENLEME_H
