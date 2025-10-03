/********************************************************************************
** Form generated from reading UI file 'GestionCompteGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONCOMPTEGUI_H
#define UI_GESTIONCOMPTEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestionCompteGUI
{
public:
    QAction *actionAjouter_un_compte_client;
    QAction *actionSupprimer_un_compte;
    QAction *actionQuitter;
    QAction *actionAjouter_un_compte;
    QAction *actionSupprimer_un_compte_2;
    QAction *actionQuitter_2;
    QAction *actionSupprimer_un_compte_3;
    QAction *actionEpargne;
    QAction *actionCheque;
    QWidget *centralwidget;
    QTextEdit *afficherClient;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GestionCompteGUI)
    {
        if (GestionCompteGUI->objectName().isEmpty())
            GestionCompteGUI->setObjectName(QString::fromUtf8("GestionCompteGUI"));
        GestionCompteGUI->resize(800, 600);
        actionAjouter_un_compte_client = new QAction(GestionCompteGUI);
        actionAjouter_un_compte_client->setObjectName(QString::fromUtf8("actionAjouter_un_compte_client"));
        actionSupprimer_un_compte = new QAction(GestionCompteGUI);
        actionSupprimer_un_compte->setObjectName(QString::fromUtf8("actionSupprimer_un_compte"));
        actionQuitter = new QAction(GestionCompteGUI);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionAjouter_un_compte = new QAction(GestionCompteGUI);
        actionAjouter_un_compte->setObjectName(QString::fromUtf8("actionAjouter_un_compte"));
        actionSupprimer_un_compte_2 = new QAction(GestionCompteGUI);
        actionSupprimer_un_compte_2->setObjectName(QString::fromUtf8("actionSupprimer_un_compte_2"));
        actionQuitter_2 = new QAction(GestionCompteGUI);
        actionQuitter_2->setObjectName(QString::fromUtf8("actionQuitter_2"));
        actionSupprimer_un_compte_3 = new QAction(GestionCompteGUI);
        actionSupprimer_un_compte_3->setObjectName(QString::fromUtf8("actionSupprimer_un_compte_3"));
        actionEpargne = new QAction(GestionCompteGUI);
        actionEpargne->setObjectName(QString::fromUtf8("actionEpargne"));
        actionCheque = new QAction(GestionCompteGUI);
        actionCheque->setObjectName(QString::fromUtf8("actionCheque"));
        centralwidget = new QWidget(GestionCompteGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        afficherClient = new QTextEdit(centralwidget);
        afficherClient->setObjectName(QString::fromUtf8("afficherClient"));
        afficherClient->setGeometry(QRect(73, 14, 621, 481));
        GestionCompteGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GestionCompteGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter = new QMenu(menuMenu);
        menuAjouter->setObjectName(QString::fromUtf8("menuAjouter"));
        GestionCompteGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(GestionCompteGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GestionCompteGUI->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter->menuAction());
        menuMenu->addAction(actionSupprimer_un_compte_3);
        menuMenu->addAction(actionQuitter_2);
        menuAjouter->addAction(actionEpargne);
        menuAjouter->addAction(actionCheque);

        retranslateUi(GestionCompteGUI);
        QObject::connect(actionQuitter_2, SIGNAL(triggered()), GestionCompteGUI, SLOT(close()));
        QObject::connect(actionEpargne, SIGNAL(triggered()), GestionCompteGUI, SLOT(slotAjoutEpargne()));
        QObject::connect(actionCheque, SIGNAL(triggered()), GestionCompteGUI, SLOT(slotAjoutCheque()));
        QObject::connect(actionSupprimer_un_compte_3, SIGNAL(triggered()), GestionCompteGUI, SLOT(slotSupprimer()));

        QMetaObject::connectSlotsByName(GestionCompteGUI);
    } // setupUi

    void retranslateUi(QMainWindow *GestionCompteGUI)
    {
        GestionCompteGUI->setWindowTitle(QCoreApplication::translate("GestionCompteGUI", "GestionCompteGUI", nullptr));
        actionAjouter_un_compte_client->setText(QCoreApplication::translate("GestionCompteGUI", "Ajouter un compte ", nullptr));
        actionSupprimer_un_compte->setText(QCoreApplication::translate("GestionCompteGUI", "Supprimer un compte", nullptr));
        actionQuitter->setText(QCoreApplication::translate("GestionCompteGUI", "Quitter", nullptr));
        actionAjouter_un_compte->setText(QCoreApplication::translate("GestionCompteGUI", "dfgs", nullptr));
        actionSupprimer_un_compte_2->setText(QCoreApplication::translate("GestionCompteGUI", "Supprimer un compte", nullptr));
        actionQuitter_2->setText(QCoreApplication::translate("GestionCompteGUI", "Quitter", nullptr));
        actionSupprimer_un_compte_3->setText(QCoreApplication::translate("GestionCompteGUI", "Supprimer", nullptr));
        actionEpargne->setText(QCoreApplication::translate("GestionCompteGUI", "Epargne", nullptr));
        actionCheque->setText(QCoreApplication::translate("GestionCompteGUI", "Cheque", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("GestionCompteGUI", "Menu", nullptr));
        menuAjouter->setTitle(QCoreApplication::translate("GestionCompteGUI", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GestionCompteGUI: public Ui_GestionCompteGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONCOMPTEGUI_H
