
#ifndef INPUT_H
# define INPUT_H


#ifdef __linux__

# define KEY_Q 113
# define KEY_W 119
# define KEY_E 101
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

#else

# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_T 17
# define KEY_Z 16
# define KEY_U 32
# define KEY_I 34
# define KEY_O 31
# define KEY_P 35
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_Y 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_N 45
# define KEY_M 46
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define KEY_ENTER 36
# define KEY_SIZE 256

#endif

int		key_down(int keycode, void *param);
int		key_up(int keycode, void *param);

#endif