//
//  ButtonsDebounce.cpp
//  ButtonsDebounce
//
//  Created by Matteo Formentin on 12/10/17.
//  Copyright © 2017 Matteo Formentin. All rights reserved.
//

#include "ButtonDebounce.h"
#include "Arduino.h"

Button::Button() {}

void Button::begin(int _pin)
{
  pin = _pin;
  pull_wiring = LOW;
  pinMode(pin, INPUT_PULLUP);
  previous_millis = 0;
  short_press_function_on = false;
  long_press_function_on = false;
}

bool Button::addShortPressCallback(void (*_short_callback)())
{
  if (short_press_function_on == true)
    return false;
  short_callback = _short_callback;
  short_press_function_on = true;
  return true;
}

//Will also disable short press callback
bool Button::removeShortPressCallback()
{
  if (short_press_function_on == false)
    return false;
  short_callback = nullptr;
  short_press_function_on = false;
  return true;
}

void Button::enableShortPressCallback()
{
  short_press_function_on = true;
}

void Button::disableShortPressCallback()
{
  short_press_function_on = false;
}

bool Button::getShortPressCallbackStatus()
{
  return short_press_function_on;
}

bool Button::addLongPressCallback(void (*_long_callback)(), int _long_press_time)
{
  if (long_press_function_on == true)
    return false;
  long_callback = _long_callback;
  if (_long_press_time <= DEBOUNCE_TIME)
    return false;
  long_press_time = _long_press_time;
  long_press_function_on = true;
  return true;
}

//Will also disable long press callback
bool Button::removeLongPressCallback()
{
  if (long_press_function_on == false)
    return false;
  long_callback = nullptr;
  long_press_function_on = false;
  return true;
}

void Button::enableLongPressCallback()
{
  long_press_function_on = true;
}

void Button::disableLongPressCallback()
{
  long_press_function_on = false;
}

bool Button::getLongPressCallbackStatus()
{
  return long_press_function_on;
}

void Button::buttonLoop()
{
  current_millis = millis();
  if (previous_millis == 0)
    previous_millis = millis(); //Prevents callback being called at boot

  current_read = digitalRead(pin);

  if (current_read == pull_wiring && previous_read == !pull_wiring)
  {
    previous_millis = millis();
    long_pressed = false;
  }

  //SHORT CALLBACK SOLO SE RILASCIATO PRIMA DEL LONG DEBOUNCE
  if (short_press_function_on == true && current_read == !pull_wiring && previous_read == pull_wiring && current_millis - previous_millis > DEBOUNCE_TIME && long_pressed == false)
  {
    short_callback();
    previous_millis = millis();
  }

  //LONG CALLBACK QUANDO RAGGIUNTO LONG DEBOUNCE - SENZA RILASCIO
  if (long_press_function_on == true && current_read == LOW && current_millis - previous_millis > long_press_time && long_pressed == false)
  {
    long_callback();
    long_pressed = true;
    previous_millis = millis();
  }

  previous_read = current_read;
}
