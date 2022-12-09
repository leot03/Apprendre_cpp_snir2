#ifndef BANQUESERVEURWIDGET_H
#define BANQUESERVEURWIDGET_H

#include <QWidget>
#include "serveurbanque.h"



QT_BEGIN_NAMESPACE
namespace Ui { class BanqueServeurWidget; }
QT_END_NAMESPACE

class BanqueServeurWidget : public QWidget
{
    Q_OBJECT

public:
    BanqueServeurWidget(QWidget *parent = nullptr);
    ~BanqueServeurWidget();

private:
    Ui::BanqueServeurWidget *ui;
    ServeurBanque laBanque;
};
#endif // BANQUESERVEURWIDGET_H
