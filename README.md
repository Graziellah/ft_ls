# ft_ls

## Objectif
Reproduction de la commande ls et de ses options:
+ l => Afficher le type du fichier, les permissions d'accès, le nombre de liens physiques, le nom du propriétaire et du groupe, la taille en octets, et l'horodatage (de la dernière modification, sauf si une autre date est réclamée). Pour les fichiers vieux de plus de 6 mois, ou en avance sur la date de plus d'une heure, l'horodatage contient l'année à la place de l'heure.
+ R => Afficher récursivement le contenu des sous-répertoires.
+ a =>Afficher tous les fichiers des répertoires, y compris les fichiers, cachés, commençant par un « . ».
+ r =>Inverser le tri du contenu des répertoires.
+ t =>Trier le contenu des répertoires en fonction de la date et non pas en ordre alphabétique. Les fichiers les plus récents sont présentés en premier.
+ u =>Trier le contenu des répertoires en fonction de la date de dernier accès au fichier plutôt que selon la date de modification. Si le format d'affichage est large, c'est la date de dernier accès qui est affichée.
+ c =>Trier le contenu des répertoires en fonction des dates de changement des statuts de fichiers, plutôt qu'en fonction de la date de modification. S'il s'agit d'un format long, afficher la date de changement de statut plutôt que la date de modification du fichier.
+ F =>Ajouter un caractère à chaque nom de fichier pour indiquer son type. les fichiers réguliers exécutables sont suivis d'un « * ». Les répertoires sont suivis de « / », les liens symboliques d'un « @ », les FIFOs d'un « | ». Les fichiers réguliers non-exécutables ne sont suivis d'aucun caractère.
+ i =>Afficher le numéro d'index (i-noeud) de chaque fichier à gauche de son nom. Ce numéro identifie un fichier de manière unique au sein d'un système de fichiers donné.

## Compilation
```
make
```

## Run
Le programme s'utilise comme la commande ls
```
./ft_ls
```
