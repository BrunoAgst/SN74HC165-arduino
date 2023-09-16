#ifndef SN74HC165
#define SN74HC165

#include "Arduino.h"

class sn74hc165 {
    public:
        sn74hc165(const int SH, const int CLK, const int DATA, const int CLK_INH, const int DATA_WIDTH);
        void readByte(void);
        void initialize(void);

    private:
        int _SH;
        int _CLK;
        int _DATA;
        int _CLK_INH;
        int _DATA_WIDTH;
        unsigned char data;
};

#endif