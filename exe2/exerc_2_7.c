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
        if(person[0] == 'q') {
            printf("Exiting...\n");
            return;
        }
        
        int nr_arr[10];
        for(int i = 0; i < 10; i++) {
            nr_arr[i] = person[i] - '0';
        }
        if( (nr_arr[2] == 1 && nr_arr[2] + nr_arr[3] <= 3) || ( nr_arr[2] == 0 && nr_arr[3] <=9 ) ) { // first digit of month is 0 or 1, second digit can be whatever
            printf("Correct month\n");
            if( (nr_arr[4] == 3 && nr_arr[4] + nr_arr[5] <= 4 ) || (nr_arr[4] <= 2 && nr_arr[5] <= 9) ) { //first digit of day should be 0, 1, 2 or 3 second is whatever
                printf("Correct day\nChecking last digit...\n");
                controlDigit(person); //do checksum
            } else {
                printf("Day not correct\n");
            }
        } else {
            printf("Month not correct\n");
        }
    }
}

int controlDigit(const char *persnr) {
    int arr[10]; 
    for(int i = 0; i < 10; i++) {
            arr[i] = persnr[i] - '0';
        }

    int tmp_1 = 0, tmp_2 = 0, result = 0;
    for(int j = 0; j < 9; j++) {
        if(j % 2 == 0) {
            arr[j] *= 2;
            if(arr[j] >= 10) {
                arr[j] = (arr[j] / 10) + (arr[j] % 10); 
            }
        } else {
            arr[j] *= 1;
        }
        result += arr[j];
    }
    if((10 - (result % 10)) == arr[9]) {
        printf("correct last digit\n");
        return 1;
    } else {
        printf("incorrect last digit\n");
        return -1;
    }
}