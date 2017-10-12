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


class Button {
public:
    Button();
    void begin(int _pin, bool _pull_wiring);
    bool addShortPressCallback(void(*_short_callback)());
    void begin(int _pin, bool _pull_wiring, int _press_time);
    bool addLongPressCallback(void(*_long_callback)(), int _long_press_time);
    void buttonLoop();

private:
    const int DEBOUNCE_TIME = 50;
    int pin;
    bool pull_wiring;
    int previous_millis;
    int current_millis;
    bool previous_read;
    bool current_read;
    void(*short_callback)();

    void(*long_callback)();
    bool long_pressed;
    int long_press_time;
    bool short_press_function_on;
    bool long_press_function_on;
};


#endif /* ButtonsDebounce_h */
