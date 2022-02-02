Votre shell doit :
- Afficher une invite lors de l'attente d'une nouvelle commande.
- Avoir une historique de travail.
- Rechercher et lancer le bon exécutable (basé sur la variable PATH ou en utilisant un chemin relatif ou absolu).
- Ne pas utiliser plus d'une variable globale. Pensez-y. Tu vas devoir t'expliquer.
- Ne pas interpréter les guillemets non fermés ou les caractères spéciaux qui ne sont pas requis par le sujet tel que \ (barre oblique inverse) ou ; (point-virgule).
- Handle ' (apostrophe) qui devrait empêcher le shell d'interpréter la méta-caractères dans la séquence citée.
- Handle " (guillemets doubles) qui devrait empêcher le shell d'interpréter la méta-caractères dans la séquence entre guillemets à l'exception de $ (signe dollar).


- Mettre en œuvre les redirections :
    - < doit rediriger l'entrée.
	- > doit rediriger la sortie.
	- << doit recevoir un délimiteur, puis lire l'entrée jusqu'à ce qu'une ligne contenant le délimiteur est vu. Cependant, il n'est pas nécessaire de mettre à jour l'historique !
	- >> doit rediriger la sortie en mode ajout.
	- Mettre en œuvre les tuyaux (caractère |). La sortie de chaque commande dans le pipeline est connecté à l'entrée de la commande suivante via un tube.
    - Gérer les variables d'environnement ($ suivi d'une séquence de caractères) qui devraient s'étendre à leurs valeurs.
    - Gérer $ ? qui devrait s'étendre au statut de sortie du dernier exécuté pipeline de premier plan.
    - Gérer ctrl-C, ctrl-D et ctrl-\ qui doivent se comporter comme dans bash.
- En mode interactif :
	- ctrl-C affiche une nouvelle invite sur une nouvelle ligne.
	- ctrl-D quitte le shell.
	- ctrl-\ ne fait rien.
- Votre shell doit implémenter les commandes intégrées suivantes :
	- écho avec l'option -n
	- cd avec uniquement un chemin relatif ou absolu
	- pwd sans options
	- exporter sans options
	- désactivé sans options
	- env sans options ni arguments
	- quitter sans options
La fonction readline() peut provoquer des fuites de mémoire. Vous n'avez pas à les réparer. Mais
cela ne signifie pas que votre propre code, oui le code que vous avez écrit, peut avoir de la mémoire
fuites. 
En savoir plus sur ce texte source
Vous devez indiquer le texte source pour obtenir des informations supplémentaires
Envoyer des commentaires
Panneaux latéraux
