# 42cursus - Born2beroot

## Indexe

1. [Prérequis](#installation)
2. [Installation](#installation)
3. [Packages](#packages)
4. [Partition](#Partition)
5. [Sudo](#sudo)
6. [Nom d'hôte](#nom-d-hote)

### Prérequis

Pour debuter, il faut telecharger la dernier version de debian.
[Url d'installer Debian](https://www.debian.org/distrib/netinst)

## Installation

Suivre les étapes d'installation du debian.

Le mot de passe utlisé est : Hellraiser42

## Packages

Le gestionnaire de packet est apt.

Pour savoir si un package est installer, utiliser la commande suivante :

```
# dpkg -l | grep [nom_du_package]
```

## partition

```
# lsblk
```

## Sudo

### Installation de sudo

Pour l'installation du sudo, il faut passer en mode administrateur root. Entrez :

```
# su -
```

puis lancer le gestionnaire de package.

```
# apt install sudo
```

### Ajouter un utilisateur dans sudo

Pour ajouter la permission a un utilisateur d'utiliser sudo, il faut 
ajouter le compte dans le groupe _sudo_.

```
# apt install sudo
```



## Nom d'hote

### connaitre le nom d'hôte? 

Pour connaitre le nom d'hôte, entrez:

```
# hostname
```

### Comment changer définitivement le nom d'hôte? 

Modifiez le fichier __/etc/hostname__, entrez: 

```
# vi /etc/hostname 
```

Supprimez le nom existant et remplacez-le avec un nouveau nom.

Enregistrez et fermez e fichier. Vous devrez peut-être également modifier le fichier __/etc/hosts__, entrez:

```
# vi /etc/hosts 
```
Trouvez toutes les références à _server_name_1_ et remplacez-les par _server_name_2_ 

Veuillez noter que le nom d'hôte est généralement défini une fois au démarrage du système dans /etc/init.d/hostname.sh (normalement en lisant le contenu d'un fichier contenant le nom d'hôte, par exemple / etc / hostname). Tapez simplement la commande suivante pour appliquer les nouvelles modifications sans redémarrer le serveur: 

```
/etc/init.d/hostname.sh start
```

# groupe

```
# addgroup user42
```

# regle de modification du mot de passe

le mot de passe devra expirer tous les 30 jours.

Le nombre minimum de jours avant de pouvoir modifier un mot de passe sera configuré à 2.

L’utilisateur devra recevoir un avertissement 7 jours avant que son mot de passen’expire.

Votre mot de passe sera de 10 caractères minimums dont une majuscule et unchiffre, et ne devra pas comporter plus de 3 caractères identiques consécutifs.

Le mot de passe ne devra pas comporter le nom de l’utilisateur.

La règle suivante ne s’applique pas à l’utilisateur root : le mot de passe devracomporter au moins 7 caractères qui ne sont pas présents dans l’ancien mot depasse.

Bien entendu votre mot de passe root devra suivre cette politiqu

```
# sudo vi /etc/pam.d/common-password
```


```
password        requisite                       pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```




```
# sudo vi /etc/login.defs
```

$ sudo vi /etc/login.defs

To set password to expire every 30 days, replace below line

160 PASS_MAX_DAYS   99999

with:

160 PASS_MAX_DAYS   30

To set minimum number of days between password changes to 2 days, replace below line

161 PASS_MIN_DAYS   0

with:

161 PASS_MIN_DAYS   2

To send user a warning message 7 days (defaults to 7 anyway) before password expiry, keep below line as is.

162 PASS_WARN_AGE   7


### verification des proprietes de scurite

```
getent passwd <username>
```

Defaults        badpass_message="<custom-error-message>"

To log all sudo commands to /var/log/sudo/<filename>:

$ sudo mkdir /var/log/sudo
<~~~>
Defaults        logfile="/var/log/sudo/<filename>"



chage -l <username>


installation de mpstat

sudo apt install sysstat
