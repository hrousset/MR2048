#include "listevaleurs.h"
#include <QObject>
#include <iostream>
#include <cstdlib>  //on inclut la fonction rand
#include <ctime>  //avoir le temps pour des nombres aleatoires

using namespace std;

listeValeurs::listeValeurs(QObject *parent) : QObject(parent)
//initialisation du jeu
{
    //on cree la liste de Qlist qui contiendra toutes les etapes du jeu
    for (int i=0;i<500;i++)
    {
            QList<int> tab({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
            tableau_point.append(tab);
    }

    compteur = 0;  //aucun coup n'a ete fait encore
    srand((int)time(0));
    int a1 = rand()%16;  //position des deux cases du debut
    int a2 = rand()%16;
    while(a1==a2){a2 = rand()%16;}   //Pour pas que les deux tuiles du depart soient superposees

    int b1 = rand()%10;
    int b2 = rand()%10;

    for (int i=0; i<16; i++) {lNombres.append(0);} //creation de la liste initialement nulle
    lNombres[a1] = 2;
    lNombres[a2] = 2;
    if (b1==0){lNombres[a1] = 4;} //1 chance sur 10 qu'une case initiale soit un 4
    if (b2==0){lNombres[a2] = 4;}

    agagne = 0;     //le jeu n'a pas encore été gagné
    chgtValeurs();

    valScore = 0;   //initialisation à 0 du score
    chgtScore();
    ajout_tab();
    depasse_compteur=false;

    etatJeu = 0;    //le jeu n'est pas perdu
    finJeu();

    etatMedaille = 0;   //le jeu n'est pas gagné
    finMedaille();

    visu = 0;  //on commence avec les couleurs claires
    chgtVisu();
}


void listeValeurs::haut() {
    QList<int> l = lNombres;
    gravite(0);
    fusion(0);
    gravite(0);
    if (l!=lNombres) {
        addtile();  //on ne rajoute une tuile que si le jeu a changé a ce mouvement
        ajout_tab();    //et on garde ce coup en memoire
    }
    if (agagne==0) {winGame();}   //verification que le jeu n'est pas gagné pour la premiere fois
    endGame();  //verification que le jeu n'est pas perdu
    chgtValeurs();
    chgtScore();
}

//les memes instructions sont faites pour toutes les fleches
//a l'exception de gravite et fusion qui sont faites dans une
//differente direction
void listeValeurs::bas() {
    QList<int> l = lNombres;
    gravite(1);
    fusion(1);
    gravite(1);
    if (l!=lNombres) {
        addtile();
        ajout_tab();
    }
    if (agagne==0) {winGame();}
    endGame();
    chgtValeurs();
    chgtScore();
}

void listeValeurs::droite() {

    QList<int> l = lNombres;
    gravite(2);
    fusion(2);
    gravite(2);
    if (l!=lNombres) {
        addtile();
        ajout_tab();
    }
    if (agagne==0) {winGame();}
    endGame();
    chgtValeurs();
    chgtScore();
}

void listeValeurs::gauche() {

    QList<int> l = lNombres;
    gravite(3);
    fusion(3);
    gravite(3);
    if (l!=lNombres) {
        addtile();
        ajout_tab();
    }
    if (agagne==0) {winGame();}
    endGame();
    chgtValeurs();
    chgtScore();
}


//les 4 methodes qui renvoient leur attribut associe
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

int listeValeurs::lireVisu() {
    return visu;
}


int listeValeurs::coordonnees(int x, int y) {
    return y*4+x;  //renvoie la position dans lNombres des cooredonnes d'une case
}

//methodes annexes de gravite(a) et fusion(a)

//regare si les cases non nulles de la ligne a+1 ont une case nulle au dessus d'elle
//si oui, cette case est remontee d'un cran
void listeValeurs::remonter_haut(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(i,a+1)]!=0 && lNombres[coordonnees(i,a)]==0) {
            lNombres[coordonnees(i,a)] = lNombres[coordonnees(i,a+1)];
            lNombres[coordonnees(i,a+1)] = 0;
        }
    }
}

//regarde si les cases de la ligne a+1 ont une case au dessus d'elles qui ont la meme valeur
//si oui, la case du bas est mise a 0, celle du haut est doublee
//et le score augmente de la valeur initiale de ces cases
void listeValeurs::fusion_haut(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(i,a+1)]==lNombres[coordonnees(i,a)]) {
            valScore += lNombres[coordonnees(i,a+1)];
            lNombres[coordonnees(i,a)] = 2*lNombres[coordonnees(i,a+1)];
            lNombres[coordonnees(i,a+1)] = 0;
        }
    }
}

//regare si les cases non nulles de la ligne a ont une case nulle en dessous d'elle
//si oui, cette case est descendue d'un cran
void listeValeurs::remonter_bas(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(i,a)]!=0 && lNombres[coordonnees(i,a+1)]==0) {
            lNombres[coordonnees(i,a+1)] = lNombres[coordonnees(i,a)];
            lNombres[coordonnees(i,a)] = 0;
        }
    }
}

//regarde si les cases de la ligne a ont une case en dessous d'elles qui ont la meme valeur
//si oui, la case du haut est mise a 0, celle du bas est doublee
//et le score augmente de la valeur initiale de ces cases
void listeValeurs::fusion_bas(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(i,a)]==lNombres[coordonnees(i,a+1)]) {
            valScore += lNombres[coordonnees(i,a)];
            lNombres[coordonnees(i,a+1)] = 2*lNombres[coordonnees(i,a)];
            lNombres[coordonnees(i,a)] = 0;
        }
    }
}

//regare si les cases non nulles de la colonne a+1 ont une case nulle a gauche d'elle
//si oui, cette case est deplacee d'un cran a gauche
void listeValeurs::remonter_gauche(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(a+1,i)]!=0 && lNombres[coordonnees(a,i)]==0) {
            lNombres[coordonnees(a,i)] = lNombres[coordonnees(a+1,i)];
            lNombres[coordonnees(a+1,i)] = 0;
        }
    }
}

//regarde si les cases de la colonne a+1 ont une case a gauche d'elles qui ont la meme valeur
//si oui, la case de droite est mise a 0, celle de gauche est doublee
//et le score augmente de la valeur initiale de ces cases
void listeValeurs::fusion_gauche(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(a+1,i)]==lNombres[coordonnees(a,i)]) {
            valScore += lNombres[coordonnees(a+1,i)];
            lNombres[coordonnees(a,i)] = 2*lNombres[coordonnees(a+1,i)];
            lNombres[coordonnees(a+1,i)] = 0;
        }
    }
}

//regare si les cases non nulles de la colonne a ont une case nulle a droite d'elle
//si oui, cette case est deplacee d'un cran a droite
void listeValeurs::remonter_droite(int a) {
    for (int i=0; i<4; i++) {
        if (lNombres[coordonnees(a,i)]!=0 && lNombres[coordonnees(a+1,i)]==0) {
            lNombres[coordonnees(a+1,i)] = lNombres[coordonnees(a,i)];
            lNombres[coordonnees(a,i)] = 0;
        }
    }
}

//regarde si les cases de la colonne a ont une case a droite d'elles qui ont la meme valeur
//si oui, la case de gauche est mise a 0, celle de droite est doublee
//et le score augmente de la valeur initiale de ces cases
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
        remonter_haut(0); //remontee des cases de la ligne 1 a la ligne 0

        remonter_haut(1); //remontee des cases de la ligne 2 a la ligne 1 et 0
        remonter_haut(0);

        remonter_haut(2); //remontee des cases de la ligne 3 a la ligne 2, 1 et 0
        remonter_haut(1);
        remonter_haut(0);
    }
    if (a==1) {
        remonter_bas(2); //de meme mais en changeant la direction

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
        fusion_haut(0); //fusion des cases de la ligne 1 vers 0
        fusion_haut(1); //fusion des cases de la ligne 2 vers 1
        fusion_haut(2); //fusion des cases de la ligne 3 vers 2
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
    int a = rand()%16;  //lieu de la nouvelle case
    int b = rand()%10;  //valeur de la nouvelle case
    int c = 0;
    for (int i=0; i<16; i++){
        if (lNombres[i]!=0) {c++;}
    }
    if (c == 16) {
        return;  //on verifie qu'il reste une case vide sinon on ne fait rien
    }
    while (lNombres[a]!=0) {a = rand()%16;} //on cherche une case vide de maniere aleatoire
    lNombres[a] = 2;
    if (b==0) {lNombres[a]=4;}  //on lui affecte sa valeur 2 ou 4
}


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
        lNombres[i]= tableau_point[compteur-1][i];
    }
    valScore = tableau_point[compteur-1][16];
    chgtValeurs();
    chgtScore();

}

void listeValeurs::modif_tableau()
{
    for (int i=0;i<16;i++)
    {
        tableau_point[compteur][i] = lNombres[i];
    }
    tableau_point[compteur][16] = valScore;
}

void listeValeurs::undo()
{
    if (compteur>1)
    {
        compteur -=1;
        modif_lN();
        chgtValeurs();
        chgtScore();
    }
}


void listeValeurs::restartGame() {
    srand((int)time(0));
    int a1 = rand()%16;  //initialisation des deux cases du debut
    int a2 = rand()%16;
    while(a1==a2){a2 = rand()%16;}   //Pour pas que les deux tuiles du depart soient superposees
    int b1 = rand()%10;
    int b2 = rand()%10;

    //on remet lNombres a 0
    for (int i=0; i<16; i++) {lNombres[i]=0;}

    //affectation des valeurs des deux cases initiales
    lNombres[a1] = 2;
    lNombres[a2] = 2;
    if (b1==0){lNombres[a1] = 4;}
    if (b2==0){lNombres[a2] = 4;}

    //on remet le score et la victoire a 0
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
    //Pour verifier si le jeu est perdu, on commence par regarder si toutes les cases sont non nulles
    int c = 0;
    for (int i=0; i<16; i++){
        if (lNombres[i]!=0) {c++;}
    }
    if (c == 16) {
        for (int i=0; i<16; i++){
            if (i>3){
                if (lNombres[i]==lNombres[i-4]){return;} //peut on fusionner vers le haut?
            }
            if (i%4!=0){
                if (lNombres[i]==lNombres[i-1]){return;} //vers la gauche?
            }
            if (i%4!=3){
                if (lNombres[i]==lNombres[i+1]){return;} //vers la droite?
            }
            if (i<12){
                if (lNombres[i]==lNombres[i+4]){return;} //ou vers le bas?
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
    //le jeu est gagne lorsqu'une case de valeur 2048 est créée
    //ici on le met a 32 pour y arriver plus rapidement
    for (int i=0; i<16; i++) {
        if (lNombres[i]==32) {
            etatMedaille = 1;
            finMedaille();
            agagne = 1;
        }
    }
}

void listeValeurs::visuclair() {
    visu = 0;
    chgtVisu();
}

void listeValeurs::visufonce() {
    visu = 1;
    chgtVisu();
}
