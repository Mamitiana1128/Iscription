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

        void ajout(QString &nom , QString &sexe , QDate &dateNaissance );
        bool supprimer(int id);
        std::vector<Etudiant>::iterator rechercher(QString name) ;
        std::vector<Etudiant>::iterator rechercher( int id) ;

    private :

        std::vector<Etudiant> m_list ;
        int m_nombreEtudiant = 0 ;

};

#endif // LISTEETUDIANT_H
