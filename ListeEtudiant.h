#ifndef LISTEETUDIANT_H
#define LISTEETUDIANT_H

#include "Etudiant.h"

class ListeEtudiant
{
    public:
        ListeEtudiant();
        ~ListeEtudiant();

        const std::vector<Etudiant>& getList() ;
        int getNombreEtudiant() ;
        void setNombreEtudiant(int nombre) ;
        int getNombreFeminin() ;
        int getNombreMasculin() ;
        int genererId();

        int ajout(const QString &nom , const QString &sexe , const QDate &dateNaissance , int id = 0 );
        bool supprimer(int id);
        void vider();
        void modifier(int id , QString nouveauNom , QString nouveauxSexe , QDate nouveauDateNaissance ) ;
        std::vector<Etudiant>::iterator rechercher(QString name) ;
        std::vector<Etudiant>::iterator rechercher( int id) ;

    private :

        std::vector<Etudiant> m_list ;
        int m_nombreEtudiant = 0 ;
        int m_nombreFeminin = 0 ;
        int m_nombreMasculin = 0 ;
        std::vector<int> m_listId ;
};

#endif // LISTEETUDIANT_H
