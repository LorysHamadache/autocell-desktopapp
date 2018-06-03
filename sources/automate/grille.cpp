using namespace std;

#include "../../headers/automate/grille.h"
#include "../../headers/automate/cellule.h"
#include <iostream>

// CLASSE GRILLE


//== CONSTRUCTEURS ============================
Grille::Grille() :nb_ligne(1),nb_colonne(10)
{
  ma_grille.resize(nb_ligne+2);
  for (vector<Cellule>& vec:ma_grille)
  {
    vec.resize(nb_colonne+2);
  }

  for(int i=0; i<nb_ligne+2;i++)
  {
    for (int j=0; j<nb_colonne+2;j++)
    {
      ma_grille[i][j] = Cellule(0,i,j);
    }
  }

}


Grille::Grille(int nbl,int nbc) : nb_ligne(nbl), nb_colonne(nbc)
{
  ma_grille.resize(nb_ligne+2);
  for (vector<Cellule>& vec:ma_grille)
  {
    vec.resize(nb_colonne+2);
  }

  for(int i=0; i<nb_ligne+2;i++)
  {
    for (int j=0; j<nb_colonne+2;j++)
    {
      ma_grille[i][j] = Cellule(0,i,j);
    }
  }
}


Grille::Grille(Grille* grilleacopier)
{
  nb_ligne = grilleacopier->nb_ligne;
  nb_colonne = grilleacopier->nb_colonne;

}

Grille::~Grille()
{
}



//== METHODES GRILLE =============================

void Grille::AfficherGrille()
{

  std::cout<<endl;
  for (int i=1; i<nb_ligne+1;i++)
  {
    for (int j=1; j<nb_colonne+1;j++)
    {
        cout<<" ";
        cout<<ma_grille[i][j].getEtat();
    }
    std::cout<<endl;
  }
}

//== METHODES VOISINAGE =============================


int Voisinage::nbEtat(int Etat)
{
  int somme = 0;
  for (int i=0; i<getLigne();i++)
  {
    for (int j=0; j<getColonne();j++)
    {
        if (ma_grille[i][j].getEtat() == Etat)
        {
          somme++;
        }
    }
  }
  return somme;
}

