using namespace std;
#include "../../headers/automate/simulateur.h"
#include "../../headers/automate/automate.h"
#include "../../headers/automate/grille.h"
#include "../../headers/automate/cellule.h"
#include <typeinfo>

// CLASSE SIMULATEUR


//== CONSTRUCTEURS ========================================================


Simulateur::Simulateur()
{
    mon_automate = nullptr;

}


Simulateur::Simulateur(Automate* mon_automate): nb_generation(0), mon_automate(mon_automate)
{
  mes_grilles[2] = mon_automate->etat_initial;
  mes_grilles[0] = nullptr;
  mes_grilles[1] = nullptr;

  //cout << "Generation : "<< nb_generation;
  //mes_grilles[2].AfficherGrille();
}


Simulateur::~Simulateur()
{

}


//== METHODES ===========================================================

Grille* Simulateur::Generer()
{
  std::cout<<"hey";
  std::cout<<mon_automate->etat_initial->getLigne();
  nb_generation++;
  delete mes_grilles[0];
  mes_grilles[0] = nullptr;
  mes_grilles[0] = mes_grilles [1];
  mes_grilles[1] = mes_grilles [2];
  std::cout<<"hey2";
  mes_grilles[2] = mon_automate->AppliquerTransition(mes_grilles[1]);

  std::cout<<"hey3";
  //cout << "Generation : "<< nb_generation;
  //mes_grilles[2].AfficherGrille();
  return mes_grilles[2];
}

Grille* Simulateur::Degenerer()
{
  if (nb_generation>0 && mes_grilles[1] != nullptr)
  {
      nb_generation--;
      delete mes_grilles[2];
      mes_grilles[2] = mes_grilles[1];
      mes_grilles[1] = mes_grilles[0];
      mes_grilles[0] = nullptr;
      return mes_grilles[2];
  }

}
