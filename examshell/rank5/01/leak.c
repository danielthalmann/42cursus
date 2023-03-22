#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
    pid_t   pid;

    int p = getpid();

    printf("my pid : %d\n", p);

    pid = fork();
    printf("after fork : %d\n", pid);

    if (pid == -1)
    {
        printf("Fork error\n");
        return (EXIT_FAILURE);
    }
    if (pid == 0)
    {
        printf("Hello from the child process\n");
        pid = getpid();
        kill(pid,  SIGUSR1);
        return (EXIT_SUCCESS);
    }
    printf("child : %d\n", pid);
    printf("Hello from the parent process\n");
    if (wait(NULL) == -1)
    {
        printf("Waitpid error\n");
        return (EXIT_FAILURE);
    }
    // kill(pid, SIGQUIT);
    printf("parent process finished\n");
    //while (1);
    return (0);
}