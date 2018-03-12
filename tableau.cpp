#include "tableau.h"
#include "math.h"
#include <vector>
#include <cstdlib>  //on inclut la fonction rand
#include "case.h"
#include <QObject>


Tableau::Tableau()
{
    table = new int*[16];
    for (int i=0;i<16;i++)
    {
        //lignes et colonnes de notre tableau comprises entre 0 et 3
        table[i] = new int;//(i/4,i%4);
    }
    //à modifier légèrement pour ne pas avoir toujours la même séquence
    int a = rand()%17;
    //Case(a/4,a%4).valeur = 2;
}
void Tableau::move_all(Tableau T)
{
    //for (int i=0;i<length(T.table);i++)
    {
        //move_case(T.table(i/4,i%4));
    }
}
