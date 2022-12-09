

https://www.freepngimg.com/png/83118-art-sprite-2d-unity-computer-graphics-grass

http://web.eecs.umich.edu/~sugih/courses/eecs487/glut-howto/#cygwin

https://medium.com/@bhargav.chippada/how-to-setup-opengl-on-mingw-w64-in-windows-10-64-bits-b77f350cea7e

## Debian / ubuntu

```
$ sudo apt update && sudo apt install build-essential

$ sudo apt-get install freeglut3-dev 

```
Lors de la compilation ajouter les options suivantes -lGL -lGLU -lglut 

```
sudo apt update && sudo apt install build-essential
```
## Mac OS X :


## windows avec cygwin :


https://www.glfw.org/download.html

## goal

La carte doit avoir au moins une sortie, une carte doit avoir au moins une 
sortie, un objet de collection et une position de départ.

Votre programme doit prendre comme premier argument un fichier de description 
de carte avec l'extension .ber.

La carte doit être composée de seulement 5 caractères possibles :
0 pour un espace vide, 1 pour un mur, C pour un objet de collection, E pour la 
sortie de la carte et P pour la position de départ du joueur.

La carte doit être fermée/entourée de murs, sinon le programme doit renvoyer
une erreur.

La carte doit avoir au moins une sortie, un objet de collection et une position
de départ. Vous n'avez pas besoin de vérifier s'il y a un chemin valide 
sur la carte.

La carte doit être rectangulaire.

Vous devez être capable d'analyser n'importe quel type de carte, tant qu'il 
respecte les règles de la carte

Si une mauvaise configuration de quelque nature que ce soit est rencontrée dans 
le fichier, le programme doit se fermer correctement et renvoyer "Erreur\n" 
suivi d'un message d'erreur explicite de votre choix.



0 0 0 0 0 0 0 1

1L << 1

0 0 0 0 0 0 1 0

1L << 5

0 0 0 1 0 0 0 0

AND

1 1 0 0 1 0 1 0
 
0 0 0 0 0 0 0 0



0 0 = 0
0 1 = 0
1 0 = 0
1 1 = 1


long

