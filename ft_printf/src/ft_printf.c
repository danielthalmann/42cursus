#include <stdarg.h>
#include <unistd.h>

ft_print_format(char c, va_list *ap);
ft_print_char(va_list *ap);
ft_print_string(va_list *ap);
ft_print_pointer(va_list *ap);
ft_print_decimal(va_list *ap);
ft_print_integer(va_list *ap);
ft_print_unsigned_dec(va_list *ap);
ft_print_hex(va_list *ap, char c);

ft_printf(const char *format, ...)
{
	va_list ap;
	char c;

	va_start(ap, format);
	while (*format)
	{
		c = *format;
		format++;
		if (c == '%')
		{
			c = *format;
			if (*format)
			{
				format++;
				ft_print_format(c, &ap);
			}
		}
	}
	va_end(ap);
}

ft_print_format(char c, va_list *ap)
{
	if (c == 'c')
		ft_print_char(&ap);
	if (c == 's')
		ft_print_string(&ap);
	if (c == 'p')
		ft_print_pointer(&ap);
	if (c == 'd')
		ft_print_decimal(&ap);
	if (c == 'i')
		ft_print_integer(&ap);
	if (c == 'u')
		ft_print_unsigned_dec(&ap);
	if (c == 'x' || c == 'X')
		ft_print_hex(&ap, c);
	if (c == '%')
		write(1, "%", 1);
}

ft_print_char(va_list *ap)
{
	char	c;

	c = (char) va_arg(*ap, int);
	write(1, &c, 1);
}

ft_print_string(va_list *ap)
{
	char	*s;

	s = (char *) va_arg(*ap, char *);
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

