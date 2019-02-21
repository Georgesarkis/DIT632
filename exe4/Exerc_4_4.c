/*====================================
File name: exerc_3_1.c
Date: 2019-02-11
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [25924]
======================================*/
/* *******************************
Program file : bit_manage_function.c
Peter Lundin / 2016-01-97
For test IO program function 

******************************** */

#include <time.h>
#include <stdio.h>

void f_delay(int);
unsigned char random_inport( void);
void printport( int);
void func(int port , int newPort);


int main(){
	int nr;
	unsigned char port;
		unsigned char newPort;
	srand(time(0)); 
	for ( nr=0; nr < 10; nr++){
	   port = random_inport();
	   printport( port);
	   func(port , newPort);
	   f_delay(5);
	}
	return(0);
}

void func(int port , int newPort){	
	if(port & (1 << 7)){
	}else{
		printf("the port value %d AND" , port);
		unsigned char bb = port & (1<< 0) | port & (1<< 1)|   port & (1<< 2)| port & (1<< 3) ;
		printf ("the key number pressed is : %x\n", bb);
	}
}

void f_delay( int tenth_sec){

   clock_t start_t, end_t;
   long int i;
   start_t = clock();
   do{
      for(i=0; i< 10000000; i++);
      end_t = clock();
   }while ((end_t - start_t) < (tenth_sec*CLOCKS_PER_SEC)/10);
   return;
}

unsigned char random_inport( void){
	unsigned char inport = 0;
	inport=  rand() % 256;
	return (inport);
}

void printport( int portvalue){
	int binchar[8], rest,j, i=0;
	rest = portvalue;
    while(rest!=0){
         binchar[i++]= rest % 2;
         rest = rest / 2;
    }
	// Fill to 8 bits 
    while( i<8){
		binchar[i++]=0;
	}
	// Print bits and at the end corresponding decimal value
    for(j =i-1 ;j > -1;j--)
         printf("  %d",binchar[j]);
	printf(" --------Porten value = %d  \n", portvalue);
	return ;
}	