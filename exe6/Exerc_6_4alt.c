#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
int program_time = 0; // The global time, start value 0
void *time_count();
void *read_inport();
double get_time_ms();
pthread_mutex_t lock;

int main(){
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }
 // Start up the thread time_count.
    pthread_t thread_id; 
    pthread_create(&thread_id, NULL, time_count, NULL); 

 // Start up the thread read_inport.
    pthread_t thread_id2; 
    pthread_create(&thread_id2, NULL, read_inport, NULL); 
    int timeNow = program_time;
    while ( program_time < 50){
         
    //Print out system time every second.
        if(timeNow != program_time){
            timeNow = program_time;
            printf("%d\n"  ,program_time);
        }
    }
    pthread_join(thread_id, NULL);
    pthread_join(thread_id2, NULL);
    pthread_mutex_destroy(&lock);
}
// --- End of main thread ------
// ----- Tread functions –
//--------------------------------------------
void *time_count() {
    int timeNow  = get_time_ms();
    while ( program_time < 50){
    // Check system-time ( get_time_ms())
    // Increase program_time by one every second.
        if(get_time_ms() - timeNow == 1){
            timeNow = get_time_ms() ;
            pthread_mutex_lock(&lock);
            program_time++;
            pthread_mutex_unlock(&lock);

        }    
    }
// exit thread;
    pthread_exit(NULL); 
} //End------------------------------------
void *read_inport(){
    int timeNow = program_time;

    while (program_time<50){
        pthread_mutex_lock(&lock);
        if(program_time % 5 == 0 && program_time != 0 && timeNow != program_time){
            timeNow = program_time;
            printf("programtime: %d\n" , program_time);   
            printf("read import\n");   
        }   
        pthread_mutex_unlock(&lock);
    }
    //Exit thread
    pthread_exit(NULL); 
} //End------------------------------------

// -------- Function get_time_ms --------------------
double get_time_ms(){
    struct timeval t;
    gettimeofday(&t, NULL);
     return t.tv_sec ;

} // ------------ End -------------------