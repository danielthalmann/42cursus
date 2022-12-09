https://linuxhint.com/signal_handlers_c_programming_language/


# Signal

Un signal est un événement qui est généré pour notifier un processus ou un 
thread qu'une situation importante est arrivée. 
Lorsqu'un processus ou un thread a reçu un signal, le processus ou le thread 
arrête ce qu'il fait et prend des mesures. Le signal peut être utile pour la 
communication inter-processus.

## Signaux standards

Les signaux sont définis dans le fichier d'en-tête signal.h en tant que 
constante macro. 
Le nom du signal commence par un « SIG » et est suivi d'une brève description 
du signal. Ainsi, chaque signal a une valeur numérique unique. 
Votre programme doit toujours utiliser le nom des signaux, 
pas le numéro des signaux. 
La raison en est que le numéro de signal peut différer selon le système, 
mais la signification des noms sera standard.

***signum***

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

## Action par défaut des signaux

Chaque signal a une action par défaut, l'une des suivantes :

**Term** : le processus se terminera.
**Core** : le processus se terminera et produira un fichier de vidage de mémoire.
**Ign** : Le processus ignorera le signal.
**Stop** : Le processus s'arrêtera.
**Cont** : Le processus continuera après avoir été arrêté.

L'action par défaut peut être modifiée à l'aide de la fonction de gestionnaire. L'action par défaut de certains signaux ne peut pas être modifiée. L'action par défaut des signaux **SIGKILL** et **SIGABRT** ne peut pas être modifiée ou ignorée.

## Traitement des signaux

Si un processus reçoit un signal, le processus a le choix d'une action pour ce type de signal. Le processus peut ignorer le signal, spécifier une fonction de gestionnaire ou accepter l'action par défaut pour ce type de signal.

* Si l'action spécifiée pour le signal est ignorée, le signal est supprimé immédiatement.
* Le programme peut enregistrer une fonction de gestionnaire en utilisant une fonction telle que **signal** ou **sigaction**. C'est ce qu'on appelle un gestionnaire captage de signal.
* Si le signal n'a été ni traité ni ignoré, son action par défaut a lieu.

Nous pouvons gérer le signal en utilisant la fonction **signal** ou **sigaction**. Nous voyons ici comment la fonction ***signal()*** la plus simple est utilisée pour gérer les signaux.

```c
int signal ( ) ( int signum , void ( * func ) ( int ) )
```

Le ***signal()*** appellera la fonction func si le processus reçoit un signal ***signum***. Le ***signal()*** renvoie un pointeur vers la fonction func en cas de succès ou renvoie une erreur vers errno et -1 sinon.

Le pointeur func peut avoir trois valeurs :

  1.  **SIG_DFL** : C'est un pointeur vers la fonction par défaut du système *SIG_DFL()*, déclarée dans le fichier d'en-tête h. Il est utilisé pour prendre l'action par défaut du signal.
  2. **SIG_IGN** : C'est un pointeur vers la fonction d' ignorance du système SIG_IGN() , déclarée dans le fichier d'en-tête h .
  3. **Pointeur de fonction de gestionnaire défini par l'utilisateur** : le type de fonction de gestionnaire défini par l'utilisateur est __void(*)(int)__, signifie que le type de retour est void et un argument de type int.


## Exemple de gestionnaire de signaux de base

```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signum)
{
	//Return type of the handler function should be void
	printf("\nInside handler function\n");
	exit(0);
}

int main()
{
	int i = 1;

	signal(SIGINT,sig_handler); // Register signal handler
	while(i++)                  // Infinite loop
	{          
		printf("%d : Inside main function\n",i);
		sleep(1);               // Delay for 1 second
	}
	return (0);
}

```

Nous pouvons voir que dans la fonction principale, une boucle infinie.
Lorsque l'utilisateur tape sur Ctrl+C, l'exécution de la fonction principale s'arrête et la fonction de gestion du signal est invoquée. Une fois la fonction de gestionnaire terminée, l'exécution de la fonction principale a repris. Lorsque l'utilisateur tape Ctrl+\, le processus est arrêté.

## Exemple pour ignorer les signaux

```c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	signal(SIGINT, SIG_IGN); // Register signal handler for ignoring the signal

	while(i++)               // Infinite loop
	{
		printf("%d : Inside main function\n",i);
		sleep(1);            // Delay for 1 second
	}
	return (0);
}
```

Ici, la fonction de gestionnaire est enregistrée dans la fonction SIG_IGN() pour ignorer l'action du signal. Ainsi, lorsque l'utilisateur a tapé Ctrl+C, le signal SIGINT est généré mais l'action est ignorée.


## Exemple de gestionnaire de signal de réenregistrement

```c
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sig_handler ( int signum ) {
  printf ( " \n Inside handler function \n " ) ;
  signal ( SIGINT , SIG_DFL ) ;    // Réenregistrer le gestionnaire de signal pour l'action par défaut
}

int main ( ) {
  signal ( SIGINT , sig_handler ) ; // Enregistrer le gestionnaire de signal
  pour ( int i = 1 ;; i ++ ) {     // Boucle infinie
    printf ( " %d : Inside main function \n " , i ) ;
    dormir ( 1 ) ;   // Délai de 1 seconde
  }
  return 0 ;
}
```

Nous pouvons voir que si l'utilisateur tape pour la première fois Ctrl+C, la fonction de gestionnaire a été invoquée. Dans la fonction de gestionnaire, le gestionnaire de signal se réenregistre auprès de SIG_DFL pour l'action par défaut du signal. Lorsque l'utilisateur tape Ctrl+C pour la deuxième fois, le processus est terminé, ce qui est l'action par défaut du signal SIGINT.

## Envoi de signaux :

Un processus peut également envoyer explicitement des signaux à lui-même ou à un autre processus. Les fonctions **raise()** et **kill()** peuvent être utilisées pour envoyer des signaux. Les deux fonctions sont déclarées dans le fichier d'en-tête signal.h.

```c
int raise(int signum)
```

La fonction raise() utilisée pour envoyer le signum du signal au processus appelant (lui-même). Il renvoie zéro en cas de succès et une valeur différente de zéro en cas d'échec.

```c
int kill(pid_t pid, int signum)
```

La fonction kill utilisé pour envoyer un signal signum à un processus ou groupe de processus spécifié par pid.
Exemple de gestionnaire de signal SIGUSR1

```c
#include <stdio.h>
#include <signal.h>

void sig_handler(int signum){
  printf("Inside handler function\n");
}

int main(){
  signal(SIGUSR1, sig_handler); // Register signal handler
  printf("Inside main function\n");
  raise(SIGUSR1);
  printf("Inside main function\n");
  return 0;
}
```

Ici, le processus s'envoie le signal SIGUSR1 à l'aide de la fonction raise().
Programme d'exemple de relance avec Kill



```c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void sig_handler(int signum){
  printf("Inside handler function\n");
}

int main(){
  pid_t pid;
  signal(SIGUSR1,sig_handler); // Register signal handler
  printf("Inside main function\n");
  pid = getpid();      //Process ID of itself
  kill(pid, SIGUSR1);        // Send SIGUSR1 to itself
  printf("Inside main function\n");
  return 0;
}
```

Ici, le processus s'envoie le signal SIGUSR1 à l'aide de 
la fonction **kill()**. **getpid()** est utilisé pour obtenir 
l'ID du processus lui-même.

Dans l'exemple suivant, nous verrons comment les processus parent et enfant 
communiquent (communication interprocessus) en utilisant kill() et la fonction 
signal. Communication parent-enfant avec des signaux

```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler_parent(int signum){
  printf("Parent : Received a response signal from child \n");
}

void sig_handler_child(int signum){
  printf("Child : Received a signal from parent \n");
  sleep(1);
  kill(getppid(),SIGUSR1);
}

int main(){
  pid_t pid;
  if((pid=fork())<0){
    printf("Fork Failed\n");
    exit(1);
  }
  /* Child Process */
  else if(pid==0){
    signal(SIGUSR1, sig_handler_child); // Register signal handler
    printf("Child: waiting for signal\n");
    pause();
  }
  /* Parent Process */
  else{
    signal(SIGUSR1,sig_handler_parent); // Register signal handler
    sleep(1);
    printf("Parent: sending signal to Child\n");
    kill(pid,SIGUSR1);
    printf("Parent: waiting for response\n");
    pause();
  }
  return 0;
}
```

Ici, la fonction fork() crée un processus enfant et renvoie zéro au processus 
enfant et l'ID du processus enfant au processus parent. Ainsi, pid a été vérifié 
pour décider du processus parent et enfant. Dans le processus parent, il est 
mis en veille pendant 1 seconde afin que le processus enfant puisse enregistrer 
la fonction de gestionnaire de signal et attendre le signal du parent. Après 1 
seconde, le processus parent envoie le signal SIGUSR1 au processus enfant et 
attend le signal de réponse de l'enfant. Dans le processus enfant, il attend 
d'abord le signal du parent et lorsque le signal est reçu, la fonction de 
gestionnaire est invoquée. À partir de la fonction de gestionnaire, le processus 
enfant envoie un autre signal SIGUSR1 au parent. Ici, la fonction getppid() est 
utilisée pour obtenir l'ID du processus parent.
Conclusion

Signal sous Linux est un sujet important. Dans cet article, nous avons vu comment 
gérer le signal de manière très basique, et également apprendre comment le signal 
est généré, comment un processus peut envoyer un signal à lui-même et à d'autres 
processus, comment le signal peut être utilisé pour la communication inter-processus.