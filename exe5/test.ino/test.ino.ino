#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define G 7
#define D1 8
#define D2 9

const int segs[7] = { A, B, C, D, E, F, G };
const byte numbers[10] = { 0b0111111, 0b00000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101,
0b1111101, 0b0000111, 0b1111111, 0b1101111 };

int a, b;
int max;

void setup() {
  pinMode(0 , OUTPUT);
  pinMode(1 , OUTPUT);
  pinMode(2 , OUTPUT);
  pinMode(3 , OUTPUT);
  pinMode(4 , OUTPUT);
  pinMode(5 , OUTPUT);
  pinMode(6 , OUTPUT);
  pinMode(7 , OUTPUT);
  pinMode(8 , OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13 , INPUT);
  pinMode(12, INPUT);
  //pinMode(13, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  float val = analogRead(0);
  int temp = ((val / 1024) * 5000) / 10;

  if(max < temp) {
        max = temp;
  }

    a = digitalRead(13);
    b = digitalRead(12);
    while(a == LOW && b == LOW){
      a = digitalRead(13);
      b = digitalRead(12);
      Serial.println("dip switch on");
      Serial.println(max);
      writeDigit2(numbers[ (int)(max % 10) ]);
      delay(5);
      writeDigit1(numbers[ (int)(max / 10) ]);
      delay(5);
    } //else {
      Serial.println("dip switch off");
  
      
      Serial.println(temp);

      

    unsigned long startTime = millis();
    for (unsigned long elapsed=0; elapsed < 600; elapsed = millis() - startTime) {
   
    
    writeDigit2(numbers[ (int)(temp % 10)] );
    delay(5);
    writeDigit1(numbers[ (int)(temp / 10)] );
    delay(5);
  //}
  }
  }

void writeDigit1(byte number) {
  digitalWrite(D2, HIGH);
  digitalWrite(D1, LOW);
  lightNumber(number);
}

void writeDigit2(byte number) {
  digitalWrite(D2, LOW);
  digitalWrite(D1, HIGH);
  lightNumber(number);
}

void lightNumber(byte number) {
  for (int i = 0; i < 7; i++) {
    int bit = bitRead(number, i);
    digitalWrite(segs[i], bit);
  }
}
