/*====================================
File name: exerc_3_3.c
Date: 2019-02-11
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [20209]
======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Konstanter ####
#define MAX 5;

// ##### Typedefs####
typedef struct q{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Funcion declarations  #####
REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE * temp, int data);

//###### Main program #######
int main(int argc, char *argv[]){
    int nr=0;
    REGTYPE *akt_post , *head=NULL;
    srand( time(0));  //   Random seed 
    head=random_list();
  /*   akt_post=head;
    while( akt_post!=NULL){
        printf("\n Post nr %d : %d" , nr++, akt_post -> number);
        akt_post = akt_post -> next;
    }  

  /* ---Free of allocated memory ---
  while((akt_post=head)!=NULL){
      head=akt_post->next;
      //free(akt_post);
    }  
*/
    return 0;
}


REGTYPE* random_list(void ){
    
    REGTYPE *top, *old, *item;
    int rnadom = rand() % 100;
    printf("%d" , rnadom);
    top ->number = rnadom;
     printf("%d" , top -> number);
    top ->next = NULL;
    top ->prev = NULL;

    return(top);
}


//==========================================================
REGTYPE* add_first(REGTYPE* temp, int data){
    // Adds a record first i list and set the field tal to data}
}