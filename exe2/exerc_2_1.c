/*====================================
File name: exerc_2_1.c
Date: 2019-02-05
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [<Ass code 1-4> <abc>] Important , No code no exercise points !
======================================*/

#include <stdio.h>
#include <string.h>

void copyString(char str[]);

void main(int argc,  char *argv[]) {
    char str1[20];
	char str2[20];
	if (argc > 1) {
		fgets(str1, 20 , stdin);
		strcpy(str2, str1);
		printf("String 2 : %s", str2);
		printf("String 2 using strcpy : %s\n", str2);
		copyString(str1);
	} else {
		printf("Input string 1: ");
		scanf("%[^\n]s",str1);
		strcpy(str2, str1);
		printf("String 2 using strcpy : %s\n", str2);
		copyString(str1);
	}
}


// Own function
void copyString(char str[]) {

    char str2[20];
    int i;

    for(i = 0; str[i] != '\0'; ++i)
    {
        str2[i] = str[i];
    }

    str2[i] = '\0';
    printf("String 2 using copyString: %s\n", str2);
}