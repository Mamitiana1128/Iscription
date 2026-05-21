#ifndef MODIFICATION_H
#define MODIFICATION_H

#include <QDialog>
#include "ListeEtudiant.h"

namespace Ui
{
    class Modification;
}

class Modification : public QDialog
{
    Q_OBJECT

    public:
        explicit Modification(QWidget *parent , ListeEtudiant &liste , int id );
        ~Modification();

    public slots :
        void isIdvalid(const QString id);
        void isNameValid() ;
        void abadonner();
        void appliquer();

    private:
        Ui::Modification *ui;
        ListeEtudiant& m_liste ;
};

#endif // MODIFICATION_H