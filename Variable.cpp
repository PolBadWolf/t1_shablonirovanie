
#include "main.h"
#include "variable.h"

namespace vg
{
#if(ee_ArchivLen>127)
    __eeprom signed int  arcSpeedInd;
    __eeprom signed int  arcSpeedLen;
#else
    __eeprom signed char arcSpeedInd;
    __eeprom signed char arcSpeedLen;
#endif
    __eeprom StrSpeed eeArcSpeed[ee_ArchivLen];
    void eeInit()
    {
        StrSpeed zero;
        arcSpeedInd = 0;
        arcSpeedLen = 0;
        zero.Send(0, 0, 0, 0, 0, 0, 0);
        for(unsigned int i=0; i<ee_ArchivLen; i++)
            eeArcSpeed[i] = zero;
    }
    void init(void)
    {
        //eeArcSpeed[0].min = 1;
    }
    // ===================================================================================
#if(ee_ArchivLen>127)
    signed int  addrArchivNorm(signed int  addr)
#else
    signed char addrArchivNorm(signed char addr)
#endif
    {
        if (addr<0)
        {
            while(addr<0)
                addr = addr + ee_ArchivLen;
        }
        else
        {
            while(addr>=ee_ArchivLen)
                addr = addr - ee_ArchivLen;
        }
        return addr;
    }
    // ===================================================================================
    void StrSpeed::Send  (unsigned char  mount, unsigned char  day, unsigned char  hour, unsigned int  min, unsigned int  max, unsigned int  avg, unsigned char  n)
    {
        if ( (mount<1) || (mount>12) ) mount = 0;
        if ( (day<1)   || (day>31)   ) day   = 0;
        if ( hour>23 ) hour = 23;
        if (min>0x03ff) min = 0x03ff;
        if (max>0x03ff) max = 0x03ff;
        if (avg>0x03ff) avg = 0x03ff;
        bb[0] = 0;
        bb[1] = 0;
        dt    = 0;
        ((unsigned int*)&(((unsigned char*)&bb[0])[0]))[0] |= min;
        ((unsigned int*)&(((unsigned char*)&bb[0])[1]))[0] |= (max<<2);
        ((unsigned int*)&(((unsigned char*)&bb[1])[0]))[0] |= (avg<<4);
        
        ((unsigned int*)&(((unsigned char*)&dt   )[0]))[0] |= ((unsigned int)mount)<<0;
        ((unsigned int*)&(((unsigned char*)&dt   )[0]))[0] |= ((unsigned int)day  )<<4;
        ((unsigned int*)&(((unsigned char*)&dt   )[1]))[0] |= ((unsigned int)hour )<<1;
        
        this->n = n;
    }
    void StrSpeed::Recive(unsigned char *mount, unsigned char *day, unsigned char *hour, unsigned int *min, unsigned int *max, unsigned int *avg, unsigned char *n)
    {
        *min   = (((unsigned int*)&(((unsigned char*)&bb[0])[0]))[0]>>0) & 0x03ff;
        *max   = (((unsigned int*)&(((unsigned char*)&bb[0])[1]))[0]>>2) & 0x03ff;
        *avg   = (((unsigned int*)&(((unsigned char*)&bb[1])[0]))[0]>>4) & 0x03ff;
        
        *mount = (((unsigned int*)&(((unsigned char*)&dt   )[0]))[0]>>0) & 0x0f;
        *day   = (((unsigned int*)&(((unsigned char*)&dt   )[0]))[0]>>4) & 0x1f;
        *hour  = (((unsigned int*)&(((unsigned char*)&dt   )[1]))[0]>>1) & 0x1f;
        
        *n = this->n;
    }

  // =====================================
//  __eeprom TDateSmena ee_Archiv[ee_ArchivLen] = {0};
}
