
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

#include <stdio.h>
#include <limits.h>


int main()
{

	printf("printf(%%i) -> \"%i\" \n", INT_MAX);
	printf("printf(%%i) -> \"%i\" \n", INT_MIN);
	printf("printf(%%d) -> \"%d\" \n", INT_MAX);

	printf("printf(%%-20i) -> \"%-20i\" \n", INT_MAX);
	printf("printf(%%-20i) -> \"%-20i\" \n", INT_MIN);
	printf("printf(%%-20d) -> \"%-20d\" \n", INT_MAX);
	printf("printf(%%-20d) -> \"%-20d\" \n", INT_MAX);
	printf("printf(%%+20d) -> \"%+20d\" \n", INT_MAX);
	printf("printf(%% d) -> \"% d\" \n", INT_MAX);
	printf("printf(%% d) -> \"% d\" \n", INT_MIN);
	printf("printf(%%20d) -> \"%20d\" \n", INT_MAX);
	printf("printf(%%+d) -> \"%+d\" \n", INT_MAX);
	printf("printf(%%+d) -> \"%+d\" \n", INT_MIN);
	printf("printf(%%#x) -> \"%#x\" \n", INT_MAX);
	printf("printf(%%#X) -> \"%#X\" \n", INT_MAX);
	printf("printf(%%#X) -> \"%#X\" \n", 0);
	printf("printf(%%X) -> \"%X\" \n", 0);
	

	return (0);
}
