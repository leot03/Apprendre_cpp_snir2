#ifndef BANQUE_H
#define BANQUE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDialog>

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Banque; }
QT_END_NAMESPACE

class Banque : public QWidget
{
    Q_OBJECT

public:
    Banque(QWidget *parent = nullptr);
    ~Banque();

private slots:
    void on_pushButton_quitter_clicked();
    void on_pushButton_connexionBDD_clicked();
    void on_pushButton_afficherInfosComptes_clicked();
    void on_pushButton_ajout_clicked();
    void on_pushButton_deconnexionBDD_clicked();

private:
    Ui::Banque *ui;
    QSqlDatabase bd;
};
#endif // BANQUE_H
