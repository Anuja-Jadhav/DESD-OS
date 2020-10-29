#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int count=0;
int main(int argc, char const *argv[])
{
    pid_t id;
    printf("Before fork\n");
    id=fork();

    //printf("After fork id\t pid\t ppid\t: %d %d %d \n",id,getpid(),getppid());
    if(0 == id)
    { //child
        //count++;
        printf("count in child=%d \n",count);
    }
    else
    { //parent
        count++;
        printf("count in parent =%d \n",count);
    }
    return 0;

}
