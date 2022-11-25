/********************************************************************************
** Form generated from reading UI file 'boutonpoussoir.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOUTONPOUSSOIR_H
#define UI_BOUTONPOUSSOIR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoutonPoussoir
{
public:
    QPushButton *pushButtonBP;

    void setupUi(QWidget *BoutonPoussoir)
    {
        if (BoutonPoussoir->objectName().isEmpty())
            BoutonPoussoir->setObjectName(QString::fromUtf8("BoutonPoussoir"));
        BoutonPoussoir->resize(176, 174);
        pushButtonBP = new QPushButton(BoutonPoussoir);
        pushButtonBP->setObjectName(QString::fromUtf8("pushButtonBP"));
        pushButtonBP->setGeometry(QRect(30, 20, 131, 131));
        QIcon icon;
        icon.addFile(QString::fromUtf8("bouton_poussoir.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonBP->setIcon(icon);
        pushButtonBP->setIconSize(QSize(128, 128));

        retranslateUi(BoutonPoussoir);

        QMetaObject::connectSlotsByName(BoutonPoussoir);
    } // setupUi

    void retranslateUi(QWidget *BoutonPoussoir)
    {
        BoutonPoussoir->setWindowTitle(QCoreApplication::translate("BoutonPoussoir", "Form", nullptr));
        pushButtonBP->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BoutonPoussoir: public Ui_BoutonPoussoir {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOUTONPOUSSOIR_H
