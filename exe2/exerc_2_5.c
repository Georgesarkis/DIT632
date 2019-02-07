/*====================================
File name: exerc_2_5.c
Date: 2019-02-05
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [<Ass code 1-4> <abc>] Important , No code no exercise points !
======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100
#define MAXNUMBER 20

void create_random( int *tab);
// Use pointer to fill the table
void count_frequency(int *tab, int *freq);
// Use pointer
void draw_histogram(int *freq);
//  Use pointer

int main ( void){
    int  table[MAX], n ;
    int frequency[MAXNUMBER];
    create_random(table);

    for(n = 0; n < MAXNUMBER; n++) {
        frequency[n] = 0;
    }

    count_frequency(table, frequency);

    draw_histogram(frequency);
}

void create_random(int *tab) {
     int i = 0, n = 0;
     for(i = 0; i<MAX; i++) {
        n = rand() % MAXNUMBER;
        tab[i] = n;
     }
}

void count_frequency(int *tab, int *freq) {
    int i = 0;
    for(i = 0; i < MAX; ++i) {
        freq[ tab[i] ] += 1;
    }
}


void draw_histogram(int *freq) {
    int i = 0, j = 0;
    for(i = 0; i < MAXNUMBER; i++) {
        printf("%d ", i);
        for(j = 0; j < freq[i]; j++) {
            printf("%s", "x");
        }
        printf("\n");
    }
}