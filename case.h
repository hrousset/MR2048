#ifndef CASE_H
#define CASE_H
#include "tableau.h"
#include <iostream>
#include <QObject>


using namespace std;

class Case
{
public:
    Case();
    Case(int x,int y);
    ~Case();

    void fusion_cases(Case Case1,Case Case2);
    //void move_case(Case Case1,Tableau tab);

    int *valeur;

private:
    int px,py;
};

#endif // CASE_H
