#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "ListeEtudiant.h"


QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
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
        QString getSEx();
        QDate getDateNaissance();

    private slots:
        void affichage() ;
        void affichage(std::vector<Etudiant>::iterator it );
        void ledChercherVide();

        void on_btnChercher_clicked();
        void on_btnNettoyer_clicked();
        void on_btnAjouter_clicked();

    private :
        Ui::MainWindow *ui;
        ListeEtudiant m_list ;
        QStandardItemModel *model ;
};
#endif // MAINWINDOW_H
