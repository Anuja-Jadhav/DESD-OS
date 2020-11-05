#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *thread(void  *arg)
{
    printf("thread\n");
}
int main()
{
    pthread_t tid;
    printf("brfore thread creation\n");
    pthread_create(&tid,NULL,thread,NULL);
    //printf("after thread creation\n");
    //sleep(1);
    //printf("after sleep creation\n");
    return 0;

}