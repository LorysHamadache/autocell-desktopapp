#ifndef AUTOCELL_H
#define AUTOCELL_H

#include <QMainWindow>
#include <vector>

class Grille;
class Automate;
class Simulateur;


namespace Ui {
class AutoCell;
}

class AutoCell : public QMainWindow
{
    Q_OBJECT

public:
    explicit AutoCell(QWidget *parent = 0);
    QTimer *timer;
    Simulateur* mon_sim;
    ~AutoCell();

    
private slots:
    void on_actionNouvel_Automate_2_triggered();

    void update_table(Automate*);
    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_4_clicked();
    void uneGeneration();
    void generationContinue();
    void settimer(int);




    void on_actionCharger_Automate_triggered();

    void on_actionSauvegarder_Automate_triggered();

signals:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_horizontalSlider_valueChanged(int);


private:
    Ui::AutoCell *ui;
    void afficher_couleur();
    void afficher_grille(Grille* grille);
};



#endif // AUTOCELL_H
