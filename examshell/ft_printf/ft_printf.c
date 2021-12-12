
#include <stdarg.h>
#include <unistd.h>

int	ft_print_d(long i)
{
	int	len;
	char	c;

	len = 0;
	if (i < 0)
	{
		len += write (1, "-", 1);
		len += ft_print_d(-i);
	}
	else
	{
		if (i < 10)
		{
			c = '0' + i;
			len += write (1, &c, 1);
		}
		else
		{
			len += ft_print_d(i / 10);
			len += ft_print_d(i % 10);
		}
	}
	return (len);
}

int	ft_print_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_s(char *s)
{
	int len;

	len = 0;
	while (*s)
	{
		len += write(1, s, 1);
		s++;
	}
	return (len);

}

int ft_printf(char *s, ...)
{
	va_list lst;
	int	len;

	va_start (lst, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 's')
				len += ft_print_s(va_arg(lst, char*));
			else if (*s == 'd')
				len += ft_print_d(va_arg(lst, int));
			else if (*s == 'c')
				len += ft_print_c(va_arg(lst, int));
			else
			{
				len += write(1, "%", 1);
				len += write(1, s, 1);
			}
		}
		else
			len += write(1, s, 1);
		s++;
	}
	
	va_end (lst);

	return (len);
}

