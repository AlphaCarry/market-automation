#ifndef MANAPENCERE_H
#define MANAPENCERE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MAnaPencere; }
QT_END_NAMESPACE

class MAnaPencere : public QMainWindow
{
    Q_OBJECT

public:
    MAnaPencere(QWidget *parent = nullptr);
    ~MAnaPencere();

private slots:
    /*void on_actionTedarikciler_triggered();

    void on_actionMevcuturunler_triggered();

    void on_actionYeni_Tedarikci_Ekleme_triggered();

    void on_actionYeni_Tedarikci_Tanimla_triggered();

    void on_actionYeni_Tedarikci_Tanimlar_triggered();

    void on_actionYeniurun_Tanimlama_triggered();*/

    void on_actionTedarik_iler_triggered();

    void on_actionYeni_Tedarik_i_Tan_mla_triggered();

    void on_actionYeni_r_n_Tan_mlama_triggered();

    void on_actionMevcut_r_nler_triggered();

    void on_actionYeni_M_teri_triggered();

private:
    Ui::MAnaPencere *ui;
};

#endif // MANAPENCERE_H
