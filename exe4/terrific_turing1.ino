// ------- Program skeleton for exerc 4.3 AT ----
// ------- File skeleton_4_3_AT.txt ----------------//
#include <avr/io.h>
#include <util/delay.h>
#define REG8(x) *((unsigned char *) (x))     
// A macro to use for IO R/W
#define OUT_PORTD      0x2B
#define IN_PORTB       0x23
#define DDR_D          0x2A
#define DDR_B          0x24
#define BLINK_DELAY_MS       800
int main (void){
    unsigned char code;
    unsigned char incode;
    // If use of simple pointer and not macro REG8
    unsigned char *portd;
    unsigned char *portb;
    portd=(unsigned char *)0x002B; 
    //Must do as this
   // *portd=0;  //If use of pointer for IO R/W
    //  set  PORTD for output, set bit gives out
    REG8(DDR_D)=0xFF;
    //  set  PORTB for input, clr bit gives inbit
    REG8(DDR_B)=0x00;
    //portd << 3;
	int i = 0;
    while(1){
      portb=(unsigned char *)0x0023; 
      if(*portb == 1){
        *portd |= (1 << i);
        if(i!= 0){
          *portd = *portd & ~(1 << i-1);
        }
      }
      else{  
  		*portd = *portd & ~(1 << i);
      }
	  i++;
      if(i == 8){
        *portd = *portd & ~(1 << i-1);
      	 i= 0;
      }
      _delay_ms(BLINK_DELAY_MS); // In util/delay.h

    }
}
