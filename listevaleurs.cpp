#include "listevaleurs.h"
#include <QObject>
#include <iostream>
#include <cstdlib>  //on inclut la fonction rand
#include <ctime>  //avoir le temps pour des nombres aleatoires

#include "listevaleurs.h"

using namespace std;

listeValeurs::listeValeurs(QObject *parent) : QObject(parent)
{
    srand((int)time(0));
    int a1 = rand()%16;  //initialisation des deux cases du debut
    int a2 = rand()%16;
    while(a1==a2){a2 = rand()%16;}   //Pour pas que les deux tuiles du depart soient superposees
    int b1 = rand()%4;
    int b2 = rand()%4;
    for (int i=0; i<16; i++){
        lNombres.append(0);
    }
    lNombres[a1] = 2;
    lNombres[a2] = 2;
    if (b1==0){lNombres[a1] = 4;}
    if (b2==0){lNombres[a2] = 4;}
    chgtValeurs();
}

void listeValeurs::haut() {
    for(int i=0; i<16; i++){lNombres[i]=2;}
    chgtValeurs();
}

void listeValeurs::bas() {
    for(int i=0; i<16; i++){lNombres[i]=4;}
    chgtValeurs();
}

void listeValeurs::droite() {

}

void listeValeurs::gauche() {

}

QList<int> listeValeurs::lireValeurs() {
    return lNombres;
}

bool listeValeurs::estVoisin(int a, int b) {
    int x1 = a%4;
    int x2 = b%4;
    int y1 = (a-a%4)/4;
    int y2 = (b-b%4)/4;
    if (abs(x1-x2)==1 || abs(y1-y2)==1) {return true;}
    return false;
}




