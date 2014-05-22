
#include "main.h"

#include "Speedmetr.h"

namespace speedmetr
{
    __eeprom unsigned int lenD_EE;
    unsigned int lenD;
    __eeprom unsigned int timeOut_EE;
    unsigned int timeOut;
#if (timeOut<256)
    unsigned char preCount;
#else
    unsigned int preCount;
#endif
    tc_ports *ObjD1 = new tc_ports('c', 0, 0, 20, 1);
    tc_ports *ObjD2 = new tc_ports('c', 1, 0, 20, 1);
    bool tcInv = 1;
    unsigned char block = 1;
    unsigned char countSt = 0;
    unsigned int count;
    unsigned int countM;
    // ==================================================
    // количество замеров за последний час
    unsigned int  n = 0;
    // текущий час
    signed   char hour    = -1;
    unsigned char mountSp = 0;
    unsigned char daySp   = 0;
    // last speed
    unsigned int  lastSpeed = 0;
    unsigned int  minSpeed = 0;
    unsigned int  maxSpeed = 0;
    unsigned long allSpeed = 0;
    unsigned char newDataSpeed = 0;
    // ==================================================
    // fist init
    void EepromInit()
    {
        // lenght 1000mm
        lenD_EE = 1000;
        
        timeOut_EE = 10000 / timeOutKF;
    }
    // init
    void Init()
    {
        lenD = lenD_EE;
        timeOut = timeOut_EE;
        preCount = 0;
        block = 0;
        countSt = 0;
        // количество замеров за последний час
        n = 0;
        // текущий час
        hour = -1;
        // last speed
        lastSpeed = 0;
        allSpeed = 0;
        newDataSpeed = 0;
    }
    void FnUsrD1()
    {
        if (ObjD2->FlI(speedmetr::tcInv)>0)
        {   // задний ход ?
            countSt = 0;
            return;
        }
        if (ObjD1->FlI(speedmetr::tcInv)>0) 
        {   // сход с датчика 1
            countSt = 2; // счета
            count = 0;
            return;
        }
    }
    void FnUsrD2()
    {
        if (ObjD1->FlI(speedmetr::tcInv)==0)
        {   // наезд на датчик 1
            countSt = 0; // сброс
            return;
        }
        count++;
        if (ObjD2->FlI(speedmetr::tcInv)>0)
        {   // пора произвести подсчет ****************************** дописать
            countM = count;
            countSt = 3;
            return;
        }
        if (count>=timeOut)
        {   // время вышло - сброс
            countSt = 0;
            return;
        }
    }
    void FnUsr()
    {
        // ожидание шаблон на датчиках
        if (countSt==0)
        {
            if ( (ObjD1->FlI(speedmetr::tcInv)==0) && (ObjD2->FlI(speedmetr::tcInv)==0) )
            {
                countSt = 1;
            }
            return;
        }
        // ожидание сход с датчика 1
        if (countSt==1)
        {
            FnUsrD1();
            return;
        }
        // ожидание сход с датчика 2 и счет
        if (countSt==2)
        {
            FnUsrD2();
            return;
        }
        if (countSt>3)
            countSt = 0;
    }
    void Timer()
    {
        if (block>0)
            return;
        ObjD1->for_timer();
        ObjD2->for_timer();
        if (++preCount>=timeOutKF)
        {
            preCount = 0;
            FnUsr();
        }
    }
    void DigitToStringZ(unsigned int digit, unsigned char len, unsigned char *adr)
    {
        adr = adr + len;
        unsigned char tmp;
        for (unsigned char i=0; i<len; i++)
        {
            adr--;
            tmp = digit%10;
            digit = digit/10;
            *adr = '0'+tmp;
        }
    }
    void DigitToStringZ(unsigned char digit, unsigned char len, unsigned char *adr)
    {
        adr = adr + len;
        unsigned char tmp;
        for (unsigned char i=0; i<len; i++)
        {
            adr--;
            tmp = digit%10;
            digit = digit/10;
            *adr = '0'+tmp;
        }
    }
    void DigitToString(unsigned int digit, unsigned char len, unsigned char *adr)
    {
        adr = adr + len;
        unsigned char tmp;
        adr--;
        tmp = digit%10;
        *adr = '0'+tmp;
        digit = digit/10;
        for (unsigned char i=1; i<len; i++)
        {
            adr--;
            tmp = digit%10;
            digit = digit/10;
            if (tmp)
                *adr = '0'+tmp;
            else
                *adr = ' ';
        }
    }
    void DigitToString(unsigned char digit, unsigned char len, unsigned char *adr)
    {
        adr = adr + len;
        unsigned char tmp;
        adr--;
        tmp = digit%10;
        *adr = '0'+tmp;
        digit = digit/10;
        for (unsigned char i=1; i<len; i++)
        {
            adr--;
            tmp = digit%10;
            digit = digit/10;
            if (tmp)
                *adr = '0'+tmp;
            else
                *adr = ' ';
        }
    }
    void SendToPc(unsigned int speed)
    {
        const unsigned char bfLen = 38;
        unsigned char bf[bfLen];
        bf[ 0] = 0xe6;
        bf[ 1] = 0x19;
        bf[ 2] = 0x00;
        bf[ 3] = bfLen-5;
        bf[ 4] = '2';
        bf[ 5] = '0';
        DigitToStringZ(clockrt::time[CT_YEAR],   2, &bf[ 6]);
        bf[ 8] = '.';
        DigitToStringZ(clockrt::time[CT_MONTH],  2, &bf[ 9]);
        bf[11] = '.';
        DigitToStringZ(clockrt::time[CT_DATE],   2, &bf[12]);
        bf[14] = 0x09;
        DigitToStringZ(clockrt::time[CT_HOUR],   2, &bf[15]);
        bf[17] = ':';
        DigitToStringZ(clockrt::time[CT_MINUTE], 2, &bf[18]);
        bf[20] = ':';
        DigitToStringZ(clockrt::time[CT_SECOND], 2, &bf[21]);
        bf[23] = 0x09;
        DigitToString(n, 4, &bf[24]);
        bf[28] = 0x09;
        DigitToString(speed/1000, 2, &bf[29]);
        speed = speed%1000;
        bf[31] = '.';
        DigitToStringZ(speed, 3, &bf[32]);
        bf[35] = 0x0d;
        bf[36] = 0x0a;
        bf[37] = crc8_buf(bf, bfLen-1);
        for (unsigned char i=0; i<bfLen; i++)
        {
            PcPort::WriteByte(bf[i]);
            CommImitator::WriteByte(bf[i]);
        }
    }
    void Main()
    {
        unsigned char temp;
        unsigned int  tempN;
        {
            CritSec speedmetrCs;
            temp = countSt;
        }
        if (temp==3)
        {   // новый замер
            {
                CritSec speedmetrCs;
                lastSpeed = (unsigned int)((unsigned long)speedmetr::lenD*1000/(speedmetr::countM*timeOutKF));
                if ( (minSpeed>lastSpeed) || (minSpeed==0) )
                    minSpeed = lastSpeed;
                if (maxSpeed<lastSpeed)
                    maxSpeed = lastSpeed;
                allSpeed = allSpeed + lastSpeed;
                n++;
                countSt = 0;
            }
            SendToPc(lastSpeed);
            newDataSpeed = 1;
        }
        // -----------
        {
            CritSec speedmetrCs;
            temp = clockrt::time[CT_HOUR];
            tempN = n;
        }
        if (hour!=temp)
        {
            // сохранить в архив
            if ( (tempN>0) && (hour>0) )
            {
                unsigned int spMin, spMax, spAvg;
                {
                    CritSec speedmetrCs;
                    spMin = (minSpeed+5)/10;
                    spMax = (maxSpeed+5)/10;
                    spAvg = ((allSpeed/n)+5)/10;
                }
                vg::StrSpeed dat;
                dat.Send(mountSp, daySp, hour, spMin, spMax, spAvg, tempN);
                vg::eeArcSpeed[vg::arcSpeedInd] = dat;
                vg::arcSpeedInd = vg::addrArchivNorm(vg::arcSpeedInd+1);
                if (vg::arcSpeedLen<ee_ArchivLen)
                    vg::arcSpeedLen++;
            }
            else
            {
                scr->Clear();
                scr->ShowString(            0, "init time arc");
                _delay_ms(1000);
                scr->Clear();
            }
            // ========================================================
            {   // time reset
                CritSec speedmetrCs;
                mountSp = clockrt::time[CT_MONTH];
                daySp   = clockrt::time[CT_DATE];
                hour    = clockrt::time[CT_HOUR];
                // reset speed
                minSpeed  = 0;
                maxSpeed  = 0;
                allSpeed  = 0;
                lastSpeed = 0;
                n = 0;
            }
            newDataSpeed = 1;
        }
        // -----------
    }
}

