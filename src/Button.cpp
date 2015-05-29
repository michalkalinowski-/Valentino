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
    default:
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
  // Use STDLIB map
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

// TODO : Write a conveniance constructor
void Button::registerAction(State state, void (*func)()) {
  switch(state) {
    case OFF:
      off_func = func;
      break;
    case CLICK:
      click_func = func;
      break;
    case HOLD:
      hold_func = func;
      break;
    default:
      break;
  }

}