#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int sum;
int a,b;
sem_t s1,s2;
void *input_thread(void *data)
{
    while(1)
    {
        printf("T1:got signal  from processing thread\n");
        sem_wait(&s2);
        printf("T1 getting new inputs\n");
        scanf("%d",&a);
        scanf("%d",&b);
        printf("T1 got new input\n");
        sem_post(&s1);
        printf("T1:sending signal toprocessing thread\n");
    }
}
void *processing_thread(void *data)
{
    while(1){
        printf("T2:waiting signal  from input thread\n");
        sem_wait(&s1);
        printf("T2:starting processing\n");
        sum=a+b;
        printf("T2:processing done .. sum=%d\n",sum);
        sem_post(&s2);
        printf("T2: sending signal to input thread\n");
    }
}
int main()
{
    pthread_t input_id,processing_id;
    sem_init(&s1,0,0);
    sem_init(&s2,0,1);
    pthread_create(&input_id,NULL,input_thread,NULL);
     pthread_create(&processing_id,NULL,processing_thread,NULL);

    pthread_join(input_id,NULL);
     pthread_join(processing_id,NULL);
     return 0;
}