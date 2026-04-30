/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOuvrir_un_fichier;
    QAction *actionEnregister;
    QAction *actionEnregister_sous;
    QAction *actionModification_pr_c_dente;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *ledName;
    QLabel *sexeLabel;
    QComboBox *comboSexe;
    QLabel *dateDeNaissanceLabel;
    QDateEdit *dateDeNaissanceDateEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnNettoyer;
    QPushButton *btnAjouter;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLabel *inputLabel;
    QLineEdit *ledChercher;
    QPushButton *btnEffacer;
    QSpacerItem *verticalSpacer;
    QLabel *nombreDEtudiantLabel;
    QLineEdit *ledNombreEtudiant;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnToutSupprimer;
    QPushButton *btnOuvrir;
    QPushButton *btnEnregistrer;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuModifier;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionOuvrir_un_fichier = new QAction(MainWindow);
        actionOuvrir_un_fichier->setObjectName("actionOuvrir_un_fichier");
        actionEnregister = new QAction(MainWindow);
        actionEnregister->setObjectName("actionEnregister");
        actionEnregister_sous = new QAction(MainWindow);
        actionEnregister_sous->setObjectName("actionEnregister_sous");
        actionModification_pr_c_dente = new QAction(MainWindow);
        actionModification_pr_c_dente->setObjectName("actionModification_pr_c_dente");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        ledName = new QLineEdit(groupBox);
        ledName->setObjectName("ledName");

        formLayout->setWidget(0, QFormLayout::FieldRole, ledName);

        sexeLabel = new QLabel(groupBox);
        sexeLabel->setObjectName("sexeLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, sexeLabel);

        comboSexe = new QComboBox(groupBox);
        comboSexe->addItem(QString());
        comboSexe->addItem(QString());
        comboSexe->setObjectName("comboSexe");

        formLayout->setWidget(1, QFormLayout::FieldRole, comboSexe);

        dateDeNaissanceLabel = new QLabel(groupBox);
        dateDeNaissanceLabel->setObjectName("dateDeNaissanceLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, dateDeNaissanceLabel);

        dateDeNaissanceDateEdit = new QDateEdit(groupBox);
        dateDeNaissanceDateEdit->setObjectName("dateDeNaissanceDateEdit");
        dateDeNaissanceDateEdit->setCalendarPopup(true);
        dateDeNaissanceDateEdit->setDate(QDate(2026, 6, 11));

        formLayout->setWidget(2, QFormLayout::FieldRole, dateDeNaissanceDateEdit);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnNettoyer = new QPushButton(centralwidget);
        btnNettoyer->setObjectName("btnNettoyer");
        btnNettoyer->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 97, 81);\n"
"color: rgb(94, 92, 100);"));

        horizontalLayout_2->addWidget(btnNettoyer);

        btnAjouter = new QPushButton(centralwidget);
        btnAjouter->setObjectName("btnAjouter");
        btnAjouter->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 162, 105);\n"
"color: rgb(94, 92, 100);"));

        horizontalLayout_2->addWidget(btnAjouter);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_2);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setObjectName("formLayout_2");
        inputLabel = new QLabel(groupBox_2);
        inputLabel->setObjectName("inputLabel");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, inputLabel);

        ledChercher = new QLineEdit(groupBox_2);
        ledChercher->setObjectName("ledChercher");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, ledChercher);

        btnEffacer = new QPushButton(groupBox_2);
        btnEffacer->setObjectName("btnEffacer");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, btnEffacer);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(3, QFormLayout::FieldRole, verticalSpacer);

        nombreDEtudiantLabel = new QLabel(groupBox_2);
        nombreDEtudiantLabel->setObjectName("nombreDEtudiantLabel");

        formLayout_2->setWidget(4, QFormLayout::LabelRole, nombreDEtudiantLabel);

        ledNombreEtudiant = new QLineEdit(groupBox_2);
        ledNombreEtudiant->setObjectName("ledNombreEtudiant");
        ledNombreEtudiant->setReadOnly(true);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, ledNombreEtudiant);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tableView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btnToutSupprimer = new QPushButton(centralwidget);
        btnToutSupprimer->setObjectName("btnToutSupprimer");

        horizontalLayout_3->addWidget(btnToutSupprimer);

        btnOuvrir = new QPushButton(centralwidget);
        btnOuvrir->setObjectName("btnOuvrir");

        horizontalLayout_3->addWidget(btnOuvrir);

        btnEnregistrer = new QPushButton(centralwidget);
        btnEnregistrer->setObjectName("btnEnregistrer");

        horizontalLayout_3->addWidget(btnEnregistrer);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName("menuFichier");
        menuModifier = new QMenu(menubar);
        menuModifier->setObjectName("menuModifier");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuModifier->menuAction());
        menuFichier->addSeparator();
        menuFichier->addAction(actionOuvrir_un_fichier);
        menuFichier->addSeparator();
        menuFichier->addAction(actionEnregister);
        menuFichier->addSeparator();
        menuFichier->addAction(actionEnregister_sous);
        menuFichier->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOuvrir_un_fichier->setText(QCoreApplication::translate("MainWindow", "Ouvrir un fichier", nullptr));
#if QT_CONFIG(shortcut)
        actionOuvrir_un_fichier->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEnregister->setText(QCoreApplication::translate("MainWindow", "Enregister", nullptr));
#if QT_CONFIG(shortcut)
        actionEnregister->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEnregister_sous->setText(QCoreApplication::translate("MainWindow", "Enregister sous", nullptr));
#if QT_CONFIG(shortcut)
        actionEnregister_sous->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionModification_pr_c_dente->setText(QCoreApplication::translate("MainWindow", "Modification pr\303\251c\303\251dente", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "INSCRIPTION :", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        ledName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        sexeLabel->setText(QCoreApplication::translate("MainWindow", " Sexe :", nullptr));
        comboSexe->setItemText(0, QCoreApplication::translate("MainWindow", "Feminin", nullptr));
        comboSexe->setItemText(1, QCoreApplication::translate("MainWindow", "Masculin", nullptr));

        dateDeNaissanceLabel->setText(QCoreApplication::translate("MainWindow", "Date de Naissance :", nullptr));
        btnNettoyer->setText(QCoreApplication::translate("MainWindow", "Nettoyer", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Recherche :", nullptr));
        inputLabel->setText(QCoreApplication::translate("MainWindow", "Input :", nullptr));
        ledChercher->setPlaceholderText(QCoreApplication::translate("MainWindow", "chercher par Nom ou id", nullptr));
        btnEffacer->setText(QCoreApplication::translate("MainWindow", "Effacer", nullptr));
        nombreDEtudiantLabel->setText(QCoreApplication::translate("MainWindow", "Nombre d'etudiant :", nullptr));
        ledNombreEtudiant->setPlaceholderText(QCoreApplication::translate("MainWindow", "Auccun", nullptr));
        btnToutSupprimer->setText(QCoreApplication::translate("MainWindow", "Tout supprimer", nullptr));
        btnOuvrir->setText(QCoreApplication::translate("MainWindow", "Ouvrir", nullptr));
        btnEnregistrer->setText(QCoreApplication::translate("MainWindow", "Enregistrer", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("MainWindow", "Fichier", nullptr));
        menuModifier->setTitle(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
