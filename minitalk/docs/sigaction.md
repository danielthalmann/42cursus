## Traitement avancé des signaux

La fonction **sigaction** a le même effet de base que signal : pour spécifier 
comment un signal doit être traité par le processus. Cependant, **sigaction** 
offre plus de contrôle, au détriment d'une plus grande complexité. 
En particulier, **sigaction** vous permet de spécifier des indicateurs 
supplémentaires pour contrôler quand le signal est généré et comment 
le gestionnaire est appelé.

La fonction sigaction est déclarée dans ***signal.h***.

```c
struct sigaction {
	void     (*sa_handler)(int);
	void     (*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t   sa_mask;
	int        sa_flags;
};
```

## Type de données : **struct sigaction**

Des structures de type struct sigaction sont utilisées dans la fonction **sigaction**
pour spécifier toutes les informations sur la façon de gérer un signal particulier. 
Cette structure contient au moins les membres suivants :

**sighandler_t sa_handler**

Il est utilisé de la même manière que l'argument action de la fonction signal. 
La valeur peut être SIG_DFL, SIG_IGN ou un pointeur de fonction. Voir 
Traitement de base du signal.

**sigset_t sa_mask**

Ceci spécifie un ensemble de signaux à bloquer pendant l'exécution du 
gestionnaire. Le blocage est expliqué dans Blocage pour le gestionnaire. 
Notez que le signal qui a été délivré est automatiquement bloqué par défaut 
avant le démarrage de son gestionnaire ; ceci est vrai quelle que soit la 
valeur dans sa_mask. Si vous voulez que ce signal ne soit pas bloqué dans 
son gestionnaire, vous devez écrire du code dans le gestionnaire pour le 
débloquer.
    
**int sa_flags**

Ceci spécifie divers drapeaux qui peuvent affecter le comportement du 
signal. 

## Flag

Macro : **int SA_NOCLDSTOP**

Ce drapeau n'a de sens que pour le signal SIGCHLD. Lorsque l'indicateur est 
défini, le système délivre le signal pour un processus fils terminé mais pas 
pour celui qui est arrêté. Par défaut, SIGCHLD est fourni à la fois pour les 
enfants terminés et pour les enfants arrêtés.

Définir ce drapeau pour un signal autre que SIGCHLD n'a aucun effet.

Macro : **int SA_ONSTACK**

Si cet indicateur est défini pour un numéro de signal particulier, le système 
utilise la pile de signaux lors de la livraison de ce type de signal. 
Voir Pile de signaux. Si un signal avec ce drapeau arrive et que vous n'avez 
pas défini de pile de signaux, le système termine le programme avec SIGILL.

Macro : **int SA_RESTART**

Ce drapeau contrôle ce qui se passe lorsqu'un signal est délivré pendant 
certaines primitives (telles que l'ouverture, la lecture ou l'écriture), et 
le gestionnaire de signal revient normalement. Il existe deux alternatives : 
la fonction de bibliothèque peut reprendre ou elle peut renvoyer un échec 
avec le code d'erreur EINTR.

Le choix est contrôlé par le drapeau SA_RESTART pour le type particulier de 
signal qui a été délivré. Si l'indicateur est défini, le retour d'un 
gestionnaire reprend la fonction de bibliothèque. Si l'indicateur est clair, 
le retour d'un gestionnaire fait échouer la fonction. Voir Primitives 
interrompues. 

Macro : **int SA_UNSUPPORTED (since Linux 5.11)**

Utilisé pour sonder dynamiquement la prise en charge des bits d'indicateur.
Si une tentative d'enregistrement d'un gestionnaire réussit avec ce
indicateur défini dans act-> sa_flags aux côtés d'autres indicateurs qui sont
potentiellement non pris en charge par le noyau, et immédiatement
appel suivant sigaction() spécifiant le même signal
nombre et avec un argument oldact non NULL donne
SA_UNSUPPORTED effacer dans oldact->sa_flags, puis
oldact->sa_flags peut être utilisé comme masque de bits décrivant quel
des drapeaux potentiellement non pris en charge sont, en fait,
prise en charge. Voir la section "Sonde dynamique pour le drapeau
bit support" ci-dessous pour plus de détails. 
      
Macro : **int SA_SIGINFO**

Le gestionnaire de signal prend trois arguments, pas un. Dans ce cas, 
sa_sigaction doit être défini au lieu de sa_handler. Ce drapeau n'a de sens 
que lorsque l'établissement d'un gestionnaire de signal. 

### Exemple :

```c
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void handler(int signo, siginfo_t *info, void *context)
{
    struct sigaction oldact;
    if (sigaction(SIGSEGV, NULL, &oldact) == -1) {
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

int main(void)
{
    struct sigaction act = { 0 };
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &handler;
    if (sigaction(SIGSEGV, &act, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    raise(SIGSEGV);
}
```
https://www.mkssoftware.com/docs/man5/siginfo_t.5.asp

union sigval {
	int sival_int;
	void *sival_ptr;
};

typedef struct {
	int si_signo;
	int si_code;
	union sigval si_value;
	int si_errno;
	pid_t si_pid;
	uid_t si_uid;
	void *si_addr;
	int si_status;
	int si_band;
} siginfo_t;



## fonction sigaction

```c
#include <signal.h>
int sigaction(int signum, const struct sigaction *action, struct sigaction *old-action);
```

***int signum***

|Nom du signal   |  La description                                             |
|----------------|-------------------------------------------------------------|
|SIGHUP          | Raccrochez le processus. Le signal SIGHUP est utilisé pour signaler la déconnexion du terminal de l'utilisateur, éventuellement parce qu'une connexion à distance est perdue ou raccroche. |
|SIGINT          | Interrompre le processus. Lorsque l'utilisateur tape le caractère INTR (normalement Ctrl + C), le signal SIGINT est envoyé.|
|SIGQUIT         | Quittez le processus. Lorsque l'utilisateur tape le caractère QUIT (normalement Ctrl + \\), le signal SIGQUIT est envoyé.|
|SIGILL          | Instruction illégal. Lorsqu'une tentative est faite pour exécuter des instructions indésirables ou privilégiées, le signal SIGILL est généré. De plus, SIGILL peut être généré lorsque la pile déborde ou lorsque le système a des difficultés à exécuter un gestionnaire de signal.|
|SIGTRAP         | Piège à traces. Une instruction de point d'arrêt et d'autres instructions de trap généreront le signal SIGTRAP. Le débogueur utilise ce signal.|
|SIGABRT         | Avorter. Le signal SIGABRT est généré lorsque la fonction **abort()** est appelée. Ce signal indique une erreur détectée par le programme lui-même et signalée par l'appel de fonction abort().|
|SIGFPE          | Exception à virgule flottante (Floating-point exception). Lorsqu'une erreur arithmétique fatale se produit, le signal SIGFPE est généré.|
|SIGUSR1, SIGUSR2| 	Les signaux SIGUSR1 et SIGUSR2 peuvent être utilisés à votre guise. Il est utile d'écrire un gestionnaire de signal pour eux dans le programme qui reçoit le signal pour une communication inter-processus simple.|


Préliminaire : | MT-Safe | AS-Safe | AC-Safe | Voir Concepts de sécurité POSIX.

L'argument action est utilisé pour configurer une nouvelle action pour le 
signal de signal, tandis que l'argument ancienne action est utilisé pour 
renvoyer des informations sur l'action précédemment associée à ce signal. 
(En d'autres termes, l'ancienne action a le même objectif que la valeur de 
retour de la fonction de signal : vous pouvez vérifier quelle était l'ancienne 
action en vigueur pour le signal et la restaurer plus tard si vous le souhaitez.)

L'action ou l'ancienne action peut être un pointeur *null*. Si old-action est un 
pointeur null, cela supprime simplement le retour d'informations sur l'ancienne 
action. Si action est un pointeur *null*, l'action associée au **signum** du signal 
est inchangée ; cela vous permet de vous renseigner sur la façon dont un signal 
est traité sans changer cette gestion.

La valeur de retour de sigaction est zéro en cas de réussite et -1 en cas 
d'échec. Les conditions d'erreur errno suivantes sont définies pour 
cette fonction :

EINVAL : **E**rror **INVAL**id argument

L'argument signum n'est pas valide, ou vous essayez d'intercepter ou d'ignorer 
**SIGKILL** ou **SIGSTOP**.


## Exemple d'utilisation de la fonction

Voici un exemple équivalent utilisant sigaction : 

```c
#include <signal.h>

void
termination_handler (int signum)
{
  struct temp_file *p;

  for (p = temp_file_list; p; p = p->next)
    unlink (p->name);
}

int
main (void)
{
  …
  struct sigaction new_action, old_action;

  /* Set up the structure to specify the new action. */
  new_action.sa_handler = termination_handler;
  sigemptyset (&new_action.sa_mask);
  new_action.sa_flags = 0;

  sigaction (SIGINT, NULL, &old_action);
  if (old_action.sa_handler != SIG_IGN)
    sigaction (SIGINT, &new_action, NULL);
  sigaction (SIGHUP, NULL, &old_action);
  if (old_action.sa_handler != SIG_IGN)
    sigaction (SIGHUP, &new_action, NULL);
  sigaction (SIGTERM, NULL, &old_action);
  if (old_action.sa_handler != SIG_IGN)
    sigaction (SIGTERM, &new_action, NULL);
  …
}
```
