
#include "main.h"
#include "variable.h"

namespace vg
{
  void init(void)
  {
  }
  // =====================================
  unsigned int acp0 = 0;
  bool acp0_new = true;
  bool WorkTime = true;
  bool WorkEnergi = true;
  __eeprom TDateSmena ee_Archiv[ee_ArchivLen] = {0};
  __eeprom TDateSmena ee_DateSmenaCur;
  TDateSmena DataSmena = {0};
  __eeprom unsigned int  ee_ArchivIndx = ee_ArchivLen;
  __eeprom unsigned long ee_K_Metr = 12500;
  __eeprom unsigned long ee_K_Kg   = 4504;
}
