
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

#include "ft_printf.h"

int main()
{
	ft_printf("ft_printf(%%25s) -> \"%25s\" \n", "mon texte");
	printf   ("   printf(%%25s) -> \"%25s\" \n", "mon texte");
	ft_printf("ft_printf(%%10s) -> \"%10s\" \n", "mon texte");
	printf   ("   printf(%%10s) -> \"%10s\" \n", "mon texte");
	ft_printf("ft_printf(%%-10s) -> \"%-10s\" \n", "mon texte");
	printf   ("   printf(%%-10s) -> \"%-10s\" \n", "mon texte");
	ft_printf("ft_printf(%%z) -> \"%z\" \n", "mon texte");
	printf("ft_printf(%%-+i) -> \"%+-20i\" \n", INT_MAX);

return (0);
	ft_printf("ft_printf(%%s) -> \"%s\" \n", "mon texte");
	printf   ("   printf(%%s) -> \"%s\" \n", "mon texte");

	ft_printf("ft_printf(%%i) -> \"%i\" \n", 0);
	printf   ("   printf(%%i) -> \"%i\" \n", 0);

	ft_printf("ft_printf(%%i) -> \"%i\" \n", INT_MAX);
	printf   ("   printf(%%i) -> \"%i\" \n", INT_MAX);

	ft_printf("ft_printf(%%i) -> \"%i\" \n", INT_MIN);
	printf   ("   printf(%%i) -> \"%i\" \n", INT_MIN);

	ft_printf("ft_printf(%%d) -> \"%d\" \n", INT_MAX);
	printf   ("   printf(%%d) -> \"%d\" \n", INT_MAX);

	printf   ("   printf(%%-20i) -> \"%-20i\" \n", INT_MAX);
	printf   ("   printf(%%-20i) -> \"%-20i\" \n", INT_MIN);
	printf   ("   printf(%%-20d) -> \"%-20d\" \n", INT_MAX);
	printf   ("   printf(%%-20d) -> \"%-20d\" \n", INT_MAX);
	printf   ("   printf(%%+20d) -> \"%+20d\" \n", INT_MAX);
	printf   ("   printf(%% d) -> \"% d\" \n", INT_MAX);
	printf   ("   printf(%% d) -> \"% d\" \n", INT_MIN);
	printf   ("   printf(%%20d) -> \"%20d\" \n", INT_MAX);
	printf   ("   printf(%%+d) -> \"%+d\" \n", INT_MAX);
	printf   ("   printf(%%+d) -> \"%+d\" \n", INT_MIN);
	printf   ("   printf(%%#x) -> \"%#x\" \n", INT_MAX);
	printf   ("   printf(%%#X) -> \"%#X\" \n", INT_MAX);
	printf   ("   printf(%%#X) -> \"%#X\" \n", 0);
	printf   ("   printf(%%X) -> \"%X\" \n", 0);
	

	return (0);
}
