// Skeleton for exercise nr 6 in WP 6 course DIT165.
// File skeleton_wp6_6.c  
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  not_empty   = PTHREAD_COND_INITIALIZER;
pthread_cond_t  not_full   = PTHREAD_COND_INITIALIZER;

// Global buffer and corresponding counters.
char  letter = 'a'; //the starting letter
#define MAX 10//buffer size
unsigned short count = 0;
char buffer[MAX]; // circular buffer
int write_pos = 0; // index for next character to be put in buffer (put)
int read_pos = 0; // index for next character to be read ( fetch )

void *put();
void *fetch();

int main(){
    int i;
	pthread_t tid, tid2;

	pthread_create(&tid, NULL, put, NULL);


	pthread_create(&tid2, NULL, fetch, NULL);

   while(1){
         printf("\nmain is executing\n");
       /* pthread_mutex_lock( &count_mutex );

        pthread_cond_wait(&not_empty, &count_mutex);
        printf("\nbuffer input\n");

        pthread_cond_wait(&not_full, &count_mutex);
        printf("\nbuffer output: %c\n" , buffer[write_pos]);
		pthread_mutex_unlock( &count_mutex );
*/
   }

	pthread_join(tid, NULL);
    pthread_join(tid2, NULL);
    return 0;
}


void *put(){
    char input = 97;
    int pos = 0;
    while(1){

        pthread_mutex_lock( &count_mutex );
        printf("\nbuffer input\n");
        buffer[write_pos] = input;
        pthread_cond_signal(&not_empty);

        if(write_pos > MAX){
            pthread_cond_wait(&not_full, &count_mutex);
            write_pos = 0;
        }else{
                write_pos ++; 
        }
        if(input > 121){
            input = 97;
        }
        else{
            input++;
        }

        pthread_mutex_unlock( &count_mutex );


    }
   	pthread_exit(0);

}


void *fetch(){
    while(1){
		pthread_mutex_lock( &count_mutex );
       // printf("%c", buffer[read_pos]);
                printf("\nbuffer output: %c\n" , buffer[read_pos]);

        buffer[read_pos] = 0;
        
        pthread_cond_signal(&not_full);

        if(read_pos > MAX){
            pthread_cond_wait(&not_empty, &count_mutex);
            read_pos = 0;
        }else{
            read_pos++; 
        }

        pthread_mutex_unlock( &count_mutex );

    }
	pthread_exit(0);

}
