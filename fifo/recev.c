#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    unsigned char rbuff[128];
    int fd;
    fd=open("desd",O_RDONLY);
    read(fd,rbuff,64);
    printf("received from sender: %s\n",rbuff);
    close(fd);
    return 0;
}
