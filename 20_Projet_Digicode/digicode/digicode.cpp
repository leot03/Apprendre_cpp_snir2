#include "digicode.h"
#include "porte.h"
#include "ui_digicode.h"
#include "ui_porte.h"

digicode::digicode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::digicode)
{
    ui->setupUi(this);
    laPorte.show();
    laPorte.move(100, 300);
}

digicode::~digicode()
{
    delete ui;
}

void digicode::closeEvent(QCloseEvent *event)
{
    qDebug() << "clique sur fermer la fenêtre";
    close();
    event->accept();
}

void digicode::on_pushButton_On_clicked()
{
    ui->lineEdit->setText("");
}

void digicode::on_pushButton_Ok_clicked()
{
    //if(QLineEdit == "1234")

}

void digicode::on_pushButton_0_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "0");
}

void digicode::on_pushButton_1_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "1");
}


void digicode::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "2");
}


void digicode::on_pushButton_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "3");
}


void digicode::on_pushButton_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "4");
}


void digicode::on_pushButton_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "5");
}


void digicode::on_pushButton_6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "6");
}


void digicode::on_pushButton_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "7");
}


void digicode::on_pushButton_8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "8");
}


void digicode::on_pushButton_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "9");
}

