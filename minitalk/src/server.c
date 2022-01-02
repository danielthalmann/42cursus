
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#include "signum.h"

void handler (int signum)
{
	if (signum == SIGUSR1)
		printf("signal usr1\n");
	return ;
}

int main (void)
{
	struct sigaction new_action;
	struct sigaction old_action;

	/* Set up the structure to specify the new action. */
	new_action.sa_handler = &handler;
	sigemptyset (&new_action.sa_mask);
	new_action.sa_flags = 0;
	
	sigaction (SIGUSR1, &new_action, &old_action);

	while (1)
	{
		usleep(100);
	}

}