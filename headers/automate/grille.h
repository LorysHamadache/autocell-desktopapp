#include <vector>
class Cellule;


class Grille
{
  int nb_ligne;
  int nb_colonne;

public:
  Grille();
  Grille(int nbl,int nbc);
  Grille(Grille* grilleacopier);
  ~Grille();
  vector< vector < Cellule > > ma_grille;
  int getLigne() {return nb_ligne;}
  int getColonne() {return nb_colonne;}
  void AfficherGrille();
};



class Voisinage : public Grille
{
public:
  int nbEtat(int Etat);

};
