#include "mainwindow.h"
#include "./ui_mainwindow.h"


using namespace std ;

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
        connect(ui->tableView , &QTableView::customContextMenuRequested , this , &MainWindow::voirListeMenu) ;

    // Connexion des actions
        connect(ui->actionEnregister , &QAction::triggered , this , &MainWindow::on_btnEnregistrer_clicked) ;
        connect(ui->actionOuvrir_un_fichier , &QAction::triggered , this , &MainWindow::on_btnOuvrir_clicked) ;

    // tritre fenetre
        MainWindow::setWindowTitle("Inscription") ;
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
/*    if (!model)
    {
        return;
    }
*/
    model->setRowCount(0);

    for(const Etudiant& e : m_list.getList())
    {
        affichage(e);
        qDebug() << "zertyuio " ;
    }
}

void MainWindow::Chercher(const QString &texte)
{
    bool ok;
    int id ;

    if (!model)
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

    for(const Etudiant& e : m_list.getList())
    {
        if(ok)
        {
            if(e.getId() == id)
            {
                affichage(e);
            }
        }
        else
        {
            if(e.getName().contains(texte, Qt::CaseInsensitive))
            {
                affichage(e);
            }
        }
    }
}
void MainWindow::on_btnNettoyer_clicked()
{
    ui->ledName->clear() ;
}

void MainWindow::on_btnAjouter_clicked()
{
    QString name ;
    QString sexe ;
    QDate dateNaissance ;

    name = ui->ledName->text();
    sexe = ui->comboSexe->currentText() ;
    dateNaissance = ui->dateDeNaissanceDateEdit->date() ;

    m_list.ajout(name , sexe , dateNaissance ) ;

    affichage() ;
    ui->ledNombreEtudiant->setText(QString::number( m_list.getNombreEtudiant() ) );
}


void MainWindow::voirListeMenu(const QPoint &pos)
{

}

void MainWindow::on_btnEffacer_clicked()
{
    ui->ledChercher->clear();
}

void MainWindow::on_btnToutSupprimer_clicked()
{
    m_list.vider() ;
    affichage();
    ui->ledNombreEtudiant->setText(QString::number(m_list.getNombreEtudiant()));
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
}


//--------------------------------------------------------------------
//Ouveture d'un fichier
//--------------------------------------------------------------------
void MainWindow::ouvrirCSV(const QString &fichier)
{
    QFile file ;

    file.setFileName(fichier);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file) ;

        // On efface tout les elements du liste
            m_list.vider();

        while( !in.atEnd())
        {
            QString texte ;
            QStringList champs ;
            QDate date;
            int id ;

            texte = in.readLine().trimmed() ;

            if(texte.isEmpty() )
            {
                continue ;
            }

            champs = texte.split(";") ;

            id = champs[3].toInt() ;
            date = QDate::fromString(champs[2] , "dd/MM/yyyy" ) ;

            qDebug() << id ;

            if( date.isValid() )
            {
                m_list.ajout(champs[0] , champs[1] , date , id ) ;
            }
            else
            {
                qDebug() << "Date invalide " ;
            }
        }

        file.close();
        affichage();
    }
}

void MainWindow::on_btnEnregistrer_clicked()
{
    QString nomFichier ;

    nomFichier = QFileDialog::getSaveFileName(this , "Eregistrement" , "" , "Fichier CSV (*.csv)");

    if(!nomFichier.isEmpty())
    {
        enregistrerCSV(nomFichier);
    }
}

void MainWindow::on_btnOuvrir_clicked()
{
    QString nomFichier ;

    nomFichier = QFileDialog::getOpenFileName(this , "Ouvrir" , "" , "Fichier CSV (*.csv)");

    if(!nomFichier.isEmpty())
    {
        ouvrirCSV(nomFichier);
    }
}
