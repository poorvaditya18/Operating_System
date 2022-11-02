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
        sleep(2); // wait till the parent process gets completed
        pid = getpid(); // child process id
        printf("\nChild id = %d", pid);
        pid = getppid(); // child parent id
        printf("\nChild process parent id= %d", pid);
    }
    // parent process
    else
    {
        printf("\nChild id = %d", pid);
        pid = getpid(); // parent process id
        printf("\nParent id = %d", pid);
        pid = getppid(); // parent process parent id
        printf("\nParent parent id =%d", pid);
    }
}