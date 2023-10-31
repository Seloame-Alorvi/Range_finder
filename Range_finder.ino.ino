#include "rgb_lcd.h"
rgb_lcd lcd;
//uint8_t serial_rx_pin = 15;
//uint8_t serial_tx_pin = 14;
//HardwareSerial xSerial(1);
//mm_read = 
uint8_t mm_conversion = 41; 
uint8_t inche_conversion =45; 
uint8_t rangeFinder= 39;
void setup() {
//xSerial.begin(9600,SERIAL_8N1,serial_rx_pin,serial_tx_pin);
Serial.begin(9600);
lcd.begin(16,2);
pinMode(inche_conversion,INPUT);

pinMode(mm_conversion,INPUT);
}


void loop(){
  pinMode(rangeFinder,OUTPUT);
  digitalWrite(rangeFinder,LOW);
  digitalWrite(rangeFinder,HIGH);
  delayMicroseconds(2);
  digitalWrite(rangeFinder,LOW);
  pinMode(rangeFinder,INPUT);
 uint64_t inBound = pulseIn(rangeFinder,HIGH);
 
 lcd.clear();
 lcd.print((float)inBound);
 delayMicroseconds(10); 
 lcd.setCursor(0, 7);
 
 }