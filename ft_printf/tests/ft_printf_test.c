
/**
 * @file ft_args_test.c
 * @author Daniel Thalmann <daniel@thalmann.li>
 * @brief Petit exemple d'utilisation des fonctions avec un nombre variable de paramètre
 * @version 0.1
 * @date 2021-11-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Cette fonction affiche dans la console le contenu de la chaine s puis
 * lit autant de fois les paramètres variables que la valeur de n
 * 
 * @param s Une chaine de caractère quelconque
 * @param n Le nombre de paramètre qu'on va lire dans les ...
 * @param ... plusieurs paramètres de type entier.
 */
void ft_example(char *s, int n, ...)
{
	va_list list;
	int i;
	int v;

	printf("param 1 : %s param 2 : %d \n", s, n);

	/**
	 * @brief Pour initialiser la lecteur des paramètres variables d'une 
	 * fonction, il faut commencer par initialiser une liste de départ avec 
	 * la fonction va_start. On donne comme premier paramètre la list et 
	 * comme deuxième paramètre le dernier paramètre de notre fonction avant
	 * les paramètre variable (dernier variable avant ...)
	 */
	va_start(list, n);

	i = 0;
	while(i < n)
	{
		/**
		 * @brief pour lire le contenu du paramètre, on utilise la fonction
		 * va_arg. Elle prend comme premier paramètre la list et comme deuxième
		 * paramètre, on indique le type de la variable qui sera lu.
		 * dans cet exemple, on récupère un type int
		 */
		v = va_arg(list, int);
		/**
		 * @brief On affiche à l'écran la valeur
		 */
		printf("value %d : %d\n", i, v);
		i++;
	}
	/**
	 * @brief Lorsque la lecture des variables est terminées, il est nécessaire
	 * de terminer la lecture de la liste à l'aide de la fonction va_end.
	 * Elle prend en paramètre la liste.
	 */
	va_end(list);
}


int main()
{
	/**
	 * @brief Voici l'exemple de notre fonction ft_example
	 * 
	 */
	ft_example("un exemple avec trois valeurs", 3, 16, 21, 42);

	printf("test\n");

	return (0);
}

/**
 * @brief Pour tester la fonction, executer dans la console :
 * $ gcc ft_args_test.c && ./a.out
 * 
 */
