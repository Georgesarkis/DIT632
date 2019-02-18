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
typedef struct{
  unsigned char engine_on : 1;
  unsigned char gear_pos : 3;
  unsigned char key_pos : 2;
  unsigned char brake1 : 1;
  unsigned char brake2 : 1;
} BYTE;

int main (int arge, char *argv[]){
 // if(arge == 1 && strlen(argv) == 5) {
    argv[1];
    BYTE banana;
    banana.engine_on = argv[1][0];
    printf("%x" , banana.engine_on);
    banana.gear_pos = argv[1][1];
    printf("%x" , banana.gear_pos);

    banana.key_pos =argv[1][2];
    printf("%x" , banana.key_pos);

    banana.brake1 = argv[1][3];
    printf("%x" , banana.brake1);

    banana.brake2 = argv[1][4];
    printf("%x\n" , banana.brake2);

    unsigned char b;
    b |= banana.brake2;
    b |= (banana.brake1 << 1);
    b |= (banana.key_pos << 2);
    b |= (banana.gear_pos << 4);
    b |= (banana.engine_on << 7);
    printf("%d\n" , b);
    printf("%X\n" , b);
  /*}else{
    printf("too many or too little arg.");
  }*/
 
}