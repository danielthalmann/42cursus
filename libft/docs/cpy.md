
## void	*ft_memcpy(void *dest, const void *src, size_t n)

__n = 3__ 

| __*src__   | A | B | C | D |
|------------|---|---|---|---|
|            | ↓ | ↓ | ↓ |   |
| __*dest__  | A | B | C |   |


## size_t	ft_strlcpy(char *dst, const char *src, size_t size)

__size = 3__ 

| __*src__   | A | B | C  | D  | \0 |
|------------|---|---|----|----|----|
|            | ↓ | ↓ | ↓  |    |    |
| __*dest__  | A | B | \0 |    |    |

__return = 4__

----

__size = 10__ 

| __*src__   | A | B | \0 |   |    |
|------------|---|---|----|---|----|
|            | ↓ | ↓ | ↓  |   |    |
| __*dest__  | A | B | \0 |   |    |

__return = 2__