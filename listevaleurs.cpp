#include "listevaleurs.h"
#include <QObject>
#include <iostream>
#include <cstdlib>  //on inclut la fonction rand
#include <ctime>  //avoir le temps pour des nombres aleatoires

#include "listevaleurs.h"

using namespace std;

listeValeurs::listeValeurs(QObject *parent) : QObject(parent)
{

    for (int i=0;i<500;i++)
    {
        cout <<0;
        for (int j=0;j<16;j++)
        {
            cout<<1;
            QList<int> tab({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
            tableau_point.append(tab);
        }

    }

    compteur = 0;
    srand((int)time(0));
    int a1 = rand()%16;  //initialisation des deux cases du debut
    int a2 = rand()%16;

    while(a1==a2){a2 = rand()%16;}   //Pour pas que les deux tuiles du depart soient superposees
    int b1 = rand()%10;
    int b2 = rand()%10;

    for (int i=0; i<16; i++) {lNombres.append(0);} //creation de la liste
    lNombres[a1] = 2;
    lNombres[a2] = 2;
    if (b1==0){lNombres[a1] = 4;} //1 chance sur 10 que la case initiale soit un 4
    if (b2==0){lNombres[a2] = 4;}
    agagne = 0;     //le jeu n'a pas encore été gagné
    chgtValeurs();

    valScore = 0;   //initialisation à  du score
    chgtScore();
    ajout_tab();
    depasse_compteur=false;

    etatJeu = 0;    //le jeu n'est pas perdu
    finJeu();

    etatMedaille = 0;   //le jeu n'est pas gagné
    finMedaille();
}


void listeValeurs::haut() {
    QList<int> l = lNombres;
    gravite(0);
    fusion(0);
    gravite(0);
    if (l!=lNombres) {addtile();}   //on ne rajoute une tuile que si le jeu a changé a ce mouvement
    if (agagne==0) {winGame();}   //verification que le jeu n'est pas gagné
    endGame();  //verification que le jeu n'est pas perdu
    chgtValeurs();
    chgtScore();
    ajout_tab();

}

void listeValeurs::bas() {
    QList<int> l = lNombres;
    gravite(1);
    fusion(1);
    gravite(1);
    if (l!=lNombres) {addtile();}
    if (agagne==0) {winGame();}
    endGame();
    chgtValeurs();
    chgtScore();
    ajout_tab();
}

void listeValeurs::droite() {

    QList<int> l = lNombres;
    gravite(2);
    fusion(2);
    gravite(2);
    if (l!=lNombres) {addtile();}
    if (agagne==0) {winGame();}
    endGame();
    chgtValeurs();
    chgtScore();
    ajout_tab();

}

void listeValeurs::gauche() {

    QList<int> l = lNombres;
    gravite(3);
    fusion(3);
    gravite(3);
    if (l!=lNombres) {addtile();}
    if (agagne==0) {winGame();}
    endGame();
    chgtValeurs();
    chgtScore();
    ajout_tab();
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

int listeValeurs::lireMedaille() {
    return etatMedaille;

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

/*
void listeValeurs::ajout_tab()
{
    //lNombres2=lNombres;

    if (compteur<500)
    {
        modif_tableau(*(tableau_point[compteur]));
        compteur += 1;
    }
    else
    {
        depasse_compteur = true;
        compteur = 0;
        tableau_point[compteur]=&lNombres; //on remet le compteur à 0, et on a en mémoire "seulement" les 500 coups précédents
        compteur+=1;
    }
}

void listeValeurs::modif_lN(QList<int> tab)
{
    for (int i=0;i<16;i++)
    {
        lNombres[i]= tab[i];
    }
    chgtValeurs();

}

void listeValeurs::modif_tableau(QList<int> tab)
{
    for (int i=0;i<16;i++)
    {
        tab[i] = lNombres[i];
    }
}

void listeValeurs::undo()
{
    //lNombres = lNombres2;
    //chgtValeurs();

    if (compteur>0)
    {
        modif_lN(*(tableau_point[compteur-1]));
        //lNombres = *(tableau_point[compteur-1]);
        compteur -=1;
        //delete &(tableau_point[compteur]);
        chgtValeurs();
    }
}



  Version 2 QList de QList*/
void listeValeurs::ajout_tab()
{
    if (compteur<500)
    {
        modif_tableau();
        compteur += 1;
    }
    else
    {
        depasse_compteur = true;
        compteur = 0;
        modif_tableau(); //on remet le compteur à 0, et on a en mémoire "seulement" les 500 coups précédents
        compteur+=1;
    }
}

void listeValeurs::modif_lN()
{
    for (int i=0;i<16;i++)
    {
        lNombres[i]= tableau_point[compteur][i];
    }
    chgtValeurs();

}

void listeValeurs::modif_tableau()
{
    for (int i=0;i<16;i++)
    {
        tableau_point[compteur][i] = lNombres[i];
    }
}

void listeValeurs::undo()
{
    //lNombres = lNombres2;
    //chgtValeurs();
    if (compteur>0)
    {
        compteur -=1;
        modif_lN();
        //lNombres = *(tableau_point[compteur-1]);

        //delete &(tableau_point[compteur]);
        chgtValeurs();
    }
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
    etatMedaille = 0;
    agagne = 0;
    chgtValeurs();
    chgtScore();
    finJeu();
    finMedaille();
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

void listeValeurs::supprmedaille() {
    etatMedaille = 0;
    finMedaille();
}

void listeValeurs::winGame() {
    for (int i=0; i<16; i++) {
        if (lNombres[i]==32) {
            etatMedaille = 1;
            finMedaille();
            agagne = 1;
        }
    }
}
