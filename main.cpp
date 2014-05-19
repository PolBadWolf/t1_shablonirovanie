
#include "main.h"

unsigned long datt;
unsigned int zad =0;
__eeprom unsigned char ee_FlagRes = 0x34;

void main(void)
{
    // time for stabl
    _delay_ms(1000); 
    __enable_interrupt();
    // init system
    {
        void InitSystem(void);
        InitSystem();
    }
    // set default for bad eeprom
    if (ee_FlagRes!=0x33)
    {
        scr->Clear();
        scr->ShowString(            0, "Clear Archiv" );
        scr->ShowString(c_stolbcov+ 0, "Len=" );
#if(ee_ArchivLen>127)
        scr->dig_u     (c_stolbcov+ 4, 5, ee_ArchivLen);
#else
        scr->dig_u     (c_stolbcov+ 4, 3, ee_ArchivLen);
#endif
        ee_FlagRes = 0x33;
#ifdef MENU
        ns_menu::InitEeprom();
#endif
        // module speedmetr
        speedmetr::EepromInit();
        //
        vg::eeInit();
    }
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
        speedmetr::Main();
        // enable job menu
#ifdef MENU
            ns_menu::main();
#endif
        //=============
    }
}
