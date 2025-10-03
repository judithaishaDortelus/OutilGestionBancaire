/********************************************************************************
** Form generated from reading UI file 'DialogAjoutEpargne.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTEPARGNE_H
#define UI_DIALOGAJOUTEPARGNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogAjoutEpargne
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *descriptionEpargne;
    QPushButton *OK;
    QLineEdit *noCompteEpargne;
    QLineEdit *tauxInteretEpargne;
    QLineEdit *soldeEpargne;

    void setupUi(QDialog *DialogAjoutEpargne)
    {
        if (DialogAjoutEpargne->objectName().isEmpty())
            DialogAjoutEpargne->setObjectName(QString::fromUtf8("DialogAjoutEpargne"));
        DialogAjoutEpargne->resize(489, 417);
        label = new QLabel(DialogAjoutEpargne);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 76, 20));
        label_2 = new QLabel(DialogAjoutEpargne);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 100, 76, 20));
        label_3 = new QLabel(DialogAjoutEpargne);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 160, 76, 20));
        label_4 = new QLabel(DialogAjoutEpargne);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 230, 101, 20));
        descriptionEpargne = new QLineEdit(DialogAjoutEpargne);
        descriptionEpargne->setObjectName(QString::fromUtf8("descriptionEpargne"));
        descriptionEpargne->setGeometry(QRect(160, 230, 261, 32));
        OK = new QPushButton(DialogAjoutEpargne);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setGeometry(QRect(170, 350, 112, 32));
        noCompteEpargne = new QLineEdit(DialogAjoutEpargne);
        noCompteEpargne->setObjectName(QString::fromUtf8("noCompteEpargne"));
        noCompteEpargne->setGeometry(QRect(160, 40, 113, 32));
        tauxInteretEpargne = new QLineEdit(DialogAjoutEpargne);
        tauxInteretEpargne->setObjectName(QString::fromUtf8("tauxInteretEpargne"));
        tauxInteretEpargne->setGeometry(QRect(160, 100, 113, 32));
        soldeEpargne = new QLineEdit(DialogAjoutEpargne);
        soldeEpargne->setObjectName(QString::fromUtf8("soldeEpargne"));
        soldeEpargne->setGeometry(QRect(160, 160, 113, 32));

        retranslateUi(DialogAjoutEpargne);
        QObject::connect(OK, SIGNAL(clicked()), DialogAjoutEpargne, SLOT(slotAjoutEpargne()));

        QMetaObject::connectSlotsByName(DialogAjoutEpargne);
    } // setupUi

    void retranslateUi(QDialog *DialogAjoutEpargne)
    {
        DialogAjoutEpargne->setWindowTitle(QCoreApplication::translate("DialogAjoutEpargne", "DialogAjoutEpargne", nullptr));
        label->setText(QCoreApplication::translate("DialogAjoutEpargne", "Compte", nullptr));
        label_2->setText(QCoreApplication::translate("DialogAjoutEpargne", "Taux", nullptr));
        label_3->setText(QCoreApplication::translate("DialogAjoutEpargne", "Solde", nullptr));
        label_4->setText(QCoreApplication::translate("DialogAjoutEpargne", "Description", nullptr));
        descriptionEpargne->setText(QCoreApplication::translate("DialogAjoutEpargne", "Epargne", nullptr));
        OK->setText(QCoreApplication::translate("DialogAjoutEpargne", "OK", nullptr));
        noCompteEpargne->setText(QCoreApplication::translate("DialogAjoutEpargne", "1234", nullptr));
        tauxInteretEpargne->setText(QCoreApplication::translate("DialogAjoutEpargne", "0.1", nullptr));
        soldeEpargne->setText(QCoreApplication::translate("DialogAjoutEpargne", "200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAjoutEpargne: public Ui_DialogAjoutEpargne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTEPARGNE_H
