#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'F','0','E','D'}
};
byte rowPins[ROWS] = {7,6,5,4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {3,2,1,0}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup()
{
lcd.begin(16, 2);               // start lcd
for(int i=0;i<=3;i++);
  lcd.print("Created");
  lcd.setCursor(0,1);
  lcd.print("by Group 5");
  delay(1000);
  lcd.clear();
}


void loop()
{

  customKey = customKeypad.getKey();
  switch(customKey) 
  {
  case '0' ... '9': // This keeps collecting the first value until a operator is pressed "+-*/"
    lcd.print(customKey);
    delay(1000);
lcd.clear();
    break;

  case 'A':
   lcd.print("A");
    delay(1000);
lcd.clear();
    break;

  case 'B':
   lcd.print("B");
    delay(1000);
lcd.clear();
    break;

  case 'C':
   lcd.print("C");
    delay(1000);
lcd.clear();
    break;

  case 'D':
   lcd.print("D");
    delay(1000);
lcd.clear();
    break;

  case 'E':
   lcd.print("E");
    delay(1000);
lcd.clear();
    break;
  case 'F':
    lcd.print("F");
    delay(1000);
lcd.clear();

    break;
  }
}
