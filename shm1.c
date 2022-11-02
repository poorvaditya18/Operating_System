#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
struct dbase
{
    char buffer[1024];
    int status;
};

int main()
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, sizeof(struct dbase), 0666 | IPC_CREAT);
    struct dbase *str = (struct dbase *)shmat(shmid, (void *)0, 0);

    str->status = 0;
    printf("\nWrite the data :");
    fgets(str->buffer, 1024, stdin);

    str->status = 1;
    while (str->status != 0)
    {
        printf("\nWaiting");
        sleep(1);
    }

    printf("\nData written in the memory : %s\n", str->buffer);

    shmdt(str);
    return 0;
}
