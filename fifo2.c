#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

    // read message from b
    char mssg_r[80];

    int fd_r;

    int i = 0;
    int wcount = 0;
    int lcount = 0;
    int count = 0;
    char *myfile = "/home/aditya/Desktop/os_lab";

    // OPEN FIFO in the read mode
    fd_r = open("file1", O_RDONLY);

    // Read from fifo and store the message array
    read(fd_r, mssg_r, 80);

    while (mssg_r[i] != '$')
    {

        // blank spaces -> increase the wcount
        if ((mssg_r[i] == ' '))
        {
            wcount++;
        }
        // new line -> increase the line count as well as word count.
        else if (mssg_r[i] == '\n')
        {
            lcount++;
            wcount++;
        }
        // increase the count : character count = count - wcount
        count++;
        i++;
    }

    printf("linecount :%d\n", lcount);
    printf("wordcount :%d\n", wcount);
    printf("character count :%d\n", (count - wcount));

    // transfering the contents to the file : count.txt
    FILE *fptr = fopen("count.txt", "w");
    if (fptr == NULL)
    { // could not open the file
        printf("File could not be openned");
        return 0;
    }

    fprintf(fptr, "linecount :%d\n", lcount);
    fprintf(fptr, "wordcount :%d\n", wcount);
    fprintf(fptr, "character count :%d\n", (count - wcount));
    fclose(fptr);

    // over pipe
    int fd_new;

    char mssg2[1000];

    // make fifo
    mkfifo("fileP", 0666);

    fd_new = open("fileP", O_WRONLY);

    write(fd_new, "count.txt", 9);

    close(fd_new);

    return 0;
}