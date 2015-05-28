// Example to demonstrate thread definition, semaphores, and thread sleep.
#include "WProgram.h"
#include <ChibiOS_ARM.h>
#include <Arduino.h>

#include "Button.h"

// The LED is attached to pin 13 on Arduino.

const uint8_t LED_PIN = 13;

Button in1;

void off_action() {
  Serial.println("Button OFF!");
}

void click_action() {
  Serial.println("Button CLICK!");
}

void hold_action() {
  Serial.println("Button HOLD!");
}


// Declare a semaphore with an inital counter value of zero.
SEMAPHORE_DECL(sem, 0);
//------------------------------------------------------------------------------
// Thread 1, turn the LED off when signalled by thread 2.

// 64 byte stack beyond task switch and interrupt needs
static WORKING_AREA(waThread1, 64);

static msg_t Thread1(void *arg) {
  int i = 0;
  // this doesn't work!!!!
  in1.registerAction(Button::OFF, &off_action);
  while (!chThdShouldTerminate()) {
    if (i < 22) {
      in1.updateStatus(true);
    } else {
      in1.updateStatus(false);
    }
    in1.printStatus();
    chThdSleepMilliseconds(500);
    i++;
  }
  return 0;
}
//------------------------------------------------------------------------------
// Thread 2, turn the LED on and signal thread 1 to turn the LED off.

// 64 byte stack beyond task switch and interrupt needs
static WORKING_AREA(waThread2, 64);

static msg_t Thread2(void *arg) {
  pinMode(LED_PIN, OUTPUT);
  while (1) {
    digitalWrite(LED_PIN, HIGH);

    // Sleep for 200 milliseconds.
    chThdSleepMilliseconds(1000);

    // Turn LED off.
    digitalWrite(LED_PIN, LOW);

    // Sleep for 200 milliseconds.
    chThdSleepMilliseconds(200);

  }
  return 0;
}
//------------------------------------------------------------------------------
// main thread runs at NORMALPRIO
void chSetup() {

  // start blink thread
  chThdCreateStatic(waThread1, sizeof(waThread1),
    NORMALPRIO + 2, Thread1, NULL);

  chThdCreateStatic(waThread2, sizeof(waThread2),
    NORMALPRIO + 1, Thread2, NULL);

}
//------------------------------------------------------------------------------
extern "C" int main(void)
{
  Serial.begin(9600);
  // wait for USB Serial
  while (!Serial) {}

  chBegin(chSetup);
  // chBegin never returns, main thread continues with mainThread()
  while(1) {
  }
}
//------------------------------------------------------------------------------
void loop() {
  // not used
}

