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
    akt_post=head;
    while( akt_post!=NULL){
        printf("Post nr %d : %d\n" , nr++, akt_post -> number);
        akt_post = akt_post -> prev;
    }
    nr=0;
    int input;
    printf("input a number to add to link:");
    scanf("%d", &input );
    head = add_first(head, input);
    akt_post=head;
    while( akt_post!=NULL){
        printf("Post nr %d : %d\n" , nr++, akt_post -> number);
        akt_post = akt_post -> prev;
    }    
    // ---Free of allocated memory ---
    while((akt_post=head)!=NULL){
      head=akt_post->next;
      free(akt_post);
    }  

    return 0;
}

REGTYPE* random_list(void ){
    int nr = MAX;
    REGTYPE *top = (REGTYPE*)malloc(sizeof(REGTYPE));
    top ->number = rand() % 100;
    top->next = NULL;
    top-> prev = NULL;
    for(int i = 0 ; i < nr -1; i++){
        REGTYPE * link = (REGTYPE*)malloc(sizeof(REGTYPE));
        link -> number = rand()%100;
        top -> next = link;
        link -> prev= top;
        link -> next = NULL;
        top = link;   
    }
    return(top);
}


//==========================================================
REGTYPE* add_first(REGTYPE* temp, int data){
        REGTYPE * link = (REGTYPE*)malloc(sizeof(REGTYPE));
        link -> number = data;
        temp -> next = link;
        link -> prev= temp;
        link -> next = NULL;
        temp = link;  
    return(temp);
}