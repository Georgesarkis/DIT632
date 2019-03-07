/*====================================
File name: exerc_3_1.c
Date: 2019-02-11
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
int ReadSensorA();
int ReadSensorB();
int ReadSensorS1();
int ReadSensorS2();

unsigned char status  = (unsigned char *)ML13_Status;
unsigned char control = (unsigned char *)ML13_Control;


int main(){
    while(1){
        if(ReadSensorA() == 1){
            status |= 1;
            OpenDoor();
            Delay();
            CloseDoor();
            status =  status & 0 ;
        }
        else if(ReadSensorB() == 1){
            status |= (1 << 1);
            OpenDoor();
            Delay();
            CloseDoor();
            status =  status & (0<< 1) ;
        }
    }
}

void OpenDoor(){
    control |= 1;
    status |= (1 << 6);
    while(ReadSensorS1() != 1 ){
    }
    status |= (1<< 3);
    control &= 0;
}

void CloseDoor(){
    control |= (1 << 1);
    status =  status & (0<< 3) ;
    status =  status & (0<< 6) ;
    status |= ( 1 << 7);
    while(ReadSensorS2() != 1){
        if(ReadSensorA() == 1 || ReadSensorB() == 1){
            control &= (0 << 1);
            status &= (0 << 7);
            OpenDoor();
            Delay();
            control |= (1 << 1);
            status =  status & (0<< 3) ;
            status =  status & (0<< 6) ;
            status |= ( 1 << 7);
        }
    }
    control &= (0 << 1);
    status =  status & (0<< 7) ;
}

void Delay(){
    for(int i = 0; i < 10000 ; i++){
        
    }
}

int ReadSensorA(){//of the sensor A is active or sensor B is active it will return 1
    return 1;
}
int ReadSensorB(){//of the sensor A is active or sensor B is active it will return 1
    return 1;
}

int ReadSensorS1(){
    return 1;
}
int ReadSensorS2(){
    return 1;
}