# 2048
Jeu du 2048 par Atwa et Laylay codé sur Qt avec QML et C++.

## Structure générale du jeu
L'objet principal qui lie le QML et le C++ est une QList<int> nomée *lNombres*, attribut de la classe *listeValeurs*, qui contient tous les nombres qui aparaissent sur le tableau de jeu. Initialement, le jeu à été crée avec 16 cases, donc la liste comporte 16 nombres.
  
LNombres est initialisé avec deux cases aléatoires qui vallent 2 ou 4 avec une certaine probabilité. Il y a ensuite 4 fonctions QINVOCABLE (haut, bas, droite et gauche) qui sont déclanchées lorsqu'une flêche du clavier est appuyée.

## Détails des attributs de la classe

La classe ListeValeurs regroupe toutes ces fonctions qui modifient la QList lorsqu'une touche est appuyée. Cette classe contient 9 attributs qui sont les suivants : 

- *lNombres*, une Qlist de 16 entiers qui à été présetée plus haut.
- *valScore*, un entier qui à la valuer du score actuel. Il est modifié a chaque mouvement et remit a 0 lorsque le jeu est recommencé.
- *agagne*, un entier qui vaut 0 si le jeu n'a pas encore été gagné et 1 sinon. Ceci permet de ne pas faire gagner le joueur à chaque fois qu'un bloc 2048 est crée mais seulement la première fois de la partie.
- *etatMedaille*, un entier qui vaut 0 ou 1 selon si la médaille est visible ou non. Lorsque le jeu est gagné pour la première fois, une medaille apparait et etatMedaille vaut 1. Une fonction qui fait disparaitre cette médaille lorsque l'on clique dessus remet cette valeur à 0.
- *etatJeu*, un entier qui vaut 0 si le jeu n'est pas perdu et 1 si plus aucun mouvement n'est possible.
- *tableau_point*
- *compteur*
- *depasse_compteur*
- *visu*, un entier qui vaut 1 ou 0 selon si les couleurs du jeu sont claires ou sombre. Pour modifier cette valeur, il suffit de cliquer sur un des deux carrés en bas à droite de la fenetre de jeu.

Lors de l'initialisation, *LNombres* contient ques des zéros sauf deux entiers qui vallent 2 ou 4 avec une chance sur 10 d'être un 4. Le entiers *valScore*, *agagne*, *etatMedaille*, *etatJeu*, *compteur* et *visu* sont tous mis à 0. La matrice *tableau_point* est remplie de 0 et *depasse_compteur* est faux.

## Méthodes de la classe

Pour modifier la fenetre de jeu, l'utilisateur peut appuyer sur les 4 flêches du clavier ou cliquer avec sa souris sur 4 boutons.
