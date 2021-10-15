#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int _uniq_random_value = 0;

/**
 * @brief generate a string with alpha caracter of length define in size
 * 
 * @param size length of string
 * @return char* 
 */
char	*ft_fake_alpha(unsigned int size)
{
	int		i;
	int		pos;
	char	*alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	*s;

	s = malloc((size + 1) * sizeof(char));
	srand(time(NULL) + _uniq_random_value++);
	i = -1;
	while (++i < size)
	{
		pos = (((float)rand() / RAND_MAX) * 52);
		s[i] = alpha[pos];
	}
	s[size] = 0;
	return s;
}

/**
 * @brief generate a string with digit caracter of length define in size
 * 
 * @param size length of string
 * @return char* 
 */
char	*ft_fake_digit(unsigned int size)
{
	int		i;
	int		pos;
	char	*alpha = "0123456789";
	char	*s;

	s = malloc((size + 1) * sizeof(char));
	srand(time(NULL) + _uniq_random_value++);
	i = -1;
	while (++i < size)
	{
		pos = (((float)rand() / RAND_MAX) * 10);
		s[i] = alpha[pos];
	}
	s[size] = 0;
	return s;
}

/**
 * @brief generate a random int
 * 
 * @return int 
 */
int	ft_fake_int()
{
	int sign;
	int value;

	srand(time(NULL) + _uniq_random_value++);
	value = rand();
	sign = rand(); 
	if (sign < RAND_MAX / 2)
		return -value;
	else
		return value;
}

/**
 * @brief generate a string with pritable caracter of length define in size
 * 
 * @param size length of string
 * @return char* 
 */
char	*ft_fake_printable(unsigned int size)
{
	int		i;
	int		sign;
	char	*s;

	s = malloc((size + 1) * sizeof(char));
	srand(time(NULL) + _uniq_random_value++);
	i = -1;
	while (++i < size)
		s[i] = ' ' + (((float)rand() / RAND_MAX) * ('~' - ' '));
	s[size] = 0;
	return s;
}

/**
 * @brief generate a string with punctuation caracter of length define in size
 * 
 * @param size length of string
 * @return char* 
 */
char	*ft_fake_punctuation(unsigned int size)
{
	int		i;
	int		pos;
	char	*p = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	char	*s;

	s = malloc((size + 1) * sizeof(char));
	srand(time(NULL) + _uniq_random_value++);
	i = -1;
	while (++i < size)
	{
		pos = (((float)rand() / RAND_MAX) * 32);
		s[i] = p[pos];
	}
	s[size] = 0;
	return s;
}

/**
 * @brief obtain a string of a repeat of the character c
 * 
 * @param size length of string
 * @param c the character reapeated
 * @return char* 
 */
char	*ft_fake_repeat(unsigned int size, char c)
{
	unsigned int	i;
	char			*s;

	s = malloc((size + 1) * sizeof(char));
	i = -1;
	while (++i < size)
		s[i] = c;
	s[size] = 0;
	return s;
}

/**
 * @brief generate a string convertible to int. 
 * 
 * @example char *s = ft_fake_strnum(5); // return "38512";
 * 			char *s = ft_fake_strnum(0); // return allway "2147483647";
 * 			char *s = ft_fake_strnum(-1); // return allway "-2147483648";
 * 
 * @param size length of string. 
 * 			   if size == 0 then function return allway "2147483647"
 * 			   if size < 0 then function return allway "-2147483648"
 * @return char* 
 */
char	*ft_fake_strnum(int size)
{
	int		value;
	int		i;
	int		sign;
	char	*s;

	if(size == 0)
	{
		s = malloc(11 * sizeof(char));
		strncpy(s, "2147483647", 11);
		return (s);
	}
	if(size < 0)
	{
		s = malloc(12 * sizeof(char));
		strncpy(s, "-2147483648", 12);
		return (s);
	}
	sign = rand(); 
	if (rand() < (RAND_MAX / 3))
		sign = 1;
	else
		sign = 0;
	s = malloc((size + sign + 1) * sizeof(char));
	if(sign)
		s[0] = '-';
	i = sign;
	srand(time(NULL) + _uniq_random_value++);
	while (i < size + sign)
	{
		value = rand();
		s[i] = '0' + (((float)value / RAND_MAX) * 10);
		i++;
	}
	s[size + sign] = 0;
	return s;
}

/**
 * @brief generate a random unsigned int
 * 
 * @return int 
 */
unsigned int	ft_fake_usint(unsigned int max)
{
	int sign;
	unsigned int value;

	if(!max)
		max = UINT_MAX;
	srand(time(NULL) + _uniq_random_value++);
	return ((float)rand() / RAND_MAX) * max;
}
