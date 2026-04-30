#include "ListeEtudiant.h"

using namespace std ;

ListeEtudiant::ListeEtudiant()
{}

ListeEtudiant::~ListeEtudiant()
{}

void ListeEtudiant::ajout(const QString &nom , const  QString &sexe , const QDate &dateNaissance , int id )
{
    if(id == 0 )
    {
        Etudiant etudiantAAjouter ;

        etudiantAAjouter.setName(nom);
        etudiantAAjouter.setDateNaissance(dateNaissance);
        etudiantAAjouter.setSexe(sexe);

        // Ajout dans le liste
        m_list.emplace_back(etudiantAAjouter) ;
        m_nombreEtudiant++;
    }
    else
    {
        Etudiant etudiantAAjouter ;

        etudiantAAjouter.setName(nom);
        etudiantAAjouter.setDateNaissance(dateNaissance);
        etudiantAAjouter.setSexe(sexe);
        etudiantAAjouter.setId(id);

        // Ajout dans le liste
        m_list.emplace_back(etudiantAAjouter) ;
        m_nombreEtudiant++;
    }
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
        m_nombreEtudiant--;

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


void ListeEtudiant::setNombreEtudiant(int nombre)
{
    m_nombreEtudiant = nombre ;
}

int ListeEtudiant::getNombreEtudiant()
{
    return (m_nombreEtudiant);
}

void ListeEtudiant::vider()
{
    m_list.clear() ;
}
