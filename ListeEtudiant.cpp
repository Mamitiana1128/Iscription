#include "ListeEtudiant.h"

using namespace std ;

ListeEtudiant::ListeEtudiant() {}
ListeEtudiant::~ListeEtudiant(){}

void ListeEtudiant::ajout(QString &nom , QString &sexe , QDate &dateNaissance )
{
    Etudiant etudiantAAjouter ;

    etudiantAAjouter.setName(nom);
    etudiantAAjouter.setDateNaissance(dateNaissance);
    etudiantAAjouter.setSex(sexe);

    // Ajout dans le liste
        m_list.emplace_back(etudiantAAjouter) ;

}

vector<Etudiant>::iterator ListeEtudiant::rechercher(QString name)
{
    vector<Etudiant>::iterator it ;


    for(it = m_list.begin() ; it != m_list.end() ; ++it )
    {
        if(it->getName() == name)
        {
            return it ;
        }
    }

    return m_list.end() ;
}

vector<Etudiant>::iterator ListeEtudiant::rechercher(int id)
{
    vector<Etudiant>::iterator it ;

    for(it = m_list.begin() ; it != m_list.end() ; ++it )
    {
        if(it->getId() == id )
        {
            return it ;
        }
    }

    return m_list.end() ;
}


bool ListeEtudiant::supprimer(int id )
{
    vector<Etudiant>::iterator it ;

    it = rechercher( id ) ;

    if(it != m_list.end() )
    {
        m_list.erase(it) ;

        return (true) ;
    }
    else
    {
        return (false);
    }

}

vector<Etudiant> ListeEtudiant::getList()
{
    return (m_list) ;
}
