/********************************************************************************
** Form generated from reading UI file 'DialogSupprimer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSUPPRIMER_H
#define UI_DIALOGSUPPRIMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogSupprimer
{
public:
    QPushButton *pushSupprimerButton;
    QLabel *label;
    QLineEdit *lineEditNumeroCompte;

    void setupUi(QDialog *DialogSupprimer)
    {
        if (DialogSupprimer->objectName().isEmpty())
            DialogSupprimer->setObjectName(QString::fromUtf8("DialogSupprimer"));
        DialogSupprimer->resize(400, 300);
        pushSupprimerButton = new QPushButton(DialogSupprimer);
        pushSupprimerButton->setObjectName(QString::fromUtf8("pushSupprimerButton"));
        pushSupprimerButton->setGeometry(QRect(140, 250, 90, 28));
        label = new QLabel(DialogSupprimer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 100, 58, 16));
        lineEditNumeroCompte = new QLineEdit(DialogSupprimer);
        lineEditNumeroCompte->setObjectName(QString::fromUtf8("lineEditNumeroCompte"));
        lineEditNumeroCompte->setGeometry(QRect(130, 90, 113, 28));

        retranslateUi(DialogSupprimer);
        QObject::connect(pushSupprimerButton, SIGNAL(clicked()), DialogSupprimer, SLOT(slotSupprimer()));

        QMetaObject::connectSlotsByName(DialogSupprimer);
    } // setupUi

    void retranslateUi(QDialog *DialogSupprimer)
    {
        DialogSupprimer->setWindowTitle(QCoreApplication::translate("DialogSupprimer", "DialogSupprimer", nullptr));
        pushSupprimerButton->setText(QCoreApplication::translate("DialogSupprimer", "Supprimer", nullptr));
        label->setText(QCoreApplication::translate("DialogSupprimer", "Compte", nullptr));
        lineEditNumeroCompte->setText(QCoreApplication::translate("DialogSupprimer", "1234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSupprimer: public Ui_DialogSupprimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSUPPRIMER_H
