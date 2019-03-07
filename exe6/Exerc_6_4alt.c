#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
int program_time = 0; // The global time, start value 0
void *time_count();
void *read_inport();
double get_time_ms();

int main(){
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
            timeNow == program_time;
            printf("%d\n"  ,program_time);
        }
    }
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
            program_time++;
        }    
    }
// exit thread;
    pthread_exit(NULL); 
} //End------------------------------------
void *read_inport(){
    while (program_time<50){
        if(program_time % 5 == 0){
            printf("read import");
        }   
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