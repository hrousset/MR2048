#include "case.h"

Case::Case()
{
    *valeur = NULL;
}
Case::Case(int x,int y)
{
    x = px;
    y = py;
    *valeur = NULL;
}
Case::fusion_cases(Case Case1,Case Case2)
{
    if (Case1.valeur == Case2.valeur)
    {
        Case1.valeur *=2;

    }
}
Case::move_case(Case Case1)
{
    // if (mouvement =...) for(...) ex: si mouvement droite, tant que l'on a rien sur la droite, on décale notre case sur la droite avec la limite de la borne : 4
}
Case::~Case()
{
    *valeur = NULL;
    delete Case();
}
