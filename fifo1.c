#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

// PART 1

// write message from a
char mssg[80]; 
int fd;  // fifo descriptor
char * myfile = "/home/aditya/Desktop/os_lab";


// MAKE FIFO -->
mkfifo("file1",0666);
//mkfifo(myfile,0666);

// OPEN FIFO  read or write mode --> store it in the fd
//fd = open(myfile,O_WRONLY);
fd = open("file1",O_WRONLY);


int c = '\0';
int i=0;
while(c!='$')
{
    c = getchar();
    mssg[i] = c;
    i++;
}

// from message array write in the fifo
write(fd,mssg,strlen(mssg)+1);

// close the fifo
close(fd);


// PART 2

// reading from the file
int fd_open;

char buffer[1000];

// open the fifo - >
fd_open = open("fileP",O_RDONLY);

// clear the buffer
memset(buffer,'\0',1000);

// read from the fifo
read(fd_open,buffer,1000);

// print the buffer
printf("%s",buffer);



return 0;
}