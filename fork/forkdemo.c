#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;
    printf("Before fork\n");
    id=fork();

    //printf("After fork id\t pid\t ppid\t: %d %d %d \n",id,getpid(),getppid());
    if(0 == id)
    { //child
        printf("in child : Pid=%d \t PPID=%d\n",getpid(),getppid());
    }
    else
    { //parent
        printf("in parent : Pid=%d \t PPID=%d\n",getpid(),getppid());
    }
    return 0;

}
