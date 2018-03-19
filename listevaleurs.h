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

    Q_PROPERTY(QList<int> jeuQML READ lireValeurs NOTIFY chgtValeurs);
    Q_PROPERTY(int scQML READ lireScore NOTIFY chgtScore);


    QList<int> lireValeurs();
    int lireScore();

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

signals:
    void chgtValeurs();
    void chgtScore();

public slots:

private:
    QList<int> lNombres;
    int valScore;

};

#endif // LISTEVALEURS_H
