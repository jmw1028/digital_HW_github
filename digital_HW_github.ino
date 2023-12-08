#include "Stepper.h"

Stepper stepper1(8, 1000);

int midiNotes[8] = { 60, 64, 67, 71, 72, 76, 79, 83 };

void setup() {
  Serial.begin(9600);
  stepper1.stepHandler(onStep);
}

void loop() {
  stepper1.process();
}

void onStep(int num) {
  usbMIDI.sendNoteOn(midiNotes[num], 127, 1);
  //usbMIDI.sendNoteOff(midiNotes[num], 127, 1);
}
