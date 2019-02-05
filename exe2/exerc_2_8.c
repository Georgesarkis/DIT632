/*====================================
File name: exerc_2_8.c
Date: 2019-02-05
Group nr 05
Members that contribute to the solutions
Sarkisian George
Stanchev Martin
Hassan Mohamad
Demonstration code: [<Ass code 1-4> <abc>] Important , No code no exercise points !
======================================*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>     


#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner( int player );

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in: 
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/

/*
 * computer_choice 
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a 
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle( int player );

/* --------------------- Utilities -------------*/
void clear_stdin();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main()
{
  int pile,			/* This is how many coins we have */
    player,			/* Who is playing? */
    n_coins;			/* Number of coins taken */
  
  srand( time(0) );		/* Setup random */

  printf("Välkommen till NIM by ...");
  
  bool playAgain = true;
 
  while (playAgain){
	  

	  pile = MAX_COINS;		/* Set start values (= init) */
	  player = HUMAN;

	  /* 
	   *  Program main loop 
	   */
	  while( true ) {	

		printf("Det ligger %d  mynt i högen\n", pile );

		if( player == HUMAN ){
		  n_coins = human_choice(pile);      
		}else{
		  n_coins = computer_choice(pile);
		  printf("Computer - Jag tog %d\n", n_coins);      
		}
		pile -= n_coins;
		  
		if( pile <= 1 ){
		  break;
		}
		player = toggle( player );
	  }
	  /*
	   * end main loop
	   */
	   
		write_winner( player );   
  
		playAgain = play_again();
  }
 
  printf("Avslutat\n");

  return 0;
}

/******************************************************
 *
 *  DEFINITIONS
 * 
 ******************************************************/


void clear_stdin()
{
  while( getchar() != '\n' ){
    ;
  }
}

int human_choice(int pile)
{
	int input;
	printf("Input number of coins you want to take between 1 to 3:");
	scanf("%d", &input);

	clear_stdin();

	while(3 < input || input < 1){
		printf("Input number of coins you want to take between 1 to 3:");
		scanf("%d", &input);
		clear_stdin();
	}

	if(input > pile){
		return pile;
	}
	return input;
}

int computer_choice(int pile)
{
	if(pile < 5 ){
		return pile -1;
	}
	else{
        int n = (rand() % 2) +1;
        return n;
	}
}

void write_winner(int player )
{
	if(player == HUMAN){
		printf("Winner is : HUMAN\n");
	}else{
		printf("Winner is : COMPUTER\n");
	}
}

int play_again()
{
	char input;
	printf("Do you want to play again?");
	scanf("%s",&input);
	if(input == 'n' || input == 'N'){
		return false;
	}else{
		return true;
	}
}

int toggle( int player )
{
	if(player == HUMAN){
		return COMPUTER;
	}
	else{
		return HUMAN;
	}
}
