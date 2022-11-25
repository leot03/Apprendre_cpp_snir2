#include "porte.h"
#include "ui_porte.h"

Porte::Porte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Porte)
{
    ui->setupUi(this);
}

Porte::~Porte()
{
    delete ui;
}

void Porte::devreouiller()
{
    QLabel *img = new QLabel();
    img->setPixmap(QPixmap("/home/USERS/ELEVES/SNIR2021/lthomas/Github/Apprendre_cpp_snir2/20_Projet_Digicode/digicode/porte_fermee.png"));
}

void Porte::verouiller()
{

}
