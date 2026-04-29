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
    QPushButton *btnChercher;
    QSpacerItem *verticalSpacer;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
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
        dateDeNaissanceDateEdit->setDate(QDate(2026, 1, 1));

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

        btnChercher = new QPushButton(groupBox_2);
        btnChercher->setObjectName("btnChercher");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, btnChercher);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(3, QFormLayout::FieldRole, verticalSpacer);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tableView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "INSCRIPTION :", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        ledName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        sexeLabel->setText(QCoreApplication::translate("MainWindow", " Sexe :", nullptr));
        comboSexe->setItemText(0, QCoreApplication::translate("MainWindow", "Feminin", nullptr));
        comboSexe->setItemText(1, QCoreApplication::translate("MainWindow", "Maculin", nullptr));

        dateDeNaissanceLabel->setText(QCoreApplication::translate("MainWindow", "Date de Naissance :", nullptr));
        btnNettoyer->setText(QCoreApplication::translate("MainWindow", "Nettoyer", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Recherche :", nullptr));
        inputLabel->setText(QCoreApplication::translate("MainWindow", "Input :", nullptr));
        ledChercher->setPlaceholderText(QCoreApplication::translate("MainWindow", "chercher par Nom ou id", nullptr));
        btnChercher->setText(QCoreApplication::translate("MainWindow", "Chercher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
