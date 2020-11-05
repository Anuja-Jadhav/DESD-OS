#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


int count =0;
int add(int a,int b)
{
    return a+b;
}
void *thread(void  *arg)
{
    add(10,20);
    count ++;
    printf("thread\n");
}
int main()
{
    pthread_t tid;
    add(40,20);
    count ++;
    printf("before thread creation\n");
    pthread_create(&tid,NULL,thread,NULL);
    printf("data:%d\n",data);
    //printf("after thread creation\n");
    //sleep(1);
    //printf("after sleep creation\n");
    return 0;

}