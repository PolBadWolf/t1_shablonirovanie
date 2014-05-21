
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
        // lenght 6000mm
        lenD_EE = 1000;
        
        timeOut_EE = 55000 / timeOutKF;
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

