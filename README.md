# ButtonDebounce - Simple Debounce Library
*Created by Matteo Formentin*  
*WebSite: https://www.ecuboost.it*  

ButtonDebounce is a very simple Arduino library which purpose is to make debounce simple by connecting buttons events with the execution of users defined callbacks. The library is non-blocking, so you can execute other task while ButtonDebounce take care of buttons events. You can also specify your own debounce time in order to execute different functions on long button press.

How to use:  
1. First, you have to declare one Button object for every button you want to use. You have to pass as parameter connected pin and pull wiring when pressed (if button is connected to 5v or ground and digital pin):   
**WE USE INTERNAL ARDUINO PULL-UP RESISTANCE SO IT IS SAFE TO CONNECT BUTTON WITHOUT EXTERNAL PULL RESISTENCE**  
      ```
      Button buttonName(4, HIGH);
      ```
2. Attach callbacks to every button object. you can add one short press callback and one long press one (in this case you have to specify the times in milliseconds before action will be performed):  
      ```
      buttonName.addShortPressCallback(callback);  
      buttonName.addLongPressCallback(callback, 1000);
      ```
      
3. Then you have to call buttonLoop() method for every Button object:  

      ```
      buttonName.buttonLoop();
      ```

  
