/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:38:38 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 09:32:49 by dthalman         ###   ########.fr       */
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
	int		decimal_point;
	int		len;
	int		sharp;
}	t_format;

int		ft_printf(const char *format, ...);
int		ft_len_itoa(long nb);
void	ft_uitoa_fd(unsigned int nb, int fd);
void	ft_itoa_fd(int nb, int fd);
void	ft_itoa_fd2(int nb, int fd, int len, t_format *format);
void	ft_ltoa_fd(long nb, int fd);
int		ft_len_ltox(unsigned long nb);
void	ft_ltox_fd(unsigned long nb, int fd);
void	ft_ltox_up_fd(unsigned long nb, int fd);
size_t	ft_strlen(const char *s);
void	ft_repeat_char(int len, char c, t_format *format);
void	ft_zero_padded(int len, t_format *format);
char	*ft_strchr(const char *s, int c);
void	ft_margin_left(int len, t_format *format);
void	ft_margin_right(int len, t_format *format);
void	ft_clear_type_format(va_list *ap, int fd, t_format *format);
char	*ft_treat_percent(va_list *ap, char *s_format, t_format	*f, int fd);
void	ft_read_modifier(char c, t_format *format);
void	ft_print_format_fd(t_format *format);
void	ft_print_char_fd(t_format *format);
void	ft_print_string_fd(t_format *format);
void	ft_print_pointer_fd(t_format *format);
void	ft_print_integer_fd(t_format *format);
void	ft_print_unsigned_dec_fd(t_format *format);
void	ft_print_hex_fd(t_format *format);
#endif