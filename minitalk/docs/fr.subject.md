
Sur la partie obligatoire, vous êtes autorisé à utiliser les fonctions suivantes : 

- write
- ft_printf and any equivalent YOU coded
- signal
- sigemptyset
- sigaddset
- sigaction
- kill
- getpid
- malloc
- free
- pause
- sleep
- usleep
- exit

# Chapitre III

Partie obligatoire
- Vous devez créer un programme de communication sous la forme d'un client et d'un serveur.
- Le serveur doit être lancé en premier, et après avoir été lancé, il doit afficher son PID.
- Le client prendra comme paramètres :
  - Le PID du serveur.
  - La chaîne qui doit être envoyée.
- Le client doit communiquer la chaîne passée en paramètre au serveur. Une fois la chaîne a été reçue, le serveur doit l'afficher.
- La communication entre vos programmes doit être effectuée UNIQUEMENT à l'aide de signaux UNIX.
- Le serveur doit pouvoir afficher la chaîne assez rapidement. Par rapidement, nous entendons que si vous pensez que c'est trop long, alors c'est probablement trop long (indice : 1 seconde pour 100 caractères est COLOSSAL)
- Votre serveur doit pouvoir recevoir des chaînes de plusieurs clients à la suite, sans besoin d'être redémarré.
- Vous ne pouvez utiliser que les deux signaux SIGUSR1 et SIGUSR2.

---

 Le système Linux ne met PAS en file d'attente les signaux lorsque vous avez déjà en attente signal de ce type ! temps de bonus ?

---

# Prime

- Le serveur confirme chaque signal reçu en envoyant un signal au client.
- prend en charge les caractères Unicode !
