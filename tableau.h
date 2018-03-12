#ifndef TABLEAU_H
#define TABLEAU_H
#include "case.h"
#include <vector>
#include <iostream>
#include <QObject>

using namespace std;


class Tableau
{
public:
    Tableau();
    ~Tableau();
    void move_all(Tableau T);
private:
    //int taille;
    int** table = NULL;
};

#endif // TABLEAU_H
