/*====================================
File name: exerc_2_4.c
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

// palindrome function
void palindrome(char str[])
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;

    // keep checking if the values are the same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
        	// if at any point values are not the same, its not a palindrome
            printf("%s is not a palindrome.\n", str);
            return;
        }
    }
    printf("%s is palindrome.\n", str);
}


int main()
{
	char str[20];
	printf("Input string: ");
	scanf("%s",str);
    palindrome(str);

    return 0;
}
