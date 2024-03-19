#ifndef MYENIMUSTERIFORMU_H
#define MYENIMUSTERIFORMU_H

#include <QObject>
#include <QWidget>

#include <QWidget>
#include <QDialog>
#include<Veri/tanimlar.h>

namespace Ui {
class MYeniMusteriFormu;
}

class MYeniMusteriFormu : public QDialog
{
    Q_OBJECT

public:
    explicit *MYeniMusteriFormu(QWidget *parent = nullptr);
    ~MYeniMusteriFormu();

    MMusteriBilgileriPtr getVeri() const;
    void setVeri(const MMusteriBilgileriPtr &value);

signals:
    void kaydetKapat();
    void iptalKapat();

private slots:
    void on_btnKaydet_clicked();

    void on_btnIptal_clicked();

private:
    Ui::MYeniMusteriFormu *ui;
    MMusteriBilgileriPtr veri;
};

#endif // MYENIMUSTERIFORMU_H
