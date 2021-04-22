
/*******************************************************************
 *  
 *  Sample for ButtonDebounce Library - created by Matteo Formentin
 *  GitHub: https://www.github.com/matt-formentin
 *  WebSite: https://www.matteoformentin.com
 *  
 *******************************************************************/
 
#include <ButtonDebounce.h>

const int button1_pin = 3;
const int button2_pin = 4;

Button button1;
Button button2;

void setup() 
{
  Serial.begin(9600);

  button1.begin(button1_pin); //Set button 1 pin and wiring mode (When triggered pin goes low)  
  button1.addShortPressCallback(callback1); //Add a callback when button 1 is short pressed and release
  button1.addLongPressCallback(callback2, 2000); //Add a callback when button 2 is long pressed (doesn't need release)

  button2.begin(button2_pin);
  button2.addShortPressCallback(callback3);
  button2.addLongPressCallback(callback4, 2000);
}

void loop() 
{
 button1.buttonLoop(); //Non blocking button loop - handle button pressed event and execute callbacks
 button2.buttonLoop();
}

//Buttons callbacks
void callback1(){
  Serial.println("short pressed button 1");
}

void callback2(){
  Serial.println("long pressed button 1");
}

void callback3(){
  Serial.println("short pressed button 2");
}

void callback4(){
  Serial.println("long pressed button 2");
}

