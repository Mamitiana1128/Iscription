#include "modification.h"
#include "ui_modification.h"

using namespace std ;

Modification::Modification(QWidget *parent , ListeEtudiant &liste , int id ): QDialog(parent), ui(new Ui::Modification) , m_liste(liste)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose) ;
    this->setWindowTitle("Modifications") ;

    vector<Etudiant>::iterator it ;

    it = liste.rechercher(id) ;

    // verification le l'id
        if( id != 0 && it != liste.getList().end() )
        {
            ui->iDLineEdit->setText(QString::number(id) ) ;
            ui->iDLineEdit->setDisabled(true) ;
            ui->nOMLineEdit->setText(it->getName());
            ui->sexeComboBox->setCurrentText(it->getSExe());
            ui->dateDeNaissanceDateEdit->setDate(it->getDateNaissance()) ;
        }
        else // Désactivation du boutton appliquer et des autres champs
        {
            ui->btnAppliquer->setDisabled(true) ;
            ui->nOMLineEdit->setDisabled(true) ;
            ui->sexeComboBox->setDisabled(true) ;
            ui->dateDeNaissanceDateEdit->setDisabled(true) ;
        }

        connect(ui->iDLineEdit , &QLineEdit::textChanged , this , &Modification::isIdvalid ) ;
        connect(ui->nOMLineEdit , &QLineEdit::textChanged , this , &Modification::isNameValid ) ;
        connect(ui->btnAbandonner , &QPushButton::clicked , this , &Modification::abadonner ) ;
        connect(ui->btnAppliquer , &QPushButton::clicked , this , &Modification::appliquer ) ;
}

Modification::~Modification()
{
    delete ui;
}


void Modification::isIdvalid(const QString id )
{
    vector<Etudiant>::iterator it ;

    it = m_liste.rechercher(id.toInt() ) ;

    if( it != m_liste.getList().end() )
    {
        ui->nOMLineEdit->setEnabled(true);
        ui->dateDeNaissanceDateEdit->setEnabled(true);
        ui->sexeComboBox->setEnabled(true) ;
    }
    else
    {
        ui->nOMLineEdit->setDisabled(true) ;
        ui->sexeComboBox->setDisabled(true) ;
        ui->dateDeNaissanceDateEdit->setDisabled(true) ;
    }
}

void Modification::isNameValid()
{
    if( !ui->nOMLineEdit->text().isEmpty() )
    {
        ui->btnAppliquer->setEnabled(true) ;
    }
}

void Modification::abadonner()
{
    this->reject() ;
}

void Modification::appliquer()
{
    QString nom , sexe ;
    QDate date ;
    int id ;

    date = ui->dateDeNaissanceDateEdit->date() ;
    nom = ui->nOMLineEdit->text() ;
    sexe = ui->sexeComboBox->currentText() ;
    id =  ui->iDLineEdit->text().toInt() ;

    m_liste.modifier(id , nom , sexe , date );

    this->accept() ;
}