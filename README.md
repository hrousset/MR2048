# 2048
Jeu du 2048 par Atwa et Laylay codé sur Qt avec QML et C++.

## Structure du jeu
L'objet qui lie le QML et le C++ est une QList<int> nomée lNombres qui contient tous les nombres qui aparaissent sur le tableau de jeu. Initialement, le jeu à été crée avec 16 cases, donc la liste comporte 16 nombres.

La classe ListeValeurs contient toutes les fonctions qui modifient la QList lorsqu'une touche est appuyée.
