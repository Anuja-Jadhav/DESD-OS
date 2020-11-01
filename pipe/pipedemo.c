#include<stdio.h>
#include<unistd.h>

int main()
{
    unsigned char rbuff[128];
    pid_t id;
    int pfd[2];
    pipe(pfd);

    id = fork();

    if(0== id)
    { //child process
        read(pfd[0],rbuff,128);
        printf("child :%s\n",rbuff);
        close(pfd[0]);
    }
    else
    { //parent process
        write(pfd[1],"cdac\n",5);
        close(pfd[1]);
    }
}