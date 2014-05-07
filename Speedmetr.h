
#ifndef Speedmetr__h
#define Speedmetr__h

namespace speedmetr
{
    extern __eeprom unsigned int lenD_EE;
    extern unsigned int lenD;
    extern __eeprom unsigned int timeOut_EE;
    extern unsigned int timeOut;
#define timeOutKF   10
    extern tc_ports *ObjD1;
    extern tc_ports *ObjD2;
    // fist init
    void EepromInit();
    // init
    void Init();
    void Timer();
}

#endif

