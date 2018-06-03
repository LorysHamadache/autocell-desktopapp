class Voisinage;

class Regle
{
    int x_cel;
    int y_cel;
    int etat_resultant;
public:
    int getX() {return x_cel;}
    int getY() {return y_cel;}
    int getEtat() {return etat_resultant;}
  Voisinage* pre_situation;
  Regle();
  ~Regle();
};
