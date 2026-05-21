#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <stack>
#include <QDate>
#include <QString>
#include <QAction>

class Historique
{
    public:
        Historique();
        ~Historique() ;

    // Ajout dans l'Historique
        void ajoutAnnuler(QString typeAction , QString name , QString sexe , QDate date , int id , QAction *act) ;
        void ajoutRefaire(QString typeAction , QString name , QString sexe , QDate date , int id , QAction *act) ;

    // Recuperation de l'historique
            QString recuperAnnuler();
            QString recuperRefaire();

    // Verification du pile
            bool annulerIsEmpty();
            bool refaireIsEmpty();

    private :

        std::stack<QString> m_annuler ;
        std::stack<QString> m_refaire ;

};

#endif // HISTORIQUE_H
