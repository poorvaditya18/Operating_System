#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{

    int status;
    pid_t pid;
    pid = fork();

    // child process
    if (pid == 0)
    {
        pid = getpid();
        printf("Child id = %d", pid);
        pid = getppid();
        printf("\nChild process parent id = %d", pid);
    }
    // parent process
    else
    {
        // Parent will wait for the child process to get over . When over it now in the memory only parent process wil be there . Zombie state .
        sleep(2);
        system("ps");
        wait(&status);
        system("ps");
        printf("\nChild id = %d", pid);
        pid = getpid();
        printf("\n Parent id = %d", pid);
        pid = getppid();
        printf("\nParent parent id  =%d", pid);
    }
}