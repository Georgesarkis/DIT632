/*====================================
File name: exerc_3_4.c
Date: 2019-02-11
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [20209]
======================================*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// -----Typedefs -------
typedef struct {
    char firstname[20];
    char famnamne[20];
    char pers_number[13]; // yyyymmddnnnc
}PERSON;

// Function declaration (to be extend) 
PERSON input_record( void);// Reads in a person record.
void write_new_file(PERSON *inrecord); //Creats a file and write a first record
void printfile(void); // print out all persons in the file
void search_by_firstname(char *name);// print out person if in list 
void append_file(PERSON *inrecord);// appends a new person to the file


int main( void){
    PERSON *ppost;
    int input;
    printf("1> Create new file\n");
    printf("2> Add new person record\n");
    printf("3> Search for person\n");
    printf("4> Print out all records in the file\n");
    printf("5> Exit\n ");
    printf("Select task to perform\n");
    scanf("%d", &input );
   switch(input) {
      case 1 :
         write_new_file(ppost);
         printf("You created a new file 'test.bin' " );
         break;
      case 2 :
           append_file(ppost);
           printf("You added a new person to 'test.bin' " );
           break;
      case 3 :
        printf("\n" );
         break;
      case 4 :
         printf("\n" );
         break;
    
      default :
         printf("\n" );
   }
   
   
    return(0);
}

void write_new_file(PERSON *inrecord) {
    // Dummy Record
    inrecord -> firstname == "John";
    inrecord -> famnamne == 'Doe';  
    inrecord -> pers_number == '199101015452';  
    
    FILE *fp;
    fp = remove("test.dat");
    fp = fopen("test.dat", "wb");
    
    
    fwrite(&inrecord, sizeof(PERSON), 1, fp);
    fclose(fp);
    
}
// appends a new person to the file
void append_file(PERSON *inrecord) {
    char fname[20];
    char lname[20];
    char pnumber[13];
    
    printf("Input first name\n");
    scanf("%s", &fname ); 
    printf("Input family name\n");
    scanf("%s", &lname );
    printf("Input personal number\n");
    scanf("%s", &pnumber);
    
    inrecord -> firstname == fname;
    inrecord -> famnamne == lname;
    inrecord -> pers_number == pnumber;
    
    FILE *fp;
    fp = fopen("test.dat", "ab");
    fwrite(&inrecord, sizeof(PERSON), 1, fp);
    fclose(fp);
}

