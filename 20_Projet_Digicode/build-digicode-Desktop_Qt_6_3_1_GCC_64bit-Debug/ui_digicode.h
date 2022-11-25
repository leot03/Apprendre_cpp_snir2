/********************************************************************************
** Form generated from reading UI file 'digicode.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIGICODE_H
#define UI_DIGICODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_digicode
{
public:
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_1;
    QVBoxLayout *verticalLayout_droite;
    QPushButton *pushButton_Ok;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_On;
    QVBoxLayout *verticalLayout_gauche;
    QPushButton *pushButton_0;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;

    void setupUi(QWidget *digicode)
    {
        if (digicode->objectName().isEmpty())
            digicode->setObjectName(QString::fromUtf8("digicode"));
        digicode->resize(404, 428);
        QFont font;
        font.setPointSize(36);
        digicode->setFont(font);
        widget = new QWidget(digicode);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 369, 384));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        QFont font1;
        font1.setPointSize(35);
        pushButton_8->setFont(font1);
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        gridLayout_4->addWidget(pushButton_8, 2, 2, 1, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font1);
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        gridLayout_4->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font1);
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        gridLayout_4->addWidget(pushButton_5, 3, 2, 1, 1);

        pushButton_1 = new QPushButton(widget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setFont(font1);
        pushButton_1->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_1->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        gridLayout_4->addWidget(pushButton_1, 4, 0, 1, 1);

        verticalLayout_droite = new QVBoxLayout();
        verticalLayout_droite->setSpacing(6);
        verticalLayout_droite->setObjectName(QString::fromUtf8("verticalLayout_droite"));

        gridLayout_4->addLayout(verticalLayout_droite, 2, 3, 4, 1);

        pushButton_Ok = new QPushButton(widget);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));
        pushButton_Ok->setFont(font1);
        pushButton_Ok->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Ok->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        gridLayout_4->addWidget(pushButton_Ok, 5, 4, 1, 1);

        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QPalette palette;
        QBrush brush(QColor(85, 87, 83, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(238, 238, 236, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_7->setPalette(palette);
        pushButton_7->setFont(font1);
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        gridLayout_4->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setFont(font1);
        pushButton_9->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        gridLayout_4->addWidget(pushButton_9, 2, 4, 1, 1);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font1);
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        gridLayout_4->addWidget(pushButton_6, 3, 4, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font1);
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        gridLayout_4->addWidget(pushButton_3, 4, 4, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font1);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        gridLayout_4->addWidget(pushButton_2, 4, 2, 1, 1);

        pushButton_On = new QPushButton(widget);
        pushButton_On->setObjectName(QString::fromUtf8("pushButton_On"));
        pushButton_On->setFont(font1);
        pushButton_On->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_On->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        gridLayout_4->addWidget(pushButton_On, 5, 0, 1, 1);

        verticalLayout_gauche = new QVBoxLayout();
        verticalLayout_gauche->setObjectName(QString::fromUtf8("verticalLayout_gauche"));

        gridLayout_4->addLayout(verticalLayout_gauche, 2, 1, 4, 1);

        pushButton_0 = new QPushButton(widget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setFont(font1);
        pushButton_0->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_0->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        gridLayout_4->addWidget(pushButton_0, 5, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(4);
        lineEdit->setEchoMode(QLineEdit::Password);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setDragEnabled(false);
        lineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 5);


        retranslateUi(digicode);

        QMetaObject::connectSlotsByName(digicode);
    } // setupUi

    void retranslateUi(QWidget *digicode)
    {
        digicode->setWindowTitle(QCoreApplication::translate("digicode", "Digicode", nullptr));
        pushButton_8->setText(QCoreApplication::translate("digicode", "8", nullptr));
        pushButton_4->setText(QCoreApplication::translate("digicode", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("digicode", "5", nullptr));
        pushButton_1->setText(QCoreApplication::translate("digicode", "1", nullptr));
        pushButton_Ok->setText(QCoreApplication::translate("digicode", "Ok", nullptr));
        pushButton_7->setText(QCoreApplication::translate("digicode", "7", nullptr));
        pushButton_9->setText(QCoreApplication::translate("digicode", "9", nullptr));
        pushButton_6->setText(QCoreApplication::translate("digicode", "6", nullptr));
        pushButton_3->setText(QCoreApplication::translate("digicode", "3", nullptr));
        pushButton_2->setText(QCoreApplication::translate("digicode", "2", nullptr));
        pushButton_On->setText(QCoreApplication::translate("digicode", "On", nullptr));
        pushButton_0->setText(QCoreApplication::translate("digicode", "0", nullptr));
        lineEdit->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class digicode: public Ui_digicode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIGICODE_H
