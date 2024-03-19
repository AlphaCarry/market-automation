#ifndef MTEDARIKCIFORMU_H
#define MTEDARIKCIFORMU_H

#include <QDialog>
#include <Veri/tanimlar.h>

namespace Ui {
class MTedarikciFormu;
}

class MTedarikciFormu : public QDialog
{
    Q_OBJECT

public:
    explicit MTedarikciFormu(QWidget *parent = nullptr);
    ~MTedarikciFormu();

    MTedarikciPtr getVeri() const;
    void setVeri(const MTedarikciPtr& value);


private slots:
    void on_tabTedarikciIslemleri_tabCloseRequested(int index);
    void on_btnYeniTedarikci_clicked(int index);

    void on_btnDuzenle_clicked();

private:
    Ui::MTedarikciFormu *ui;
    MTedarikciPtr veri;
};

#endif // MTEDARIKCIFORMU_H
