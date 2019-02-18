/*====================================
File name: exerc_3_1.c
Date: 2019-02-11
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [20209]
======================================*/
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#define MAX 1000

typedef struct{
  unsigned char engine_on : 1;
  unsigned char gear_pos : 3;
  unsigned char key_pos : 2;
  unsigned char brake1 : 1;
  unsigned char brake2 : 1;
} BYTE;

int main (int arge, char *argv[]){
 // if(arge == 1 && strlen(argv) == 5) {
    BYTE banana;
   
    volatile unsigned char b1;
    char* asd = "0x";

    sscanf(argv[1], "%p", &b1);

    banana.brake2 |= b1;
    banana.brake1 |= (b1 >> 1);
    banana.key_pos |= (b1  >> 2);
    banana.gear_pos |= (b1 >> 4);
    banana.engine_on |= (b1 >> 7);
    printf("Name               Value\n");
    printf("------------------------\n");
    printf("engine_on             %d\n" , banana.engine_on);
    printf("gear_pos              %d\n" , banana.gear_pos);
    printf("key_pos               %d\n" , banana.key_pos);
    printf("brake1                %d\n" , banana.brake1);
    printf("brake2                %d\n" , banana.brake2);
    return 0;   

}
 