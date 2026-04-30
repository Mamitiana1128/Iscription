#include "Etudiant.h"

Etudiant::Etudiant() {}
Etudiant::~Etudiant() {}


// -------------------------------------
//// Getter
// -------------------------------------


QString Etudiant::getName() const
{
    return (m_name);
}

QString Etudiant::getSExe() const
{
    return (m_sexe);
}

QDate Etudiant::getDateNaissance() const
{
    return (m_dateNaissance) ;
}

int Etudiant::getId() const
{
    return (m_id) ;
}

// -------------------------------------
//// Setter
// -------------------------------------

void Etudiant::setDateNaissance(const QDate &date)
{
    m_dateNaissance = date ;
}

void Etudiant::setName(const QString &name)
{
    m_name = name ;
}

void Etudiant::setSexe(const QString &sexe)
{
    m_sexe = sexe ;
}

void Etudiant::setId(const int id)
{
    m_id = id ;
}
