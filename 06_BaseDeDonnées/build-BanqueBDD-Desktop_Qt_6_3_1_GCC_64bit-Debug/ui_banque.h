/********************************************************************************
** Form generated from reading UI file 'banque.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANQUE_H
#define UI_BANQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Banque
{
public:
    QGroupBox *groupBox_connexionBDD;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_general;
    QHBoxLayout *horizontalLayout_menu;
    QVBoxLayout *verticalLayout_menuGauche;
    QLabel *label_adresseIP;
    QLabel *label_nomBDD;
    QLabel *label_nomBDD_2;
    QLabel *label_motDePasse;
    QVBoxLayout *verticalLayout_menudroite;
    QLineEdit *lineEdit_adresseIP;
    QLineEdit *lineEdit_nomBDD;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_motDePasse;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_connexionBDD;
    QPushButton *pushButton_deconnexionBDD;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_infosBanque;
    QPushButton *pushButton_afficherInfosComptes;
    QTextEdit *textEdit_infoBanque;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget_infoBanque;
    QPushButton *pushButton_ajout;
    QPushButton *pushButton_quitter;

    void setupUi(QWidget *Banque)
    {
        if (Banque->objectName().isEmpty())
            Banque->setObjectName(QString::fromUtf8("Banque"));
        Banque->setEnabled(true);
        Banque->resize(652, 660);
        groupBox_connexionBDD = new QGroupBox(Banque);
        groupBox_connexionBDD->setObjectName(QString::fromUtf8("groupBox_connexionBDD"));
        groupBox_connexionBDD->setGeometry(QRect(20, 20, 611, 201));
        widget = new QWidget(groupBox_connexionBDD);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 50, 509, 112));
        horizontalLayout_general = new QHBoxLayout(widget);
        horizontalLayout_general->setObjectName(QString::fromUtf8("horizontalLayout_general"));
        horizontalLayout_general->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_menu = new QHBoxLayout();
        horizontalLayout_menu->setObjectName(QString::fromUtf8("horizontalLayout_menu"));
        verticalLayout_menuGauche = new QVBoxLayout();
        verticalLayout_menuGauche->setObjectName(QString::fromUtf8("verticalLayout_menuGauche"));
        label_adresseIP = new QLabel(widget);
        label_adresseIP->setObjectName(QString::fromUtf8("label_adresseIP"));

        verticalLayout_menuGauche->addWidget(label_adresseIP);

        label_nomBDD = new QLabel(widget);
        label_nomBDD->setObjectName(QString::fromUtf8("label_nomBDD"));

        verticalLayout_menuGauche->addWidget(label_nomBDD);

        label_nomBDD_2 = new QLabel(widget);
        label_nomBDD_2->setObjectName(QString::fromUtf8("label_nomBDD_2"));

        verticalLayout_menuGauche->addWidget(label_nomBDD_2);

        label_motDePasse = new QLabel(widget);
        label_motDePasse->setObjectName(QString::fromUtf8("label_motDePasse"));

        verticalLayout_menuGauche->addWidget(label_motDePasse);


        horizontalLayout_menu->addLayout(verticalLayout_menuGauche);

        verticalLayout_menudroite = new QVBoxLayout();
        verticalLayout_menudroite->setObjectName(QString::fromUtf8("verticalLayout_menudroite"));
        lineEdit_adresseIP = new QLineEdit(widget);
        lineEdit_adresseIP->setObjectName(QString::fromUtf8("lineEdit_adresseIP"));

        verticalLayout_menudroite->addWidget(lineEdit_adresseIP);

        lineEdit_nomBDD = new QLineEdit(widget);
        lineEdit_nomBDD->setObjectName(QString::fromUtf8("lineEdit_nomBDD"));

        verticalLayout_menudroite->addWidget(lineEdit_nomBDD);

        lineEdit_login = new QLineEdit(widget);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setEchoMode(QLineEdit::Normal);

        verticalLayout_menudroite->addWidget(lineEdit_login);

        lineEdit_motDePasse = new QLineEdit(widget);
        lineEdit_motDePasse->setObjectName(QString::fromUtf8("lineEdit_motDePasse"));
        lineEdit_motDePasse->setEchoMode(QLineEdit::Password);

        verticalLayout_menudroite->addWidget(lineEdit_motDePasse);


        horizontalLayout_menu->addLayout(verticalLayout_menudroite);


        horizontalLayout_general->addLayout(horizontalLayout_menu);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_general->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_connexionBDD = new QPushButton(widget);
        pushButton_connexionBDD->setObjectName(QString::fromUtf8("pushButton_connexionBDD"));
        pushButton_connexionBDD->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_connexionBDD->setAcceptDrops(false);

        verticalLayout_3->addWidget(pushButton_connexionBDD);

        pushButton_deconnexionBDD = new QPushButton(widget);
        pushButton_deconnexionBDD->setObjectName(QString::fromUtf8("pushButton_deconnexionBDD"));
        pushButton_deconnexionBDD->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_deconnexionBDD->setAcceptDrops(false);

        verticalLayout_3->addWidget(pushButton_deconnexionBDD);


        horizontalLayout_general->addLayout(verticalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_general->addItem(horizontalSpacer);

        groupBox_infosBanque = new QGroupBox(Banque);
        groupBox_infosBanque->setObjectName(QString::fromUtf8("groupBox_infosBanque"));
        groupBox_infosBanque->setGeometry(QRect(20, 240, 611, 371));
        pushButton_afficherInfosComptes = new QPushButton(groupBox_infosBanque);
        pushButton_afficherInfosComptes->setObjectName(QString::fromUtf8("pushButton_afficherInfosComptes"));
        pushButton_afficherInfosComptes->setGeometry(QRect(20, 30, 291, 23));
        pushButton_afficherInfosComptes->setCursor(QCursor(Qt::PointingHandCursor));
        textEdit_infoBanque = new QTextEdit(groupBox_infosBanque);
        textEdit_infoBanque->setObjectName(QString::fromUtf8("textEdit_infoBanque"));
        textEdit_infoBanque->setGeometry(QRect(20, 60, 571, 71));
        widget1 = new QWidget(groupBox_infosBanque);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 150, 571, 201));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableWidget_infoBanque = new QTableWidget(widget1);
        if (tableWidget_infoBanque->columnCount() < 4)
            tableWidget_infoBanque->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_infoBanque->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_infoBanque->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_infoBanque->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_infoBanque->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget_infoBanque->setObjectName(QString::fromUtf8("tableWidget_infoBanque"));

        verticalLayout_2->addWidget(tableWidget_infoBanque);

        pushButton_ajout = new QPushButton(widget1);
        pushButton_ajout->setObjectName(QString::fromUtf8("pushButton_ajout"));
        pushButton_ajout->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(pushButton_ajout);

        pushButton_quitter = new QPushButton(Banque);
        pushButton_quitter->setObjectName(QString::fromUtf8("pushButton_quitter"));
        pushButton_quitter->setGeometry(QRect(550, 620, 80, 23));
        pushButton_quitter->setCursor(QCursor(Qt::PointingHandCursor));

        retranslateUi(Banque);

        QMetaObject::connectSlotsByName(Banque);
    } // setupUi

    void retranslateUi(QWidget *Banque)
    {
        Banque->setWindowTitle(QCoreApplication::translate("Banque", "La Banque des SNIR", nullptr));
        groupBox_connexionBDD->setTitle(QCoreApplication::translate("Banque", "Connexion \303\240 la BDD", nullptr));
        label_adresseIP->setText(QCoreApplication::translate("Banque", "Adresse IP :", nullptr));
        label_nomBDD->setText(QCoreApplication::translate("Banque", "Nom de la base de donn\303\251es :", nullptr));
        label_nomBDD_2->setText(QCoreApplication::translate("Banque", "Login :", nullptr));
        label_motDePasse->setText(QCoreApplication::translate("Banque", "Mot de passe :", nullptr));
        lineEdit_adresseIP->setText(QCoreApplication::translate("Banque", "172.18.58.8", nullptr));
        lineEdit_nomBDD->setText(QCoreApplication::translate("Banque", "banque", nullptr));
        lineEdit_login->setText(QCoreApplication::translate("Banque", "snir", nullptr));
        lineEdit_login->setPlaceholderText(QCoreApplication::translate("Banque", "snir", nullptr));
        lineEdit_motDePasse->setText(QCoreApplication::translate("Banque", "snir", nullptr));
        lineEdit_motDePasse->setPlaceholderText(QCoreApplication::translate("Banque", "snir", nullptr));
        pushButton_connexionBDD->setText(QCoreApplication::translate("Banque", "Connexion \303\240 la base\n"
"de donn\303\251es", nullptr));
        pushButton_deconnexionBDD->setText(QCoreApplication::translate("Banque", "D\303\251connexion de la base\n"
"de donn\303\251es", nullptr));
        groupBox_infosBanque->setTitle(QCoreApplication::translate("Banque", "Informations de la banque", nullptr));
        pushButton_afficherInfosComptes->setText(QCoreApplication::translate("Banque", "Afficher les informations de tous les comptes", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_infoBanque->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Banque", "Num\303\251ro de compte", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_infoBanque->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Banque", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_infoBanque->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Banque", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_infoBanque->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Banque", "Soldes en euros", nullptr));
        pushButton_ajout->setText(QCoreApplication::translate("Banque", "Ajouter", nullptr));
        pushButton_quitter->setText(QCoreApplication::translate("Banque", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Banque: public Ui_Banque {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANQUE_H
