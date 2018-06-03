using namespace std;
#include "../../headers/automate/grille.h"
#include "../../headers/automate/cellule.h"



//== CLASSE CELLULE ==============


//== CONSTRUCTEURS ===================================
Cellule::Cellule() : etat(0),positionx(0),positiony(0)
{

}

Cellule::Cellule(int etat, int positionx, int positiony) : etat(etat), positionx(positionx), positiony(positiony)
{
}

Cellule::~Cellule()
{

}



//== METHODES =======================================

void Cellule::setEtat(int new_etat)
{
  etat = new_etat;
}


int Cellule::nb_vosines_etat(int etat_recherche)
{
  if (etat == etat_recherche)
  {
    return mon_voisinage->nbEtat(etat_recherche)-1;
  }
  else
  {
    return mon_voisinage->nbEtat(etat_recherche);
  }


}
