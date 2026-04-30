#ifndef LISTEETUDIANT_H
#define LISTEETUDIANT_H

#include "Etudiant.h"

class ListeEtudiant
{
    public:
        ListeEtudiant();
        ~ListeEtudiant();

        std::vector<Etudiant> getList() ;
        int getNombreEtudiant() ;
        void setNombreEtudiant(int nombre) ;

        void ajout(const QString &nom , const QString &sexe , const QDate &dateNaissance , int id = 0 );
        bool supprimer(int id);
        void vider();
        std::vector<Etudiant>::iterator rechercher(QString name) ;
        std::vector<Etudiant>::iterator rechercher( int id) ;

    private :

        std::vector<Etudiant> m_list ;
        int m_nombreEtudiant = 0 ;

};

#endif // LISTEETUDIANT_H
