//
//  ButtonsDebounce Library
//
//  Created by Matteo Formentin
//  GitHub: https://www.github.com/matt-formentin
//  WebSite: https://www.ecuboost.it
//

#ifndef ButtonDebounce_h
#define ButtonDebounce_h

#include "Arduino.h"

class Button
{
public:
  Button();
  void begin(int _pin);
  void begin(int _pin, int _press_time);

  bool setShortPressCallback(void (*_short_callback)());
  [[deprecated("Use setShortPressCallback instead")]];
  bool addShortPressCallback(void (*_short_callback)());
  bool removeShortPressCallback();
  void enableShortPressCallback();
  void disableShortPressCallback();
  bool getShortPressCallbackStatus();

  bool setLongPressCallback(void (*_long_callback)(), int _long_press_time);
  [[deprecated("Use setLongPressCallback instead")]];
  bool addLongPressCallback(void (*_long_callback)(), int _long_press_time);
  bool removeLongPressCallback();
  void enableLongPressCallback();
  void disableLongPressCallback();
  bool getLongPressCallbackStatus();
  void buttonLoop();

private:
  const int DEBOUNCE_TIME = 50;
  int pin;
  bool pull_wiring;
  int previous_millis;
  int current_millis;
  bool previous_read;
  bool current_read;
  void (*short_callback)();

  void (*long_callback)();
  bool long_pressed;
  int long_press_time;
  bool short_press_function_on;
  bool long_press_function_on;
};

#endif /* ButtonsDebounce_h */
