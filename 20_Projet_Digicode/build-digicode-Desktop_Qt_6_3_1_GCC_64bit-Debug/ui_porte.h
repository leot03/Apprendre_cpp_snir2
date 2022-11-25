/********************************************************************************
** Form generated from reading UI file 'porte.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTE_H
#define UI_PORTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Porte
{
public:
    QLabel *labelImage;
    QLabel *labelEtat;

    void setupUi(QWidget *Porte)
    {
        if (Porte->objectName().isEmpty())
            Porte->setObjectName(QString::fromUtf8("Porte"));
        Porte->resize(400, 300);
        labelImage = new QLabel(Porte);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setGeometry(QRect(150, 30, 111, 161));
        labelImage->setPixmap(QPixmap(QString::fromUtf8("porte_fermee.png")));
        labelEtat = new QLabel(Porte);
        labelEtat->setObjectName(QString::fromUtf8("labelEtat"));
        labelEtat->setGeometry(QRect(70, 200, 261, 31));
        QFont font;
        font.setPointSize(19);
        labelEtat->setFont(font);

        retranslateUi(Porte);

        QMetaObject::connectSlotsByName(Porte);
    } // setupUi

    void retranslateUi(QWidget *Porte)
    {
        Porte->setWindowTitle(QCoreApplication::translate("Porte", "La Porte", nullptr));
        labelImage->setText(QString());
        labelEtat->setText(QCoreApplication::translate("Porte", "La porte est v\303\251rouill\303\251e", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Porte: public Ui_Porte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTE_H
