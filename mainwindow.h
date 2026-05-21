#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include "Historique.h"
#include <QMainWindow>
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

        // Methodes
        void ajoutHistorique(QString typeAction , QString name , QString sexe , QDate date , int id ) ;
        void ajoutRetourHistorique(QString typeAction , QString name , QString sexe , QDate date , int id ) ;

    private slots:
        void affichage() ;
        void affichage(const Etudiant& e);

        void Chercher(const QString &texte);
        void btnNettoyer_clicked();
        void btnAjouter_clicked();
        void btnToutSupprimer_clicked();

        bool modifier(int id = 0 );

        // Activation du button ajouter
            void activerBtnAjouter();

        // Pour le menu du tableView
            void voirMenu(const QPoint &pos);

        // pour le action retour et refaire
            void retour() ;
            void refaire() ;

        // Quitter
            void quitter() ;

        // Barre de statues
            void creerStatues();
            void updateStatus() ;

        // Enregistrement et ouverture
            void enregistrerCSV(const QString &fichier);
            void ouvrirCSV(const QString &fichier);
            void btnEnregistrer_clicked();
            void enregistrerSous() ;
            void btnOuvrir_clicked() ;

    protected :

        void closeEvent(QCloseEvent *event) override ;

    private :
        Ui::MainWindow *ui;
        Historique m_historique ;
        ListeEtudiant m_list ;
        QStandardItemModel *model ;

        QLabel *m_nombreEtudiant ;
        QLabel *m_nombreGarcon ;
        QLabel *m_nombreFille ;

        bool enregister = true ;
};
#endif // MAINWINDOW_H
