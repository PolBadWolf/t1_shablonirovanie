
#ifndef variable__h
#define variable__h
#define ee_ArchivLen 93
namespace vg
{
  struct TDateSmena {
    unsigned char Year;
    unsigned char Mounth;
    unsigned char Date;
    unsigned char Smena;
    unsigned long Impuls;
  };
  struct THourSmena {
    unsigned char Year;
    unsigned char Mounth;
    unsigned char Date;
    unsigned char Hour;
    unsigned char Smena;
  };
  void init(void);
  extern unsigned int acp0;
  extern bool acp0_new;
  extern bool WorkTime;
  extern bool WorkEnergi;
  extern __eeprom TDateSmena ee_Archiv[];
  extern __eeprom TDateSmena ee_DateSmenaCur;
  extern TDateSmena DataSmena;
  extern __eeprom unsigned int  ee_ArchivIndx;
  extern __eeprom unsigned long ee_K_Metr;
  extern __eeprom unsigned long ee_K_Kg;
}

#endif

