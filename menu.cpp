
#include "main.h"
#ifdef MENU
#include "menu.h"

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//            показ старого парол€ при установки нового парол€
// #define ShowPass


//              закрывать звездочками новый вводимый пароль
#define ShowStar


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#define TIME_EXIT 2500

namespace ns_menu
{
    //=================================
    unsigned char key;
    unsigned char keyFlOn  = 0;
    unsigned char keyFlOn1 = 0;
#define keyFastOnMax  2500
#define keyFastOffMax 200
    unsigned int  keyFastOnCount  = keyFastOnMax;
    unsigned int  keyFastOffCount = keyFastOffMax;
    unsigned char keyFastFl    = 0;
    //=================================
    //     select configure
    // path select menu
    unsigned char menuNap = 0;
    // ==========================
    //      for work password
    // new password
    T_psw vvPasword;
    // count for input password
    unsigned char vvPaswordCount;
#define PSWN 1
    // massive user passwords
    __eeprom T_psw ee_psw[PSWN];
    // back door
    __flash T_psw flPsw= {2,2,3,6,0};
    // flag status checked password
    unsigned char flPasswordStatus = 0;
    // ==============================
    //     Time out
    // count time out menu
    unsigned int  menuTimeOut;
    unsigned int  menuTimeOutSet;
    // count time delay key
    unsigned int  menuTimeDelayKey = 0;
    void SetMenuTimeOut(unsigned int t);
    // count menu time delay
    unsigned int  menuTimeDelay = 1;
    unsigned char afterMode = 0;
    // flash
#define menuFlashSet 300
    unsigned int  menuFlash = menuFlashSet/2;
    unsigned char menuFlashSt = 0;
    // ================================================
    unsigned int  vRefreshCount;
#define vRefreshCountMax 5000
    unsigned int  vFlashCount;
#define vFlashCountMax 3000
#define vFlashCountFls 350
      signed char vSecStat;
    unsigned char tik_cn = 5;
    // ================================================
    // N mode/step menu
    unsigned char mode = 0;
    // ================================================
    // bad eeprom - restore to default
    void InitEeprom()
    {
        ns_menu::ee_psw[0].pin[0] = 0;
        ns_menu::ee_psw[0].pin[1] = 0;
        ns_menu::ee_psw[0].pin[2] = 0;
        ns_menu::ee_psw[0].pin[3] = 0;
        ns_menu::ee_psw[0].pin[4] = 0;
    }
    // ====================================
    // init to start system 
    void init()
    {
        // reset status password
        flPasswordStatus = 0;
        // set work screen
        void workscr_i();
        workscr_i();
        void SetMenuTimeDelay(unsigned int t, unsigned char m);
        SetMenuTimeDelay(0, 0);
    }
// ====================================
// work scr
#define md_workscr          0
    void workscr_i();
    void workscr_0(void);
    unsigned char workscrFlCl = 0;
// ------------------------------------
// select fist menu archive
#define md_SelectArchiv     1
    void SelectArchiv_i();
// select fist menu configure
#define md_SelectConfig     2
    void SelectConfig_i();
// select fist menu exit
#define md_SelectExit       3
    void SelectExit_i();
// ------------------------------------
#define md_PassWrd          4
    void PassWrd_i();
    void PassWrd_v();
    void PassWrd_m();
    void PassWrd_p();
    void PassWrd_e();
    void PassWrd_Chk();
// ------------------------------------
#define md_M2SelLen         5
    void M2SelLen_i();
#define md_M2SelTOut        6
    void M2SelTOut_i();
#define md_M2SelClock       7
    void M2SelClock_i();
#define md_M2SelPass        8
    void M2SelPass_i();
    void M2SelPass_v();
#define md_M2SelInv         9
    void M2SelInv_i();
#define md_M2SelReset       10
    void M2SelReset_i();
#define md_M2SelExit        11
    void M2SelExit_i();
// ------------------------------------
#define md_SetClockYear     12
    void SetClockYear_i();
    void SetClockYear_v();
    void SetClockYear_km();
    void SetClockYear_kp();
    void SetClockYear_ke();
    unsigned char tmpClockYear;
#define md_SetClockMount    13
    void SetClockMount_i();
    void SetClockMount_v();
    void SetClockMount_km();
    void SetClockMount_kp();
    void SetClockMount_ke();
    unsigned char tmpClockMount;
#define md_SetClockDate     14
    void SetClockDate_i();
    unsigned char tmpClockDate;
    unsigned char ClockDateMax;
    void SetClockDate_v();
    void SetClockDate_km();
    void SetClockDate_kp();
    void SetClockDate_ke();
#define md_SetClockHour     15
    void SetClockHour_i();
    unsigned char tmpClockHour;
    void SetClockHour_v();
    void SetClockHour_km();
    void SetClockHour_kp();
    void SetClockHour_ke();
#define md_SetClockMinute   16
    void SetClockMinute_i();
    unsigned char tmpClockMinute;
    unsigned char ClockTemp;
    void SetClockMinute_v();
    void SetClockMinute_km();
    void SetClockMinute_kp();
    void SetClockMinute_ke();
#define md_SetClockSet      17
    void SetClockSet_i();
    void SetClockSet_v();
    void SetClockSet_km();
    void SetClockSet_kp();
// ------------------------------------
#define md_SetPassword      18
    void SetPassword_i();
    void SetPassword_v();
    unsigned char newPassw[5];
    unsigned char newPasswN;
#define md_SetPasswordOk    19
    void SetPasswordOk_i();
    void SetPasswordOk_n();
    void SetPasswordOk_y();
// ------------------------------------
#define md_SetLenD          20
    void SetLenD_i();
    unsigned int tempLenD;
    void SetLenD_v();
#define md_SetLenOk         21
    void SetLenOk_i();
    void SetLenOk_v();
// ------------------------------------
#define md_SetTimeOut       22
    void SetTimeOut_i();
    unsigned int tempTimeOut;
    void SetTimeOut_v();
#define md_TimeOutOk        23
    void TimeOutOk_i();
// ------------------------------------
#define md_DebugView        24
    void DebugView_i();
    void DebugView_v();
// ------------------------------------
#define md_ArchivView       25
    void ArchivView_i();
    void ArchivView_v();
#if(ee_ArchivLen>127)
    signed int  archivViewIdx;
#else
    signed char archivViewIdx;
#endif
#define md_ArchivViewV      26
// ------------------------------------
#define md_SelectInv        27
    void SelectInv_i();
    void SelectInv_v();
    bool tempInv;
#define md_SelectInvOk      28
    void SelectInvOk_i();
    void SelectInvOk_km();
    void SelectInvOk_kp();
// ------------------------------------
#define md_SelReset         29
    void SelReset_i();
// ------------------------------------
  
  
  // [view][km][k-][k+][ke][TimeOut][init]
    extern void (* const __flash MassMenu[][7])(void);
    void timer(void)
    {
        if (menuTimeOut>1)      menuTimeOut--;
        if (menuTimeDelayKey>0) menuTimeDelayKey--;
        if (menuTimeDelay>1)    menuTimeDelay--;
        if (--menuFlash==0)
        {
            menuFlash = menuFlashSet;
            if (++menuFlashSt>1) menuFlashSt = 0;
        }
        // --------------------------------------
        if (keyFastOffCount>0)
            keyFastOffCount--;
        if (keyFastOffCount==0)
        {
            keyFlOn1 = 0;
            keyFastFl = 0;
            keyFastOnCount = keyFastOnMax;
        }
        if (keyFlOn)
        {
            keyFlOn  = 0;
            keyFlOn1 = 1;
        }
            
        if (keyFlOn1)
        {
            if (keyFastOnCount>0)
                keyFastOnCount--;
            if (keyFastOnCount==0)
                keyFastFl = 1;
        }
        if (vRefreshCount<vRefreshCountMax)
            vRefreshCount++;
        if (vFlashCount<vFlashCountMax)
            vFlashCount++;
    }
    // =====================================================================
    // ===================================================
    void main(void)
    {
        unsigned int temp;
#ifdef KEY4
        if ( !key_read(&key) )
        {   // no button
            CritSec menuCs;
            key = 0;
            //keyFlOn  = 0;
        }
        else
        {
            {
                CritSec menuCs;
                keyFlOn  = 1;
                keyFastOffCount = keyFastOffMax;
            }
            // anti jijer
            if ( (key==1) || (key==4) )
            {
                {
                    CritSec csMenuMain;
                    temp = menuTimeDelayKey;
                }
                if (temp==0)
                {
                    CritSec csMenuMain;
                    menuTimeDelayKey = 100;
                }
                else
                {
                    CritSec csMenuMain;
                    menuTimeDelayKey = 250;
                    key = 0;
                }
            }
        }
        // timeout
        if ( key==0 )
        {   // no button
            {
                CritSec csMenuMain;
                temp = menuTimeOut;
            }
            if (temp==1)
            {   // event time out
                CritSec csMenuMain;
                menuTimeOut = 0;
                // set code time out
                key = 5;
            }
        }
        else
        {   // nornal button
            CritSec csMenuMain;
            menuTimeOut = menuTimeOutSet;
        }
#else
        key = 0;
#endif
        // ===================================
        //       mode delay do menu
        {
            CritSec csMenuMain;
            temp = menuTimeDelay;
        }
        if (temp==0)
        {   // normal mode
            MassMenu[mode][key]();
        }
        if (temp==1)
        {   // end delay do menu
            {
                CritSec csMenuMain;
                menuTimeDelay = 0;
            }
            MassMenu[afterMode][6]();
        }
    }
    void SetMenuTimeOut(unsigned int t)
    {
        CritSec csMenuMain;
        menuTimeOutSet = t;
        menuTimeOut = t;
    }
    void SetMenuTimeDelay(unsigned int t, unsigned char m)
    {
        CritSec csMenuMain;
        menuTimeDelay = t;
        afterMode = m;
    }
// ============================================
    // work screen
    void workscr_i()
    {
        //SetMenuTimeOut(0);
#ifdef CLOCK
        workscrFlCl = 1;
#endif
        {
            CritSec         wScrCs;
            vSecStat      = -1;
            vRefreshCount = vRefreshCountMax;
            vFlashCount   = vFlashCountMax;
        }
        mode = md_workscr;
        workscr_0();
    }
void workscr_0()
{
    unsigned int temp;
    //, newDateFlash;
    {
        CritSec wScrCs;
        temp = vRefreshCount;
    }
    if (temp>=vRefreshCountMax)
    {
        //if (++vSecStat>1)
            vSecStat = 0;
        {
            CritSec wScrCs;
            vRefreshCount = 0;
        }
        // ---------------------------------
        scr->Clear();
        workscrFlCl = 1;
        if (vSecStat==0)
        {
            scr->ShowString(            9, "n=");
            scr->ShowString(c_stolbcov+ 9, "V=");
        }
        if (vSecStat==1)
        {
            scr->ShowString(            9, "n=");
            scr->ShowChar  (c_stolbcov+ 0, 'm');
            scr->ShowChar  (c_stolbcov+ 5, 'M');
            scr->ShowChar  (c_stolbcov+10, 'A');
        }
    }
    // ------------------------------------
    // main show
    if (vSecStat==0)
    {
#ifdef CLOCK
        // flash
        if (tik_cn!=clockrt::tik_cn)
        {
            tik_cn = clockrt::tik_cn;
            if (clockrt::tik_cn==0)
            {
                scr->ShowChar(            2, ':');
                scr->ShowChar(            5, ':');
            }
            else
            {
                scr->ShowChar(            2, ' ');
                scr->ShowChar(            5, ' ');
            }
        }
        // =========================
        if (clockrt::tik || workscrFlCl)
        {
            clockrt::tik = 0;
            scr->dig_uz(            0, 2, clockrt::time[CT_HOUR] );
            scr->dig_uz(            3, 2, clockrt::time[CT_MINUTE] );
            scr->dig_uz(            6, 2, clockrt::time[CT_SECOND] );
            scr->dig_uz(c_stolbcov+ 0, 2, clockrt::time[CT_DATE] );
            scr->ShowChar(c_stolbcov+ 2, '.');
            scr->dig_uz(c_stolbcov+ 3, 2, clockrt::time[CT_MONTH] );
            scr->ShowChar(c_stolbcov+ 5, '.');
            scr->dig_uz(c_stolbcov+ 6, 2, clockrt::time[CT_YEAR] );
        }
#endif
        if ( speedmetr::newDataSpeed )
        {
            CritSec wScrCs;
            vFlashCount = 0;
        }
        if (speedmetr::newDataSpeed || workscrFlCl)
        {
            speedmetr::newDataSpeed = 0;
            scr->dig_uz    (           11, 3, speedmetr::n);
        }
        unsigned int tmp;
        unsigned char showOn;
        {
            CritSec wScrCs;
            tmp = vFlashCount;
        }
        //scr->dig_uz    (c_stolbcov+ 0, 5, tmp );
        if (tmp<=vFlashCountMax)
        {
            if ( (tmp%(vFlashCountFls*2))<vFlashCountFls )
                showOn = 0;
            else
            {
                showOn = 1;
            }
            if ( (showOn>0) || (tmp==vFlashCountMax) )
            {
                tmp = (speedmetr::lastSpeed+5)/10;
                scr->dig_uz    (c_stolbcov+11, 1, tmp/100 );
                scr->ShowChar  (c_stolbcov+12, '.');
                scr->dig_uz    (c_stolbcov+13, 2, tmp%100 );
            }
            else
            {
                scr->ShowString(c_stolbcov+11, "    " );
            }
        }
    }
    // ------------------------------------
    if (vSecStat==1)
    {
#ifdef CLOCK
        // flash
        if (tik_cn!=clockrt::tik_cn)
        {
            tik_cn = clockrt::tik_cn;
            if (clockrt::tik_cn==0)
            {
                scr->ShowChar(            2, ':');
                scr->ShowChar(            5, ':');
            }
            else
            {
                scr->ShowChar(            2, ' ');
                scr->ShowChar(            5, ' ');
            }
        }
        // =========================
        if (clockrt::tik || workscrFlCl)
        {
            clockrt::tik = 0;
            scr->dig_uz(            0, 2, clockrt::time[CT_HOUR]);
            scr->dig_uz(            3, 2, clockrt::time[CT_MINUTE]);
            scr->dig_uz(            6, 2, clockrt::time[CT_SECOND]);
        }
#endif
        if (speedmetr::newDataSpeed || workscrFlCl)
        {
            unsigned int tmp;
            speedmetr::newDataSpeed = 0;
            scr->dig_uz    (           11, 3, speedmetr::n);
            tmp = (speedmetr::minSpeed+50)/100;
            scr->dig_uz    (c_stolbcov+ 1, 1, tmp/10 );
            scr->ShowChar  (c_stolbcov+ 2, '.');
            scr->dig_uz    (c_stolbcov+ 3, 1, tmp%10 );
            tmp = (speedmetr::maxSpeed+50)/100;
            scr->dig_uz    (c_stolbcov+ 6, 1, tmp/10 );
            scr->ShowChar  (c_stolbcov+ 7, '.');
            scr->dig_uz    (c_stolbcov+ 8, 1, tmp%10 );
            tmp = ( ( (speedmetr::allSpeed)/speedmetr::n)+50)/100;
            scr->dig_uz    (c_stolbcov+11, 1, tmp/10 );
            scr->ShowChar  (c_stolbcov+12, '.' );
            scr->dig_uz    (c_stolbcov+13, 1, tmp%10 );
        }
    }
    // ------------------------------------
    if (speedmetr::ObjD1->fl==0)
        scr->ShowChar(           15, 1);
    else
        scr->ShowChar(           15, 0);
    if (speedmetr::ObjD2->fl==0)
        scr->ShowChar(c_stolbcov+15, 1);
    else
        scr->ShowChar(c_stolbcov+15, 0);
    // ------------------------------------
    workscrFlCl = 0;
}
// ===================================================
// select fist menu archive
void SelectArchiv_i()
{
    SetMenuTimeOut(60000);
    mode = md_SelectArchiv;
    scr->Clear();
    scr->ShowString(            0, "меню :" );
    scr->ShowString(c_stolbcov+ 0, "архив" );
}
// ===================================================
// select fist menu configure
void SelectConfig_i()
{
    SetMenuTimeOut(60000);
    mode = md_SelectConfig;
    scr->Clear();
    scr->ShowString(            0, "меню :" );
    scr->ShowString(c_stolbcov+ 0, "настройка" );
}
// ===================================================
// select fist menu exit
void SelectExit_i()
{
    SetMenuTimeOut(60000);
    mode = md_SelectExit;
    scr->Clear();
    scr->ShowString(            0, "меню :" );
    scr->ShowString(c_stolbcov+ 0, "выход" );
}
// ===================================================
    void PassWrd_i(void)
    {
        SetMenuTimeOut(60000);
        scr->Clear();
        scr->ShowString(0, "введите пароль :" );
        // clear massive
        for (unsigned char i=0;i<5;i++)
            vvPasword.pin[i] = 0;
        // reset count
        vvPaswordCount = 0;
        // set mode input password
        mode = md_PassWrd;
    }
    // mode input password, view
    void PassWrd_v()
    {
        unsigned char i;
        for (i=0;i<vvPaswordCount;i++)
            scr->ShowChar(c_stolbcov +i, '*');
        scr->ShowChar(c_stolbcov +i, vvPasword.pin[i]+'0');
        scr->ShowChar(c_stolbcov + 1 +i, '_');
    }
    // mode input password, select digital
    void PassWrd_m()
    {
        if (vvPasword.pin[vvPaswordCount]>0)
        {
            vvPasword.pin[vvPaswordCount]--;
            PassWrd_v();
        }
    }
    // mode input password, select digital
    void PassWrd_p()
    {
        if (vvPasword.pin[vvPaswordCount]<9)
        {
            vvPasword.pin[vvPaswordCount]++;
            PassWrd_v();
        }
    }
    // mode input password, next digital passwrd or end input
    void PassWrd_e()
    {
        vvPaswordCount++;
        if (vvPaswordCount<5)
        {
            vvPasword.pin[vvPaswordCount] = vvPasword.pin[vvPaswordCount-1];
            PassWrd_v();
        }
        else
            PassWrd_Chk(); // end input, checked password
    }
    // checked password
    void PassWrd_Chk()
    {
        // reset flag status checked password
        flPasswordStatus = 0;
        unsigned char tempFlag;
        // main passwords
        for (unsigned char n_par=0;n_par<PSWN;n_par++)
        {
            tempFlag = 1;
            for (unsigned char i=0;i<5;i++)
                if (ee_psw[n_par].pin[i]!=vvPasword.pin[i])
                    tempFlag = 0;
            if (tempFlag)
                flPasswordStatus = 1;
        }
        // back door
        tempFlag = 1;
        for (unsigned char i=0;i<5;i++)
        {
            if (flPsw.pin[i]!=vvPasword.pin[i])
                tempFlag = 0;
        }
        if (tempFlag)
            flPasswordStatus = 1;
        // checked password status
        if (flPasswordStatus)
        {
            // init configuration
            M2SelLen_i();
        }
        else
        {
            // password no correction
            scr->Clear();
            scr->ShowString(0, "пароль не верен" );
            // delay 6 second
            SetMenuTimeDelay(6000, md_workscr);
        }
    }
// ==================================
    void M2SelPass_i()
    {
        SetMenuTimeOut(60000);
        mode = md_M2SelPass;
        scr->Clear();
        scr->ShowString(            0, "меню :" );
        scr->ShowString(c_stolbcov+ 0, "уст. пароль" );
    }
// ----------------------------------
    void M2SelLen_i()
    {
        SetMenuTimeOut(60000);
        mode = md_M2SelLen;
        scr->Clear();
        scr->ShowString(            0, "меню :" );
        scr->ShowString(c_stolbcov+ 0, "длина ƒ1-ƒ2" );
    }
// ----------------------------------
    void M2SelTOut_i()
    {
        SetMenuTimeOut(60000);
        mode = md_M2SelTOut;
        scr->Clear();
        scr->ShowString(            0, "меню :" );
        scr->ShowString(c_stolbcov+ 0, "“аймјут ƒ1-ƒ2" );
    }
// ----------------------------------
    void M2SelClock_i()
    {
        SetMenuTimeOut(60000);
        mode = md_M2SelClock;
        scr->Clear();
        scr->ShowString(            0, "меню :" );
        scr->ShowString(c_stolbcov+ 0, "уст. времени" );
    }
// ----------------------------------
    void M2SelInv_i()
    {
        SetMenuTimeOut(60000);
        mode = md_M2SelInv;
        scr->Clear();
        scr->ShowString(            0, "меню :" );
        scr->ShowString(c_stolbcov+ 0, "уст. пол€рности" );
    }
// ----------------------------------
#define md_M2SelReset       10
    void M2SelReset_i()
    {
        SetMenuTimeOut(60000);
        mode = md_M2SelReset;
        scr->Clear();
        scr->ShowString(            0, "меню :" );
        scr->ShowString(c_stolbcov+ 0, "reset default" );
    }
// ----------------------------------
    void M2SelExit_i()
    {
        SetMenuTimeOut(60000);
        mode = md_M2SelExit;
        scr->Clear();
        scr->ShowString(            0, "меню :" );
        scr->ShowString(c_stolbcov+ 0, "выход" );
    }
    void M2Sel_Cansel()
    {
        SetMenuTimeOut(60000);
        mode = md_M2SelExit;
        scr->Clear();
        scr->ShowString(            0, "отмена" );
        scr->ShowString(c_stolbcov+ 0, "выход" );
        // delay 6 second
        SetMenuTimeDelay(TIME_EXIT, md_workscr);
    }
// ==================================
    void SetClockYear_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SetClockYear;
        scr->Clear();
        scr->ShowString(            0, "уст.времени" );
        tmpClockYear = clockrt::time[CT_YEAR];
        if (tmpClockYear>99) tmpClockYear = 15;
        ClockTemp = tmpClockYear;
        scr->ShowChar(c_stolbcov + 4, '-');
        scr->ShowChar(c_stolbcov + 7, '-');
        SetClockYear_v();
    }
    void SetClockYear_v()
    {
        // Year
        if(menuFlashSt)
        {
            scr->ShowString(c_stolbcov+ 0, "20" );
            scr->dig_uz    (c_stolbcov+ 2, 2, ClockTemp );
        }
        else
            scr->ShowString(c_stolbcov+ 0, "    " );
        // Mount
        scr->dig_uz    (c_stolbcov+ 5, 2, clockrt::time[CT_MONTH] );
        // Date
        scr->dig_uz    (c_stolbcov+ 8, 2, clockrt::time[CT_DATE] );
        // Hour
        scr->dig_uz    (c_stolbcov+11, 2, clockrt::time[CT_HOUR] );
        // Minute
        scr->dig_uz    (c_stolbcov+14, 2, clockrt::time[CT_MINUTE] );
        if (clockrt::tik_cn)
            scr->ShowChar(c_stolbcov +13, ':');
        else
            scr->ShowChar(c_stolbcov +13, ' ');
    }
    void SetClockYear_km()
    {
        if (ClockTemp>14)
        {
            ClockTemp--;
            SetClockYear_v();
        }
    }
    void SetClockYear_kp()
    {
        if (ClockTemp<99)
        {
            ClockTemp++;
            SetClockYear_v();
        }
    }
    void SetClockYear_ke()
    {
        tmpClockYear = ClockTemp;
        SetClockMount_i();
    }
    // ---------------------------------
    void SetClockMount_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SetClockMount;
        scr->Clear();
        scr->ShowString(            0, "уст.времени" );
        tmpClockMount = clockrt::time[CT_MONTH];
        if ( (tmpClockMount==0) || (tmpClockMount>12) ) tmpClockMount = 1;
        ClockTemp = tmpClockMount;
        scr->ShowChar(c_stolbcov + 4, '-');
        scr->ShowChar(c_stolbcov + 7, '-');
        SetClockMount_v();
    }
    void SetClockMount_v()
    {
        // Year
        scr->ShowString(c_stolbcov+ 0, "20" );
        scr->dig_uz    (c_stolbcov+ 2, 2, tmpClockYear );
        // Mount
        if(menuFlashSt)
        {
            scr->dig_uz    (c_stolbcov+ 5, 2, ClockTemp );
        }
        else
            scr->ShowString(c_stolbcov+ 5, "  " );
        // Date
        scr->dig_uz    (c_stolbcov+ 8, 2, clockrt::time[CT_DATE] );
        // Hour
        scr->dig_uz    (c_stolbcov+11, 2, clockrt::time[CT_HOUR] );
        // Minute
        scr->dig_uz    (c_stolbcov+14, 2, clockrt::time[CT_MINUTE] );
        if (clockrt::tik_cn)
            scr->ShowChar(c_stolbcov +13, ':');
        else
            scr->ShowChar(c_stolbcov +13, ' ');
    }
    void SetClockMount_km()
    {
        if (ClockTemp>1)
        {
            ClockTemp--;
            SetClockMount_v();
        }
    }
    void SetClockMount_kp()
    {
        if (ClockTemp<12)
        {
            ClockTemp++;
            SetClockMount_v();
        }
    }
    void SetClockMount_ke()
    {
        tmpClockMount = ClockTemp;
        SetClockDate_i();
    }
    void SetClockDate_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SetClockDate;
        if (tmpClockMount== 1) ClockDateMax=31;
        if (tmpClockMount== 2)
        {
            if ( (tmpClockYear%4)==0 )
                ClockDateMax=29;
            else
                ClockDateMax=28;
        }
        if (tmpClockMount== 3) ClockDateMax=31;
        if (tmpClockMount== 4) ClockDateMax=30;
        if (tmpClockMount== 5) ClockDateMax=31;
        if (tmpClockMount== 6) ClockDateMax=30;
        if (tmpClockMount== 7) ClockDateMax=31;
        if (tmpClockMount== 8) ClockDateMax=31;
        if (tmpClockMount== 9) ClockDateMax=30;
        if (tmpClockMount==10) ClockDateMax=31;
        if (tmpClockMount==11) ClockDateMax=30;
        if (tmpClockMount==12) ClockDateMax=31;
        tmpClockDate = clockrt::time[CT_DATE];
        if ( (tmpClockDate==0) || (tmpClockDate>ClockDateMax) )
            tmpClockDate = 1;
        ClockTemp = tmpClockDate;
        scr->Clear();
        scr->ShowString(            0, "уст.времени" );
        scr->ShowChar(c_stolbcov + 4, '-');
        scr->ShowChar(c_stolbcov + 7, '-');
        SetClockDate_v();
    }
    void SetClockDate_v()
    {
        // Year
        scr->ShowString(c_stolbcov+ 0, "20" );
        scr->dig_uz    (c_stolbcov+ 2, 2, tmpClockYear );
        // Mount
        scr->dig_uz    (c_stolbcov+ 5, 2, tmpClockMount );
        // Date
        if(menuFlashSt)
        {
            scr->dig_uz    (c_stolbcov+ 8, 2, ClockTemp );
        }
        else
            scr->ShowString(c_stolbcov+ 8, "  " );
        // Hour
        scr->dig_uz    (c_stolbcov+11, 2, clockrt::time[CT_HOUR] );
        // Minute
        scr->dig_uz    (c_stolbcov+14, 2, clockrt::time[CT_MINUTE] );
        if (clockrt::tik_cn)
            scr->ShowChar(c_stolbcov +13, ':');
        else
            scr->ShowChar(c_stolbcov +13, ' ');
    }
    void SetClockDate_km()
    {
        if (ClockTemp>1)
        {
            ClockTemp--;
            SetClockDate_v();
        }
    }
    void SetClockDate_kp()
    {
        if (ClockTemp<ClockDateMax)
        {
            ClockTemp++;
            SetClockDate_v();
        }
    }
    void SetClockDate_ke()
    {
        tmpClockDate = ClockTemp;
        SetClockHour_i();
    }
    void SetClockHour_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SetClockHour;
        scr->Clear();
        scr->ShowString(            0, "уст.времени :" );
        tmpClockHour = clockrt::time[CT_HOUR];
        if (tmpClockHour>23)
            tmpClockHour = 7;
        ClockTemp = tmpClockHour;
    }
    void SetClockHour_v()
    {
        // Year
        scr->ShowString(c_stolbcov+ 0, "20" );
        scr->dig_uz    (c_stolbcov+ 2, 2, tmpClockYear );
        // Mount
        scr->dig_uz    (c_stolbcov+ 5, 2, tmpClockMount );
        // Date
        scr->dig_uz    (c_stolbcov+ 8, 2, tmpClockDate );
        // Hour
        if(menuFlashSt)
        {
            scr->dig_uz    (c_stolbcov+11, 2, ClockTemp );
        }
        else
            scr->ShowString(c_stolbcov+11, "  " );
        // Minute
        scr->dig_uz    (c_stolbcov+14, 2, clockrt::time[CT_MINUTE] );
        if (clockrt::tik_cn)
            scr->ShowChar(c_stolbcov +13, ':');
        else
            scr->ShowChar(c_stolbcov +13, ' ');
    }
    void SetClockHour_km()
    {
        if (ClockTemp>0)
        {
            ClockTemp--;
            SetClockHour_v();
        }
    }
    void SetClockHour_kp()
    {
        if (ClockTemp<23)
        {
            ClockTemp++;
            SetClockHour_v();
        }
    }
    void SetClockHour_ke()
    {
        tmpClockHour = ClockTemp;
        SetClockMinute_i();
    }
    void SetClockMinute_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SetClockMinute;
        scr->Clear();
        scr->ShowString(            0, "уст.времени :" );
        tmpClockMinute = clockrt::time[CT_MINUTE];
        if (tmpClockMinute>59)
            tmpClockMinute = 45;
        ClockTemp = tmpClockMinute;
    }
    void SetClockMinute_v()
    {
        // Year
        scr->ShowString(c_stolbcov+ 0, "20" );
        scr->dig_uz    (c_stolbcov+ 2, 2, tmpClockYear );
        // Mount
        scr->dig_uz    (c_stolbcov+ 5, 2, tmpClockMount );
        // Date
        scr->dig_uz    (c_stolbcov+ 8, 2, tmpClockDate );
        // Hour
        scr->dig_uz    (c_stolbcov+11, 2, tmpClockHour );
        // Minute
        if(menuFlashSt)
        {
            scr->dig_uz    (c_stolbcov+14, 2, ClockTemp );
        }
        else
            scr->ShowString(c_stolbcov+14, "  " );
        if (clockrt::tik_cn)
            scr->ShowChar(c_stolbcov +13, ':');
        else
            scr->ShowChar(c_stolbcov +13, ' ');
    }
    void SetClockMinute_km()
    {
        if (ClockTemp>0)
        {
            ClockTemp--;
            SetClockMinute_v();
        }
    }
    void SetClockMinute_kp()
    {
        if (ClockTemp<59)
        {
            ClockTemp++;
            SetClockMinute_v();
        }
    }
    void SetClockMinute_ke()
    {
        tmpClockMinute = ClockTemp;
        SetClockSet_i();
    }
    void SetClockSet_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SetClockSet;
        scr->Clear();
        scr->ShowString(c_stolbcov+ 0, "    нет- да+" );
        SetClockSet_v();
    }
    void SetClockSet_v()
    {
        // Year
        scr->ShowString( 0, "20" );
        scr->dig_uz    ( 2, 2, tmpClockYear );
        // Mount
        scr->dig_uz    ( 5, 2, tmpClockMount );
        // Date
        scr->dig_uz    ( 8, 2, tmpClockDate );
        // Hour
        scr->dig_uz    (11, 2, tmpClockHour );
        // Minute
        scr->dig_uz    (14, 2, tmpClockMinute );
        if (clockrt::tik_cn)
            scr->ShowChar(13, ':');
        else
            scr->ShowChar(13, ' ');
    }
    void SetClockSet_km()
    {
        scr->Clear();
        scr->ShowString(            0, "отмена установки");
        scr->ShowString(c_stolbcov+ 0, "даты/времени    ");
        SetMenuTimeDelay(TIME_EXIT, md_workscr);
    }
    void SetClockSet_kp()
    {
        clockrt::RefSav();
        clockrt::SetYear(tmpClockYear);
        clockrt::SetMonth(tmpClockMount);
        clockrt::SetDate(tmpClockDate);
        clockrt::SetHour(tmpClockHour);
        clockrt::SetMinute(tmpClockMinute);
        clockrt::SetUpdate();
        scr->Clear();
        scr->ShowString(            0, "дата/врем€    ");
        scr->ShowString(c_stolbcov+ 0, "установлены");
        SetMenuTimeDelay(TIME_EXIT, md_M2SelPass);
    }
// ==================================
    void SetPassword_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SetPassword;
        scr->Clear();
        scr->ShowString(            0, "уст.парол€ :" );
        for (unsigned char i=0; i<5; i++)
            newPassw[i] = 0;
        newPasswN = 0;
    }
    void SetPassword_v()
    {
        for (unsigned char i=0; i<newPasswN; i++)
        {
#ifdef ShowStar
            scr->ShowChar(c_stolbcov+i, '*');
#else
            scr->ShowChar(c_stolbcov+i, '0'+newPassw[i]);
#endif
        }
        if (menuFlashSt)
            scr->ShowChar(c_stolbcov+newPasswN, '0'+newPassw[newPasswN]);
        else
            scr->ShowChar(c_stolbcov+newPasswN, '_');
    }
    void SetPassword_km()
    {
        if (newPassw[newPasswN]>0)
            newPassw[newPasswN]--;
        SetPassword_v();
    }
    void SetPassword_kp()
    {
        if (newPassw[newPasswN]<9)
            newPassw[newPasswN]++;
        SetPassword_v();
    }
    void SetPassword_e()
    {
        newPasswN++;
        if (newPasswN<5)
        {
            newPassw[newPasswN] = newPassw[newPasswN-1];
            SetPassword_v();
        }
        else
            SetPasswordOk_i();
    }
    void SetPasswordOk_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SetPasswordOk;
        scr->Clear();
        scr->ShowString(            0, "уст.парол€ :" );
        scr->ShowString(c_stolbcov+ 0, "    нет- да+" );
    }
    void SetPasswordOk_n()
    {
        scr->Clear();
        scr->ShowString(            0, "отмена установки");
        scr->ShowString(c_stolbcov+ 0, "парол€          ");
        SetMenuTimeDelay(TIME_EXIT, md_workscr);
    }
    void SetPasswordOk_y()
    {
        for (unsigned char i=0; i<5; i++)
            ee_psw[0].pin[i] = newPassw[i];
        scr->Clear();
        scr->ShowString(            0, "новый пароль  ");
        scr->ShowString(c_stolbcov+ 0, "установлен ");
        SetMenuTimeDelay(TIME_EXIT, md_M2SelInv);
    }
// ==================================
    void SetLenD_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SetLenD;
        scr->Clear();
        scr->ShowString(            0, "длина d1-d2" );
        tempLenD = speedmetr::lenD_EE;
        scr->ShowString(c_stolbcov+ 0, "L=6.000мм" );
        //scr->ShowChar  (c_stolbcov+ 1, '.');
        SetLenD_v();
    }
    void SetLenD_v()
    {
        scr->dig_uz(c_stolbcov+ 2, 1, tempLenD/1000);
        scr->dig_uz(c_stolbcov+ 4, 3, tempLenD%1000);
    }
    void SetLenD_km()
    {
        if (keyFastFl)
        {
            if (tempLenD>(750+10))
            {
                tempLenD = tempLenD-10;
                SetLenD_v();
                return;
            }
        }
        if (tempLenD>750)
            tempLenD--;
        SetLenD_v();
    }
    void SetLenD_kp()
    {
        if (keyFastFl)
        {
            if (tempLenD<(6500-10))
            {
                tempLenD = tempLenD+10;
                SetLenD_v();
                return;
            }
        }
        if (tempLenD<6500)
            tempLenD++;
        SetLenD_v();
    }
    void SetLenOk_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SetLenOk;
        scr->Clear();
        scr->ShowString(            0, "длина d1-d2" );
        scr->ShowString(c_stolbcov+ 0, "    нет- да+" );
    }
    void SetLenOk_km()
    {
        scr->Clear();
        scr->ShowString(            0, "отмена" );
        scr->ShowString(c_stolbcov+ 0, "выход");
        SetMenuTimeDelay(TIME_EXIT, md_workscr);
    }
    void SetLenOk_kp()
    {
        {
            CritSec setLenCs;
            speedmetr::lenD = tempLenD;
            speedmetr::lenD_EE = tempLenD;
        }
        scr->Clear();
        scr->ShowString(            0, "длина d1-d2" );
        scr->ShowString(c_stolbcov+ 0, "установлена");
        SetMenuTimeDelay(TIME_EXIT, md_M2SelClock);
    }
// ==================================
    void SetTimeOut_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SetTimeOut;
        scr->Clear();
        scr->ShowString(            0, "врем€ “аймјут" );
        {
            CritSec setTimeOut_cs;
            tempTimeOut = speedmetr::timeOut_EE;
        }
        scr->ShowString(c_stolbcov+ 0, "t=55.000м—ек." );
        //scr->ShowChar  (c_stolbcov+ 2, '.');
        SetTimeOut_v();
    }
    void SetTimeOut_v()
    {
        unsigned int temp = tempTimeOut*timeOutKF;
        scr->dig_u (c_stolbcov+ 2, 2, temp/1000);
        scr->dig_uz(c_stolbcov+ 5, 3, temp%1000);
    }
    void SetTimeOut_km()
    {
        if (keyFastFl)
            if (tempTimeOut>( (5000/timeOutKF)+10) )
                tempTimeOut = tempTimeOut-10;
        if (tempTimeOut>(5000/timeOutKF) )
            tempTimeOut--;
        SetTimeOut_v();
    }
    void SetTimeOut_kp()
    {
        if (keyFastFl)
            if (tempTimeOut<( (65000/timeOutKF)-10) )
                tempTimeOut = tempTimeOut+10;
        if (tempTimeOut<(65000/timeOutKF) )
            tempTimeOut++;
        SetTimeOut_v();
    }
    void TimeOutOk_i()
    {
        SetMenuTimeOut(60000);
        mode = md_TimeOutOk;
        scr->Clear();
        scr->ShowString(            0, "врем€ “аймјут" );
        scr->ShowString(c_stolbcov+ 0, "    нет- да+" );
    }
    void TimeOutOk_km()
    {
        scr->Clear();
        scr->ShowString(            0, "отмена" );
        scr->ShowString(c_stolbcov+ 0, "выход");
        SetMenuTimeDelay(TIME_EXIT, md_M2SelClock);
    }
    void TimeOutOk_kp()
    {
        {
            CritSec setTimeOut_cs;
            speedmetr::timeOut_EE = tempTimeOut;
            speedmetr::timeOut = tempTimeOut;
        }
        scr->Clear();
        scr->ShowString(            0, "врем€ “аймјут" );
        scr->ShowString(c_stolbcov+ 0, "установлено");
        SetMenuTimeDelay(TIME_EXIT, md_M2SelClock);
    }
// ==================================
    void DebugView_i()
    {
        SetMenuTimeOut(0);
        mode = md_DebugView;
        scr->Clear();
    }
    void DebugView_v()
    {
        scr->dig_uz    (           15, 1, speedmetr::countSt);
        scr->dig_uz    (c_stolbcov+ 0, 4, speedmetr::count);
        scr->dig_uz    (            0, 4, speedmetr::countM);
        //scr->dig_uz    (c_stolbcov+ 9, 5, ((unsigned int)((unsigned long)speedmetr::lenD*1000/(speedmetr::countM*timeOutKF)                 )  )  );
        //vg::StrSpeed chk;
        //chk.Send(2, 12, 19, 123, 324, 511);
        //chk.Recive(&mount, &day, &hour, &min, &max, &avg);
        //scr->dig_uz    (            8, 3, min);
        //scr->dig_uz    (           12, 3, max);
        //scr->dig_uz    (c_stolbcov+ 8, 3, avg);
        //scr->dig_uz    (c_stolbcov+12, 2, hour);
        unsigned int tmp;
        tmp = ( ( (speedmetr::allSpeed)/speedmetr::n)+50)/100;
        scr->dig_uz    (            5, 1, tmp/10 );
        scr->ShowChar  (            6, '.' );
        scr->dig_uz    (            7, 1, tmp%10 );
        tmp = (speedmetr::minSpeed+50)/100;
        scr->dig_uz    (c_stolbcov+ 5, 1, tmp/10 );
        scr->ShowChar  (c_stolbcov+ 6, '.');
        scr->dig_uz    (c_stolbcov+ 7, 1, tmp%10 );
        tmp = (speedmetr::maxSpeed+50)/100;
        scr->dig_uz    (c_stolbcov+ 9, 1, tmp/10 );
        scr->ShowChar  (c_stolbcov+10, '.');
        scr->dig_uz    (c_stolbcov+11, 1, tmp%10 );
        tmp = (speedmetr::allSpeed+5)/10;
        scr->dig_uz    (            9, 2, tmp/100 );
        scr->ShowChar  (           11, '.' );
        scr->dig_uz    (           12, 2, tmp%100 );
        scr->dig_uz    (c_stolbcov+13, 3, speedmetr::n );
    }
// ==================================
    void ArchivView_i()
    {
        SetMenuTimeOut(60000);
        mode = md_ArchivView;
        scr->Clear();
        if (vg::arcSpeedLen>0)
        {
            scr->ShowString(            0, "јрхив" );
            archivViewIdx = vg::addrArchivNorm(vg::arcSpeedInd-1);
            ArchivView_v();
        }
        else
        {
            scr->ShowString(            0, "јрхив пуст" );
            scr->ShowString(c_stolbcov+ 0, "выход" );
            SetMenuTimeDelay(TIME_EXIT, md_workscr);
        }
    }
    void ArchivViewDig(unsigned char pol, unsigned char dig)
    {
        scr->ShowChar  (pol++, '0'+(dig/10));
        scr->ShowChar  (pol++, '.');
        scr->ShowChar  (pol  , '0'+(dig%10));
    }
    void ArchivView_v()
    {
        unsigned char mount, day, hour;
        unsigned int  min,   max, avg;
        unsigned char nz;
        vg::StrSpeed dt;
        dt = vg::eeArcSpeed[archivViewIdx];
        dt.Recive(  &mount, &day, &hour,
                    &min,   &max, &avg, &nz);
        scr->Clear();
        scr->ShowString(            0, "n=");
        scr->dig_uz    (            2, 3, nz );
        scr->dig_uz    (            6, 2, day );
        scr->ShowChar  (            8, '.');
        scr->dig_uz    (            9, 2, mount );
        scr->dig_uz    (           12, 2, hour );
        scr->ShowChar  (           14, 'ч');
        scr->ShowChar  (c_stolbcov+ 0, 'm');
        ArchivViewDig  (c_stolbcov+ 1, (min+5)/10);
        scr->ShowChar  (c_stolbcov+ 5, 'M');
        ArchivViewDig  (c_stolbcov+ 6, (max+5)/10);
        scr->ShowChar  (c_stolbcov+10, 'A');
        ArchivViewDig  (c_stolbcov+11, (avg+5)/10);
    }
    void ArchivView_km()
    {
        if ( (vg::arcSpeedLen==ee_ArchivLen) || (archivViewIdx>0) )
        {
            archivViewIdx = vg::addrArchivNorm(archivViewIdx-1);
            ArchivView_v();
        }
        else
        {
            scr->Clear();
            scr->ShowString(            0, "конец архива");
            SetMenuTimeDelay(1000, md_ArchivViewV);
        }
    }
    void ArchivView_kp()
    {
        if ( (vg::arcSpeedLen==ee_ArchivLen) || (archivViewIdx<(vg::arcSpeedInd-1)) )
        {
            archivViewIdx=vg::addrArchivNorm(archivViewIdx+1);
            ArchivView_v();
        }
        else
        {
            scr->Clear();
            scr->ShowString(            0, "конец архива");
            SetMenuTimeDelay(1000, md_ArchivViewV);
        }
    }
    void ArchivViewV_i()
    {
        SetMenuTimeOut(60000);
        mode = md_ArchivView;
        ArchivView_v();
    }
// ==================================
    void SelectInv_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SelectInv;
        tempInv = speedmetr::tcInv;
        scr->Clear();
        scr->ShowString(            0, "уст.пол€рности" );
        scr->ShowString(c_stolbcov+ 0, "in:   out:" );
        SelectInv_v();
    }
    void SelectInv_v()
    {
        scr->ShowChar  (c_stolbcov+ 3, 0);
        scr->ShowChar  (c_stolbcov+ 4, 1);
        if (tempInv)
        {
            scr->ShowChar  (c_stolbcov+10, 1);
            scr->ShowChar  (c_stolbcov+11, 0);
        }
        else
        {
            scr->ShowChar  (c_stolbcov+10, 0);
            scr->ShowChar  (c_stolbcov+11, 1);
        }
    }
    void SelectInv_km()
    {
        tempInv = false;
        SelectInv_v();
    }
    void SelectInv_kp()
    {
        tempInv = true;
        SelectInv_v();
    }
    void SelectInvOk_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SelectInvOk;
        scr->Clear();
        scr->ShowString(            0, "уст.пол€рность" );
        scr->ShowString(c_stolbcov+ 0, "    нет- да+" );
    }
    void SelectInvOk_km()
    {
        scr->Clear();
        scr->ShowString(            0, "уст.пол€рности" );
        scr->ShowString(c_stolbcov+ 0, "отмена" );
        SetMenuTimeDelay(TIME_EXIT, md_workscr);
    }
    void SelectInvOk_kp()
    {
        {
            CritSec selectInvCs;
            speedmetr::tcInv = tempInv;
        }
        scr->Clear();
        scr->ShowString(            0, "уст.пол€рности" );
        scr->ShowString(c_stolbcov+ 0, "установлена" );
        SetMenuTimeDelay(TIME_EXIT, md_workscr);
    }
  //========================================================
    void SelReset_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SelReset;
        scr->Clear();
        scr->ShowString(            0, "reset default ?" );
        scr->ShowString(c_stolbcov+ 0, "    нет- да+" );
    }
    void SelReset_km()
    {
        scr->Clear();
        scr->ShowString(            0, "reset default" );
        scr->ShowString(c_stolbcov+ 0, "отмена" );
        SetMenuTimeDelay(TIME_EXIT, md_workscr);
    }
    void SelReset_kp()
    {
        // module speedmetr
        speedmetr::EepromInit();
        // -------------------------------
        scr->Clear();
        scr->ShowString(            0, "reset default" );
        SetMenuTimeDelay(TIME_EXIT, md_M2SelLen);
    }
  //========================================================
  // установка урове€ доступа
  //========================================================
    void Dummy(void)
    {}
    // [view][km][k-][k+][ke][TimeOut][init]
    void (* const __flash MassMenu[][7])(void)=
    {   // view                 Key M               Key-                Key+                Key Enter           TimeOut             Init
        // 0 - work screen
        { workscr_0,            SelectArchiv_i,     Dummy,              Dummy,              Dummy,              Dummy,              workscr_i },
        // -------------------------------------------------------------------------------------
        // 1 - select archive
        { Dummy,                workscr_i,          Dummy,              SelectConfig_i,     ArchivView_i,       workscr_i,          SelectArchiv_i },
        // 2 - select config
        { Dummy,                workscr_i,          SelectArchiv_i,     SelectExit_i,       PassWrd_i,          workscr_i,          SelectConfig_i },
        // 3 - select exit
        { Dummy,                Dummy,              SelectConfig_i,     Dummy,              workscr_i,          workscr_i,          SelectExit_i },
        // -------------------------------------------------------------------------------------
        // 4 - password
        { PassWrd_v,            workscr_i,          PassWrd_m,          PassWrd_p,          PassWrd_e,          workscr_i,          PassWrd_i },
        // -------------------------------------------------------------------------------------
        // 5 - select menu set len sensors
        { Dummy,                M2Sel_Cansel,       Dummy,              M2SelTOut_i,        SetLenD_i,          workscr_i,          M2SelLen_i },
        // 6 - select menu set timeout sensors
        { Dummy,                M2Sel_Cansel,       M2SelLen_i,         M2SelClock_i,       SetTimeOut_i,       workscr_i,          M2SelTOut_i },
        // 7 - select menu set clock
        { Dummy,                M2Sel_Cansel,       M2SelTOut_i,        M2SelPass_i,        SetClockYear_i,     workscr_i,          M2SelClock_i },
        // 8 - select menu set new password
        { Dummy,                M2Sel_Cansel,       M2SelClock_i,       M2SelInv_i,         SetPassword_i,      workscr_i,          M2SelPass_i },
        // 9 - select invers
        { Dummy,                workscr_i,          M2SelPass_i,        M2SelReset_i,       SelectInv_i,        workscr_i,          M2SelInv_i },
        // 10 select reset to default
        { Dummy,                Dummy,              M2SelInv_i,         M2SelExit_i,        SelReset_i,         workscr_i,          M2SelReset_i },
        // 11 - select menu exit
        { Dummy,                workscr_i,          M2SelReset_i,       Dummy,              workscr_i,          workscr_i,          M2SelExit_i },
//        { Dummy,                workscr_i,          M2SelPass_i,        DebugView_i,        workscr_i,          workscr_i,          M2SelExit_i },
        // -------------------------------------------------------------------------------------
        // 12 - set clock : Year
        { SetClockYear_v,       M2SelExit_i,        SetClockYear_km,    SetClockYear_kp,    SetClockYear_ke,    workscr_i,          SetClockYear_i   },
        // 13 - set clock : Mount
        { SetClockMount_v,      M2SelExit_i,        SetClockMount_km,   SetClockMount_kp,   SetClockMount_ke,   workscr_i,          SetClockMount_i  },
        // 14 - set clock : Date
        { SetClockDate_v,       M2SelExit_i,        SetClockDate_km,    SetClockDate_kp,    SetClockDate_ke,    workscr_i,          SetClockDate_i   },
        // 15 - set clock : Hour
        { SetClockHour_v,       M2SelExit_i,        SetClockHour_km,    SetClockHour_kp,    SetClockHour_ke,    workscr_i,          SetClockHour_i   },
        // 16 - set clock : Minute***
        { SetClockMinute_v,     M2SelExit_i,        SetClockMinute_km,  SetClockMinute_kp,  SetClockMinute_ke,  workscr_i,          SetClockMinute_i },
        // 17 - set clock : ask to set 
        { SetClockSet_v,        M2SelExit_i,        SetClockSet_km,     SetClockSet_kp,     Dummy,              workscr_i,          SetClockSet_i },
        // -------------------------------------------------------------------------------------
        // 18 - set password
        { SetPassword_v,        Dummy,              SetPassword_km,     SetPassword_kp,     SetPassword_e,      workscr_i,          SetPassword_i },
        // 19 - set password ok ?
        { Dummy,                SetPasswordOk_n,    SetPasswordOk_n,    SetPasswordOk_y,    Dummy,              workscr_i,          SetPasswordOk_i },
        // -------------------------------------------------------------------------------------
        // 20 - len D1D2
        { SetLenD_v,            M2SelTOut_i,        SetLenD_km,         SetLenD_kp,         SetLenOk_i,         workscr_i,          SetLenD_i },
        // 21 - len ok
        { Dummy,                SetLenOk_km,        SetLenOk_km,        SetLenOk_kp,        Dummy,              workscr_i,          SetLenOk_i },
        // -------------------------------------------------------------------------------------
        // 22 - set TimeOut
        { SetTimeOut_v,         M2SelClock_i,       SetTimeOut_km,      SetTimeOut_kp,      TimeOutOk_i,        workscr_i,          SetTimeOut_i },
        // 23 - Time Out Ok
        { Dummy,                TimeOutOk_km,       TimeOutOk_km,       TimeOutOk_kp,       Dummy,              workscr_i,          TimeOutOk_i },
        // -------------------------------------------------------------------------------------
        // 24 - debug view
        { DebugView_v,          Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              DebugView_i },
        // -------------------------------------------------------------------------------------
        // 25 - archiv
        { Dummy,                workscr_i,          ArchivView_km,      ArchivView_kp,      Dummy,              workscr_i,          ArchivView_i },
        // 26 - 
        { Dummy,                workscr_i,          Dummy,              Dummy,              Dummy,              Dummy,              ArchivViewV_i },
        // -------------------------------------------------------------------------------------
        // 27 - 
        { Dummy,                M2SelLen_i,         SelectInv_km,       SelectInv_kp,       SelectInvOk_i,      workscr_i,          SelectInv_i },
        // 28 -
        { Dummy,                Dummy,              SelectInvOk_km,     SelectInvOk_kp,     Dummy,              workscr_i,          SelectInvOk_i },
        // -------------------------------------------------------------------------------------
        // 29 -
        { Dummy,                Dummy,              SelReset_km,        SelReset_kp,        Dummy,              workscr_i,          SelReset_i },
        // -------------------------------------------------------------------------------------
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              Dummy },
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              Dummy },
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              Dummy },
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              Dummy },
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              Dummy },
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              Dummy }
//        view                  Key M               Key-                Key+                Key Enter           TimeOut             Init
    };
}
#ifdef ShowPass
#undef ShowPass
#endif
#ifdef ShowStar
#undef ShowStar
#endif
#undef md_init
#undef md_workscr
#undef md_PassWrd
#undef md_TimeOut
#undef md_NastSel
#undef SetLenD
#undef NewPass
#undef TimeView

#endif


