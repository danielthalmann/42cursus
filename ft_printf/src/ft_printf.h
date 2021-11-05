/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:38:38 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/05 00:38:38 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_format
{
	va_list	*ap;
	int		c;
	int		fd;
	int		mod;
	int		align_left;
	int		margin;
	int		space_sign;
	int		zero_fill;
	int		plus_sign;
}	t_format;

void	ft_printf(const char *format, ...);
int		ft_len_itoa(int nb);
void	ft_uitoa_fd(unsigned int nb, int fd);
void	ft_itoa_fd(int nb, int fd);
void	ft_ltoa_fd(long nb, int fd);
void	ft_ltox_fd(long nb, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_format_space(int left, int len, t_format *format);
void	ft_clear_type_format(va_list *ap, int fd, t_format *format);
char	*ft_treat_percent(va_list *ap, char *s_format, int fd);
void	ft_print_format_fd(t_format *format);
void	ft_print_char_fd(t_format *format);
void	ft_print_string_fd(t_format *format);
void	ft_print_pointer_fd(t_format *format);
void	ft_print_integer_fd(t_format *format);
void	ft_print_unsigned_dec_fd(t_format *format);
void	ft_print_hex_fd(t_format *format);
#endif