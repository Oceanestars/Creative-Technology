
/*
 * Resources:
 * https://learn.adafruit.com/circuit-playground-music/using-the-circuit-playground-speaker
 * https://learn.adafruit.com/circuit-playground-music/the-sound-of-music
 * https://musescore.com/discord5321/closer-the-chainsmokers-ft-halsey
*/


#include <Adafruit_CircuitPlayground.h>
#include "notes.h"
#define CAP_THRESHOLD   65

int melody[] = {                           
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4,NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4};

int closer[] = {                           
  NOTE_GS4, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_AS4, NOTE_GS4,NOTE_GS4, NOTE_C5, NOTE_C5, NOTE_GS4, NOTE_GS4,NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4,NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_AS4,NOTE_GS4,NOTE_GS4,NOTE_C5, NOTE_C5, NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_AS4, NOTE_GS4 };
float color;

boolean capButton(uint8_t pad) {
  if (CircuitPlayground.readCap(pad) > CAP_THRESHOLD) {
    return true;
  } else {
    return false;
  }
}

const int speaker = 5;       
const int leftButton = 4;   
const int rightButton = 19;
bool soundReset = false; 
int rightButtonCounter = 0;
  
void setup() {
  Serial.begin(9600); // Starting the serial monitor
  CircuitPlayground.begin();
  pinMode(speaker, OUTPUT);     
  pinMode(leftButton, INPUT);  
}

void loop() {
  if (capButton(0)) {
    Serial.println("Pin 0 is activated!");  
    for (int i = 0 ; i < 32; i++) { 
      color = i % 2 == 0 ? 0x580aff : 0x000000;
      CircuitPlayground.playTone(closer[i], 100);
      delay(110);
      for(int j = 0 ; j < 10; j++) {
        CircuitPlayground.setPixelColor(j, color);
       }
    }
  }

    if (capButton(6)) {
    Serial.println("Pin 0 is activated!");  
    for (int i = 0 ; i < 14; i++) { 
        if(i == 7){
              delay(200);
        }
        CircuitPlayground.playTone(melody[i], 100);
        if( melody[i] == NOTE_C4)
        {
          color = 0xbe0aff;
          Serial.print("C4 ");
        }
        if( melody[i] == NOTE_G4)
        {
          color = 0xff0000;
          Serial.print("G4 ");
        }
        if( melody[i] == NOTE_D4)
        {
          color = 0x147df5;
          Serial.print("D4 ");
        }
        if( melody[i] == NOTE_A4)
        {
          color = 0xa1ff0a;
          Serial.print("A4 ");
        }
        if( melody[i] == NOTE_E4)
        {
          color = 0xff8700;
          Serial.print("E4 ");
        }
        if( melody[i] == NOTE_F4)
        {
          color = 0xa1ff0a;
          Serial.print("F4 ");
        }
        for(int i = 0 ; i < 10; i++) {
          CircuitPlayground.setPixelColor(i, color);
        }
        delay(110);
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
