
#include "main.h"

unsigned long datt;
unsigned int zad =0;
__eeprom unsigned char ee_FlagRes = 0x34;

void main(void)
{
    // time for stabl
    _delay_ms(1000); 
    // set default for bad eeprom
    if (ee_FlagRes!=0x33)
    {
        ee_FlagRes = 0x33;
#ifdef MENU
        ns_menu::InitEeprom();
#endif
        // module speedmetr
        speedmetr::EepromInit();
    }
    // init system
    {
        void InitSystem(void);
        InitSystem();
    }
    __enable_interrupt();
    // Load adwanced simbol to lcd 
    scr->LoadSymbol();
    // time for stabl
    _delay_ms(1000);
    // ------------------------------
    // module speedmetr
    speedmetr::Init();
    // ------------------------------
    // main cicle
    while(true)
    {
        // job uni block
        // provolka::main();
    
        // enable job menu
#ifdef MENU
            ns_menu::main();
#endif
        //=============
    }
}
