/*====================================
File name: exerc_3_2.c
Date: 2019-02-11
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [16754]
======================================*/

#include <stdio.h>
#include <string.h>

int search_number( int number, int tab[], int size);
void sort(int number, int tab[]);


int main(){
    int num = 10;
    int test [] = { 1,2,34,5,67,3,23,12,13,10}; // 1 2 3 5 10 12 13 23 34 67
    int position = search_number(num , test , 10);
    if(position == -1){
        printf("could not find the %d in the array\n" , num);
    }
    else{
        printf("We found the number %d in the array at position %d.\n" , num, position );
    }

    printf("sorting...\n");
    sort(10, test);
    for(int a = 0; a<10; a++) {
        printf("%d\n", test[a]);
    }
    return 0;
}

int search_number( int number, int tab[], int size){
    for(int i = 0 ; i < size ; i++){
        if(tab[i] == number){
            return i;
        }
    }
    return -1;
}

void sort(int number, int tab[]) {
    int k = 0, i = 0, j = 0, min_val, min_val_pos;
    int tmp=0;
    for(k = 0; k < number; k++) {
        min_val = tab[k];
        
        for(i = k; i < number; i++) {
            if(min_val > tab[i]) {
                min_val = tab[i];
                min_val_pos = i;
            }
        }
        if(min_val != tab[k]) {
            tmp = tab[k];
            tab[k] = min_val;
            tab[min_val_pos] = tmp;
        }
    }
}