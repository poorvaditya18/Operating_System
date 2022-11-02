// CLIENT SIDE
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct dbase
{
    char buffer[1024];
    int status;
};

int main()
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 0, 0666);
    struct dbase *str = (struct dbase *)shmat(shmid, (void *)0, 0);

    while (str->status != 1)
    {
        printf("\nWaiting");
        sleep(1);
    }

    printf("\nData read from the memory : %s\n", str->buffer);
    str->status = 1;

    printf("\nWrite the data :");
    fgets(str->buffer, 1024, stdin);
    str->status = 0;

    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL); // destroy the shared memory
    return 0;
}