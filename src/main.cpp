#include <Arduino.h>
#include "../lib/SN74HC165.cpp"

const int SH = 4;
const int CLK = 3;
const int DATA = 2;
const int CLK_INH = 5;
const int DATA_WIDTH = 8;

void setup() {
  sn74hc165 ShiftRegister(SH, CLK, DATA, CLK_INH, DATA_WIDTH);
  
  ShiftRegister.initialize();
  ShiftRegister.readByte();
}

void loop() {}