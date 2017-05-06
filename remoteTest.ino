#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#define ANALOGMINVERTICAL 109
#define ANALOGMAXVERTICAL 914
#define ANALOGMINHORIZONTAL 123
#define ANALOGMAXHORIZONTAL 930

#define VERTICALMIN 0
#define VERTICALMAX 180
#define HORIZONTALMIN 0
#define HORIZONTALMAX 100

#define DELAY 20


#define VERTICAL 0
#define HORIZONTAL 1
#define CBUTTON 2
#define ZBUTTON 3

/*short cButtonPin = A5;
short zButtonPin = A4;

short analogVerticalPin = A3;
short analogHorizontalPin = A2;*/

short cButtonPin = A7;
short zButtonPin = A2;

short analogVerticalPin = A4;
short analogHorizontalPin = A5;

short ledPin = 6;

short RF24cePin = 9;
short RF24csnPin = 10;

int msg[4];
RF24 radio(RF24cePin, RF24csnPin);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int value1 = 0;                  // variable to read the value from the analog pin 0
int value2 = 0;                  // variable to read the value from the analog pin 1
int value3 = 0;

void setup() {
 // radio.begin();
 // radio.openWritingPipe(pipe);

  pinMode(ledPin, OUTPUT);
  pinMode(cButtonPin, INPUT_PULLUP);
  pinMode(zButtonPin, INPUT_PULLUP);
  pinMode(analogVerticalPin, INPUT);
  pinMode(analogHorizontalPin, INPUT);
  
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600); // Other baud rates can be used..
}

int treatValue(int data) {
  return (data * 9 / 1024) + 48;
 }


void loop() {
  /*delay(DELAY);
  
  msg[VERTICAL] = map(analogRead(analogVerticalPin), ANALOGMINVERTICAL, ANALOGMAXVERTICAL, VERTICALMIN, VERTICALMAX);
  msg[HORIZONTAL] = map(analogRead(analogHorizontalPin), ANALOGMINHORIZONTAL, ANALOGMAXHORIZONTAL, HORIZONTALMIN, HORIZONTALMAX);
  if (digitalRead(cButtonPin)) { msg[CBUTTON] = 1;
  } else { msg[CBUTTON] = 0;}
  if (digitalRead(zButtonPin)) { msg[ZBUTTON] = 1;
  } else { msg[ZBUTTON] = 0;}
  
  radio.write(msg,8);*/
   // reads the value of the variable resistor 
  value1 = analogRead(analogVerticalPin);   
  // this small pause is needed between reading
  // analog pins, otherwise we get the same value twice
  delay(100);             
  // reads the value of the variable resistor 
  value2 = analogRead(analogHorizontalPin);   
  value3 = analogRead(cButtonPin);
  //digitalWrite(ledPin, HIGH);           
  delay(value1);
  //digitalWrite(ledPin, LOW);
  delay(value2);
  Serial.print("vertical");
  Serial.println(treatValue(value1));
  Serial.print("horizontal");
  Serial.println(treatValue(value2));
  Serial.print("buttton");
  Serial.println(treatValue(value3));
}
