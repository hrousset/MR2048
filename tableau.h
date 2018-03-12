#ifndef TABLEAU_H
#define TABLEAU_H
#include "case.h"

#include <vector>


class Tableau
{
public:
    Tableau();
    move_all(Tableau T);
private:
    int taille;
    Case **table = NULL;
}

#endif // TABLEAU_H
