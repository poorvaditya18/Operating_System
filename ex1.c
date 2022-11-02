// EXECV

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    pid_t pid, status;
    char *temp;
    int x[argc - 1];

    for (int i = 2; i < argc - 1; i++)
    {
        for (int j = 2; j < argc - i - 1; j++)
        {
            if (atoi(argv[j]) > atoi(argv[j + 1]))
            {
                temp = argv[j];
                argv[j] = argv[j + 1];
                argv[j + 1] = temp;
            }
        }
    }
    for (int i = 1; i < argc; i++)
    {
        printf("%s", argv[i]);
    }
    pid = fork();
    if (pid == 0)
    {
        execv(argv[1], argv);
    }
    else
    {
        wait(&status);
    }
}
