
#include "../main.h"

#ifdef USERTIMERUSER
#include "SystemTimerUser.h"
namespace ns_TimerUser
{
  void Init(void)
  {
    // ������� �������
    #define Ft 1000
    // ��������������� �������� : 1, 8, 32, 64, 128, 256, 1024
    #define PrDel 64
    
    #if (PrDel==1)
    #define PrCs02 0
    #define PrCs01 0
    #define PrCs00 1
    #elif (PrDel==8)
    #define PrCs02 0
    #define PrCs01 1
    #define PrCs00 0
    #elif (PrDel==32)
    #define PrCs02 0
    #define PrCs01 1
    #define PrCs00 1
    #elif (PrDel==64)
    #define PrCs02 1
    #define PrCs01 0
    #define PrCs00 0
    #elif (PrDel==128)
    #define PrCs02 1
    #define PrCs01 0
    #define PrCs00 1
    #elif (PrDel==256)
    #define PrCs02 1
    #define PrCs01 1
    #define PrCs00 0
    #elif (PrDel==1024)
    #define PrCs02 1
    #define PrCs01 1
    #define PrCs00 1
    #else
    #error Error Timer System pred div
    #endif
    
    TCCR0_CS02 = PrCs02;
    TCCR0_CS01 = PrCs01;
    TCCR0_CS00 = PrCs00;
    TCCR0_WGM00 = 0;
    TCCR0_WGM01 = 1;
    TCCR0_COM01 = 0;
    TCCR0_COM00 = 0;
    TCCR0_FOC0 = 0;
    TCNT0 = 0;
    unsigned int ocrK = ((unsigned long)C_Fosc/((unsigned long)1*PrDel*Ft))-1;
    #if ocrK>255
    #error ocrK>255
    #endif
//    unsigned long tmpx = ((unsigned long)C_Fosc/((unsigned long)2*PrDel*Ft))-1;
    OCR0 = ocrK;
    TIMSK_OCIE0 = 1;
  
    #undef PrDel
    #undef TCCR0_CS02
    #undef TCCR0_CS01
    #undef TCCR0_CS00
    #undef Ft
    #undef PrCs02
    #undef PrCs01
    #undef PrCs00
  }
  
  #pragma vector = TIMER0_COMP_vect
  __interrupt void tim0_interrupt(void)
  {
    UserTimerUser();
  }
}
#endif

