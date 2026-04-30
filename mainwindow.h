#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QStandardItemModel>
#include "ListeEtudiant.h"
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow ;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public :
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        // getter
        QString getName();
        QString getSExe();
        QDate getDateNaissance();

    private slots:
        void affichage() ;
        void affichage(const Etudiant& e);
        void voirListeMenu(const QPoint &pos);

        void Chercher(const QString &texte);
        void on_btnNettoyer_clicked();
        void on_btnAjouter_clicked();
        void on_btnEffacer_clicked();
        void on_btnToutSupprimer_clicked();

        // Enregistrement et ouverture
            void enregistrerCSV(const QString &fichier);
            void ouvrirCSV(const QString &fichier);
            void on_btnEnregistrer_clicked();
            void on_btnOuvrir_clicked() ;

    private :
        Ui::MainWindow *ui;
        ListeEtudiant m_list ;
        QStandardItemModel *model ;
};
#endif // MAINWINDOW_H
