#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    // taking the input from the terminal
    pid_t pid;
    int temp;
    int arr[10];
    int n;

    for (int i = 1; i < argc; i++)
    {
        // atoi -> converts string to integer
        arr[i - 1] = atoi(argv[i]);
    }
    n = argc - 1;

    pid = fork();

    if (pid == 0)
    {
        // sort in the child process
        // Descending order

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        printf("\nSorted Descending order is : ");
        for (int i = 0; i < n; i++)
        {
            printf("\t%d", arr[i]);
        }
    }
    else
    {
        // Ascending order ->
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        printf("\nSorted Ascending order is:");
        for (int i = 0; i < n; i++)
        {
            printf("\t%d", arr[i]);
        }
    }
}