/*====================================
File name: exerc_6_3alt.c
Date: 2019-03-12
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [25924]
======================================*/


#include <time.h>
#include <stdio.h>
#define ML13_Status 0x0B00
#define ML13_Control 0x0B00 

void Delay();
void OpenDoor();
void CloseDoor();

unsigned char status  = (unsigned char *)ML13_Status;
unsigned char control = (unsigned char *)ML13_Control;


int main(){
    while(1){
        if(status & (1 << 0) == 1){
            OpenDoor();
            Delay();
            CloseDoor();
        }
        else if(status & (1 << 1) == 1){
            OpenDoor();
            Delay();
            CloseDoor();
        }
    }
}

void OpenDoor(){
    control |= 1; // set bit 0 to indicate that we're opening the dorr
    while(status & (1 << 6) == 1 ){ // wait until the door is opened by checking if the bit 6 is set

    }
    control &= 0; // unset bit 0
}

void CloseDoor(){
    control |= (1 << 1); // set bit 1 to indicate we're closing the door
    while(status & (1 << 7) == 1){ // wait until the door is closed by checking if bit 7 is set or unset
        if(status & (1 << 0) == 1 || status & (1 << 1) == 1){ // if anyone tries to go in while the door is closing, the sensor detects them
            control &= (0 << 1); // stop the closing sequence
            OpenDoor(); // open door again
            Delay(); 
            control |= (1 << 1); // start closing again
        }
    }
    control &= (0 << 1); // set bit 1 as 0 
}

void Delay(){
    for(int i = 0; i < 10000 ; i++){
        
    }
}
