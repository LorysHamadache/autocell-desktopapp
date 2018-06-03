class Voisinage;

class Cellule
{
  int positionx;
  int positiony;
  int etat;

public:
  Cellule();
  Cellule(int etat, int positionx, int positiony);
  ~Cellule();
  int getEtat() {return etat;};
  void setEtat(int new_etat);
  int nb_vosines_etat(int etat_recherche);
  Voisinage* mon_voisinage;

};
