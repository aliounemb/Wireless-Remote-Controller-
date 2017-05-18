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
#define ZBUTTON 2

//short zButtonPin = A4;

short analogVerticalPin = A2;
short analogHorizontalPin = A3;



short RF24cePin = 9;
short RF24csnPin = 10;

int msg[3]; //4
RF24 radio(RF24cePin, RF24csnPin);
const uint64_t pipe = 0xE8E8F0F0E1LL;


void setup() {
  radio.begin();
  radio.openWritingPipe(pipe);


 // pinMode(zButtonPin, INPUT_PULLUP);
  pinMode(analogVerticalPin, INPUT);
  pinMode(analogHorizontalPin, INPUT);
  

  Serial.begin(9600);
}



void loop() {
  delay(DELAY);
  
  msg[VERTICAL] = map(analogRead(analogVerticalPin), ANALOGMINVERTICAL, ANALOGMAXVERTICAL, VERTICALMIN, VERTICALMAX);
  msg[HORIZONTAL] = map(analogRead(analogHorizontalPin), ANALOGMINHORIZONTAL, ANALOGMAXHORIZONTAL, HORIZONTALMIN, HORIZONTALMAX);

  msg[ZBUTTON] = 1;
  radio.write(msg,sizeof(8));

}
