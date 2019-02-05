/*====================================
File name: exerc_2_3.c
Date: 2019-02-05
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [<Ass code 1-4> <abc>] Important , No code no exercise points !
======================================*/

#include <string.h>
#include <stdio.h>

void WithStrcmp(char str1 [], char str2 []);
void WithoutStrcmp(char Str1[] , char Str2[]);

void main(int argc, char **argv){
	WithStrcmp(argv[1],argv[2]);
	WithoutStrcmp(argv[1],argv[2]);
}

void WithStrcmp(char str1 [], char str2 []){
	int val;
	val = strcmp(str1,str2);
	if(val == 0){
		printf("strings are the same with strcmp funcation \n");
	}
}

void WithoutStrcmp(char Str1[] , char Str2[]){
	int bool = 0;
	if(strlen(Str1) == strlen(Str2)){
		for(int i = 0;i < strlen(Str1); i++){
			if(Str1[i] =! Str2[i]){
				bool = 1;
			}
		}
	}
	else{
		bool = 1;
	}
	if(bool == 0){
		printf("str1 is equal to str2 without the strcmp \n");
	}
}