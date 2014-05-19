
#ifndef variable__h
#define variable__h

#define ee_ArchivLen 24*24
#if (ee_ArchivLen>32767)
#error Error len archive
#endif
namespace vg
{
    class StrSpeed
    {
//    private:
    public:
        unsigned int  bb[2];
        unsigned int  dt;
        unsigned char n;
    public:
        void Send  (unsigned char  mount, unsigned char  day, unsigned char  hour, unsigned int  min, unsigned int  max, unsigned int  avg, unsigned char  n);
        void Recive(unsigned char *mount, unsigned char *day, unsigned char *hour, unsigned int *min, unsigned int *max, unsigned int *avg, unsigned char *n);
    };
    void eeInit();
    void init(void);
#if(ee_ArchivLen>127)
    signed int  addrArchivNorm(signed int  addr);
#else
    signed char addrArchivNorm(signed char addr);
#endif
#if(ee_ArchivLen>127)
    extern __eeprom signed int  arcSpeedInd;
    extern __eeprom signed int  arcSpeedLen;
#else
    extern __eeprom signed char arcSpeedInd;
    extern __eeprom signed char arcSpeedLen;
#endif
    extern __eeprom StrSpeed eeArcSpeed[];
}

#endif

