/********************************************************************************
** Form generated from reading UI file 'DialogAjoutCheque.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTCHEQUE_H
#define UI_DIALOGAJOUTCHEQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogAjoutCheque
{
public:
    QLabel *compte;
    QLabel *taux;
    QLabel *solde;
    QLabel *description;
    QLabel *nbTransac;
    QLabel *tauxMin;
    QLineEdit *noCompteCheque;
    QLineEdit *tauxInteretCheque;
    QLineEdit *soldeCheque;
    QLineEdit *descriptionCheque;
    QLineEdit *nbTransactions;
    QLineEdit *tauxMinimum;
    QPushButton *OK;

    void setupUi(QDialog *DialogAjoutCheque)
    {
        if (DialogAjoutCheque->objectName().isEmpty())
            DialogAjoutCheque->setObjectName(QString::fromUtf8("DialogAjoutCheque"));
        DialogAjoutCheque->resize(502, 351);
        compte = new QLabel(DialogAjoutCheque);
        compte->setObjectName(QString::fromUtf8("compte"));
        compte->setGeometry(QRect(30, 30, 76, 20));
        taux = new QLabel(DialogAjoutCheque);
        taux->setObjectName(QString::fromUtf8("taux"));
        taux->setGeometry(QRect(30, 70, 76, 20));
        solde = new QLabel(DialogAjoutCheque);
        solde->setObjectName(QString::fromUtf8("solde"));
        solde->setGeometry(QRect(30, 120, 76, 20));
        description = new QLabel(DialogAjoutCheque);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(30, 170, 101, 20));
        nbTransac = new QLabel(DialogAjoutCheque);
        nbTransac->setObjectName(QString::fromUtf8("nbTransac"));
        nbTransac->setGeometry(QRect(30, 220, 121, 20));
        tauxMin = new QLabel(DialogAjoutCheque);
        tauxMin->setObjectName(QString::fromUtf8("tauxMin"));
        tauxMin->setGeometry(QRect(30, 270, 76, 20));
        noCompteCheque = new QLineEdit(DialogAjoutCheque);
        noCompteCheque->setObjectName(QString::fromUtf8("noCompteCheque"));
        noCompteCheque->setGeometry(QRect(180, 20, 113, 32));
        tauxInteretCheque = new QLineEdit(DialogAjoutCheque);
        tauxInteretCheque->setObjectName(QString::fromUtf8("tauxInteretCheque"));
        tauxInteretCheque->setGeometry(QRect(180, 70, 113, 32));
        soldeCheque = new QLineEdit(DialogAjoutCheque);
        soldeCheque->setObjectName(QString::fromUtf8("soldeCheque"));
        soldeCheque->setGeometry(QRect(180, 120, 113, 32));
        descriptionCheque = new QLineEdit(DialogAjoutCheque);
        descriptionCheque->setObjectName(QString::fromUtf8("descriptionCheque"));
        descriptionCheque->setGeometry(QRect(180, 170, 113, 32));
        nbTransactions = new QLineEdit(DialogAjoutCheque);
        nbTransactions->setObjectName(QString::fromUtf8("nbTransactions"));
        nbTransactions->setGeometry(QRect(180, 210, 113, 32));
        tauxMinimum = new QLineEdit(DialogAjoutCheque);
        tauxMinimum->setObjectName(QString::fromUtf8("tauxMinimum"));
        tauxMinimum->setGeometry(QRect(180, 260, 113, 32));
        OK = new QPushButton(DialogAjoutCheque);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setGeometry(QRect(180, 310, 112, 32));

        retranslateUi(DialogAjoutCheque);
        QObject::connect(OK, SIGNAL(clicked()), DialogAjoutCheque, SLOT(slotAjoutCheque()));

        QMetaObject::connectSlotsByName(DialogAjoutCheque);
    } // setupUi

    void retranslateUi(QDialog *DialogAjoutCheque)
    {
        DialogAjoutCheque->setWindowTitle(QCoreApplication::translate("DialogAjoutCheque", "DialogAjoutCheque", nullptr));
        compte->setText(QCoreApplication::translate("DialogAjoutCheque", "Compte", nullptr));
        taux->setText(QCoreApplication::translate("DialogAjoutCheque", "Taux", nullptr));
        solde->setText(QCoreApplication::translate("DialogAjoutCheque", "Solde", nullptr));
        description->setText(QCoreApplication::translate("DialogAjoutCheque", "Description", nullptr));
        nbTransac->setText(QCoreApplication::translate("DialogAjoutCheque", "Nb Transaction", nullptr));
        tauxMin->setText(QCoreApplication::translate("DialogAjoutCheque", "Taux min", nullptr));
        noCompteCheque->setText(QCoreApplication::translate("DialogAjoutCheque", " 9000", nullptr));
        tauxInteretCheque->setText(QCoreApplication::translate("DialogAjoutCheque", "0.2", nullptr));
        soldeCheque->setText(QCoreApplication::translate("DialogAjoutCheque", "300", nullptr));
        descriptionCheque->setText(QCoreApplication::translate("DialogAjoutCheque", " Cheque", nullptr));
        nbTransactions->setText(QCoreApplication::translate("DialogAjoutCheque", "20", nullptr));
        tauxMinimum->setText(QCoreApplication::translate("DialogAjoutCheque", "0.1", nullptr));
        OK->setText(QCoreApplication::translate("DialogAjoutCheque", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAjoutCheque: public Ui_DialogAjoutCheque {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTCHEQUE_H
