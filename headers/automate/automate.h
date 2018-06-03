
#include <iostream>
#include <vector>
#include <QMetaType>

class Grille;
class Regle;

using namespace std;

class Automate
{
protected:
  int etat_max;
  int effet_bord;  // un entier dans le nombre d'etat, si effet_bord>= nb_etat  => tore

public:
  virtual ~Automate();
  Grille* etat_initial;
  int getEffetBord() {return effet_bord;}
  void setEffetBord(int effet);
  virtual string Presenter() {return "Automate";}
  virtual Grille*  AppliquerTransition(Grille* ma_grille);
};


//== AUTOMATE GENERAL =================================

class AutomateG : public Automate
{
protected:
  vector< Regle > liste_regle; //regle1 est plus complet et permet d'appliqer des regles par motifs
public:
  AutomateG(int etatmax, vector < Regle > liste_regle, int effetbord,Grille* etat_ini);
  ~AutomateG();
  Grille* AppliquerTransition(Grille* grille_actuelle);
};



//== AUTOMATE JEU DE VIE =================================


class AutomateJeuVie : public Automate
{
    int max_vivants;
    int min_vivants;
  public:
    AutomateJeuVie();
    AutomateJeuVie(int effetbord, Grille* etat_ini);
    AutomateJeuVie(int effetbord, Grille* etat_ini,int min,int max);
    ~AutomateJeuVie();
    int getMax() {return max_vivants;}
    int getMin(){return min_vivants;}
    void setMax(int max);
    void setMin(int min);
    string Presenter() {return "Jeu-Vie";}
    Grille* AppliquerTransition(Grille* grille_actuelle);
};

Q_DECLARE_METATYPE(Automate*)


class Automate1D : public Automate
{
    unsigned short int numero;
    string numeroBit;
public:
    Automate1D(int effet_bord,unsigned short int num, Grille* etat_ini);
    Automate1D(int effet_bord,const string& numeroBit, Grille* etat_ini);
    ~Automate1D(){};
    Grille* etat_initiale;
    string Presenter() {return "1D";}
    unsigned short int getNumero() const { return numero; }
    const std::string& getNumeroBit() const { return numeroBit; }
    Grille* AppliquerTransition(Grille* grille_actuelle);
};

short unsigned int NumBitToNum(const std::string& num);
string NumToNumBit(short unsigned int num);

