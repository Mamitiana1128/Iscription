#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <stack>
#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>
#include "modification.h"

using namespace std ;

// Pour stocker tout les historique
stack<QString> historique ;
stack<QString> retourHistorique ;
QString cheminFichier = "" ;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Rendu professionnel
        ui->tableView->horizontalHeader()->setStretchLastSection(true);
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers) ; // pour le readonly

    // Création du model du tableView
        model = new QStandardItemModel(this) ;
        model->setHorizontalHeaderLabels({"Nom","Sexe","Date de naissance","ID"});

        ui->tableView->setModel(model) ;

    // Activation du menu dans le model
        ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu) ;

    // Verification On fait plus de recherche
        connect(ui->ledChercher , &QLineEdit::textChanged , this , &MainWindow::Chercher );

    // Création menu
        connect(ui->tableView , &QTableView::customContextMenuRequested , this , &MainWindow::voirMenu) ;

    // Connexion des actions
        connect(ui->actionEnregister , &QAction::triggered , this , &MainWindow::btnEnregistrer_clicked) ;
        connect(ui->actionEnregister_sous , &QAction::triggered , this , &MainWindow::enregistrerSous ) ;
        connect(ui->actionOuvrir_un_fichier , &QAction::triggered , this , &MainWindow::btnOuvrir_clicked) ;
        connect(ui->actionMEtudiant , &QAction::triggered , this , &MainWindow::modifier) ;
        connect(ui->actionAnnuler_M , &QAction::triggered , this , &MainWindow::retour );
        connect(ui->actionRefaire , &QAction::triggered , this , &MainWindow::refaire ) ;
        connect(ui->actionQuitter , &QAction::triggered , this , &MainWindow::quitter);
        connect(ui->actionTout_Effacer , &QAction::triggered , this , &MainWindow::btnToutSupprimer_clicked ) ;

    // Connecions des buttons
        connect(ui->btnNettoyer , &QPushButton::clicked , this , &MainWindow::btnNettoyer_clicked);
        connect(ui->btnAjouter , &QPushButton::clicked , this , &MainWindow::btnAjouter_clicked );


    // tritre fenetre
        MainWindow::setWindowTitle("Inscription") ;

    // desactive le boutton ajouter au départ et attend si le nom n'est plus vide
        ui->btnAjouter->setEnabled(false) ;
        connect(ui->ledName , &QLineEdit::textChanged , this , &MainWindow::activerBtnAjouter ) ;


    // Desactivation des actions unitiles au depart
        ui->actionAnnuler_M->setDisabled(true);
        ui->actionMEtudiant->setDisabled(true);
        ui->actionRefaire->setDisabled(true) ;
        ui->actionTout_Effacer->setDisabled(true) ;

        creerStatues() ;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::affichage(const Etudiant& e)
{
    QList<QStandardItem*> items;
    items.append(new QStandardItem(e.getName()));
    items.append(new QStandardItem(e.getSExe()));
    items.append(new QStandardItem(e.getDateNaissance().toString("dd/MM/yyyy")));
    items.append(new QStandardItem(QString::number(e.getId())));

    model->appendRow(items);
}

//Modifie l'affichage global
void MainWindow::affichage()
{
   if (!model)
    {
        return;
    }

    model->setRowCount(0);

    for(const Etudiant& e : m_list.getList())
    {
        affichage(e);
    }

    ui->NombreEtudiant->display( m_list.getNombreEtudiant() ) ;

    updateStatus() ;
}

void MainWindow::Chercher(const QString &texte)
{
    bool ok;
    int id ;

    if ( !model )
    {
        return ;
    }

    model->setRowCount(0);

    if(texte.isEmpty())
    {
        affichage();
        return;
    }

    id = texte.toInt(&ok);

    for(const Etudiant& e : m_list.getList() )
    {
        if(ok)
        {
            if(e.getId() == id )
            {
                affichage(e) ;
            }
        }
        else
        {
            if(e.getName().contains(texte, Qt::CaseInsensitive) )
            {
                affichage(e) ;
            }
        }
    }
}
void MainWindow::btnNettoyer_clicked()
{
    ui->ledName->clear() ;
}

void MainWindow::btnAjouter_clicked()
{
    QString name ;
    QString sexe ;
    QDate dateNaissance ;
    int id ;

    name = ui->ledName->text();
    sexe = ui->comboSexe->currentText() ;
    dateNaissance = ui->dateDeNaissanceDateEdit->date() ;

    id = m_list.ajout(name , sexe , dateNaissance ) ;

    m_historique.ajoutAnnuler("ajouter" , name , sexe , dateNaissance , id , ui->actionAnnuler_M );
//    ajoutHistorique("ajouter" , name , sexe , dateNaissance , id );

    ui->actionMEtudiant->setEnabled(true) ;
    ui->actionTout_Effacer->setEnabled(true);

    enregister = false ;
    affichage() ;
    ui->ledName->clear() ;
}

//--------------------------------------------------------------------------

void MainWindow::btnToutSupprimer_clicked()
{

    auto reponse = QMessageBox::information(this , "Confirmation de Suppression" , "Vous-êtes sûr de vouloir supprimer définitimement toute la liste ?" , QMessageBox::Ok | QMessageBox::Cancel ) ;

    if( reponse == QMessageBox::Ok )
    {
        m_list.vider() ;
        m_list.setNombreEtudiant(0);

        ui->actionMEtudiant->setDisabled(true) ;
        ui->actionTout_Effacer->setDisabled(true) ;
        enregister = false ;
        affichage();
    }
}


//--------------------------------------------------------------------
//Enregistrement dans un fichier
//--------------------------------------------------------------------
void MainWindow::enregistrerCSV(const QString &fichier)
{
    QFile file;

    file.setFileName(fichier);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file) ;

        for(const Etudiant& e : m_list.getList())
        {
            out << e.getName() << ";" << e.getSExe() << ";" << e.getDateNaissance().toString("dd/MM/yyyy") << ";" << e.getId() << "\n" ;
        }
        file.close();
    }

    ui->statusbar->showMessage("Sauvegarde Términé !" , 5000 ) ;
    enregister = true ;
}


//--------------------------------------------------------------------
//Ouveture d'un fichier
//--------------------------------------------------------------------
void MainWindow::ouvrirCSV(const QString &fichier)
{
    QFile file ;
    QString texte ;
    QStringList champs ;
    QDate date;
    int id ;


    file.setFileName(fichier);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file) ;

        // On efface tout les elements du liste
            m_list.vider();

        while( !in.atEnd() )
        {
            texte = in.readLine().trimmed() ;

            if(texte.isEmpty() )
            {
                continue ;
            }

            champs = texte.split(";") ;

            // Ignore les lignes incomplets
            if(champs.size() < 4 )
            {
                continue ;
            }

            id = champs[3].toInt() ;
            date = QDate::fromString(champs[2] , "dd/MM/yyyy" ) ;

            if( date.isValid() )
            {
                m_list.ajout(champs[0] , champs[1] , date , id ) ;

                ui->actionMEtudiant->setEnabled(true) ;
                ui->actionTout_Effacer->setEnabled(true) ;
            }
        }
        file.close();
        affichage();
    }
}


void MainWindow::btnEnregistrer_clicked()
{
    if( cheminFichier.isEmpty() )
    {
        cheminFichier = QFileDialog::getSaveFileName(this , "Eregistrement" , "" , "Fichier CSV (*.csv)");
    }

    if(!cheminFichier.isEmpty())
    {
        enregistrerCSV(cheminFichier);
    }
}


void MainWindow::enregistrerSous()
{

    cheminFichier = QFileDialog::getSaveFileName(this , "Eregistrement" , "" , "Fichier CSV (*.csv)");

    if(!cheminFichier.isEmpty())
    {
        enregistrerCSV(cheminFichier);
    }
}


void MainWindow::btnOuvrir_clicked()
{
    cheminFichier = QFileDialog::getOpenFileName(this , "Ouvrir" , "" , "Fichier CSV (*.csv)");

    if(!cheminFichier.isEmpty())
    {
        ouvrirCSV(cheminFichier) ;
    }

    ui->statusbar->showMessage("Ouverture fichier !" , 5000 ) ;
}

void MainWindow::activerBtnAjouter()
{
    ui->btnAjouter->setEnabled(!ui->ledName->text().isEmpty() ) ;
}


void MainWindow::voirMenu(const QPoint &pos )
{
    // Récuperation du position cliquer
        QModelIndex index ;
        QMenu menu = QMenu(this);
        int r , id ;
        QString name , sexe ;
        QDate date ;

        index = ui->tableView->indexAt(pos) ;

    // Si on clique dans le vide
        if(!index.isValid())
        {
            return ;
        }

        QAction *supprimer = menu.addAction("Supprimer");
        QAction *modifie = menu.addAction("Modifier");
        QAction *action = menu.exec(ui->tableView->viewport()->mapToGlobal(pos)) ;

        if( action == supprimer)
        {
            r = index.row() ;

            // Récuperation des données
                name = model->index(r , 0).data().toString();
                sexe = model->index(r , 1).data().toString();
                date = model->index(r , 2).data().toDate() ;
                id = model->index(r , 3).data().toInt() ;

            // Suppression de l'etudiant
                m_historique.ajoutAnnuler("supprimer" , name , sexe , date , id , ui->actionAnnuler_M );
//                ajoutHistorique("supprimer" , name , sexe , date , id ) ; // ajout dans l'historique
                m_list.supprimer(id) ;

                if( m_list.getList().empty() )
                {
                    ui->actionMEtudiant->setDisabled(true);
                    ui->actionTout_Effacer->setDisabled(true) ;
                }

                enregister = false ;
                affichage();
        }
        else if(action == modifie)
        {
            int r , id ;

            r = index.row() ;

            // Récuperation des données
            name = model->index(r , 0).data().toString();
            sexe = model->index(r , 1).data().toString();
            date = model->index(r , 2).data().toDate() ;
            id = model->index(r , 3).data().toInt() ;

            // Lancement du modification
            if( modifier(id ))
            {
                m_historique.ajoutAnnuler("modifier" , name , sexe , date , id , ui->actionAnnuler_M );
//                ajoutHistorique("Modifier" , name , sexe , date , id ) ; // ajout dans l'historique
                affichage() ;
            }
        }
}

bool MainWindow::modifier(int id )
{
    Modification *fenetre = new Modification(this , m_list , id ) ;


    if( fenetre->exec() == QDialog::Accepted )
    {
        enregister = false ;

        return true ;
    }

    return false ;
}

void MainWindow::retour()
{
    QString texte ;
    QStringList champ ;
    QString action , name , sexe ;
    int id ;
    QDate date ;

    texte = m_historique.recuperAnnuler() ;

    if( m_historique.annulerIsEmpty() )
    {
        ui->actionAnnuler_M->setDisabled(true);
    }

    champ = texte.split(";") ;

    action = champ[0] ;
    name = champ[1];
    sexe = champ[2];
    date = QDate::fromString(champ[3] , "dd/MM/yyyy")  ;
    id = champ[4].toInt() ;

    // Execution du retour et ajout dans l'historique de retour
        if(action == "ajouter")
        {
            m_list.supprimer(id) ;
            m_historique.ajoutRefaire("supprimer" , name , sexe , date , id , ui->actionRefaire );
//            ajoutRetourHistorique("supprimer" , name , sexe , date , id ) ;
        }
        else if(action == "supprimer")
        {
            m_list.ajout(name , sexe , date , id ) ;
            m_historique.ajoutRefaire("ajouter" , name , sexe , date , id , ui->actionRefaire );
//            ajoutRetourHistorique("ajouter" , name , sexe , date , id ) ;
        }
        else if(action == "modifier")
        {
            m_list.modifier(id , name , sexe , date ) ;
            m_historique.ajoutRefaire("modifier" , name , sexe , date , id , ui->actionRefaire );
//            ajoutRetourHistorique("modifier" , name , sexe , date , id ) ;
        }

    // Activation du action refaire
    ui->actionRefaire->setEnabled(true) ;

    affichage();
}

//----------------------------------------------------------------------------

void MainWindow::refaire()
{
    QString texte ;
    QStringList champ ;
    QString action , name , sexe ;
    int id ;
    QDate date ;

    texte = m_historique.recuperRefaire() ;

    if( m_historique.refaireIsEmpty() )
    {
        ui->actionRefaire->setDisabled(true);
    }

    champ = texte.split(";") ;

    action = champ[0] ;
    name = champ[1];
    sexe = champ[2];
    date = QDate::fromString(champ[3] , "dd/MM/yyyy")  ;
    id = champ[4].toInt() ;

    if(action == "ajouter")
    {
        m_list.supprimer(id) ;
        m_historique.ajoutAnnuler("supprimer" , name , sexe , date , id , ui->actionAnnuler_M );
//        ajoutHistorique("supprimer" , name , sexe , date , id ) ;
    }
    else if(action == "supprimer")
    {
        m_list.ajout(name , sexe , date , id ) ;
        m_historique.ajoutAnnuler("ajouter" , name , sexe , date , id , ui->actionAnnuler_M );
//        ajoutHistorique("ajouter" , name , sexe , date , id ) ;
    }
    else if(action == "modifier")
    {
        m_list.modifier(id , name , sexe , date ) ;
        m_historique.ajoutAnnuler("modifier" , name , sexe , date , id , ui->actionAnnuler_M );
//        ajoutHistorique("Modifier" , name , sexe , date , id ) ;
    }

    affichage();
}

//----------------------------------------------------------------------------
void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox message(this) ;
    QPushButton *quitter ;
    QPushButton *save ;
    QPushButton *annuler ;

    if( enregister || ( cheminFichier.isEmpty() && m_list.getList().empty() ) )
    {
        event->accept();
        return ;
    }

    message.setWindowTitle("Quitter");
    message.setText("Voulez-vous enregistrer les modifications avant de quitter ?");
    message.setIcon(QMessageBox::Question);

    annuler = message.addButton("Annuler " , QMessageBox::RejectRole ) ;
    quitter = message.addButton("Quitter sans sauver" , QMessageBox::DestructiveRole );
    save = message.addButton("Enregistrer " , QMessageBox::AcceptRole );

    message.exec() ;

    if(message.clickedButton() == annuler)
    {
        event->ignore() ;
    }
    else if(message.clickedButton() == quitter)
    {
        event->accept() ;
    }
    else
    {
        btnEnregistrer_clicked() ;
        event->accept() ;
    }
}


void MainWindow::quitter()
{
    this->close() ;
}


void MainWindow::creerStatues()
{
    m_nombreEtudiant = new QLabel("Nombre d'Etudiant : 0");
    m_nombreFille = new QLabel("Feminin : 0") ;
    m_nombreGarcon = new QLabel("Masculin : 0") ;

    ui->statusbar->addPermanentWidget(m_nombreEtudiant ) ;
    ui->statusbar->addPermanentWidget(m_nombreFille) ;
    ui->statusbar->addPermanentWidget(m_nombreGarcon) ;
}


void MainWindow::updateStatus()
{
    int nombreT = 0 ;
    int nombreF = 0 ;
    int nombreM = 0 ;

    // Recuperation des données utiles
        nombreT = m_list.getNombreEtudiant() ;
        nombreF = m_list.getNombreFeminin() ;
        nombreM = m_list.getNombreMasculin() ;

    m_nombreEtudiant->setText("Nombre d'Etudiant : " + QString::number(nombreT) ) ;
    m_nombreFille->setText("Feminin : " + QString::number(nombreF)) ;
    m_nombreGarcon->setText("Masculin : " + QString::number(nombreM)) ;

}