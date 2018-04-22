#ifndef LISTEVALEURS_H
#define LISTEVALEURS_H


#include <QObject>
#include <iostream>

class listeValeurs : public QObject
{
    Q_OBJECT
public:
    explicit listeValeurs(QObject *parent=0);
    //methodes appellees lorsque l'on appuye sur les fleches du clavier
    Q_INVOKABLE void haut();
    Q_INVOKABLE void bas();
    Q_INVOKABLE void gauche();
    Q_INVOKABLE void droite();

    //les cinq attributs qui lient le C++ avec le QML
    Q_PROPERTY(QList<int> jeuQML READ lireValeurs NOTIFY chgtValeurs);
    Q_PROPERTY(QString scQML READ lireScore NOTIFY chgtScore);
    Q_PROPERTY(int finQML READ lireFin NOTIFY finJeu);
    Q_PROPERTY(int medailleQML READ lireMedaille NOTIFY finMedaille);
    Q_PROPERTY(int visuQML READ lireVisu  NOTIFY chgtVisu)

    //les cinq methodes qui renvoient ces attributs
    QList<int> lireValeurs();
    QString lireScore();
    int lireFin();
    int lireMedaille();
    int lireVisu();

    //methode qui envoie toutes les cases d'un cote selon l'entier a
    void gravite(int a);
    //methode qui fusionne les cases cote a cote selon une direction dictee par l'entier a
    void fusion(int a);
    //methode simplificatrice qui prend les coordonnees d'une case et renvoie son rang dans lNombres
    int coordonnees(int x,int y);
    //methode qui rajoute une case a apres chaque coup de maniere aleatoire
    void addtile();

    //méthodes utilisees dans gravite et fusion pour simplifier leur ecriture
    void remonter_haut(int a);
    void remonter_bas(int a);
    void remonter_droite(int a);
    void remonter_gauche(int a);
    void fusion_haut(int a);
    void fusion_bas(int a);
    void fusion_droite(int a);
    void fusion_gauche(int a);


    void ajout_tab();
    //modifie la liste actuelle
    void modif_lN();
    //ajoute le tableau (l'état du 2048) à une liste de tableaux
    void modif_tableau();

    //si le jeu est perdu, il met finJeu à 1
    void endGame();
    //si le jeu est gagné, il met agagne à 1
    void winGame();

signals:
    void chgtValeurs();
    void chgtScore();
    void finJeu();
    void finMedaille();
    void chgtVisu();

public slots:
    //ces methodes sont appellees lorsque l'on clique sur une mouseArea

    //reinitialise lNombres et donc le jeu
    void restartGame();
    //met la variable etatMedaille à 0 (ce qui supprime la medaille)
    void supprmedaille();
    //fait revenir le jeu d'un coup en arrière
    void undo();
    //met visu à 0 (ce qui enclenche les couleurs claires)
    void visuclair();
    //met visu à 1 (ce qui enclenche les couleurs sombres)
    void visufonce();

private:
    //vecteur de 16 nombres qui correspondent aux valeurs dans les cases du jeu
    QList<int> lNombres;
    //entier qui donne le score
    int valScore;
    //va nous permettre de savoir si on a dépassé les 500 coups
    bool depasse_compteur;
    //tableau de tableaux qui stockent tous les états précédents du 2048 pour pouvoir y remonter
    QList<QList<int>> tableau_point;
    //l'entier nous permettra de savoir où nous en sommes lorsque nous stockerons les tableaux précédents
    int compteur;
    //1 si le jeu est perdu, 0 sinon
    int etatJeu;
    //1 si la medaille est visible, 0 sinon
    int etatMedaille;
    //1 si le jeu a deja ete gagne, 0 sinon (car on peut continuer a jouer meme si on a gagne)
    int agagne;
    //1 si les couleurs sont sombres, 0 si claires
    int visu;


};

#endif // LISTEVALEURS_H
