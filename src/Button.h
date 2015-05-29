#ifndef BUTTON_H
  #define BUTTON_H

  #include "Arduino.h"
  #include "MapSimple.h"

  class Button {
    boolean previousStates[20] = {0};
    void (*off_func)();
    void (*click_func)();
    void (*hold_func)();
    public:
    enum State {
      OFF,
      CLICK,
      DB_CLICK,
      HOLD
    };
    private:
    void shiftArrayRight(boolean* array, size_t size);
    void transitionState(State state);
    bool checkOn();
    bool checkHold();
    bool checkOff();
    typedef void(*f_pointer)();
    MapSimple<State, f_pointer>* actionsMap;
    public:
    State currentState = OFF;
    void updateStatus(boolean status);
    void registerAction(State state, void (*func)());
    void printStatus();
  };

#endif