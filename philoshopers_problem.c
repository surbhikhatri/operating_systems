0#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

void Pickup(int );
void Putdown(int );
void test(int );
void init(void );

enum status {eating,thinking,hungry} state[5];
pthread_cond_t self[5]=PTHREAD_COND_INITIALIZER;
sem_t mutex;
//sem_init(&mutex,0,1);

int main(){
    int i,choice;
    
    pthread_cond_t self[5]=PTHREAD_COND_INITIALIZER;
   
    
    do{
        printf("\nenter the philosopher number who wants to eat or enter 0 to exit\n");
        scanf("%d",&choice);
        if(choice==0){
            return 0;
        }
        else{
            init();
            Pickup(choice-1);
            Putdown(choice-1);
        }
    
    }while(choice);
    return 0;
}

    
 
void Pickup(int i){
        state[i] = hungry;
        test(i);
        if (state[i] != eating)
            pthread_cond_wait(&self[i],&mutex);
    }
void Putdown(int i){
    state[i] = thinking;
    test((i + 1) % 5);
    test((i - 1) % 5);
}
 
void test(int i){
    if (state[(i + 1) % 5] != eating && state[(i - 1) % 5] != eating && state[i] == hungry) {
        state[i] = eating;
        pthread_cond_signal(&self[i]);
    }
}

void init(void){
    int i;
    for(i = 0;i<5;i++){
        state[i] = thinking;
    }
} 
