#include <stdio.h>

// Own function
void copyString() {

    char str1[20];
    char str2[20];
    char i;

    printf("Input string 1: ");
    scanf("%[^\n]s",str1);

    for(i = 0; str1[i] != '\0'; ++i)
    {
        str2[i] = str1[i];
    }

    str2[i] = '\0';
    printf("String 2: %s", str2);


}

int main(int argc,  char *argv[]) {

	// strcpy() function
        char str1[20];
	   char str2[20];
	   if (argc > 1) {
		   fgets(str1, 20 , stdin);
		   strcpy(str2, str1);
		  	   printf("String 2 : %s", str2);
	   } else {
		   printf("Input string 1: ");
			  scanf("%[^\n]s",str1);
			   strcpy(str2, str1);
			   printf("String 2 : %s", str2);

			  // copyString();
	   }


	   return(0);


}
