Il faut écrire un programme pour la partie obligatoire et un autre pour la partie bonus
mais ils auront les mêmes règles de base :

• Les variables globales sont interdites !
• Le programme doit prendre les arguments suivants : number_of_philosophers time_to_die
time_to_eat time_to_sleep \[number_of_times_each_philosopher_must_eat\]

__number_of_philosophers__ : est le nombre de philosophes et aussi le nombre de fourches.

__time_to_die__ : est en millisecondes, si un philosophe ne commence pas à manger 'time_to_die'
millisecondes après le début de son dernier repas ou le début de la simulation, il meurt.

__time_to_eat__ : est en millisecondes et est le temps qu'il faut à un philosophe pour
manger. Pendant ce temps, ils devront garder les deux fourches.

__time_to_sleep__ : est en millisecondes et est le temps que le philosophe passera
en train de dormir.

__number_of_times_each_philosopher_must_eat__ : l'argument est facultatif, si tous
les philosophes mangent au moins 'number_of_times_each_philosopher_must_eat' le
la simulation s'arrête. Si non spécifié, la simulation ne s'arrêtera qu'à la mort
d'un philosophe.

- Chaque philosophe doit recevoir un nombre allant de 1 à « nombre_de_philosophes ».
- Le philosophe numéro 1 est à côté du philosophe numéro 'nombre_de_philosophes'.


Tout autre philosophe portant le numéro N est assis entre le philosophe N - 1 et
philosophe N+1 


À propos des journaux de votre programme :

- Tout changement de statut d'un philosophe doit s'écrire comme suit (avec X remplacé
avec le numéro de philosophe et timestamp_in_ms l'horodatage actuel en millisecondes) :

	timestamp_in_ms X a pris un fork
	
	timestamp_in_ms X mange
	
	timestamp_in_ms X dort
	
	timestamp_in_ms X réfléchit
	
	timestamp_in_ms X est décédé

- Le statut imprimé ne doit pas être brouillé ou entrelacé avec celui d'un autre philosophe.
statut.
- Vous ne pouvez pas avoir plus de 10 ms entre la mort d'un philosophe et le moment où il
imprimera sa mort.
- Encore une fois, les philosophes doivent éviter de mourir !
