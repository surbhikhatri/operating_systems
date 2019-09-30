#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int buf[5],f,r;
sem_t mutex,full,empty;
void *produce(void *arg){
    int i;
    int *s;
    for(i=0;i<10;i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("produced item is %d\n",i);
        buf[(++r)%5]=i;
        sleep(1);
        sem_post(&mutex);
        sem_post(&full);
        sem_getvalue(&full,&s);
        printf("full %d\n",s);
        
    }
}
void *consume(void *arg)
{
        int item,i;
        int *x;
        for(i=0;i<10;i++)
        {
                sem_wait(&full);
        printf("full %u\n",full);
                sem_wait(&mutex);
                item=buf[(++f)%5];
                printf("consumed item is %d\n",item);
                sleep(1);
                sem_post(&mutex);
                sem_post(&empty);
                sem_getvalue(&full,&x);
        }
}

int main()
{
    pthread_t tid1,tid2;
    sem_init(&mutex,0,1);
    sem_init(&full,0,1);
    sem_init(&empty,0,5);
    pthread_create(&tid1,NULL,produce,NULL);
        pthread_create(&tid2,NULL,consume,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
}


----------------
output
produced item is 0
full 0
full 1
consumed item is 0
full 0
produced item is 1
full 1
consumed item is 1
full 0
produced item is 2
full 1
consumed item is 2
full 0
produced item is 3
full 1
consumed item is 3
full 0
produced item is 4
full 1
consumed item is 4
full 0
produced item is 5
full 1
consumed item is 5
full 0
produced item is 6
full 1
consumed item is 6
full 0
produced item is 7
full 1
consumed item is 7
full 0
produced item is 8
full 1
consumed item is 8
full 0
produced item is 9
full 1
consumed item is 9

