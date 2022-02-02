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
    - Gérer $? qui devrait s'étendre au statut de sortie du dernier exécuté pipeline de premier plan.
    - Gérer ctrl-C, ctrl-D et ctrl-\ qui doivent se comporter comme dans bash.
- En mode interactif :
	- ctrl-C affiche une nouvelle invite sur une nouvelle ligne.
	- ctrl-D quitte le shell.
	- ctrl-\ ne fait rien.
- Votre shell doit implémenter les commandes intégrées suivantes :
	- **echo** avec l'option -n
	- **cd** avec uniquement un chemin relatif ou absolu
	- **pwd** sans options
	- **export** sans options
	- **unset** sans options
	- **env** sans options ni arguments
	- **exit** sans options
La fonction readline() peut provoquer des fuites de mémoire. Vous n'avez pas à les réparer. Mais
cela ne signifie pas que votre propre code, oui le code que vous avez écrit, peut en avoir. 

## Fonctions autorisé

readline
rl_clear_history
rl_on_new_line
rl_replace_line
rl_redisplay
add_history
printf
malloc
free
write

int access(const char *path, int mode);

The access() system call checks the accessibility of the file named by the path argument for the access permissions indicated by the mode argument.  The value of mode is either the bitwise-inclusive OR of the access permissions to be checked (R_OK for read permission, W_OK for write permission, and X_OK for execute/search permission), or the existence test (F_OK).


open
read
close
fork
wait
waitpid
wait3
wait4
signal
sigaction
sigemptyset
sigaddset
kill
exit
getcwd
chdir
stat

int lstat(const char *restrict path, struct stat *restrict buf);

The lstat() function obtains information about the file pointed to by path.  Read, write or execute permission of the named file is not required, but all directories listed in the
     path name leading to the file must be searchable.

fstat

The fstat() obtains the same information about an open file known by the file descriptor fildes.

unlink
execve
dup

int dup2(int fildes, int fildes2);

pipe
opendir
readdir
closedir
strerror
perror
isatty
ttyname
ttyslot
ioctl
getenv
tcsetattr
tcgetattr
tgetent
tgetflag
tgetnum
tgetstr
tgoto
tputs
