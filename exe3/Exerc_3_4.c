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
void search_by_firstname( char *name);// print out person if in list 
void append_file(PERSON *inrecord);// appends a new person to the file


int main( void){
    PERSON *ppost;
    char fname[20];
    char lname[20];
    char pnumber[13];
    ppost -> firstname == "John";
    ppost -> famnamne == 'Doe';  
    ppost -> pers_number == '199101015452'; 
    int input;
    printf("Select task to perform");
    scanf("%d", &input );
   switch(input) {
      case 1 :
         write_new_file(ppost);
         printf("You created a new file 'test.bin' " );
         break;
      case 2 :
           printf("Input first name");
            scanf("%s", &fname ); 
          printf("Input family name");
            scanf("%s", &lname );
           printf("Input personal number");
            scanf("%s", &pnumber);
           ppost -> firstname == fname;
           ppost -> famnamne == lname;
           ppost -> pers_number == pnumber;
           append_file(ppost);
           break;
      case 3 :
         printf("\n" );
         break;
      case 4 :
         printf("\n" );
         break;
      case 5 :
         printf("\n" );
         break;
      default :
         printf("\n" );
   }
   
   
    return(0);
}

void write_new_file(PERSON *inrecord) {
    //PERSON *myPerson;
    FILE *fp;
    fp = remove("test.dat");
    fp = fopen("test.dat", "wb");
    // Dummy Record
   // myPerson -> firstname == "John";
//    myPerson -> famnamne == 'Doe';  
  //  myPerson -> pers_number == '199101015452';  
    
    fwrite(&inrecord, sizeof(PERSON), 1, fp);
    fclose(fp);
    
   /* // read func
    fp = fopen("test.bin", "rb");
  fread(&myPerson, sizeof(PERSON), 1,fp);
  printf("a: %s\t \n", myPerson -> firstname);
 
 fclose(fp);
    */
}
// appends a new person to the file
void append_file(PERSON *inrecord) {
    FILE *fp;
    fp = fopen("test.dat", "ab");
    fwrite(&inrecord, sizeof(PERSON), 1, fp);
    fclose(fp);
}
