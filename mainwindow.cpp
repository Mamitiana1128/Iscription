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

    // Verification On fait plus de recherche
        connect(ui->ledChercher , &QLineEdit::textChanged , this , &MainWindow::ledChercherVide );

    // tritre fenetre
        MainWindow::setWindowTitle("Inscription") ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::affichage()
{
    model->setRowCount(0);

    const vector<Etudiant>& listRef = m_list.getList()  ;

    for( auto i = listRef.begin() ; i != listRef.end() ; ++i)
    {
        QList<QStandardItem*> item ;

        item.append(new QStandardItem(i->getName())) ;
        item.append(new QStandardItem(i->getSExe())) ;
        item.append(new QStandardItem(i->getDateNaissance().toString("dd/MM/yyyy")) );
        item.append(new QStandardItem(QString::number(i->getId()))) ;

        model->appendRow(item);
    }
}

void MainWindow::affichage(vector<Etudiant>::iterator it)
{
    model->setRowCount(0);

        QList<QStandardItem*> item ;

        item.append(new QStandardItem(it->getName())) ;
        item.append(new QStandardItem(it->getSExe())) ;
        item.append(new QStandardItem(it->getDateNaissance().toString("dd/MM/yyyy")) );
        item.append(new QStandardItem(QString::number(it->getId()))) ;

    model->appendRow(item);
}


void MainWindow::on_btnChercher_clicked()
{
    QString indice ;
    int id ;
    bool ok ;
    vector<Etudiant>::iterator it ;

    indice = ui->ledChercher->text() ;
    // Verification si un chiffre ou pas
        id = indice.toInt(&ok) ;

        if(ok)
        {
            it = m_list.rechercher(id) ;
        }
        else
        {
            it = m_list.rechercher(indice) ;
        }

    // affichage du list
        if(it != m_list.getList().end() )
        {
            affichage(it);
        }
        else
        {
            model->setRowCount(0) ;
        }
}

void MainWindow::on_btnNettoyer_clicked()
{
    ui->ledName->clear();
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
}

void MainWindow::ledChercherVide()
{
    if(ui->ledChercher->text().isEmpty())
    {
        affichage() ;
    }
}
