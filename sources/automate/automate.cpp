using namespace std;
#include "../../headers/automate/automate.h"
#include "../../headers/automate/grille.h"
#include "../../headers/automate/regle.h"
#include "../../headers/automate/cellule.h"



// CLASSE AUTOMATES



//== CONSTRUCTEUR AUTOMATE =============================================================================



Automate::~Automate()
{

}


//== CONSTRUCTEUR AUTOMATE GENERAL =============================================================================


AutomateG::AutomateG(int etatmax, vector < Regle > liste_regle, int effetbord,Grille* etat_ini): liste_regle(liste_regle)
{
  etat_max = etatmax;
  effet_bord = effetbord;
  etat_initial = etat_ini;
}


AutomateG::~AutomateG()
{
}


//== CONSTRUCTEUR AUTOMATE JEU DE VIE =============================================================================


AutomateJeuVie::AutomateJeuVie()
{
  etat_max = 1;
  max_vivants = 3;
  min_vivants = 2;
  effet_bord = 0;
}

AutomateJeuVie::AutomateJeuVie(int effetbord,Grille* etat_ini)
{

  etat_max = 1;
  max_vivants = 3;
  min_vivants = 2;
  effet_bord = effetbord;
  etat_initial= etat_ini;
}

AutomateJeuVie::AutomateJeuVie(int effetbord,Grille* etat_ini,int min,int max) : max_vivants(max),min_vivants(min)
{

  etat_max = 1;
  effet_bord = effetbord;
  etat_initial = etat_ini;
}

AutomateJeuVie::~AutomateJeuVie()
{

}


//== METHODES AUTOMATE =========================================================================================


Grille* Automate::AppliquerTransition(Grille* grille_actuelle)
{
     std::cout<<"classic auto"<<endl;
    return grille_actuelle;
}

void Automate::setEffetBord(int effet)
{
    effet_bord=effet;
}

//== METHODES AUTOMATE GENERAL ===================================================================================


Grille* AutomateG::AppliquerTransition(Grille* grille_actuelle)
{
     std::cout<<"gen"<<endl;
    return grille_actuelle;
}



//== METHODES AUTOMATE JEU DE VIE ==============================================================================


Grille* AutomateJeuVie::AppliquerTransition(Grille* grille_actuelle)
{

  Grille* grille2 = new Grille();
  *grille2 = *grille_actuelle;

  for (int i=1;i<grille_actuelle->getLigne()+1;i++)
  {
    for (int j=1;j<grille_actuelle->getColonne()+1;j++)
    {
      int somv = grille_actuelle->ma_grille[i-1][j-1].getEtat() + grille_actuelle->ma_grille[i-1][j].getEtat() + grille_actuelle->ma_grille[i-1][j+1].getEtat() + grille_actuelle->ma_grille[i][j-1].getEtat() +grille_actuelle->ma_grille[i][j+1].getEtat() + grille_actuelle->ma_grille[i+1][j-1].getEtat() + grille_actuelle->ma_grille[i+1][j].getEtat()
      + grille_actuelle->ma_grille[i+1][j+1].getEtat();
      if (((grille_actuelle->ma_grille[i][j].getEtat() == 1) && (somv <=max_vivants) && (somv>=min_vivants)) || ((grille_actuelle->ma_grille[i][j].getEtat() == 0) && (somv==max_vivants)))
      {
        grille2->ma_grille[i][j].setEtat(1);
      }
      else
      {
        grille2->ma_grille[i][j].setEtat(0);
      }
    }
  }



  if (effet_bord == 2)
  {
      std::cout<<"YO";
      for (int i=1; i < grille2->getLigne() +1 ; i++)
      {
          grille2->ma_grille[i][0].setEtat(grille2->ma_grille[i][grille2->getColonne()].getEtat());
          grille2->ma_grille[i][grille2->getColonne()+1].setEtat(grille2->ma_grille[i][1].getEtat());
      }
      for (int j=1; j < grille2->getColonne() +1 ; j++)
      {
          grille2->ma_grille[0][j].setEtat(grille2->ma_grille[grille2->getLigne()][j].getEtat());
          grille2->ma_grille[grille2->getLigne()+1][j].setEtat(grille2->ma_grille[1][j].getEtat());
      }
      grille2->ma_grille[0][0].setEtat(grille2->ma_grille[grille2->getLigne()][grille2->getColonne()].getEtat());
      grille2->ma_grille[0][grille2->getColonne()+1].setEtat(grille2->ma_grille[grille2->getLigne()][1].getEtat());
      grille2->ma_grille[grille2->getLigne()+1][grille2->getColonne()+1].setEtat(grille2->ma_grille[1][1].getEtat());
      grille2->ma_grille[grille2->getLigne()+1][0].setEtat(grille2->ma_grille[1][grille2->getColonne()].getEtat());

  }

  return grille2;
}

void AutomateJeuVie::setMax(int max) {
    max_vivants=max;
}

void AutomateJeuVie::setMin(int min) {
    min_vivants=min;
}
//Automate1D

Automate1D::Automate1D(int effet_bord,const string& numeroBit, Grille* etat_ini) : numeroBit(numeroBit)
{
    effet_bord = effet_bord;
    numero=NumBitToNum(numeroBit);
    etat_initial = etat_ini;
}

Automate1D::Automate1D(int effet_bord,unsigned short int num, Grille* etat_ini)
{
    effet_bord = effet_bord;
    numero=num;
    numeroBit=NumToNumBit(num);
    etat_initial = etat_ini;
}

short unsigned int NumBitToNum(const std::string& num) {
    int puissance = 1;
    short unsigned int numero = 0;
    for (int i = 7; i >= 0; i--) {
        if (num[i] == '1') numero += puissance;
        //else if (num[i] != '0') throw AutomateException("Numero d'automate indefini");
        puissance *= 2;
    }
    return numero;
}

std::string NumToNumBit(short unsigned int num) {
    std::string numeroBit;
    unsigned short int p = 128;
    int i = 7;
    while (i >= 0) {
        if (num >= p) {
            numeroBit.push_back('1');
            num -= p;
        }
        else { numeroBit.push_back('0'); }
        i--;
        p = p / 2;
    }
    return numeroBit;
}


Grille* Automate1D::AppliquerTransition(Grille* grille_actuelle)
{
    Grille* grille2 = new Grille();
    *grille2 = *grille_actuelle;   
        for (int i=1; i<grille_actuelle->getColonne()+1; i++)
        {
            int conf = 0;
            if(i>1) conf+=grille_actuelle->ma_grille[1][i-1].getEtat()*4;
            conf+=(grille_actuelle->ma_grille[1][i].getEtat())*2;
            if (i<(grille_actuelle->getColonne())-1) conf+=grille_actuelle->ma_grille[1][i+1].getEtat();
            grille2->ma_grille[1][i].setEtat(numeroBit[7-conf]-'0');
        }
    return grille2;
}




