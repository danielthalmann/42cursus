
#ifndef FAKER_H
# define FAKER_H

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

char			*ft_fake_alpha(unsigned int size);
char			*ft_fake_digit(unsigned int size);
int				ft_fake_int();
char			*ft_fake_printable(unsigned int size);
char			*ft_fake_punctuation(unsigned int size);
char			*ft_fake_repeat(unsigned int size, char c);
char			*ft_fake_strnum(int size);
unsigned int	ft_fake_usint(unsigned int max);

#endif