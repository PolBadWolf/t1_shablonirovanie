
#include "main.h"

#include "Speedmetr.h"

namespace speedmetr
{
    __eeprom unsigned int lenD_EE;
    unsigned int lenD;
    // fist init
    void EepromInit()
    {
        // lenght 6000mm
        lenD_EE = 6000;
    }
    // init
    void Init()
    {
        lenD = lenD_EE;
    }
}

