


/*
 * Resources:
 * https://learn.adafruit.com/circuit-playground-music/using-the-circuit-playground-speaker
 * https://learn.adafruit.com/circuit-playground-bike-light/hello-neopixel
 * https://learn.adafruit.com/circuit-playground-music/the-sound-of-music
 * https://cdn-learn.adafruit.com/downloads/pdf/circuit-playgrounds-motion-sensor.pdf
*/


#include <Adafruit_CircuitPlayground.h>
#include "notes.h"

const int speaker = 5;       
const int leftButton = 4;   
const int rightButton = 19;
bool soundReset = false; 
int rightButtonCounter = 0;
int melody[] = {                           
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 };
  float Z, X, Y;
void setup() {
  CircuitPlayground.begin();
  pinMode(speaker, OUTPUT);     
  pinMode(leftButton, INPUT);  

}

void loop() {
  delay(2000);
  Z = CircuitPlayground.motionZ();
  Serial.print(" Z value= ");
  Serial.print(Z);
  Y = CircuitPlayground.motionY();
  Serial.print(" Y value= ");
  Serial.print(Y);
   X = CircuitPlayground.motionX();
  Serial.print(" X value= ");
  Serial.print(X);
  soundReset = rightButtonCounter == 2 ? true : false;
  
  if( Z < -0.7 && soundReset==false){
    for (int thisNote = 0; thisNote < 8; thisNote++) { 
        CircuitPlayground.playTone(melody[thisNote], 100);
    }
  }
  if(digitalRead(leftButton)) {   
    CircuitPlayground.setPixelColor(0, 0xbe0aff);
    delay(100);
    CircuitPlayground.setPixelColor(1, 0x580aff);
    delay(500);
    CircuitPlayground.setPixelColor(2, 0x147df5);
    delay(500);
    CircuitPlayground.setPixelColor(3, 0x0aefff);
    delay(500);
    CircuitPlayground.setPixelColor(4, 0x0aff99);
    delay(500);
    CircuitPlayground.setPixelColor(5, 0xa1ff0a);
    delay(500);
    CircuitPlayground.setPixelColor(6, 0xdeff0a);
    delay(500);
    CircuitPlayground.setPixelColor(7, 0xffd300);
    delay(500);
    CircuitPlayground.setPixelColor(8, 0xff8700);
    delay(500);
    CircuitPlayground.setPixelColor(9, 0xff0000);  
  }
  if(digitalRead(rightButton)) { 
    rightButtonCounter +=1;
    CircuitPlayground.setPixelColor(0, 0x000000);
    CircuitPlayground.setPixelColor(1, 0x000000);
    CircuitPlayground.setPixelColor(2, 0x000000);
    CircuitPlayground.setPixelColor(3, 0x000000);
    CircuitPlayground.setPixelColor(4, 0x000000);
    CircuitPlayground.setPixelColor(5, 0x000000);
    CircuitPlayground.setPixelColor(6, 0x000000);
    CircuitPlayground.setPixelColor(7, 0x000000);
    CircuitPlayground.setPixelColor(8, 0x000000);
    CircuitPlayground.setPixelColor(9, 0x000000);                     
  }

}
