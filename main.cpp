


#include <QApplication>

#include <QDebug>
#include <QRandomGenerator>


#include "./headers/ui/autocell.h"
#include "./headers/automate/automate.h"





int main(int argc, char *argv[])
{


    qRegisterMetaType<Automate*>();
    QApplication a(argc, argv);
    AutoCell w;
    w.show();


    return a.exec();
}
