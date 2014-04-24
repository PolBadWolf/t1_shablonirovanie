
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
#ifdef MENU
        ns_menu::InitEeprom();
#endif
        ee_FlagRes = 0x33;
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
    // init uni block
    //
    // main cicle
    while(true)
    {
        // enable job clock
        #ifdef CLOCK
        if ( (clockrt::time[CT_YEAR]==0) || (clockrt::time[CT_YEAR]>99) )
        {
//      vg::WorkTime = false;
//  else vg::WorkTime = true;
        }
        #else
            vg::WorkTime = true;
        #endif
    
        // job uni block
        // provolka::main();
    
        // enable job menu
        #ifdef MENU
            ns_menu::main();
        #endif
        //=============
        /*
        #ifdef CLOCK
            if (clockrt::tik_cn==0)
            {
                scr->ShowChar(c_stolbcov+2, ':');
                scr->ShowChar(c_stolbcov+5, ':');
            }
            if (clockrt::tik_cn==1)
            {
                scr->ShowChar(c_stolbcov+2, ' ');
                scr->ShowChar(c_stolbcov+5, ' ');
            }
            if (clockrt::tik)
            {
                clockrt::tik = 0;
                scr->dig_uz(c_stolbcov+0, 2, clockrt::time[CT_HOUR] );
                scr->dig_uz(c_stolbcov+3, 2, clockrt::time[CT_MINUTE] );
                scr->dig_uz(c_stolbcov+6, 2, clockrt::time[CT_SECOND] );
            }
        #endif
        */
    }
}
