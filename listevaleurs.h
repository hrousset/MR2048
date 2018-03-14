#ifndef LISTEVALEURS_H
#define LISTEVALEURS_H

using namespace std;

#include <QObject>
#include <iostream>

class listeValeurs : public QObject
{
    Q_OBJECT;
public:
    explicit listeValeurs(QObject *parent=0);
    Q_INVOKABLE void haut();
    Q_INVOKABLE void bas();
    Q_INVOKABLE void gauche();
    Q_INVOKABLE void droite();

    Q_PROPERTY(QList<int> jeuQML READ lireValeurs NOTIFY chgtValeurs);

    QList<int> lireValeurs();
    bool estVoisin(int a, int b);

signals:
    void chgtValeurs();

public slots:

private:
    QList<int> lNombres;

};

#endif // LISTEVALEURS_H
