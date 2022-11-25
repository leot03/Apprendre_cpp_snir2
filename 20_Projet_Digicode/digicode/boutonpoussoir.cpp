#include "boutonpoussoir.h"
#include "ui_boutonpoussoir.h"

BoutonPoussoir::BoutonPoussoir(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BoutonPoussoir)
{
    ui->setupUi(this);
}

BoutonPoussoir::~BoutonPoussoir()
{
    delete ui;
}

void BoutonPoussoir::on_pushButtonBP_clicked()
{
    actions();
}

