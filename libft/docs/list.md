
Les fonctions suivantes vous permettront de manipuler vos listes aisément.

Function name

ft_lstnew

Prototype

t_list *ft_lstnew(void *content);

Fichiers de rendu
-
Paramètres

#1. Le contenu du nouvel élément. Valeur de retour Le nouvel element 

Fonctions ex-ternes autorisées

malloc

Description

Alloue (avec malloc(3)) et renvoie un nouvelélément. la variable content est initialisée àl’aide de la valeur du paramètre content. Lavariable ’next’ est initialisée à NULL.

Function name

ft_lstadd_front

Prototype

void ft_lstadd_front(t_list **alst, t_list *new);

Fichiers de rendu
-
Paramètres

#1. L’adresse du pointeur vers le premier élément de la liste.
#2. L’adresse du pointeur vers l’élément à rajouter à la liste.

Valeur de retour 

None 

Fonctions ex-ternes autorisées

None

Description

Ajoute l’élément ’new’ au début de la liste.

Function name

ft_lstsize

Prototype

int ft_lstsize(t_list *lst);

Fichiers de rendu
-
Paramètres

#1. Le début de la liste.Valeur de retourTaille de la liste.

Fonctions ex-ternes autorisées

None

Description

Compte le nombre d’éléments de la liste.

Function name

ft_lstlast

Prototype

t_list *ft_lstlast(t_list *lst);

Fichiers de rendu
-
Paramètres

#1. Le début de la liste.Valeur de retourDernier élément de la liste

Fonctions ex-ternes autorisées

None

Description

Renvoie le dernier élément de la liste

Function name

ft_lstadd_back

Prototype

void ft_lstadd_back(t_list **alst, t_list *new);

Fichiers de rendu
-
Paramètres

#1. L’adresse du pointeur vers le premier élémentde la liste.
#2. L’adresse du pointeur vers l’élément à rajouter à la liste. 

Valeur de retour

None

Fonctions ex-ternes autorisées

None

Description

Ajoute l’élément new à la fin de la liste.

Function name

ft_lstdelone

Prototype

void ft_lstdelone(t_list *lst, void (*del)(void*));

Fichiers de rendu
-
Paramètres

#1. L’élement à free
#2. L’adresse de la fonction permettant desupprimer le contenu de l’élement.

Valeur de retour

None

Fonctions ex-ternes autorisées

free

Description

Libère la mémoire de l’élément passé en argumenten utilisant la fonction del puis avec free(3). Lamémoire de next ne doit pas être free.

Function name

ft_lstclear

Prototype

void ft_lstclear(t_list **lst, void (*del)(void*));

Fichiers de rendu
-
Paramètres

#1. L’adresse du pointeur vers un élément.
#2. L’adresse de la fonction permettant desupprimer le contenu d’un élément.Valeur de retourNone

Fonctions ex-ternes autorisées

free

Description

Supprime et libère la mémoire de l’élément passé en paramètre, et de tous les élements qui suivent, à l’aide de del et de free(3)Enfin, le pointeur initial doit être mis à NULL

Function name

ft_lstiter

Prototype

void ft_lstiter(t_list *lst, void (*f)(void *));

Fichiers de rendu
-
Paramètres

#1 L’adresse du pointeur vers un élément.
#2. L’adresse de la fonction à appliquer.Valeur de retourNone

Fonctions ex-ternes autorisées

None

Description

Itère sur la list lst et applique la fonction f aucontenu chaque élément.

Function name

ft_lstmap

Prototype

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *));

Fichiers de rendu
-
Paramètres

#1. L’adresse du pointeur vers un élément.
#2. L’adresse de la fonction à appliquer.Valeur de retourLa nouvelle liste. NULL si l’allocation échoue.

Fonctions ex-ternes autorisées

malloc, free

Description

Itère sur la liste lst et applique la fonction f aucontenu de chaque élément. Crée une nouvelle listerésultant des applications successives de f. lafonction del est la pour detruire le contenu d unelement si necessaire


touch ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
