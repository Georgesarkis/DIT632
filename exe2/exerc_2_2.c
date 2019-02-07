/*====================================
File name: exerc_2_2.c
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
#define MAX 99

int main()
{
	int byteSize = 0;
	int arraySize;
	int array[MAX];
	for(int i =0; i < MAX ; i ++){
		array[i] = (rand() % 99) + 1;
	}
	
	arraySize = sizeof(array);
	byteSize = sizeof(array[0]);
	printf("\nThe value of the label array(address) is : %p", array);
	printf("\nFirst integer in the array is (array[0]) : %d" , array[0]);
	printf("\nThe size of an integer (number of bytes) is : %d" , byteSize);
	printf("\nThe size of the whole array is : %d\n", arraySize);
	for(int j = 0; j < MAX; j++) {
        printf("int value is : %d", *(array + j));
		printf(" and double value is : %f\n", (double)*(array + j));
    }
	
	return 0;
}
