class Grille;
class Automate;

class Simulateur
{
      int nb_generation;
public:
  Simulateur();
  Simulateur(Automate* mon_automate);
  ~Simulateur();
  int getNbGen() {return nb_generation;}
  Automate* mon_automate;
  Grille* mes_grilles[3];
  Grille* Generer();
  Grille* Degenerer();
};

