#ifndef LISTEVALEURS_H
#define LISTEVALEURS_H


#include <QObject>
#include <iostream>

class listeValeurs : public QObject
{
    Q_OBJECT
public:
    explicit listeValeurs(QObject *parent=0);
    Q_INVOKABLE void haut();
    Q_INVOKABLE void bas();
    Q_INVOKABLE void gauche();
    Q_INVOKABLE void droite();


    Q_PROPERTY(QList<int> jeuQML READ lireValeurs NOTIFY chgtValeurs)
    Q_PROPERTY(int scQML READ lireScore NOTIFY chgtScore)

    Q_PROPERTY(QList<int> jeuQML READ lireValeurs NOTIFY chgtValeurs);
    Q_PROPERTY(QString scQML READ lireScore NOTIFY chgtScore);
    Q_PROPERTY(int finQML READ lireFin NOTIFY finJeu);
    Q_PROPERTY(int medailleQML READ lireMedaille NOTIFY finMedaille);



    QList<int> lireValeurs();
    QString lireScore();
    int lireFin();
    int lireMedaille();

    void gravite(int a);
    void fusion(int a);
    int coordonnees(int x,int y);
    void addtile();

    void remonter_haut(int a);
    void remonter_bas(int a);
    void remonter_droite(int a);
    void remonter_gauche(int a);

    void fusion_haut(int a);
    void fusion_bas(int a);
    void fusion_droite(int a);
    void fusion_gauche(int a);
    void ajout_tab();


    void endGame();
    void winGame();

signals:
    void chgtValeurs();
    void chgtScore();
    void finJeu();
    void finMedaille();

public slots:
    void restartGame();
    void supprmedaille();
    void undo();

private:
    QList<int> lNombres;
    int valScore;
    QList<int> **tableau_point;
    int compteur;
    bool depasse_compteur;
    int etatJeu;
    int etatMedaille;
    int agagne;





//>>>>>>> 11080c69b86b3043be17083ce53c681655f5d07d
};

#endif // LISTEVALEURS_H
