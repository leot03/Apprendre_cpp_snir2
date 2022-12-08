#include "banqueserveurwidget.h"
#include "ui_banqueserveurwidget.h"

BanqueServeurWidget::BanqueServeurWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BanqueServeurWidget)
    , laBanque(this)
{
    ui->setupUi(this);
    laBanque.Lancer();
}

BanqueServeurWidget::~BanqueServeurWidget()
{
    laBanque.Arreter();
    delete ui;
}

