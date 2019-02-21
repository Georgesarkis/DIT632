/*====================================
File name: exerc_3_1.c
Date: 2019-02-11
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [25780]
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
  if(arge == 2) {// && (int)(argv[1] - '0') <= 188 
    if(argv[1][strspn(argv[1] , "0123456789ABCDEFabcdef")] == 0){
      BYTE banana;
    
      volatile unsigned char b1;
      char* asd = "0x";

      sscanf(argv[1], "%p", &b1);

      banana.brake2 |= b1;
      banana.brake1 |= (b1 >> 1);
      banana.key_pos |= (b1  >> 2);
      banana.gear_pos |= (b1 >> 4);
      banana.engine_on |= (b1 >> 7);
      if(banana.gear_pos > 3 || banana.key_pos > 2 ){
        printf("Invalid input banana");
        return 0;
      }
      printf("Name               Value\n");
      printf("------------------------\n");
      printf("engine_on             %d\n" , banana.engine_on);
      printf("gear_pos              %d\n" , banana.gear_pos);
      printf("key_pos               %d\n" , banana.key_pos);
      printf("brake1                %d\n" , banana.brake1);
      printf("brake2                %d\n" , banana.brake2);
    }
    else{
      printf("Invalid input");
    }
  }
  else{
    printf("too many or too little arg.");
  }
    return 0;   
}
 