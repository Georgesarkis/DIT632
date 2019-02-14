/*====================================
File name: exerc_3_1.c
Date: 2019-02-11
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [20209]
======================================*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

enum DIRECTION {N,O,S,W};

typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

void Move(ROBOT * robot);
void Turn(ROBOT * robot);
void printRobot(ROBOT * robot);

int main (){
    int x = -1,y = -1;
    char directions[MAX];
    printf("Welcome! please provide starting coordinations for the robot \n");
    while(1){
        while(!(x >= 0 && x <= 99)){
            printf("Please provide X:\n");
            scanf("%d", &x);
        }
        while(!(y >= 0 && y <= 99)){
            printf("Please provide Y:\n");
            scanf("%d", &y);
        }
        ROBOT * robot = (ROBOT*)malloc(sizeof(ROBOT));;
        robot ->xpos = x;
        robot ->ypos = y;
        robot ->dir = N;
        printf("Please provide direction of the robot with Ms and Ts:\n");
        scanf("%s", directions);
        for(int i = 0 ; i < strlen(directions) ; i++){
        char dir =  directions[i];
        if(dir == 'm'){
            Move(robot);
        }else{
            Turn(robot);
        }
        }
        printRobot(robot);
        char input;
        printf("do you want to play again?");
        scanf("%s" , &input);
        if(input == 'n'){
            return 0;
        }
    
    }
    
    return 0;
}

void Move(ROBOT * robot){
    if(robot->dir == N){
        robot->xpos++;
    }else if(robot ->dir == O){
        robot ->ypos++;
    }else if(robot->dir == S){
        robot ->xpos--;
    }else{
        robot -> ypos--;
    }
}
void Turn(ROBOT * robot){
    if(robot -> dir == N){
        robot -> dir = O;
    }else if(robot -> dir == O){
        robot -> dir = S;
    }else if(robot -> dir == S){
        robot -> dir = W;
    }else{
        robot -> dir = N;
    }
}

void printRobot(ROBOT * robot){
    printf("New position of the robot is X: %d and Y:%d and the direction is %d\n" , robot-> xpos , robot -> ypos , robot -> dir);
}