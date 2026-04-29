#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <QString>
#include <QDate>

class Etudiant
{
    public:
        Etudiant();
        ~Etudiant() ;

    // getter setter
        void setName(QString &name);
        void setSex(QString &sex);
        void setDateNaissance(QDate &date) ;

        QString getName() const ;
        QString getSExe()const ;
        QDate getDateNaissance() const ;
        int getId() const ;


    private :
        QString m_name ;
        QString m_sexe ;
        QDate m_dateNaissance ;
        int m_id ;

};

#endif // ETUDIANT_H
