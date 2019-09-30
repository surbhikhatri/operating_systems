//Aim:PRODUCER CONSUMER WITHOUT SYNCHRONISATION.

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void *producer(); 
void *consumer( ); 

int main() {
		 int a=10;
   
         pthread_t ptid,ctid;       
         pthread_create(&ptid,NULL,producer,NULL);
         pthread_create(&ctid,NULL,consumer,NULL);
         pthread_join(ptid, NULL);
		 pthread_join(ctid, NULL);
     }

void *producer(void * p) {
int i,a=5;
for(i=0;i<6;i++){
	a=a+2;
   	printf("I m producer %d\n",a);
 }
  pthread_exit(0);
}

void *consumer(void * p) {
	int i,a=5;
	for( i=0;i<6;i++){
		a=a-1;
	   	printf("I m consumer %d\n",a);
	}
	   pthread_exit(0);
}

/*
output-------------
I m consumer 4
I m consumer 3
I m consumer 2
I m consumer 1
I m consumer 0
I m consumer -1
I m producer 7
I m producer 9
I m producer 11
I m producer 13
I m producer 15
I m producer 17
*/

