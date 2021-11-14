# 42cursus - Born2beroot

## Indexe

- [42cursus - Born2beroot](#42cursus---born2beroot)
	- [Indexe](#indexe)
	- [Debian vs CentOS](#debian-vs-centos)
	- [AppArmor vs SELinux](#apparmor-vs-selinux)
	- [Installation](#installation)
		- [Prérequis](#prérequis)
	- [Packages](#packages)
	- [Partition](#partition)
	- [Sudo](#sudo)
		- [Installation de sudo](#installation-de-sudo)
		- [Modification de la configuration](#modification-de-la-configuration)
		- [Ajouter un utilisateur dans sudo](#ajouter-un-utilisateur-dans-sudo)
	- [Hostname](#hostname)
		- [connaitre le nom d'hôte ?](#connaitre-le-nom-dhôte-)
		- [Comment changer le nom d'hôte ?](#comment-changer-le-nom-dhôte-)
- [group](#group)
- [Password](#password)
		- [verification des proprietes de sécurités](#verification-des-proprietes-de-sécurités)
	- [réseau](#réseau)
	- [creer un checksum](#creer-un-checksum)

## Debian vs CentOS

Debian est plus axé installation serveur. CentOS est un fork de redhat.
Deux systèm d'exploitation basé sur une unix-like stable.

## AppArmor vs SELinux

AppArmor et SELinux sont deux des modules de sécurité Linux qui peuvent être utilisés pour un contrôle d'accès obligatoire à granularité fine. Ils essaient tous les deux d'atteindre des objectifs très similaires, mais AppArmor est largement considéré comme plus facile à utiliser (et, vraiment, il l'est) et SELinux est largement considéré comme plus fin. 

Ces systèmes de sécurité fournissent des outils pour isoler les applications les unes des autres... et à leur tour isoler un attaquant du reste du système lorsqu'une application est compromise.

Les ensembles de règles SELinux sont incroyablement complexes, mais avec cette complexité, vous avez plus de contrôle sur la façon dont les processus sont isolés. La génération de ces stratégies peut être automatisée. Une grève contre ce système de sécurité est qu'il est très difficile à vérifier de manière indépendante.

AppArmor (et SMACK) est très simple. Les profils peuvent être écrits à la main par des humains ou générés à l'aide de aa-logprof. AppArmor utilise un contrôle basé sur le chemin, ce qui rend le système plus transparent afin qu'il puisse être vérifié de manière indépendante. 

## Installation

### Prérequis

Pour debuter, il faut telecharger la dernier version de debian.
[Url d'installer Debian](https://www.debian.org/distrib/netinst)


Suivre les étapes d'installation du debian.

Le mot de passe utlisé dans cet exercice est : __Hellraiser42__

## Packages

Le gestionnaire de packet est __apt__.

Pour savoir si un package est installer, utiliser la commande suivante :

```
$ dpkg -l | grep [nom_du_package]
```

## Partition

La commande suivante permet d'afficher les partitions

```
$ lsblk
```

## Sudo

### Installation de sudo

Pour l'installation du sudo, il faut passer en mode administrateur root. Entrez :

```
$ su -
```

puis lancer le gestionnaire de package.

```
$ apt install sudo

```

### Modification de la configuration

entrez

```
vi /etc/sudoers
```

Message d'erreur lorsque l'on tappe le mauvais mot de passe et modification du lieu du fichier log

```
Defaults        badpass_message="<custom-error-message>"

Defaults        logfile="/var/log/sudo.log"
```

### Ajouter un utilisateur dans sudo

Pour ajouter la permission a un utilisateur d'utiliser sudo, il faut 
ajouter le compte dans le groupe _sudo_.

Entrez la ligne suivante pour ajouter un membre au goupe

```
$ useradd <username> sudo
```


## Hostname

### connaitre le nom d'hôte ? 

Pour connaitre le nom d'hôte, entrez:

```
$ hostname
```

### Comment changer le nom d'hôte ?

Modifiez le fichier __/etc/hostname__, entrez: 

```
$ vi /etc/hostname
```

Supprimez le nom existant et remplacez-le avec un nouveau nom.

Enregistrez et fermez le fichier. Vous devrez peut-être également modifier le fichier __/etc/hosts__, entrez:

```
$ vi /etc/hosts 
```

Trouvez toutes les références à <server_name_1> et remplacez-les par <server_name_2>

Tapez simplement la commande suivante pour appliquer les nouvelles modifications sans redémarrer le serveur: 

```
/etc/init.d/hostname.sh start
```

# group

Entrez la commande suivante pour ajouter le groupe __user42__.

```
$ addgroup user42
```

# Password

Installez de la librairie de mise en place de règle de mot de passe

``` 
$ sudo apt-get install libpam-pwquality
```

Ouvrez le fichier __common-password__ pour modifier les règle de

``` apt-get install libpam
$ sudo vi /etc/pam.d/common-password
```

Recherchez la ligne __pam_pwquality.so__ et modifiez les paramètres comme suite :

```
password        requisite                       pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```

Le mot de passe sera de 10 caractères minimums (__minlen=10__) dont une majuscule (__ucredit=-1__) et un chiffre (__dcredit=-1__), et ne devra pas comporter plus de 3 caractères identiques consécutifs (__maxrepeat=3__).

Le mot de passe ne devra pas comporter le nom de l’utilisateur (__reject_username__).

La règle suivante ne s’applique pas à l’utilisateur root (__enforce_for_root__): le mot de passe devra comporter au moins 7 (__difok=7__) caractères qui ne sont pas présents dans l’ancien mot depasse.

Le mot de passe peut être saisi 3 fois avant de retourner une erreur (__retry=3__)

Entrez la commande suivante pour modifier les propriétés du login.

```
$ sudo vi /etc/login.defs
```

Recherchez les paramètres suivant et modifiez les selon ces valeurs :

```
PASS_MAX_DAYS   30
PASS_MIN_DAYS   2
PASS_WARN_AGE   7
```

le mot de passe expirer tous les 30 jours. (__PASS_MAX_DAYS__)

Le nombre minimum de jours avant de pouvoir modifier un mot de passe est à 2. (__PASS_MIN_DAYS__)

L’utilisateur recevoit un avertissement 7 jours avant que son mot de passen’expire. (__PASS_WARN_AGE__)


### verification des proprietes de sécurités

Entrez la commande suivante pour afficher le résumé de sécurité

```
$ chage -l <username>

Last password change                                    : Oct 15, 2021
Password expires                                        : never
Password inactive                                       : never
Account expires                                         : never
Minimum number of days between password change          : 0
Maximum number of days between password change          : 99999
Number of days of warning before password expires       : 7
```

installation de mpstat

sudo apt install sysstat

## réseau

voir les port ouvert

```
ss -tunlp
```


## creer un checksum

creation du ash

```
shasum
```