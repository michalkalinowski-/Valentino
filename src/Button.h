#ifndef BUTTON_H
  #define BUTTON_H

  #include "Arduino.h"

  class Button {
    boolean previousStates[20] = {0};
    enum State {
      OFF,
      CLICK,
      DB_CLICK,
      HOLD
    };
    void (*off_func)();
    void (*click_func)();
    void (*hold_func)();
    //
    void shiftArrayRight(boolean* array, size_t size);
    void transitionState(State state);
    bool checkOn();
    bool checkHold();
    bool checkOff();
    //
    State currentState = OFF;
    public:
    void updateStatus(boolean status);
    void registerAction(int state, void (*func)());
    void printStatus();
  };

#endif