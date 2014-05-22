
#include "../main.h"
#ifdef DISPLAY_TIMER
#include "DisplayTimer.h"
namespace ns_DisplayTimer
{
  // частота таймера ( таймер2 )
  #define Ft 1000
  // предделители 1, 8, 64, 256, 1024
  #define PrDel 64
  void TimerOn(void);
  void TimerInit(void)
  {
  // предделители 1, 8, 64, 256, 1024
    TCCR2 = 0;
    // CTC mode
    TCCR2_WGM21 = 1;
    TCCR2_WGM20 = 0;
    TCCR2_COM21 = 0;
    TCCR2_COM20 = 0;
    #if (PrDel==1)
    #define PrCs20 1
    #define PrCs21 0
    #define PrCs22 0
    #elif (PrDel==8)
    #define PrCs20 0
    #define PrCs21 1
    #define PrCs22 0
    #elif (PrDel==64)
    #define PrCs20 1
    #define PrCs21 1
    #define PrCs22 0
    #elif (PrDel==256)
    #define PrCs20 0
    #define PrCs21 0
    #define PrCs22 1
    #elif (PrDel==1024)
    #define PrCs20 1
    #define PrCs21 0
    #define PrCs22 1
    #else
    #error Error Timer LCD pred div
    #endif
    TCCR2_CS22 = PrCs22;
    TCCR2_CS21 = PrCs21;
    TCCR2_CS20 = PrCs20;
    TimerOn();
  }
  void TimerOn(void)
  {
    TCNT2 = 0;
    #if ((C_Fosc/PrDel/Ft)-1)>255
    #error ((C_Fosc/PrDel/Ft)-1)>255
    #endif
    OCR2 = (C_Fosc/PrDel/Ft)-1;
    TIFR_OCF2 = 0;
    TIFR_TOV2 = 0;
    TIMSK_OCIE2 = 1;
  }
  #pragma vector = TIMER2_COMP_vect
  __interrupt void tim2_interrupt(void)
  {
    void f_UserTimerLcd(void);
    TIMSK_OCIE2 = 0;
    //__enable_interrupt();
    #ifdef LCD
    scr->for_timer();
    #endif
    #ifdef KEY4
    key_int();
    #endif
    #ifdef MENU
    ns_menu::timer();
    #endif
    #ifdef USERTIMERDISPLAY
    UserTimerDisplay();
    #endif
    #ifdef CLOCK
    clockrt::timer();
    #endif
    TimerOn();
  }
  #undef PrDel
  #undef Ft
  #undef PrCs02
  #undef PrCs01
  #undef PrCs00
}
#endif
