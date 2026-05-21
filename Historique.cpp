#include "Historique.h"

Historique::Historique() {}
Historique::~Historique() {}


void Historique::ajoutAnnuler(QString typeAction , QString name , QString sexe , QDate date , int id ,  QAction *act)
{
    QString champ ;

    champ = QString("%1;%2;%3;%4;%5").arg(typeAction , name , sexe , date.toString("dd/MM/yyyy") ,  QString::number(id)) ;

    m_annuler.push(champ) ;
    act->setEnabled(true) ;
}

//----------------------------------------------------------------------------

void Historique::ajoutRefaire(QString typeAction , QString name , QString sexe , QDate date , int id , QAction *act)
{
    QString champ ;

    champ = QString("%1;%2;%3;%4;%5").arg(typeAction , name , sexe , date.toString("dd/MM/yyyy") ,  QString::number(id)) ;

    m_refaire.push(champ) ;
    act->setEnabled(true) ;
}

//----------------------------------------------------------------------------
QString Historique::recuperAnnuler()
{
    QString texte ;

    texte = m_annuler.top() ;
    m_annuler.pop() ;

    return (texte) ;
}

//----------------------------------------------------------------------------

QString Historique::recuperRefaire()
{
    QString texte ;

    texte = m_refaire.top() ;
    m_refaire.pop();

    return (texte) ;
}

//----------------------------------------------------------------------------

bool Historique::annulerIsEmpty()
{
    if(m_annuler.empty())
    {
        return (true) ;
    }

    return (false) ;
}
//----------------------------------------------------------------------------
bool Historique::refaireIsEmpty()
{
    if(m_refaire.empty())
    {
        return (true) ;
    }

    return (true) ;
}