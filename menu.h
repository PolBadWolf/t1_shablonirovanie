
#ifndef menu__h
#define menu__h
#ifdef MENU
namespace ns_menu
{
    void timer();
    void main();
//    void zero();
    void init();
    void InitEeprom();
    //     variable
    // struck password variable
    struct T_psw
    {
        unsigned char pin[5];
    };
    extern __eeprom T_psw ee_psw[];
}
#endif
#endif

