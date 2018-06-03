#include "../../headers/ui/autocell.h"
#include "../../headers/ui/creation_automate.h"

#include "../../headers/automate/simulateur.h"
#include "../../headers/automate/automate.h"
#include "../../headers/automate/grille.h"
#include "../../headers/automate/cellule.h"



#include "ui_autocell.h"
#include<QTimer>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <typeinfo>

AutoCell::AutoCell(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AutoCell)
{
    ui->setupUi(this);
    connect(this,SIGNAL(on_pushButton_2_clicked()),this,SLOT(uneGeneration()));
    connect(this,SIGNAL(on_pushButton_clicked()),this,SLOT(generationContinue()));
    /*ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(10);


    for (int i=0; i< ui->tableWidget->rowCount();i++)
    {
        for (int j=0; j< ui->tableWidget->columnCount();j++)
        {
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString("0")));
        }
    }
    ui->tableWidget->setItem(3,5,new QTableWidgetItem("1"));
    ui->tableWidget->setItem(3,6,new QTableWidgetItem("1"));
    ui->tableWidget->setItem(4,5,new QTableWidgetItem("1"));
    ui->tableWidget->setItem(4,4,new QTableWidgetItem("1"));
    //afficher_couleur();
    */

}

AutoCell::~AutoCell()
{
    delete ui;
}


void AutoCell::on_actionNouvel_Automate_2_triggered()
{
    creation_automate fenetre2;
    connect(&fenetre2,SIGNAL(send_grille(Automate*)),this,SLOT(update_table(Automate*)));
    fenetre2.setModal(false);
    fenetre2.exec();

}


void AutoCell::generationContinue(){
    timer = new QTimer();
    timer->connect(timer, SIGNAL(timeout()),this, SLOT(uneGeneration()));
    timer->connect(this, SIGNAL(on_pushButton_3_clicked()),timer, SLOT(stop()));
    timer->connect(this, SIGNAL(on_horizontalSlider_valueChanged(int)),this,SLOT(settimer(int)));
    timer->start(this->ui->horizontalSlider->value());


}

void AutoCell::afficher_couleur()
{
    bool ok = false;
    for (int i=0; i< ui->tableWidget->rowCount();i++)
    {
        for (int j=0; j< ui->tableWidget->columnCount();j++)
        {

            switch (ui->tableWidget->item(i,j)->text().toInt(&ok,10))
            {
            case 0:
                ui->tableWidget->item(i,j)->setBackgroundColor(Qt::white);
                ui->tableWidget->item(i,j)->setForeground(Qt::white);
                break;
            case 1:
                ui->tableWidget->item(i,j)->setBackgroundColor(Qt::black);
                ui->tableWidget->item(i,j)->setForeground(Qt::black);
                break;
            case 2:
                ui->tableWidget->item(i,j)->setBackgroundColor(Qt::red);
                ui->tableWidget->item(i,j)->setForeground(Qt::red);
                break;
            case 3:
                ui->tableWidget->item(i,j)->setBackgroundColor(Qt::blue);
                ui->tableWidget->item(i,j)->setForeground(Qt::blue);
                break;
            case 4:
                ui->tableWidget->item(i,j)->setBackgroundColor(Qt::green);
                ui->tableWidget->item(i,j)->setForeground(Qt::green);
                break;
            case 5:
                ui->tableWidget->item(i,j)->setBackgroundColor(Qt::yellow);
                ui->tableWidget->item(i,j)->setForeground(Qt::yellow);
                break;
            default:
                break;
            }
            ok = false;


        }
    }

}

void AutoCell::update_table(Automate* mon_auto)
{
    Simulateur* sim = new Simulateur(mon_auto);
    this->mon_sim = sim;

    ui->tableWidget->clearContents();
    if (mon_sim->mon_automate->etat_initial->getLigne() == 1)
    {
            ui->tableWidget->setRowCount(0);
            ui->pushButton_4->setEnabled(0);
    }
    else
    {
        ui->tableWidget->setRowCount(mon_sim->mon_automate->etat_initial->getLigne());
        ui->pushButton_4->setEnabled(1);

    }
    ui->tableWidget->setColumnCount(mon_sim->mon_automate->etat_initial->getColonne());
    afficher_grille(this->mon_sim->mes_grilles[2]);

    if (ui->checkBox->isChecked() == 1 )
    {
        afficher_couleur();
    }


}

void AutoCell::afficher_grille(Grille* grille)
{
    if (grille != nullptr)
    {

        ui->label_4->setText(QString::number(mon_sim->getNbGen()));

        if (grille->getLigne() == 1)
        {
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            for (int j=1; j< grille->getColonne()+1;j++)
            {
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,j-1,new QTableWidgetItem(QString::number(grille->ma_grille[1][j].getEtat())));
            }
            ui->tableWidget->scrollToBottom();
        }
        else
        {

            for (int i=1; i< grille->getLigne() +1 ;i++)
            {
                for (int j=1; j< grille->getColonne()+1;j++)
                {

                    ui->tableWidget->setItem(i-1,j-1,new QTableWidgetItem(QString::number(grille->ma_grille[i][j].getEtat())));
                }
            }
        }
    }


}


void AutoCell::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 0)
    {
        for (int i=0; i< ui->tableWidget->rowCount();i++)
        {
            for (int j=0; j< ui->tableWidget->columnCount();j++)
            {
                ui->tableWidget->item(i,j)->setBackgroundColor(Qt::white);
                ui->tableWidget->item(i,j)->setForeground(Qt::black);
            }

        }

    }

    else
    {
        afficher_couleur();
    }
}

void AutoCell::on_pushButton_4_clicked()
{
    afficher_grille(this->mon_sim->Degenerer());

    if (ui->checkBox->isChecked()== 1)
    {
        afficher_couleur();
    }
}

void AutoCell::uneGeneration()
{
    afficher_grille(this->mon_sim->Generer());
    if (ui->checkBox->isChecked()== 1)
    {
        afficher_couleur();
    }
}

void AutoCell::settimer(int time)
{
    timer->setInterval(time);
}

void AutoCell::on_actionCharger_Automate_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Ouvrir Automate"), "../", tr("Fichier Autocell (*.autocell)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line = in.readLine();

    bool ok = false;

    if(line == "AutomateJeuVie")
    {
        int effetb = in.readLine().toInt(&ok,10);
        ok=false;
        int maxv = in.readLine().toInt(&ok,10);
        ok=false;
        int minv = in.readLine().toInt(&ok,10);
        ok=false;
        int nbl = in.readLine().toInt(&ok,10);
        ok=false;
        int nbc = in.readLine().toInt(&ok,10);
        ok=false;

        Grille* grille = new Grille(nbl,nbc);



        // REMPLIR GRILLE
        line = in.readLine();
        for (int i = 1; i< grille->getLigne() +1; i++)
        {

            for (int j = 1; j < grille->getColonne() + 1; j++)
            {

                //std::cout<<QString(line[j-1]).toInt(&ok,10);
                grille->ma_grille[i][j].setEtat(line[j-1].digitValue());
                ok = false;
            }
            //std::cout<<""<<endl;
            line = in.readLine();
        }

        // REMPLIRE BORD
        if (effetb == 1)
        {
            for (int i=0; i < grille->getLigne() +2 ; i++)
            {
                grille->ma_grille[i][0].setEtat(1);
                grille->ma_grille[i][grille->getColonne()+1].setEtat(1);
            }
            for (int j=0; j < grille->getColonne() +2 ; j++)
            {
                grille->ma_grille[0][j].setEtat(1);
                grille->ma_grille[grille->getLigne()+1][j].setEtat(1);
            }
        }

        if (effetb == 2)
        {
            for (int i=1; i < grille->getLigne() +1 ; i++)
            {
                grille->ma_grille[i][0].setEtat(grille->ma_grille[i][grille->getColonne()].getEtat());
                grille->ma_grille[i][grille->getColonne()+1].setEtat(grille->ma_grille[i][1].getEtat());
            }
            for (int j=1; j < grille->getColonne() +1 ; j++)
            {
                grille->ma_grille[0][j].setEtat(grille->ma_grille[grille->getLigne()][j].getEtat());
                grille->ma_grille[grille->getLigne()+1][j].setEtat(grille->ma_grille[1][j].getEtat());
            }

            grille->ma_grille[0][0].setEtat(grille->ma_grille[grille->getLigne()][grille->getColonne()].getEtat());
            grille->ma_grille[0][grille->getColonne()+1].setEtat(grille->ma_grille[grille->getLigne()][1].getEtat());
            grille->ma_grille[grille->getLigne()+1][grille->getColonne()+1].setEtat(grille->ma_grille[1][1].getEtat());
            grille->ma_grille[grille->getLigne()+1][0].setEtat(grille->ma_grille[1][grille->getColonne()].getEtat());


        }

        AutomateJeuVie* mon_auto = new AutomateJeuVie(effetb,grille);
        mon_auto->setEffetBord(effetb);
        mon_auto->setMax(maxv);
        mon_auto->setMin(minv);
        update_table(mon_auto);

    }
}

void AutoCell::on_actionSauvegarder_Automate_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Sauvegarder un Automate");
    msgBox.setInformativeText("Voulez vous vraiment sauvegarder votre automate?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

}
