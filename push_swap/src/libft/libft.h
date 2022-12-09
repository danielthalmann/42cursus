/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:06:19 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/12 17:40:42 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# define BUFFER_SIZE 81

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int nb);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
//bonus
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//get_next_line
char	*get_next_line(int fd);
char	*ft_str_append(char *s, char *add);
size_t	ft_strlen2(char *s, char *eos);
int		ft_fill_buffer(int fd, char *buffer);
char	*ft_allocate(char *buffer, int len);
int		ft_while_not_eol(int fd, char *buffer, char **out);
void	ft_strmov(char *to, char *s, int len);
//ft_printf
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
int		ft_fprintf(int fd, const char *format, ...);
int		ft_len_itoa(long nb);
void	ft_uitoa_fd(unsigned int nb, int fd);
void	ft_itoa_fd(int nb, int fd);
void	ft_itoa_fd2(int nb, int fd, int len, t_format *format);
void	ft_ltoa_fd(long nb, int fd);
int		ft_len_ltox(unsigned long nb);
void	ft_ltox_fd(unsigned long nb, int fd);
void	ft_ltox_up_fd(unsigned long nb, int fd);
void	ft_uitox_fd(unsigned int nb, int fd);
void	ft_uitox_up_fd(unsigned int nb, int fd);
void	ft_repeat_char(int len, char c, t_format *format);
void	ft_zero_padded(int len, t_format *format);
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
