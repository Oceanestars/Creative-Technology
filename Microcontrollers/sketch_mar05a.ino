//https://learn.adafruit.com/circuit-playground-fruit-drums/basic-print
#include <Adafruit_CircuitPlayground.h>

int ledPin = 9;

void setup() {}

void loop() {
  int temp = CircuitPlayground.temperatureF();
  Serial.println(temp);
  if(temp < 65){
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) { 
      analogWrite(ledPin, fadeValue);
      delay(30);
    } 
   }
}
