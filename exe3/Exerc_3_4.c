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
    PERSON ppost;
    char p_name[20];
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
           // Dummy Record
            strcpy(ppost.firstname, "John");
            strcpy(ppost.famnamne, "Doe"); 
            strcpy(ppost.pers_number, "199101015452"); 
            write_new_file(&ppost);
            printf("You created a new file 'test.dat' " );
         break;
      case 2 :
           ppost=input_record(); 
           append_file(&ppost);
           printf("You added a new person to 'test.dat' " );
           break;
      case 3 :
        printf("Input person name\n");
        scanf("%s", &p_name );
        search_by_firstname(p_name);
         break;
      case 4 :
         printfile();
         break;
    
      default :
         printf("Exiting program...." );
   }
   
   
    return(0);
}

void write_new_file(PERSON *inrecord) {
    FILE *fp;
    fp = remove("test.dat");
    fp = fopen("test.dat", "wb");
    
    fwrite(inrecord, sizeof(PERSON), 1, fp);
    fclose(fp);
    
}

PERSON input_record( void) {
    PERSON person;
    printf("Input first name\n");
    scanf("%s", person.firstname ); 
    printf("Input family name\n");
    scanf("%s", person.famnamne );
    printf("Input personal number\n");
    scanf("%s", person.pers_number);
   
    return person;
}

// appends a new person to the file
void append_file(PERSON *inrecord) {   
    FILE *fp;
    fp = fopen("test.dat", "ab");
    fwrite(inrecord, sizeof(PERSON), 1, fp);
    fclose(fp);
}

void search_by_firstname(char *name) {
    PERSON person;
    FILE *fp;
    fp = fopen("test.dat", "r");   
    
    while (fread(&person, sizeof(PERSON), 1, fp) != '\0') {
        if(strcmp(person.firstname, name) ==0 || strcmp(person.famnamne,name) == 0) {
            printf("First name: %s\tLast name: %s\tPersonal number: %s\n", person.firstname, person.famnamne, person.pers_number);
        } 
    } 
    
    fclose(fp);
}

// print out all persons in the file 
void printfile(void) {
    PERSON person;
    FILE *fp;
    fp = fopen("test.dat", "rb");
    
    printf("All the person records in the file:\n");
      while (fread(&person, sizeof(PERSON), 1, fp) != '\0') {
      printf("First name: %s\tLast name: %s\tPersonal number: %s\n", person.firstname, person.famnamne, person.pers_number);
            
   }
   fclose(fp);
}
