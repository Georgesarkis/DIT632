/*====================================
File name: exerc_3_1.c
Date: 2019-02-11
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [25767]
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
  if(arge == 2 && strlen(argv[1]) == 5) {
    argv[1];
    BYTE banana;
    if(argv[1][0] == '0' || argv[1][0] == '1'){
      banana.engine_on = argv[1][0];
      printf("%x" , banana.engine_on);
    }
    else{
      printf("out of bounds\n");
      return 0;
    }
    if(argv[1][1] >= 48 && argv[1][1] < 52 ) {
      banana.gear_pos = argv[1][1];
      printf("%x" , banana.gear_pos);
    }
    else{
      printf("out of bounds\n");
      return 0;
    }
    if(argv[1][2] >= 48 && argv[1][2] <= 50) {
      banana.key_pos =argv[1][2];
      printf("%x" , banana.key_pos);
    }
    else{
      printf("out of bounds\n");
      return 0;
    }
    if(argv[1][3] == '0' || argv[1][3] == '1') {
      banana.brake1 = argv[1][3];
      printf("%x" , banana.brake1);
    }
    else{
      printf("out of bounds\n");
      return 0;
    }
    if(argv[1][4] == '0' || argv[1][4] == '1') {
      banana.brake2 = argv[1][4];
      printf("%x\n" , banana.brake2);
    }
    else{
      printf("out of bounds\n");
      return 0;
    } 
    unsigned char b;
    b |= banana.brake2;
    b |= (banana.brake1 << 1);
    b |= (banana.key_pos << 2);
    b |= (banana.gear_pos << 4);
    b |= (banana.engine_on << 7);
    printf("%d\n" , b);
    printf("%X\n" , b);
  }else{
    printf("too many or too little arg or input a value as 12211 without spaces.");
  }
 
}