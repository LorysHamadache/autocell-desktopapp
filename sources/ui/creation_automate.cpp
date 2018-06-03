#include "../../headers/ui/creation_automate.h"

#include "../../headers/automate/simulateur.h"
#include "../../headers/automate/automate.h"
#include "../../headers/automate/grille.h"
#include "../../headers/automate/cellule.h"

#include <iostream>
#include <QRandomGenerator>
#include <math.h>
#include "ui_creation_automate.h"


//====  CONSTRUCTEURS PAGE ================================================
creation_automate::creation_automate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creation_automate)
{
    ui->setupUi(this);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("0"));

    QRegExp rx("([0-1]){1,8}");
    ui->lineEdit->setValidator(new QRegExpValidator(rx, this));
}


creation_automate::~creation_automate()
{
    delete ui;
}



//== METHODES =============================================


Automate* creation_automate::fromtabletogrille()
{

    Grille* grille = new Grille(ui->tableWidget->rowCount(),ui->tableWidget->columnCount());

    int effet=0;

    bool ok = false;

    // GENERATION PERSONALISE
    if(ui->comboBox_2->currentIndex() == 2)
    {

        for (int i = 1; i< grille->getLigne() +1; i++)
        {
            for (int j = 1; j < grille->getColonne() + 1; j++)
            {
                grille->ma_grille[i][j].setEtat(ui->tableWidget->item(i-1,j-1)->text().toInt(&ok,10));
                ok = false;
            }
        }
    }

    // GENERATION ALEATOIRE


    else if( ui->comboBox_2->currentIndex() == 0)
    {
        for (int i = 1; i< grille->getLigne() +1; i++)
        {
            for (int j = 1; j < grille->getColonne() + 1; j++)
            {
                grille->ma_grille[i][j].setEtat(QRandomGenerator::global()->bounded(2));

            }
        }

    }

    else if(ui->comboBox_2->currentIndex() == 1)
    {
        for (int i= 1; i<grille->getLigne() +1; i++)
        {
            for (int j=1; j < (floor(grille->getColonne())/2) +1; j++){
                grille->ma_grille[i][j].setEtat(QRandomGenerator::global()->bounded(2));
            }
        }
        if(grille->getColonne()%2!=0)
        {
            for (int i= 1; i<grille->getLigne() +1; i++)
            {
                    grille->ma_grille[i][(floor(grille->getColonne())/2)].setEtat(QRandomGenerator::global()->bounded(2));
            }
        }
        int r=0;
        int e=(ceil(grille->getColonne())/2);
        for (int i= 1; i<grille->getLigne() +1; i++)
        {
            for (int j= (ceil(grille->getColonne())/2) +1; j < grille->getColonne() +1; j++){
                grille->ma_grille[i][j].setEtat(grille->ma_grille[i][e-r].getEtat());
                ++r;
            }
            r=0;
        }
    }



    // EFFETS DE BORDS
    if (ui->comboBox_3->currentIndex() == 1)
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
        effet =1;
    }

    if (ui->comboBox_3->currentIndex() == 2)
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
        grille->ma_grille[0][grille->getColonne()+1].setEtat(grille->ma_grille[grille->getColonne()][1].getEtat());
        grille->ma_grille[grille->getLigne()+1][grille->getColonne()+1].setEtat(grille->ma_grille[1][1].getEtat());
        grille->ma_grille[grille->getLigne()+1][0].setEtat(grille->ma_grille[1][grille->getColonne()].getEtat());

        effet=2;
    }

    // AUTOMATE 1D

    if (ui->comboBox->currentIndex() == 0)
    {
        Automate1D* mon_auto = new Automate1D(ui->comboBox_3->currentText().toInt(&ok,10),ui->spinBox_5->value(),grille);
        mon_auto->setEffetBord(effet);
        ok = false;
        return mon_auto;
    }

    // AUTOMATE JEU DE VIE

    else if ( ui->comboBox->currentIndex() == 1)
    {
        AutomateJeuVie* mon_auto = new AutomateJeuVie(ui->comboBox_3->currentText().toInt(&ok,10),grille);
        mon_auto->setEffetBord(effet);
        mon_auto->setMax(ui->spinBox_6->value());
        mon_auto->setMin(ui->spinBox_4->value());
        ok = false;
        return mon_auto;
    }
}


//== SLOTS WIDGETS =======================================



void creation_automate::on_buttonBox_rejected()
{
   close();
}

void creation_automate::on_buttonBox_accepted()
{
    //connect(ui->buttonBox,SIGNAL(accepted()),this,SIGNAL(send_grille(std::vector < std::vector < int >>)));
    std::cout<<"1"<<endl;
    emit send_grille(fromtabletogrille());
    std::cout<<"close"<<endl;

    close();

}


void creation_automate::on_comboBox_currentIndexChanged(int index)
{
    if(index == 1 || index == 2)
    {
        ui->spinBox->setEnabled(1);
        ui->spinBox_5->setEnabled(0);
        ui->lineEdit->setEnabled(0);
    }
    else
    {
        ui->spinBox->setEnabled(0);
        ui->spinBox->setValue(1);
        ui->spinBox_5->setEnabled(1);
        ui->lineEdit->setEnabled(1);

    }

    if (index == 1)
    {
        ui->spinBox_3->setValue(2);
        ui->spinBox_3->setEnabled(0);
        ui->spinBox_4->setEnabled(1);
        ui->spinBox_6->setEnabled(1);
    }
    else
    {
        ui->spinBox_4->setEnabled(0);
        ui->spinBox_6->setEnabled(0);
        ui->spinBox_3->setEnabled(1);
    }
}

void creation_automate::on_comboBox_2_currentIndexChanged(int index)
{
    if (index == 2)
    {
        ui->tableWidget->setMaximumHeight(55000);
        ui->tableWidget->setMaximumWidth(55000);
    }
    else
    {
        ui->tableWidget->setMaximumHeight(0);
        ui->tableWidget->setMaximumWidth(0);

    }
}

void creation_automate::on_spinBox_2_valueChanged(int arg1)
{
    ui->tableWidget->setColumnCount(arg1);
    for (int i=0; i< ui->tableWidget->rowCount();i++)
    {
        for (int j=0; j< ui->tableWidget->columnCount();j++)
        {
            if (ui->tableWidget->item(i,j) == nullptr)ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString("0")));
        }
    }

}

void creation_automate::on_spinBox_valueChanged(int arg1)
{
    ui->tableWidget->setRowCount(arg1);
    for (int i=0; i< ui->tableWidget->rowCount();i++)
    {
        for (int j=0; j< ui->tableWidget->columnCount();j++)
        {
            if (ui->tableWidget->item(i,j) == nullptr)ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString("0")));
        }
    }
}

void creation_automate::on_spinBox_5_valueChanged(int arg1)
{
    ui->lineEdit->setText(QString::fromStdString(NumToNumBit(arg1)));
}



void creation_automate::on_lineEdit_editingFinished()
{
    ui->spinBox_5->setValue(NumBitToNum(ui->lineEdit->text().toStdString()));
}
