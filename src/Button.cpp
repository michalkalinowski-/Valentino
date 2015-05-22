#include "Button.h"

#define HOLDLENGTH  20

void Button::updateStatus(boolean status) {
  shiftArrayRight(previousStates, sizeof(previousStates)/sizeof(*previousStates));
  previousStates[0] = status;
  switch(currentState) {
    case OFF:
      if (checkOn()) {
        transitionState(CLICK);
      }
      break;
    case CLICK:
      if (checkOff()) {
        transitionState(OFF);
      } else {
        if (checkHold()) {
          transitionState(HOLD);
        }
      }
      break;
    case HOLD:
      if (checkOff()) {
        transitionState(OFF);
      }
      break;
  }
}

void Button::printStatus() {
  for (int i=0; i<20; i++) {
    Serial.print(previousStates[i]);
  }
  Serial.println("");
}

void Button::shiftArrayRight(boolean* array, size_t size) {
  for(int i=size-1; i>=0; i--) {
    array[i] = array[i-1];
  }
  array[0] = false;
}

void Button::transitionState(State state) {
  currentState = state;
  // Execute state method here
}

bool Button::checkHold() {
  for (int i = 1; i<HOLDLENGTH; i++) {
    if (!previousStates[i] && !previousStates[i-1]) {
      return false;
    }
  }
  return true;
}

bool Button::checkOn() {
  if (previousStates[0] && previousStates[1]) {
    return true;
  }
  return false;
}

bool Button::checkOff() {
  if (!previousStates[0] && !previousStates[1]) {
    return true;
  }
  return false;
}

void Button::registerAction(int state, void (*func)()) {
  switch(state) {
    case 0:
      off_func = func;
      break;
    case 1:
      click_func = func;
      break;
    case 3:
      hold_func = func;
      break;
  }

}