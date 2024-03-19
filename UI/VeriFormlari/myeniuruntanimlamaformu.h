#ifndef MYENIURUNTANIMLAMAFORMU_H
#define MYENIURUNTANIMLAMAFORMU_H

#include <QDialog>
#include<Veri/tanimlar.h>

namespace Ui {
class MYeniUrunTanimlamaFormu;
}

class MYeniUrunTanimlamaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit MYeniUrunTanimlamaFormu(QWidget *parent = nullptr);
    ~MYeniUrunTanimlamaFormu();

    MUrunBilgileriPtr getVeri() const;
    void setVeri(const MUrunBilgileriPtr &value);

private slots:
//    void on_btnKaydet_clicked();

private:
    Ui::MYeniUrunTanimlamaFormu *ui;

    MUrunBilgileriPtr veri;
};

#endif // MYENIURUNTANIMLAMAFORMU_H
