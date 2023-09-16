#include "Arduino.h"
#include "../include/SN74HC165.hpp"

sn74hc165::sn74hc165(const int SH, const int CLK, const int DATA, const int CLK_INH, const int DATA_WIDTH){
    _SH = SH;
    _CLK = CLK;
    _DATA = DATA;
    _CLK_INH = CLK_INH;
    _DATA_WIDTH = DATA_WIDTH;
}

void sn74hc165::initialize(){
    Serial.begin(9600);

    pinMode(_SH, OUTPUT);
    pinMode(_CLK, OUTPUT);
    pinMode(_DATA, INPUT);
    pinMode(_CLK_INH, OUTPUT);

    digitalWrite(_CLK, LOW);
    digitalWrite(_SH, HIGH);
}

void sn74hc165::readByte(){
    data = 0;

    digitalWrite(_CLK_INH, HIGH);
    digitalWrite(_SH, LOW);
    delayMicroseconds(2);
    digitalWrite(_SH, HIGH);
    digitalWrite(_CLK_INH, LOW);

    Serial.print("Binary: ");
    for(int i = 0; i < 8; i++){
        Serial.print(digitalRead(_DATA));
        data |= (digitalRead(_DATA) << ((_DATA_WIDTH - 1) - i));
        digitalWrite(_CLK, HIGH);
        delayMicroseconds(2);
        digitalWrite(_CLK, LOW);
    }

    digitalWrite(_SH, HIGH);
    digitalWrite(_SH, LOW);

    Serial.println();
    Serial.print("0x");
    Serial.println(data, HEX);
};