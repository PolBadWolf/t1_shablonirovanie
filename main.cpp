
#include "main.h"

unsigned long datt;
unsigned int zad =0;
__eeprom unsigned char ee_FlagRes = 0x34;

void main(void)
{
  DDRA = 255;
  PORTA = 255;
  if (ee_FlagRes!=0x33) {
    _delay_ms(1000);
    for(unsigned int i=0;i<ee_ArchivLen;i++) {
      vg::ee_Archiv[i].Year = 0;
      vg::ee_Archiv[i].Mounth = 0;
      vg::ee_Archiv[i].Date = 0;
      vg::ee_Archiv[i].Smena = 0;
      vg::ee_Archiv[i].Impuls = 0;
    }
    vg::ee_DateSmenaCur.Year = 0;
    vg::ee_DateSmenaCur.Mounth = 0;
    vg::ee_DateSmenaCur.Date = 0;
    vg::ee_DateSmenaCur.Smena = 0;
    vg::ee_DateSmenaCur.Impuls = 0;
    vg::ee_ArchivIndx = ee_ArchivLen - 1;
    vg::ee_K_Metr = 30027;
    vg::ee_K_Kg   = 4504;
    ns_menu::ee_psw[0].mask = 0;
    ns_menu::ee_psw[1].mask = 0x02;
    ns_menu::ee_psw[1].pin[0] = 0;
    ns_menu::ee_psw[1].pin[1] = 1;
    ns_menu::ee_psw[1].pin[2] = 0;
    ns_menu::ee_psw[1].pin[3] = 0;
    ns_menu::ee_psw[1].pin[4] = 0;
    ns_menu::ee_psw[2].mask = 0x04;
    ns_menu::ee_psw[2].pin[0] = 0;
    ns_menu::ee_psw[2].pin[1] = 3;
    ns_menu::ee_psw[2].pin[2] = 0;
    ns_menu::ee_psw[2].pin[3] = 0;
    ns_menu::ee_psw[2].pin[4] = 0;
    ns_menu::ee_psw[3].mask = 0;
    ns_menu::ee_psw[4].mask = 0;
    ns_menu::ee_psw[5].mask = 0;
    ns_menu::ee_psw[6].mask = 0;
    ns_menu::ee_psw[7].mask = 0x7f;
    ns_menu::ee_psw[7].pin[0] = 0;
    ns_menu::ee_psw[7].pin[1] = 0;
    ns_menu::ee_psw[7].pin[2] = 0;
    ns_menu::ee_psw[7].pin[3] = 0;
    ns_menu::ee_psw[7].pin[4] = 1;
    ee_FlagRes = 0x33;
  }
  {
    void InitSystem(void);
    InitSystem();
  }
  __enable_interrupt();
  scr->LoadSymbol();
  _delay_ms(1000);
  //provolka::init();  
  //PowerDown::up();
  //scr->Clear();
  //scr->dig_uz(0,10, vg::DD_save );
  while(true)
  {
    // разрешение работы по часам
    #ifdef CLOCK
    if ( (clockrt::time[CT_YEAR]==0) || (clockrt::time[CT_YEAR]>99) )
         vg::WorkTime = false;
    else vg::WorkTime = true;
    #else
    vg::WorkTime = true;
    #endif
    // разрешение работы по напряжению
    //PowerDown::main();
    
    // счет проволки
    //provolka::main();
    
    #ifdef MENU
    ns_menu::main();
    #endif
    /*
    {
      unsigned char cs = __save_interrupt();
      __disable_interrupt();
      if (vg::acp0_new) {
        vg::acp0_new = false;  
        acp0d = vg::acp0;
        acp0f = true;
      }
      __restore_interrupt(cs);
    }
    {
      unsigned char cs = __save_interrupt();
      __disable_interrupt();
      if (datt!=vg::DD_save) {
        datt = vg::DD_save;
        scr->dig_uz(0,10, vg::DD_save );
      }
      __restore_interrupt(cs);
    }
    if (acp0f) {
      unsigned long x;
      acp0f = false;
      acp0_mas[acp0_ind] = acp0d;
      acp0_ind++;
      if (acp0_ind>=20) acp0_ind = 0;
      acp0_min = acp0_mas[0];
      for(unsigned char i=1;i<20;i++) if (acp0_mas[i]>acp0_min) acp0_min = acp0_mas[i];
      x = (unsigned long)acp0_min*1000/2046;
      //scr->ShowChar(c_stolbcov+0, '0' + x/100 );
      //scr->ShowChar(c_stolbcov+1, ',');
      //scr->dig_uz(c_stolbcov+2, 2,  x%100 );
      if (x<450) {
          unsigned char cs = __save_interrupt();
          __disable_interrupt();
          datt = vg::DD_save;
          __restore_interrupt(cs);
          zad++;
          if (zad>10) {
            vg::EE_save = datt;
            while(true) 
            __no_operation();
          }
      }
      else zad = 0;
    }
    */
    //=============
    /*
    #ifdef CLOCK
    if (clockrt::tik_cn==0) {
          scr->ShowChar(c_stolbcov+2, ':');
          scr->ShowChar(c_stolbcov+5, ':');
    }
    if (clockrt::tik_cn==1) {
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
