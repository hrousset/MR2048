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
    int b1 = rand()%10;
    int b2 = rand()%10;
    for (int i=0; i<16; i++) {lNombres.append(0);}
    lNombres[a1] = 2;
    lNombres[a2] = 2;
    if (b1==0){lNombres[a1] = 4;}
    if (b2==0){lNombres[a2] = 4;}
    valScore = 0;
    etatJeu = 0;
    chgtValeurs();
    chgtScore();
    finJeu();
}

void listeValeurs::haut() {
    QList<int> l = lNombres;
    gravite(0);
    fusion(0);
    gravite(0);
    if (l!=lNombres) {addtile();}
    endGame();
    chgtValeurs();
    chgtScore();
}

void listeValeurs::bas() {
    QList<int> l = lNombres;
    gravite(1);
    fusion(1);
    gravite(1);
    if (l!=lNombres) {addtile();}
    endGame();
    chgtValeurs();
    chgtScore();
}

void listeValeurs::droite() {
    QList<int> l = lNombres;
    gravite(2);
    fusion(2);
    gravite(2);
    if (l!=lNombres) {addtile();}
    endGame();
    chgtValeurs();
    chgtScore();
}

void listeValeurs::gauche() {
    QList<int> l = lNombres;
    gravite(3);
    fusion(3);
    gravite(3);
    if (l!=lNombres) {addtile();}
    endGame();
    chgtValeurs();
    chgtScore();
}

QList<int> listeValeurs::lireValeurs() {
    return lNombres;
}

QString listeValeurs::lireScore() {
    return QString::number(valScore);
}

int listeValeurs::lireFin() {
    return etatJeu;
}


int listeValeurs::coordonnees(int x, int y) {
    return y*4+x;
}

void listeValeurs::remonter_haut(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(i,a+1)]!=0 && lNombres[coordonnees(i,a)]==0) {
            lNombres[coordonnees(i,a)] = lNombres[coordonnees(i,a+1)];
            lNombres[coordonnees(i,a+1)] = 0;
        }
    }
}

void listeValeurs::fusion_haut(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(i,a+1)]==lNombres[coordonnees(i,a)]) {
            valScore += lNombres[coordonnees(i,a+1)];
            lNombres[coordonnees(i,a)] = 2*lNombres[coordonnees(i,a+1)];
            lNombres[coordonnees(i,a+1)] = 0;
        }
    }
}

void listeValeurs::remonter_bas(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(i,a)]!=0 && lNombres[coordonnees(i,a+1)]==0) {
            lNombres[coordonnees(i,a+1)] = lNombres[coordonnees(i,a)];
            lNombres[coordonnees(i,a)] = 0;
        }
    }
}

void listeValeurs::fusion_bas(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(i,a)]==lNombres[coordonnees(i,a+1)]) {
            valScore += lNombres[coordonnees(i,a)];
            lNombres[coordonnees(i,a+1)] = 2*lNombres[coordonnees(i,a)];
            lNombres[coordonnees(i,a)] = 0;
        }
    }
}

void listeValeurs::remonter_gauche(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(a+1,i)]!=0 && lNombres[coordonnees(a,i)]==0) {
            lNombres[coordonnees(a,i)] = lNombres[coordonnees(a+1,i)];
            lNombres[coordonnees(a+1,i)] = 0;
        }
    }
}

void listeValeurs::fusion_gauche(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(a+1,i)]==lNombres[coordonnees(a,i)]) {
            valScore += lNombres[coordonnees(a+1,i)];
            lNombres[coordonnees(a,i)] = 2*lNombres[coordonnees(a+1,i)];
            lNombres[coordonnees(a+1,i)] = 0;
        }
    }
}

void listeValeurs::remonter_droite(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(a,i)]!=0 && lNombres[coordonnees(a+1,i)]==0) {
            lNombres[coordonnees(a+1,i)] = lNombres[coordonnees(a,i)];
            lNombres[coordonnees(a,i)] = 0;
        }
    }
}

void listeValeurs::fusion_droite(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(a,i)]==lNombres[coordonnees(a+1,i)]) {
            valScore += lNombres[coordonnees(a,i)];
            lNombres[coordonnees(a+1,i)] = 2*lNombres[coordonnees(a,i)];
            lNombres[coordonnees(a,i)] = 0;
        }
    }
}

void listeValeurs::gravite(int a) {
    if (a==0) {
        remonter_haut(0);

        remonter_haut(1);
        remonter_haut(0);

        remonter_haut(2);
        remonter_haut(1);
        remonter_haut(0);
    }
    if (a==1) {
        remonter_bas(2);

        remonter_bas(1);
        remonter_bas(2);

        remonter_bas(0);
        remonter_bas(1);
        remonter_bas(2);
    }
    if (a==2) {
        remonter_droite(2);

        remonter_droite(1);
        remonter_droite(2);

        remonter_droite(0);
        remonter_droite(1);
        remonter_droite(2);
    }
    if (a==3) {
        remonter_gauche(0);

        remonter_gauche(1);
        remonter_gauche(0);

        remonter_gauche(2);
        remonter_gauche(1);
        remonter_gauche(0);
    }
}

void listeValeurs::fusion(int a) {
    if (a==0) {
        fusion_haut(0);
        fusion_haut(1);
        fusion_haut(2);
    }
    if (a==1) {
        fusion_bas(2);
        fusion_bas(1);
        fusion_bas(0);
    }
    if (a==2) {
        fusion_droite(2);
        fusion_droite(1);
        fusion_droite(0);
    }
    if (a==3) {
        fusion_gauche(0);
        fusion_gauche(1);
        fusion_gauche(2);
    }
}

void listeValeurs::addtile() {
    srand((int)time(0));
    int a = rand()%16;
    int b = rand()%10;
    int c = 0;
    for (int i=0; i<16; i++){
        if (lNombres[i]!=0) {c++;}
    }
    if (c == 16) {
        return;
    }
    while (lNombres[a]!=0) {a = rand()%16;}
    lNombres[a] = 2;
    if (b==0) {lNombres[a]=4;}
}

void listeValeurs::restartGame() {
    srand((int)time(0));
    int a1 = rand()%16;  //initialisation des deux cases du debut
    int a2 = rand()%16;
    while(a1==a2){a2 = rand()%16;}   //Pour pas que les deux tuiles du depart soient superposees
    int b1 = rand()%10;
    int b2 = rand()%10;
    for (int i=0; i<16; i++) {lNombres[i]=0;}
    lNombres[a1] = 2;
    lNombres[a2] = 2;
    if (b1==0){lNombres[a1] = 4;}
    if (b2==0){lNombres[a2] = 4;}
    valScore = 0;
    etatJeu = 0;
    chgtValeurs();
    chgtScore();
    finJeu();
}

void listeValeurs::endGame() {
    int c = 0;
    for (int i=0; i<16; i++){
        if (lNombres[i]!=0) {c++;}
    }
    if (c == 16) {
        for (int i=0; i<16; i++){
            if (i>3){
                if (lNombres[i]==lNombres[i-4]){return;} //en haut
            }
            if (i%4!=0){
                if (lNombres[i]==lNombres[i-1]){return;} //a gauche
            }
            if (i%4!=3){
                if (lNombres[i]==lNombres[i+1]){return;} //a droite
            }
            if (i<12){
                if (lNombres[i]==lNombres[i+4]){return;} //en bas
            }
        }
        etatJeu = 1;
    }
    finJeu();
}


