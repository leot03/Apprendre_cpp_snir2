#ifndef BDD_H
#define BDD_H
#include <QSqlDatabase>
#include <QSqlQuery>

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class bdd; }
QT_END_NAMESPACE

class bdd : public QWidget
{
    Q_OBJECT

public:
    bdd(QWidget *parent = nullptr);
    ~bdd();

private slots:
    void on_pushButton_Leave_clicked();
    void on_pushButton_Login_clicked();

    void on_pushButton_nomDepartement_clicked();

private:
    Ui::bdd *ui;
    QSqlDatabase bd;
};
#endif // BDD_H
