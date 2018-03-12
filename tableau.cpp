#include "tableau.h"
#include "math.h"
#include <vector>
#include <cstdlib>  //on inclut la fonction rand

Tableau::Tableau()
{
    table = new Case*[16];
    for (i=0;i<16;i++)
    {
        //lignes et colonnes de notre tableau comprises entre 0 et 3
        table[i] = Case(i/4,i%4);
        int a = rand()%17; //à modifier légèrement pour ne pas avoir toujours la même séquence
        Case(a/4,a%4).valeur = 2;
    }
}
Tableau::move_all(Tableau T)
{
    for (i=0;i<length(T.table);i++)
    {
        move_case(T.table(i/4,i%4));
    }
}
