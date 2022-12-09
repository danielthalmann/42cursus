#include <signal.h>
#include <stdio.h>
#include <unistd.h>
 
typedef struct s_sig
{
	int sig;
} t_sig;

volatile t_sig *ft_get_sig()
{
	volatile static t_sig t;
	return (&t);
}

void signal_handler(int signal)
{
	volatile static t_sig *t;
	
	t = ft_get_sig();
	sleep(1);
    t->sig = signal;
}
 
int main(void)
{
	volatile static t_sig *t;
	int pid;
	
	t = ft_get_sig();
    signal(SIGUSR2, signal_handler);
 
    printf("SignalValue:   %d\n", t->sig);
    printf("Sending signal %d\n", SIGUSR2);
	pid = getpid();
	kill(pid, SIGUSR2); // est bloquant si le pid est son propre processus
    // raise(SIGINT); // est bloquant
    printf("SignalValue:   %d\n", t->sig);
	sleep(1);
	printf("SignalValue after 1 sec. :   %d\n", t->sig);
}