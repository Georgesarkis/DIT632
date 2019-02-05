#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void readPersnr(char *person);
int controlDigit(const char *persnr);

void main() {
    char input_nr[10];
    
    readPersnr(input_nr);
    
}

void readPersnr(char *person) {
    //int pers_nr = 0;
    while(1) {
        printf("Enter a personal number\n");
        scanf("%s", person);
        if(person == "q") {
            break;
        }
        long int pers_nr = strtol(person, NULL, 10);
        printf("%ld\n", pers_nr); 

        char month[2];
        month[0] = person[2]; 
        month[1] = person[3];
        printf("%s\n", month);
        int monthNr = strtol(month, NULL, 2);
        printf("%d\n", monthNr);
        if(monthNr >= 1 && monthNr <= 12) {
            char day[2];
            day[0] = person[4];
            day[1] = person[5];
            printf("%s\n", day);
        }


    }
}