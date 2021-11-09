# 42cursus - Born2beroot

## Indexe

1. [Prérequis](#installation)
2. [Installation](#installation)
3. [Nom d'hôte](#nom-d-hote)

### Prérequis

[Installer Debian](https://www.debian.org/distrib/netinst)

## Installation

Suivre les étapes d'installation du debian.

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
