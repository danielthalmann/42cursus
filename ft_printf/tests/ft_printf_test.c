
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
	char c;
	c = 65;

	printf   ("   printf(%%25c) -> \"%25c\" \n", c);
	ft_printf("ft_printf(%%25c) -> \"%25c\" \n", c);

	char *n;
	n = 0;

	printf   ("   printf(%%p) -> \"%p\" \n", n);
	ft_printf("ft_printf(%%p) -> \"%p\" \n", n);

	n = "test";

	printf   ("   printf(%%p) -> \"%p\" \n", n);
	ft_printf("ft_printf(%%p) -> \"%p\" \n", n);


return (0);

	n = 0;

	printf   ("   printf(%%25s) -> \"%25s\" \n", n);
	ft_printf("ft_printf(%%25s) -> \"%25s\" \n", n);

	printf   ("   printf(%%.25s) -> \"%.25s\" \n", n);
	ft_printf("ft_printf(%%.25s) -> \"%.25s\" \n", n);

	printf   ("   printf(%% i) -> \"% i\" \n", INT_MAX);
	ft_printf("ft_printf(%% i) -> \"% i\" \n", INT_MAX);

	printf   ("   printf(%% 12i) -> \"% 12i\" \n", INT_MAX);
	ft_printf("ft_printf(%% 12i) -> \"% 12i\" \n", INT_MAX);

	printf   ("   printf(%% 12i) -> \"% 12i\" \n", INT_MAX);
	ft_printf("ft_printf(%% 12i) -> \"% 12i\" \n", INT_MAX);

	printf   ("   printf(%% -11i) -> \"% -11i\" \n", INT_MAX);
	ft_printf("ft_printf(%% -11i) -> \"% -11i\" \n", INT_MAX);

	printf   ("   printf(%%+-11i) -> \"%+-11i\" \n", INT_MAX);
	ft_printf("ft_printf(%%+-11i) -> \"%+-11i\" \n", INT_MAX);

	printf   ("   printf(%%+i) -> \"%+i\" \n", INT_MAX);
	ft_printf("ft_printf(%%+i) -> \"%+i\" \n", INT_MAX);

	printf   ("   printf(%%+i) -> \"%+i\" \n", 0);
	ft_printf("ft_printf(%%+i) -> \"%+i\" \n", 0);

	printf   ("\n");

	ft_printf("ft_printf(%%10s) -> \"%10s\" \n", "mon texte");
	printf   ("   printf(%%10s) -> \"%10s\" \n", "mon texte");

	printf   ("\n");
	
	ft_printf("ft_printf(%%-10s) -> \"%-10s\" \n", "mon texte");
	printf   ("   printf(%%-10s) -> \"%-10s\" \n", "mon texte");
	printf   ("\n");
	ft_printf("ft_printf(%%z) -> \"%z\" \n", "mon texte");
	printf("ft_printf(%%-+i) -> \"%+-20i\" \n", INT_MAX);
	printf("ft_printf(%%-+i) -> \"%+-20i\" \n", INT_MAX);

return (0);

    printf("size of int : %ld\n",sizeof(int));
    printf("size of signed int : %ld\n",sizeof(signed int));
    printf("size of unsigned long : %ld\n",sizeof(long));
	printf("size of pointer : %ld\n",sizeof(void *));

	ft_printf("ft_printf(%%i) -> \"%i\" \n", INT_MIN);
	printf   ("   printf(%%i) -> \"%i\" \n", INT_MIN);


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
