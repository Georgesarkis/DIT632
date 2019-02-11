/*====================================
File name: exerc_3_2.c
Date: 2019-02-11
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [20209]
======================================*/

#include <stdio.h>

int search_number( int number, int tab[], int size);

int main(){
    int num = 0;
    int test [] = { 1,2,34,5,67,3,23,12,13,10};
    int position = search_number(num , test , 10);
    if(position == 0){
        printf("could not find the %d in the array\n" , num);
    }
    else{
        printf("We found the number %d in the array\n" , num);
    }
}

int search_number( int number, int tab[], int size){
    for(int i = 0 ; i < size ; i++){
        if(tab[i] == number){
            return 1;
        }
    }
    return 0;
}