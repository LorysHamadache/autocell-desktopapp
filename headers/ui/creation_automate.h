#ifndef CREATION_AUTOMATE_H
#define CREATION_AUTOMATE_H

#include <QDialog>
#include <vector>


class Automate;


namespace Ui {
class creation_automate;
}

class creation_automate : public QDialog
{
    Q_OBJECT

public:
    explicit creation_automate(QWidget *parent = 0);
    ~creation_automate();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_5_valueChanged(int arg1);

    void on_lineEdit_editingFinished();

signals:
    void send_grille(Automate*);
private:
    Ui::creation_automate *ui;

    Automate* fromtabletogrille ();

};


#endif // CREATION_AUTOMATE_H
