/*====================================
File name: exerc_2_6.c
Date: 2019-02-05
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [<Ass code 1-4> <abc>] Important , No code no exercise points !
======================================*/

#include <stdio.h>

void printArray(int list[], int max);
void initQue (int list [], int max);
int input (int list [] , int number, int max);
int output( int list[], int max);

void main(){
	int max = 5;
	int list[max];
	initQue(list,max);
	printArray(list,max);
	input(list,4,max);
	input(list,6,max);
	input(list,7,max);
	input(list,8,max);
	printArray(list,max);
	output(list,max);
	printArray(list,max);
}
 
void printArray(int list[], int max){
	for(int i = 0;i < max ; i++){
		printf("%d" , list [i]);
	}
	printf("\n");
}

void initQue (int list [], int max) {
	for(int i = 0; i < max ; i++){
		list[i] = -1;
	}	
}

int input (int list [] , int number, int max){
	for(int i = 0; i < max ; i++){
		if(list[i] == -1){
			list[i] = number;
			return 0;
		}
	}
}

int output( int list[], int max){
	int firstValue = list[0];
	for(int i = 0; i < max-1 ; i++){
		list[i] = list[i+1];
	} 
	list[max] = -1;
	return firstValue;
}