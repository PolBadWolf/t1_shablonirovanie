
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
    unsigned char block = 1;
    unsigned char countSt = 0;
    unsigned int count;
    unsigned int countM;
    // fist init
    void EepromInit()
    {
        // lenght 6000mm
        lenD_EE = 6000;
        
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
    }
    void FnUsrD1()
    {
        if (ObjD2->fl>0)
        {   // задний ход ?
            countSt = 0;
            return;
        }
        if (ObjD1->fl>0)
        {   // сход с датчика 1
            countSt = 2; // счета
            count = 0;
            return;
        }
    }
    void FnUsrD2()
    {
        if (ObjD1->fl==0)
        {   // наезд на датчик 1
            countSt = 0; // сброс
            return;
        }
        count++;
        if (ObjD2->fl>0)
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
            if ( (ObjD1->fl==0) && (ObjD2->fl==0) )
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
}

