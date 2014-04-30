
#ifndef Speedmetr__h
#define Speedmetr__h

namespace speedmetr
{
    extern __eeprom unsigned int lenD_EE;
    extern unsigned int lenD;
    // fist init
    void EepromInit();
    // init
    void Init();
}

#endif

