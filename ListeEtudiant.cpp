#include "ListeEtudiant.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std ;

ListeEtudiant::ListeEtudiant()
{}

ListeEtudiant::~ListeEtudiant()
{}

int ListeEtudiant::ajout(const QString &nom , const  QString &sexe , const QDate &dateNaissance , int id )
{
    int nouveauId ;
    Etudiant etudiantAAjouter ;

    if(id == 0 )
    {
        nouveauId = genererId();

        etudiantAAjouter.setName(nom);
        etudiantAAjouter.setDateNaissance(dateNaissance);
        etudiantAAjouter.setSexe(sexe);
        etudiantAAjouter.setId(nouveauId);

        // Ajout dans le liste
            m_list.emplace_back(etudiantAAjouter) ;
            m_nombreEtudiant++ ;
            m_listId.emplace_back(nouveauId);

            return (nouveauId) ;
    }
    else
    {
        etudiantAAjouter.setName(nom);
        etudiantAAjouter.setDateNaissance(dateNaissance);
        etudiantAAjouter.setSexe(sexe);
        etudiantAAjouter.setId(id);

        // Ajout dans le liste
            m_list.emplace_back(etudiantAAjouter) ;
            m_nombreEtudiant++;
            m_listId.emplace_back(id) ;

            return id ;
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
    vector<int>::iterator itd ;

    it = rechercher( id ) ;
    itd = find(m_listId.begin() , m_listId.end() , id ) ;

    if(it != m_list.end() )
    {
        // Suppresion de l'ID dans le liste
            m_listId.erase(itd);

        // Suppression de l'etudiant
            m_list.erase(it) ;
            m_nombreEtudiant-- ;

        return (true) ;
    }
    else
    {
        return (false);
    }

}

const vector<Etudiant>& ListeEtudiant::getList()
{
    return (m_list) ;
}


void ListeEtudiant::setNombreEtudiant(int nombre)
{
    m_nombreEtudiant = nombre ;
}

int ListeEtudiant::getNombreEtudiant()
{
    return (m_nombreEtudiant) ;
}

void ListeEtudiant::vider()
{
    m_list.clear() ;
    m_listId.clear() ;
}

int ListeEtudiant::genererId()
{
    int id ;
    vector<int>::iterator it ;

    srand(time(0));
    do
    {

        id = (rand() % 90000 ) + 10000 ; // Géneration Id de 5 chiffres

        // Verification si Id existe déja
            it = find(m_listId.begin() , m_listId.end() , id ) ;

    }while(it != m_listId.end() );


    return id ;
}

//---------------------------------------------------------
// Modification d'un étudiant a partir de son id
//---------------------------------------------------------
void ListeEtudiant::modifier(int id , QString nouveauNom , QString nouveauxSexe , QDate nouveauDateNaissance )
{
    vector<Etudiant>::iterator it ;

    it = rechercher(id) ;

    if(it != m_list.end() )
    {
        it->setName(nouveauNom);
        it->setSexe(nouveauxSexe);
        it->setDateNaissance(nouveauDateNaissance);
    }
}