# Supprimer les CR dans un fichier
Pour le passage d'un fichier `mode windows` a un fichier `mode unix`, il faut supprimer les caractères `CR` présent dans les retours à la ligne.

## Utilisation
Saisir en premier le nom du fichier d'origne. Puis le nom du fichier qui contiendra la version sans les caractères `CR`.

## Fonctionnement
L'objet de type `ifstream` sert à acquérir les caractères du fichier d'origine. Si l'ouverture s'est convenablement déroulée, la lecture caractère par caractère se fera par la méthode `get()`.

Pour l'écriture dans un fichier, il faut un objet de type `ofstream`. De même, si l'ouverture s'est bien déroulée, l'écriture des caractères se feront avec la méthode `put()`.