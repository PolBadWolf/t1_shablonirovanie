
#ifndef Speedmetr__h
#define Speedmetr__h

namespace speedmetr
{
    extern __eeprom unsigned int lenD_EE;
    extern unsigned int lenD;
    extern __eeprom unsigned int timeOut_EE;
    extern unsigned int timeOut;
#define timeOutKF   1
    extern tc_ports *ObjD1;
    extern tc_ports *ObjD2;
    // ==================================================
    extern unsigned char countSt;
    extern unsigned int count;
    extern unsigned int countM;
    // количество замеров за последний час
    extern unsigned int  n;
    // текущий час
    extern signed char hour;
    // last speed
    extern unsigned int  lastSpeed;
    extern unsigned int  minSpeed;
    extern unsigned int  maxSpeed;
    extern unsigned long allSpeed;
    extern unsigned char newDataSpeed;
    extern bool tcInv;
    // ==================================================
    // fist init
    void EepromInit();
    // init
    void Init();
    void Timer();
    void Main();
}

#endif

