#include<stdio.h>              
#include <unistd.h>

int main()
{
    int pfd1[2],pfd2[2],integ[128],rbuff[128];
    pipe(pfd1);
    pipe(pfd2);
    pid_t pid;
     
    printf("Enter two numbers:\n");
    scanf("%d %d",&integ[1],&integ[2]);
    pid = fork();
    if(pid!=0)//parent
    {   
        printf("in 1st process:\n");
        write(pfd1[1],integ,128);
        printf("P1 send the two numbers to P2: %d %d\n",integ[1],integ[2]);
        close (pfd1[1]); //close p1 write
        read(pfd2[0],rbuff,128);
        close(pfd2[0]); //close p2 read
        printf(" AGAIN IN 1ST PROCESS\n");
        printf("P1 received Sum from P2: %d\n",rbuff[0]);
    }
    else//child
    {
        printf("in 2nd Process-:\n");
        read(pfd1[0],integ,128);
        printf("P2 receive 1st  and 2nd num: %d %d\n",integ[1],integ[2]);
        rbuff[0]= add(integ[1],integ[2]);
        write(pfd2[1],rbuff,128);
        close(pfd2[1]);    //close p2 write   
        close(pfd1[0]); //close p1 read
        printf("P2 send the sum of two numbers to P1: %d\n",rbuff[0]);
        
    }
    return 0;
}
int add(int a,int b)
{
    return a+b;
}
