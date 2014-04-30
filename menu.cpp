
#include "main.h"
#ifdef MENU
#include "menu.h"

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//            показ старого пароля при установки нового пароля
// #define ShowPass


//              закрывать звездочками новый вводимый пароль
#define ShowStar


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


namespace ns_menu
{
    //=================================
    unsigned char key;
    unsigned int  keyTout = 0;
    unsigned int  keyToutx;
    unsigned int  keyTout1 = 0;
    unsigned int  keyTout1x;
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
    unsigned int  menuTimeDelay = 0;
    unsigned char afterMode = 0;
    // flash
#define menuFlashSet 300
    unsigned int  menuFlash = menuFlashSet/2;
    unsigned char menuFlashSt = 0;
    // ==============================
  unsigned int  menuTimeOutx;
  unsigned char vNastSel;
  unsigned char vNastSelx;
  signed int  position_min;
  signed int  position_max;
  signed int  position_cur;
//  unsigned char TimeViewInd;
    // ================================================
    // N mode/step menu
    unsigned char mode;
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
#define md_M2SelPass        5
    void M2SelPass_i();
    void M2SelPass_v();
#define md_M2SelLen         6
    void M2SelLen_i();
#define md_M2SelTOut        7
    void M2SelTOut_i();
#define md_M2SelClock       8
    void M2SelClock_i();
#define md_M2SelExit        9
    void M2SelExit_i();
// ------------------------------------
#define md_SetClockYear     10
    void SetClockYear_i();
    void SetClockYear_v();
    void SetClockYear_km();
    void SetClockYear_kp();
    void SetClockYear_ke();
    unsigned char tmpClockYear;
#define md_SetClockMount    11
    void SetClockMount_i();
    void SetClockMount_v();
    void SetClockMount_km();
    void SetClockMount_kp();
    void SetClockMount_ke();
    unsigned char tmpClockMount;
#define md_SetClockDate     12
    void SetClockDate_i();
    unsigned char tmpClockDate;
    unsigned char ClockDateMax;
    void SetClockDate_v();
    void SetClockDate_km();
    void SetClockDate_kp();
    void SetClockDate_ke();
#define md_SetClockHour     13
    void SetClockHour_i();
    unsigned char tmpClockHour;
    void SetClockHour_v();
    void SetClockHour_km();
    void SetClockHour_kp();
    void SetClockHour_ke();
#define md_SetClockMinute   14
    void SetClockMinute_i();
    unsigned char tmpClockMinute;
    unsigned char ClockTemp;
    void SetClockMinute_v();
    void SetClockMinute_km();
    void SetClockMinute_kp();
    void SetClockMinute_ke();
#define md_SetClockSet      15
    void SetClockSet_i();
    void SetClockSet_v();
    void SetClockSet_km();
    void SetClockSet_kp();
// ------------------------------------
#define md_SetPassword      16
    void SetPassword_i();
    void SetPassword_v();
    unsigned char newPassw[5];
    unsigned char newPasswN;
#define md_SetPasswordOk    17
    void SetPasswordOk_i();
    void SetPasswordOk_n();
    void SetPasswordOk_y();
// ------------------------------------
#define md_SetLenD      18
    void SetLenD_i();
// ------------------------------------




    
    
    
    



    
    
    
    
    
    
    
    







#define md_PaswSel  5
  // выбор пароля
  unsigned PaswSel_OldPsw;
  unsigned PaswSel_CntPsw;
  void PaswSel_i();
  void PaswSel_0();
  void PaswSel_1();
  void PaswSel_2();
  void PaswSel_3();
  void PaswSel_4();
#define md_PaswSetPsw 6
  // установка пароля
  unsigned char PaswSetPsw_Pasw[5];
  unsigned char PaswSetPsw_Count;
  void PaswSetPsw_i();
  void PaswSetPsw_0();
  void PaswSetPsw_1();
  void PaswSetPsw_2();
  void PaswSetPsw_3();
  void PaswSetPsw_4();
#define md_PaswSetAcs 7
  // установка пароля
  unsigned char PaswSetAcs_mask;
  unsigned char PaswSetAcs_count;
  void PaswSetAcs_i();
  void PaswSetAcs_0();
  void PaswSetAcs_1();
  void PaswSetAcs_2();
  void PaswSetAcs_3();
  void PaswSetAcs_4();
#define md_DateYear 8
  // ввод года
  unsigned char Date_Year;
  void DateYear_i();
  void DateYear_0();
  void DateYear_1();
  void DateYear_2();
  void DateYear_3();
  void DateYear_4();
#define md_DateMonth 9
  // ввод месяца
  unsigned char Date_Month;
  void DateMonth_i();
  void DateMonth_0();
  void DateMonth_1();
  void DateMonth_2();
  void DateMonth_3();
  void DateMonth_4();
#define md_DateDate 10
  // ввод числа
  unsigned char Date_Date;
  unsigned char DateDate_Max;
  void DateDate_i();
  void DateDate_0();
  void DateDate_1();
  void DateDate_2();
  void DateDate_3();
  void DateDate_4();
#define md_DateHour 11
  // ввод часов
  unsigned char Date_Hour;
  void DateHour_i();
  void DateHour_0();
  void DateHour_1();
  void DateHour_2();
  void DateHour_3();
  void DateHour_4();
#define md_DateMinute 12
  // ввод минут
  unsigned char Date_Minute;
  void DateMinute_i();
  void DateMinute_0();
  void DateMinute_1();
  void DateMinute_2();
  void DateMinute_3();
  void DateMinute_4();
#define md_DateSet 13
  // потверждение или отказ от установки даты
  void DateSet_i();
  void DateSet_2();
  void DateSet_3();
#define md_Zero 14
  // требование ввести пароль
#define md_ZaSmenu 15
  // за смену
  unsigned long ZaSmenu_Old;
  unsigned long K_Metr;
  void ZaSmenu_i();
  void ZaSmenu_0();
#define md_Archiv 16
  // архив
  //unsigned int  ZaSmenu_Old;
  unsigned long K_Kg;
  unsigned int vArchivIndx;
  void Archiv_i();
  void Archiv_s();
  void Archiv_2();
  void Archiv_3();
#define md_Kmetr 17
  // метровый кофицент
  char Kedit[20];
  unsigned char Kediti;
  void Kmetr_i();
  void Kmetr_s();
  void Kmetr_0();
  void Kmetr_2();
  void Kmetr_3();
  void Kmetr_4();
#define md_KmetrSav 18
  // метровый кофицент сохранение
  void KmetrSav_i();
  void KmetrSav_2();
  void KmetrSav_3();
#define md_Kkg 19
  // метровый кофицент
  void Kkg_i();
  void Kkg_s();
  void Kkg_0();
  void Kkg_2();
  void Kkg_3();
  void Kkg_4();
#define md_KkgSav 20
  // метровый кофицент сохранение
  void KkgSav_i();
  void KkgSav_2();
  void KkgSav_3();

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
        /* timer2 debug
        static unsigned char debugT = 0;
        static unsigned int  debugTp = 0;
        if (++debugTp>=1000)
        {
            debugTp = 0;
            scr->dig_uz(14, 2, debugT++ );
            if (debugT==100) debugT = 0;
        }
        */
    }
    // =====================================================================
  void imp2data(const unsigned long imp, unsigned long *m, unsigned long *Kg) {
    unsigned long  m_m;
    unsigned long  m_kg;
    m_m = imp;
    m_m = m_m * (unsigned long)K_Metr;
    m_m = m_m + ((unsigned long)500);
    m_m = m_m / ((unsigned long)1000);
    *m = (unsigned long)m_m;
    m_kg = imp;
    m_kg = m_kg * (unsigned long)K_Kg;
    m_kg = m_kg / ((unsigned long)10000);
    m_kg = m_kg + ((unsigned long)5);
    m_kg = m_kg / ((unsigned long)10);
    *Kg = (unsigned long)m_kg;
  }
// ===================================================
    void main(void)
    {
        unsigned int temp;
#ifdef KEY4
        if ( !key_read(&key) )
        {   // no button
            key = 0;
        }
        else
        {
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
        /*
        if (clockrt::time[CT_YEAR]==0)
        {
            zero();
            return;
        }
        */
        workscrFlCl = 1;
#endif
        scr->Clear();
        mode = md_workscr;
        scr->ShowChar(2, '.');
        scr->ShowChar(5, '.');
        scr->ShowString(9, "Смена");
        // scr->ShowChar(c_stolbcov +  9, 'Т');
        // scr->ShowChar(c_stolbcov + 12, 'И');
    }
void workscr_0()
{
#ifdef CLOCK
    if (clockrt::tik_cn==0)
    {
        scr->ShowChar(c_stolbcov + 2, ':');
        scr->ShowChar(c_stolbcov + 5, ':');
    }
    else
    {
        scr->ShowChar(c_stolbcov + 2, ' ');
        scr->ShowChar(c_stolbcov + 5, ' ');
    }
    if (clockrt::tik)
    {
        clockrt::tik = 0;
        workscrFlCl = 1;
    }
    if (workscrFlCl)
    {
        workscrFlCl = 0;
//      vg::THourSmena sm;
//    sm.Year   = clockrt::time[CT_YEAR];
//    sm.Mounth = clockrt::time[CT_MONTH];
//    sm.Date   = clockrt::time[CT_DATE];
//    sm.Hour   = clockrt::time[CT_HOUR];
      //PowerDown::smena(&sm);
//    scr->ShowChar(15, '1' + sm.Smena);
        scr->dig_uz(0, 2, clockrt::time[CT_DATE] );
        scr->dig_uz(3, 2, clockrt::time[CT_MONTH] );
        scr->dig_uz(6, 2, clockrt::time[CT_YEAR] );
        scr->dig_uz(c_stolbcov + 0, 2, clockrt::time[CT_HOUR] );
        scr->dig_uz(c_stolbcov + 3, 2, clockrt::time[CT_MINUTE] );
        scr->dig_uz(c_stolbcov + 6, 2, clockrt::time[CT_SECOND] );
    }
#endif
    // scr->ShowChar(c_stolbcov + 10, '0'+og::D_Tok->fl);
    // scr->ShowChar(c_stolbcov + 13, '0'+og::D_Tahometr->fl);
    if ( og::D_Tok->fl )
    {
        scr->ShowChar(c_stolbcov +  9, '_');
        scr->ShowChar(c_stolbcov + 10, '_');
        scr->ShowChar(c_stolbcov + 11, '_');
    }
    else
    {
        scr->ShowChar(c_stolbcov +  9, 'Т');
        scr->ShowChar(c_stolbcov + 10, 'О');
        scr->ShowChar(c_stolbcov + 11, 'К');
    }
    if ( og::D_Tahometr->fl ) {
        scr->ShowChar(c_stolbcov + 13, 'и');
        scr->ShowChar(c_stolbcov + 14, 'м');
        scr->ShowChar(c_stolbcov + 15, 'п');
    }
    else
    {
        scr->ShowChar(c_stolbcov + 13, 'И');
        scr->ShowChar(c_stolbcov + 14, 'М');
        scr->ShowChar(c_stolbcov + 15, 'П');
    }
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
            M2SelPass_i();
        }
        else
        {
            // password no correction
            scr->Clear();
            scr->ShowString(0, "пароль не верен" );
            // delay 6 second
            SetMenuTimeDelay(3000, md_workscr);
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
        scr->ShowString(c_stolbcov+ 0, "длина Д1-Д2" );
    }
// ----------------------------------
    void M2SelTOut_i()
    {
        SetMenuTimeOut(60000);
        mode = md_M2SelTOut;
        scr->Clear();
        scr->ShowString(            0, "меню :" );
        scr->ShowString(c_stolbcov+ 0, "ТаймАут Д1-Д2" );
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
    void M2SelExit_i()
    {
        SetMenuTimeOut(60000);
        mode = md_M2SelExit;
        scr->Clear();
        scr->ShowString(            0, "меню :" );
        scr->ShowString(c_stolbcov+ 0, "выход" );
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
        scr->ShowString(c_stolbcov+ 0, "  отм.  уст. " );
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
        SetMenuTimeDelay(5000, md_workscr);
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
        scr->ShowString(            0, "дата/время    ");
        scr->ShowString(c_stolbcov+ 0, "установлены");
        SetMenuTimeDelay(5000, md_workscr);
    }
// ==================================
    void SetPassword_i()
    {
        SetMenuTimeOut(60000);
        mode = md_SetPassword;
        scr->Clear();
        scr->ShowString(            0, "уст.пароля :" );
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
        scr->ShowString(            0, "уст.пароля :" );
        scr->ShowString(c_stolbcov+ 0, "  отм.  уст. " );
    }
    void SetPasswordOk_n()
    {
        scr->Clear();
        scr->ShowString(            0, "отмена установки");
        scr->ShowString(c_stolbcov+ 0, "пароля          ");
        SetMenuTimeDelay(5000, md_workscr);
    }
    void SetPasswordOk_y()
    {
        for (unsigned char i=0; i<5; i++)
            ee_psw[0].pin[i] = newPassw[i];
        scr->Clear();
        scr->ShowString(            0, "новый пароль  ");
        scr->ShowString(c_stolbcov+ 0, "установлен ");
        SetMenuTimeDelay(5000, md_workscr);
    }
// ==================================














    
    
    
    
    
    
    
    
    
    
    
    
    
    















    
    
    
    
    
    
    
    
    
    
    

/*
    //            mode configure
    // init configure
    void NastSel_i()
    {
        // set mode
//        mode = md_NastSel;
        // show scr
        scr->Clear();
        scr->ShowString(0, "  Меню :        " );
    vNastSel = 0;
    vNastSelx = 255;
        // path select menu
        menuNap = 0;
    }
    // view
    void NastSel_0(void)
    {
        if (vNastSelx!=vNastSel)
    {
      if (vNastSel==0 ) scr->ShowString(c_stolbcov, "выбор параметра " );

      // уровень доступа "0"
      // уст.даты/время
      if ( vNastSel<10 ) {
//        if (mask_menu & (1<<0))
        {
          if (vNastSel>1)
          {
            if (menuNap) vNastSel = 1;
            else          vNastSel = 10;
          }
          else vNastSelx = vNastSel;
        }
//        else
        {
          if (menuNap) vNastSel = 79;
          else          vNastSel = 10;
        }
      }
*/
      // уровень доступа "1"
      // просмотр за текущую смену
//      if ( (vNastSel>=10 ) && (vNastSel<20) ) {
          /*
//        if (mask_menu & (1<<1)) {
          if (vNastSel>10) {
            if (menu_nap) vNastSel = 10;
            else          vNastSel = 20;
          }
          else vNastSelx = vNastSel;
        }
//        else {
          if (menu_nap) vNastSel = 9;
          else          vNastSel = 20;
        }
        */
//      }

      // уровень доступа "2"
      // просмотр архива
//      if ( (vNastSel>=20 ) && (vNastSel<30) ) {
          /*
        if (mask_menu & (1<<2)) {
          if (vNastSel>20) {
            if (menu_nap) vNastSel = 20;
            else          vNastSel = 30;
          }
          else vNastSelx = vNastSel;
        }
        else {
          if (menu_nap) vNastSel = 19;
          else          vNastSel = 30;
        }
          */
//      }

      // уровень доступа "3"
      // установка кофицентов
//      if ( (vNastSel>=30 ) && (vNastSel<40) )
//      {
          /*
        if (mask_menu & (1<<3)) {
          if (vNastSel>31) {
            if (menu_nap) vNastSel = 31;
            else          vNastSel = 40;
          }
          else vNastSelx = vNastSel;
        }
        else {
          if (menu_nap) vNastSel = 29;
          else          vNastSel = 40;
        }
          */
//      }
/*
      // уровень доступа "4"
      // пустой
      if ( (vNastSel>=40 ) && (vNastSel<50) ) {
        if (menuNap) vNastSel = 39;
        else          vNastSel = 50;
      }

      // уровень доступа "5"
      // пустой
      if ( (vNastSel>=50 ) && (vNastSel<60) ) {
        if (menuNap) vNastSel = 49;
        else          vNastSel = 60;
      }
*/
      // уровень доступа "6"
      // пустой
//      if ( (vNastSel>=60 ) && (vNastSel<70) ) {
          /*
        if (mask_menu & (1<<6)) {
          if (vNastSel>60) {
            if (menu_nap) vNastSel = 60;
            else          vNastSel = 70;
          }
          else vNastSelx = vNastSel;
        }
        else {
          if (menu_nap) vNastSel = 59;
          else          vNastSel = 70;
        }
        */
//      }
/*
      // уровень доступа "7"
      // уровень админ - установка пароля и уровней доступ
      if ( vNastSel>=70 ) {
        if (menuNap) vNastSel = 69;
        else          vNastSel = 1;
      }

      if (vNastSel==1 ) scr->ShowString(c_stolbcov, "уст.даты/время  " );
      if (vNastSel==10) scr->ShowString(c_stolbcov, "текущая смена   " );
      if (vNastSel==20) scr->ShowString(c_stolbcov, "архив           " );
      if (vNastSel==30) scr->ShowString(c_stolbcov, "ввод К длины    " );
      if (vNastSel==31) scr->ShowString(c_stolbcov, "ввод К веса     " );
      if (vNastSel==60) scr->ShowString(c_stolbcov, "уст. паролей    " );
      // vNastSelx = vNastSel;
    }
  }
*/
/*
    void NastSel_1(void)
  {
    scr->Clear();
    scr->ShowString(0, "выход");
    SetMenuTimeDelay(2000, md_workscr);
  }
  void NastSel_2(void)
  {
    menuNap = 1;
    if (vNastSel>1)
      vNastSel--;
    else
      vNastSel = 254;
    NastSel_0();
  }
  void NastSel_3(void)
  {
    menuNap = 0;  
    vNastSel++;
      NastSel_0();
  }
  void NastSel_4()
  {
    if (vNastSel==0) {
      return;
    }
    if (vNastSel==1) {
      DateYear_i();
      return;
    }
    if (vNastSel==10) {
      ZaSmenu_i();
      return;
    }
    if (vNastSel==20) {
      Archiv_i();
      return;
    }
    if (vNastSel==30) {
      Kmetr_i();
      return;
    }
    if (vNastSel==31) {
      Kkg_i();
      return;
    }
    if (vNastSel==60) {
      PaswSel_i();
      return;
    }
    scr->Clear();
    scr->ShowString(0, "ошибка в меню");
            SetMenuTimeDelay(12000, md_workscr);
  }
    */
/*
    //========================================================
  // выбор пароля
  void PaswSel_i()
  {
    mode = md_PaswSel;
    PaswSel_CntPsw = 0;
    PaswSel_OldPsw = 255;
    scr->Clear();
    scr->ShowString(             0, "user N   view");
    scr->ShowString(c_stolbcov + 0, "код доступа:");
  }
  void PaswSel_0()
  {
//    unsigned char accs;
    if (PaswSel_CntPsw>7) {
      PaswSel_CntPsw = 0;
      PaswSel_OldPsw = 255;
    }
    if (PaswSel_OldPsw!=PaswSel_CntPsw) {
      PaswSel_OldPsw=PaswSel_CntPsw;
//      accs = ee_psw[PaswSel_CntPsw].mask;
//      scr->ShowChar(        7,'0'+PaswSel_CntPsw);
//      scr->Hex(c_stolbcov + 12,accs);
    }
  }
  */
    /*
  void PaswSel_1() {
    NastSel_i();
  }
  void PaswSel_2() {
    if (PaswSel_CntPsw>0) PaswSel_CntPsw--;
  }
  void PaswSel_3() {
    if (PaswSel_CntPsw<7) PaswSel_CntPsw++;
  }
  void PaswSel_4() {
    PaswSetPsw_i();
  }
  */
  //========================================================
  // установка пароля
  void PaswSetPsw_i() {
    mode = md_PaswSetPsw;
    for (unsigned char i=0;i<5;i++) {
      if (ee_psw[PaswSel_CntPsw].pin[i]>9) PaswSetPsw_Pasw[i] = 0;
      else PaswSetPsw_Pasw[i] = ee_psw[PaswSel_CntPsw].pin[i];
    }
    PaswSetPsw_Count = 0;
    scr->Clear();
    scr->ShowString(             0, "user N   enter");
    scr->ShowChar  (        7,'0'+PaswSel_CntPsw);
    scr->ShowString(c_stolbcov + 0, "пароль :");
  }
  void PaswSetPsw_0() {
    unsigned char a = 0;
    while(a<=PaswSetPsw_Count) {
      if (a==PaswSetPsw_Count) {
        scr->ShowChar(c_stolbcov +  9+a, '0'+PaswSetPsw_Pasw[a]);
        scr->ShowChar(c_stolbcov + 10+a, '_');
      }
      else {
        scr->ShowChar(c_stolbcov +  9+a, '*');
      }
      a++;
    }
  }
  void PaswSetPsw_1() {
  }
  void PaswSetPsw_2() {
    if (PaswSetPsw_Pasw[PaswSetPsw_Count]>0) PaswSetPsw_Pasw[PaswSetPsw_Count]--;
  }
  void PaswSetPsw_3() {
    if (PaswSetPsw_Pasw[PaswSetPsw_Count]<9) PaswSetPsw_Pasw[PaswSetPsw_Count]++;
  }
  void PaswSetPsw_4() {
    if (PaswSetPsw_Count==4) PaswSetAcs_i();
    if (PaswSetPsw_Count<4) PaswSetPsw_Count++;
  }
  //========================================================
  // установка операций
  void PaswSetAcs_i() {
    mode = md_PaswSetAcs;
    PaswSetAcs_mask = 0;
    PaswSetAcs_count = 0;
    scr->Clear();
    scr->ShowString(             0, "user N   enter");
    scr->ShowChar  (        7,'0'+PaswSel_CntPsw);
    scr->ShowString(c_stolbcov + 0, "код доступа:");
  }
  void PaswSetAcs_0() {
    unsigned char temp;
    if (PaswSetAcs_count==0) {
      temp = (PaswSetAcs_mask & 0xf0) >> 4;
      if (temp>9) temp += 7;
      scr->ShowChar(c_stolbcov + 12,'0'+temp);
      scr->ShowChar(c_stolbcov + 13,'_');
    }
    if (PaswSetAcs_count==1) {
      scr->Hex(c_stolbcov + 12, PaswSetAcs_mask);
      scr->ShowChar(c_stolbcov + 14,'_');
    }
  }
  void PaswSetAcs_1() {
  }
  void PaswSetAcs_2() {
    if (PaswSetAcs_count==0) {
      if ( (PaswSetAcs_mask & 0xf0)>0x00 ) PaswSetAcs_mask -= 0x10;
    }
    if (PaswSetAcs_count==1) {
      if ( (PaswSetAcs_mask & 0x0f)>0x00 ) PaswSetAcs_mask -= 0x01;
    }
  }
  void PaswSetAcs_3() {
      /*
    if (mask_menu & (1<<7) ) {
      if (PaswSetAcs_count==0) {
        if ( (PaswSetAcs_mask & 0xf0)<0xf0 ) PaswSetAcs_mask += 0x10;
      }
      if (PaswSetAcs_count==1) {
        if ( (PaswSetAcs_mask & 0x0f)<0x0f ) PaswSetAcs_mask += 0x01;
      }
    }
    else {
      if (PaswSetAcs_count==0) {
        if ( (PaswSetAcs_mask & 0xf0)<0x70 ) PaswSetAcs_mask += 0x10;
        if ( (PaswSetAcs_mask & 0xf0)>0x70 ) PaswSetAcs_mask = (PaswSetAcs_mask & 0x0f) + 0x70;
      }
      if (PaswSetAcs_count==1) {
        if ( (PaswSetAcs_mask & 0x0f)<0x0f ) PaswSetAcs_mask += 0x01;
      }
    }
      */
  }
  void PaswSetAcs_4() {
    if (PaswSetAcs_count==0) {
      PaswSetAcs_count++;
      return;
    }
    if (PaswSetAcs_count==1) {
      T_psw psw;
//      psw.mask = PaswSetAcs_mask;
      for(unsigned char i=0;i<5;i++) 
        psw.pin[i] = PaswSetPsw_Pasw[i];
      ee_psw[PaswSel_CntPsw] = psw;
      PaswSel_i();
    }
  }
  //========================================================
  // установка года
  void DateYear_i() {
    mode = md_DateYear;
    Date_Year = clockrt::time[CT_YEAR];
    if (Date_Year>99) Date_Year = 0;
    scr->Clear();
    scr->ShowString(             0, "уст.года:");
    scr->ShowString(c_stolbcov + 0, "отм. +1X +1 ввод");
  }
  void DateYear_0() {
    scr->dig_uz(             9, 2, Date_Year);
  }
  void DateYear_1() {
//    NastSel_i();
  }
  void DateYear_2() {
    Date_Year -= Date_Year%10;
    Date_Year += 10;
    if (Date_Year>99) Date_Year = 1;
  }
  void DateYear_3() {
    Date_Year++;
    if (Date_Year>99) Date_Year = 1;
  }
  void DateYear_4() {
    DateMonth_i();
  }
  //========================================================
  // установка месяца
  void DateMonth_i() {
    mode = md_DateMonth;
    Date_Month = clockrt::time[CT_MONTH];
    if (Date_Month>12) Date_Month = 1;
    scr->Clear();
    scr->ShowString(             0, "уст.месяца:");
    scr->ShowString(c_stolbcov + 0, "отм. +1X +1 ввод");
  }
  void DateMonth_0() {
    scr->dig_uz(             11, 2, Date_Month);
  }
  void DateMonth_1() {
//    NastSel_i();
  }
  void DateMonth_2() {
    Date_Month -= Date_Month%10;
    Date_Month += 10;
    if (Date_Month>12) Date_Month = 1;
  }
  void DateMonth_3() {
    Date_Month++;
    if (Date_Month>12) Date_Month = 1;
  }
  void DateMonth_4() {
    DateDate_i();
  }
  //========================================================
  // установка даты
  void DateDate_i() {
    mode = md_DateDate;
    Date_Date = clockrt::time[CT_DATE];
    if (Date_Month== 1) DateDate_Max = 31;
    if (Date_Month== 2) {
      if ( (Date_Year%4)==0 ) DateDate_Max = 29;
      else                    DateDate_Max = 28;
    }
    if (Date_Month== 3) DateDate_Max = 31;
    if (Date_Month== 4) DateDate_Max = 30;
    if (Date_Month== 5) DateDate_Max = 31;
    if (Date_Month== 6) DateDate_Max = 30;
    if (Date_Month== 7) DateDate_Max = 31;
    if (Date_Month== 8) DateDate_Max = 31;
    if (Date_Month== 9) DateDate_Max = 30;
    if (Date_Month==10) DateDate_Max = 31;
    if (Date_Month==11) DateDate_Max = 30;
    if (Date_Month==12) DateDate_Max = 31;
    if (Date_Date>DateDate_Max) Date_Date = 1;
    scr->Clear();
    scr->ShowString(             0, "уст.даты:");
    scr->ShowString(c_stolbcov + 0, "отм. +1X +1 ввод");
  }
  void DateDate_0() {
    scr->dig_uz(             9, 2, Date_Date);
  }
  void DateDate_1() {
//    NastSel_i();
  }
  void DateDate_2() {
    Date_Date -= Date_Date%10;
    Date_Date += 10;
    if (Date_Date>DateDate_Max) Date_Date = 1;;
  }
  void DateDate_3() {
    Date_Date++;
    if (Date_Date>DateDate_Max) Date_Date = 1;;
  }
  void DateDate_4() {
    DateHour_i();
  }
  //========================================================
  // установка часов
  void DateHour_i() {
    mode = md_DateHour;
    Date_Hour = clockrt::time[CT_HOUR];
    if (Date_Hour>23) Date_Hour = 0;
    scr->Clear();
    //scr->ShowString( 0, "время чч:мм:сс");
    scr->ShowString(             0, "уст.часов:");
    scr->ShowString(c_stolbcov + 0, "отм. +1X +1 ввод");
  }
  void DateHour_0() {
    /*
    scr->dig_uz(6, 2, clockrt::time[CT_HOUR]);
    scr->dig_uz(9, 2, clockrt::time[CT_MINUTE]);
    scr->dig_uz(12, 2, clockrt::time[CT_SECOND]);
    */
    scr->dig_uz(             10, 2, Date_Hour);
  }
  void DateHour_1() {
//    NastSel_i();
  }
  void DateHour_2() {
    Date_Hour -= Date_Hour%10;
    Date_Hour += 10;;
    if (Date_Hour>23) Date_Hour = 0;
  }
  void DateHour_3() {
    Date_Hour++;
    if (Date_Hour>23) Date_Hour = 0;
  }
  void DateHour_4() {
    DateMinute_i();
  }
  //========================================================
  // установка минут
  void DateMinute_i() {
    mode = md_DateMinute;
    Date_Minute = clockrt::time[CT_MINUTE];
    if (Date_Minute>59) Date_Minute = 0;
    scr->Clear();
    //scr->ShowString( 0, "время чч:мм:сс");
    scr->ShowString(             0, "уст.минут:");
    scr->ShowString(c_stolbcov + 0, "отм. +1X +1 ввод");
  }
  void DateMinute_0() {
    /*
    scr->dig_uz(6, 2, clockrt::time[CT_HOUR]);
    scr->dig_uz(9, 2, clockrt::time[CT_MINUTE]);
    scr->dig_uz(12, 2, clockrt::time[CT_SECOND]);
    */
    scr->dig_uz(             10, 2, Date_Minute);
  }
  void DateMinute_1() {
//    NastSel_i();
  }
  void DateMinute_2() {
    Date_Minute -= Date_Minute%10;
    Date_Minute += 10;
    if (Date_Minute>59) Date_Minute = 0;
  }
  void DateMinute_3() {
    Date_Minute++;
    if (Date_Minute>59) Date_Minute = 0;
  }
  void DateMinute_4() {
    DateSet_i();
  }
  //========================================================
  // потверждение или отказ от установки даты
  void DateSet_i() {
    mode = md_DateSet;
    scr->Clear();
    scr->ShowString( 0,             "уст.Дату/Врея?");
    //scr->ShowString(c_stolbcov + 0, "обновить ?");
    scr->ShowString(c_stolbcov + 0, "     Нет Да     ");
  }
  void DateSet_2() {
//    NastSel_i();
  }
  void DateSet_3() {
    scr->Clear();
    scr->ShowString( 0, "time set");
    /*
    clockrt::RefSav();
    clockrt::SetYear(Date_Year);
    clockrt::SetMonth(Date_Month);
    clockrt::SetDate(Date_Date);
    clockrt::SetHour(Date_Hour);
    clockrt::SetMinute(Date_Minute);
    clockrt::SetZeroSecond();
    clockrt::Update();
    */
//    NastSel_i();
    /*
    {
      CritSec cs;
      menuTimeOut = 500;
      TimeOut_i();
    }
    */
  }
  //========================================================
    void zero()
    {
        mode = md_Zero;
        scr->Clear();
        scr->ShowString( 0, "БАТАРЕЯ !!!");
        scr->ShowString( c_stolbcov + 0, "уст. новое время");
    }
  //========================================================
  // за смену
  void ZaSmenu_i() {
    mode = md_ZaSmenu;
    ZaSmenu_Old = ~0;
//    K_Metr = vg::ee_K_Metr;
//    K_Kg = vg::ee_K_Kg;
//    vg::THourSmena sm;
//  sm.Year   = clockrt::time[CT_YEAR];
//  sm.Mounth = clockrt::time[CT_MONTH];
//  sm.Date   = clockrt::time[CT_DATE];
//  sm.Hour   = clockrt::time[CT_HOUR];
    //PowerDown::smena(&sm);
    scr->Clear();
    scr->ShowString( 0, "тек.смена");
//  scr->ShowChar(  9, '1' + sm.Smena);
    scr->ShowChar( c_stolbcov + 3, '.');
    scr->ShowString( c_stolbcov + 7, "м");
    scr->ShowChar(c_stolbcov + 12, '.');
    scr->ShowChar(c_stolbcov + 14, 'К');
    scr->ShowChar(c_stolbcov + 15, 'г');
  }
  void ZaSmenu_0() {
    static unsigned long m;
    static unsigned long kg;
    static unsigned long temp;
//    if (ZaSmenu_Old==vg::DataSmena.Impuls) return;
//    ZaSmenu_Old = vg::DataSmena.Impuls;
    temp = ZaSmenu_Old;
//    temp = 2087;
    imp2data(temp, &m, &kg);
//    scr->digit_uz(c_stolbcov + 0, 7, 3, m);
//    scr->dig_uz(c_stolbcov + 0, 7, m );
    scr->dig_u (c_stolbcov + 0, 3, m/((unsigned long)1000) );
    scr->dig_uz(c_stolbcov + 4, 3, m%((unsigned long)1000) );
//    scr->digit_uz(c_stolbcov + 9, 5, 1, kg);
    scr->dig_u (c_stolbcov +  9, 3, kg/((unsigned long)10) );
    scr->dig_uz(c_stolbcov + 13, 1, kg%((unsigned long)10) );
//    if (mask_menu & (1<<7) ) scr->dig_uz(11, 5, temp);
  }
  void ZaSmenu_3() {
//  if (mask_menu & (1<<7) ) vg::DataSmena.Impuls = 0;
  }
  //========================================================
  // архив
  //unsigned int  ZaSmenu_Old;
  void Archiv_i() {
    mode = md_Archiv;
//  K_Metr = vg::ee_K_Metr;
//  K_Kg = vg::ee_K_Kg;
//  vArchivIndx = vg::ee_ArchivIndx;
    scr->Clear();
    scr->ShowChar(             2, '.');
    scr->ShowChar(             5, '.');
    scr->ShowChar(c_stolbcov + 3, '.');
    scr->ShowChar(c_stolbcov + 7, 'м');
    scr->ShowChar(c_stolbcov + 12, '.');
    scr->ShowChar(c_stolbcov + 14, 'К');
    scr->ShowChar(c_stolbcov + 15, 'г');
    scr->ShowString( 9, "смена:");
    Archiv_s();
  }
  void Archiv_s() {
    static unsigned long m;
    static unsigned long kg;
//  unsigned long temp;
//    temp = vg::ee_Archiv[vArchivIndx].Impuls;
    /*
    if (mask_menu & (1<<7) ) {
//      scr->dig_uz(0, 2, vg::ee_Archiv[vArchivIndx].Date);
//      scr->ShowChar(2, 'A' + vg::ee_Archiv[vArchivIndx].Smena);
//      scr->dig_uz(3, 2, vg::ee_Archiv[vArchivIndx].Mounth);
//    scr->dig_uz(9, 6, temp);
    }
    else {
//      scr->dig_uz(0, 2, vg::ee_Archiv[vArchivIndx].Date);
//      scr->dig_uz(3, 2, vg::ee_Archiv[vArchivIndx].Mounth);
//    scr->dig_uz(6, 2, vg::ee_Archiv[vArchivIndx].Year);
//    scr->ShowChar(15, '1' + vg::ee_Archiv[vArchivIndx].Smena);
    }
    */
    //scr->dig_u (10, 5, vg::ee_Archiv[vArchivIndx].Impuls);
//  imp2data(temp, &m, &kg);
//    scr->digit_uz(c_stolbcov + 0, 7, 3, m);
    scr->dig_u (c_stolbcov + 0, 3, m/((unsigned long)1000) );
    scr->dig_uz(c_stolbcov + 4, 3, m%((unsigned long)1000) );
//    scr->digit_uz(c_stolbcov + 9, 5, 1, kg);
    scr->dig_u (c_stolbcov +  9, 3, kg/((unsigned long)10) );
    scr->dig_uz(c_stolbcov + 13, 1, kg%((unsigned long)10) );
  }
  void Archiv_2() {
    if (vArchivIndx==0) vArchivIndx = ee_ArchivLen;
    vArchivIndx--;
    Archiv_s();
  }
  void Archiv_3() {
    vArchivIndx++;
    if (vArchivIndx>=ee_ArchivLen) vArchivIndx = 0;
    Archiv_s();
  }
  //========================================================
  // метровый кофицент
  void Kmetr_i() {
    mode = md_Kmetr;
    unsigned long x;
//  x = vg::ee_K_Metr;
    for(unsigned char i=0;i<20;i++) Kedit[i] = 0;
    for(unsigned char i=0;i<6;i++) {
      unsigned char j = 5 - i;
      if (j==2) {
        Kedit[j] = '.';
        continue;
      }
      unsigned char s = x%((unsigned long)10);
      Kedit[j] = s + '0';
      x = x / ((unsigned long)10);
    }
    Kediti = 0;
    scr->Clear();
    scr->ShowString(             7, "мм/имп.");
    scr->ShowString(c_stolbcov + 0, "отм.  -  +  ввод");
    Kmetr_s();
  }
  void Kmetr_s() {
    scr->ShowString(0, Kedit);
  }
  void Kmetr_0() {
    //static unsigned int count = 0;
    //count++;
    //if (count>=1000) count = 0;
    if (t_count<500) scr->ShowChar(0 + Kediti, Kedit[Kediti]);
    else scr->ShowChar(0 + Kediti, '_');
  }
  void Kmetr_2() {
    Kedit[Kediti]--;
    if (Kedit[Kediti]<'0') Kedit[Kediti] = '9';
  }
  void Kmetr_3() {
    Kedit[Kediti]++;
    if (Kedit[Kediti]>'9') Kedit[Kediti] = '0';
  }
  void Kmetr_4() {
    if (Kediti<5) {
      Kediti++;
      if (Kediti==2) Kediti++;
      Kmetr_s();
    }
    else KmetrSav_i();
  }
  // метровый кофицент сохранение
  void KmetrSav_i() {
    mode = md_KmetrSav;
    scr->Clear();
    scr->ShowString(             0, "Сохранить ?");
    scr->ShowString(c_stolbcov + 0, "     Нет Да     ");
  }
  void KmetrSav_2() {
//    NastSel_i();
  }
  void KmetrSav_3() {
    unsigned long x = 0;
    for(unsigned char i=0;i<6;i++) {
      if (i==2) continue;
      x = x * ((unsigned long)10);
      x = x + (unsigned long)(Kedit[i] - '0');
    }
//  vg::ee_K_Metr = x;
//    NastSel_i();
  }
  //========================================================
  // метровый кофицент
  void Kkg_i() {
    mode = md_Kkg;
    unsigned long x;
//  x = vg::ee_K_Kg;
    for(unsigned char i=0;i<20;i++) Kedit[i] = 0;
    for(unsigned char i=0;i<6;i++) {
      unsigned char j = 5 - i;
      if (j==2) {
        Kedit[j] = '.';
        continue;
      }
      unsigned char s = x%10;
      Kedit[j] = s + '0';
      x = x / ((unsigned long)10);
    }
    Kediti = 0;
    scr->Clear();
    scr->ShowString(             7, "г/имп.");
    scr->ShowString(c_stolbcov + 0, "отм.  -  +  ввод");
    Kkg_s();
  }
  void Kkg_s() {
    scr->ShowString(             0, Kedit);
  }
  void Kkg_0() {
//    static unsigned int count = 0;
//    count++;
//    if (count>=1600) count = 0;
//    if (count<900) scr->ShowChar(8 + Kediti, Kedit[Kediti]);
//    else scr->ShowChar(8 + Kediti, '_');
    if (t_count<500) scr->ShowChar(0 + Kediti, Kedit[Kediti]);
    else scr->ShowChar(0 + Kediti, '_');
  }
  void Kkg_2() {
    Kedit[Kediti]--;
    if (Kedit[Kediti]<'0') Kedit[Kediti] = '9';
  }
  void Kkg_3() {
    Kedit[Kediti]++;
    if (Kedit[Kediti]>'9') Kedit[Kediti] = '0';
  }
  void Kkg_4() {
    if (Kediti<5) {
      Kediti++;
      if (Kediti==2) Kediti++;
      Kkg_s();
    }
    else KkgSav_i();
  }
  // кг кофицент сохранение
  void KkgSav_i() {
    mode = md_KkgSav;
    scr->Clear();
    scr->ShowString(             0, "Сохранить ?");
    scr->ShowString(c_stolbcov + 0, "     Нет Да     ");
  }
  void KkgSav_2() {
//    NastSel_i();
  }
  void KkgSav_3() {
    unsigned long x = 0;
    for(unsigned char i=0;i<6;i++) {
      if (i==2) continue;
      x = x * ((unsigned long)10);
      x = x + (unsigned long)(Kedit[i] - '0');
    }
//  vg::ee_K_Kg = x;
//    NastSel_i();
  }
  //========================================================
  // установка уровея доступа
  //========================================================
    void Dummy(void)
    {}
    // [view][km][k-][k+][ke][TimeOut][init]
    void (* const __flash MassMenu[][7])(void)=
    {
        // 0 - work screen
        { workscr_0,            SelectArchiv_i,     Dummy,              Dummy,              Dummy,              Dummy,              workscr_i },
        // -------------------------------------------------------------------------------------
        // 1 - select archive
        { Dummy,                workscr_i,          Dummy,              SelectConfig_i,     Dummy,              workscr_i,          SelectArchiv_i },
        // 2 - select config
        { Dummy,                Dummy,              SelectArchiv_i,     SelectExit_i,       PassWrd_i,          workscr_i,          SelectConfig_i },
        // 3 - select exit
        { Dummy,                Dummy,              SelectConfig_i,     Dummy,              workscr_i,          workscr_i,          SelectExit_i },
        // -------------------------------------------------------------------------------------
        // 4 - password
        { PassWrd_v,            workscr_i,          PassWrd_m,          PassWrd_p,          PassWrd_e,          workscr_i,          PassWrd_i },
        // -------------------------------------------------------------------------------------
        // 5 - select menu set new password
        { Dummy,                Dummy,              Dummy,              M2SelLen_i,         SetPassword_i,      workscr_i,          M2SelPass_i },
        // 6 - select menu set len sensors
        { Dummy,                Dummy,              M2SelPass_i,        M2SelTOut_i,        Dummy,              workscr_i,          M2SelLen_i },
        // 7 - select menu set timeout sensors
        { Dummy,                Dummy,              M2SelLen_i,         M2SelClock_i,       Dummy,              workscr_i,          M2SelTOut_i },
        // 8 - select menu set clock
        { Dummy,                Dummy,              M2SelTOut_i,        M2SelExit_i,        SetClockYear_i,     workscr_i,          M2SelClock_i },
        // 9 - select menu exit
        { Dummy,                Dummy,              M2SelClock_i,       Dummy,              workscr_i,          workscr_i,          M2SelExit_i },
        // -------------------------------------------------------------------------------------
        // 10 - set clock : Year
        { SetClockYear_v,       SetClockMount_i,    SetClockYear_km,    SetClockYear_kp,    SetClockYear_ke,    Dummy,              SetClockYear_i   },
        // 11 - set clock : Mount
        { SetClockMount_v,      SetClockDate_i,     SetClockMount_km,   SetClockMount_kp,   SetClockMount_ke,   Dummy,              SetClockMount_i  },
        // 12 - set clock : Date
        { SetClockDate_v,       SetClockHour_i,     SetClockDate_km,    SetClockDate_kp,    SetClockDate_ke,    Dummy,              SetClockDate_i   },
        // 13 - set clock : Hour
        { SetClockHour_v,       SetClockMinute_i,   SetClockHour_km,    SetClockHour_kp,    SetClockHour_ke,    Dummy,              SetClockHour_i   },
        // 14 - set clock : Minute***
        { SetClockMinute_v,     M2SelClock_i,       SetClockMinute_km,  SetClockMinute_kp,  SetClockMinute_ke,  Dummy,              SetClockMinute_i },
        // 15 - set clock : ask to set 
        { SetClockSet_v,        M2SelClock_i,       SetClockSet_km,     SetClockSet_kp,     Dummy,              Dummy,              SetClockSet_i },
        // -------------------------------------------------------------------------------------
        // 16 - set password
        { SetPassword_v,        Dummy,              SetPassword_km,     SetPassword_kp,     SetPassword_e,      workscr_i,          SetPassword_i },
        // 17 - set password ok ?
        { Dummy,                SetPasswordOk_n,    SetPasswordOk_n,    SetPasswordOk_y,    Dummy,              workscr_i,          SetPasswordOk_i },
        // -------------------------------------------------------------------------------------
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              SetLenD_i },
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              Dummy },
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              Dummy },
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              Dummy },
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              Dummy },
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              Dummy },
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              Dummy },
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              Dummy },
        { Dummy,                Dummy,              Dummy,              Dummy,              Dummy,              Dummy,              Dummy },
	/*



















{ workscr_0,   PassWrd_i,   Dummy,       Dummy,       Dummy,       Dummy },
    { PassWrd_0,   workscr_i,   PassWrd_2,   PassWrd_3,   PassWrd_4,   workscr_i },
    { TimeOut_0,   Dummy,       Dummy,       Dummy,       Dummy,       Dummy },
    { NastSel_0,   NastSel_1,   NastSel_2,   NastSel_3,   NastSel_4,   workscr_i },
    { PaswSel_0,   PaswSel_1,   PaswSel_2,   PaswSel_3,   PaswSel_4,   workscr_i },
    { PaswSetPsw_0,PaswSetPsw_1,PaswSetPsw_2,PaswSetPsw_3,PaswSetPsw_4,workscr_i },
    { PaswSetAcs_0,PaswSetAcs_1,PaswSetAcs_2,PaswSetAcs_3,PaswSetAcs_4,workscr_i },
    { DateYear_0,  DateYear_1,  DateYear_2,  DateYear_3,  DateYear_4,  workscr_i },
    { DateMonth_0, DateMonth_1, DateMonth_2, DateMonth_3, DateMonth_4, workscr_i },
    { DateDate_0,  DateDate_1,  DateDate_2,  DateDate_3,  DateDate_4,  workscr_i },
    { DateHour_0,  DateHour_1,  DateHour_2,  DateHour_3,  DateHour_4,  workscr_i },
    { DateMinute_0,DateMinute_1,DateMinute_2,DateMinute_3,DateMinute_4,workscr_i },
    { Dummy,       Dummy,       DateSet_2,   DateSet_3,   Dummy,       workscr_i },
    { Dummy,       PassWrd_i,   Dummy,       Dummy,       Dummy,       Dummy },
    { ZaSmenu_0,   NastSel_i,   Dummy,       ZaSmenu_3,   Dummy,       workscr_i },
    { Dummy,       NastSel_i,   Archiv_2,    Archiv_3,    Dummy,       workscr_i },
    { Kmetr_0,     NastSel_i,   Kmetr_2,     Kmetr_3,     Kmetr_4,     workscr_i },
    { Dummy,       Dummy,       KmetrSav_2,  KmetrSav_3,  Dummy,       workscr_i },
    { Kkg_0,       NastSel_i,   Kkg_2,       Kkg_3,       Kkg_4,       workscr_i },
    { Dummy,       Dummy,       KkgSav_2,    KkgSav_3,    Dummy,       workscr_i },
	*/
        { Dummy,       Dummy,           Dummy,       Dummy,             Dummy,       Dummy,     Dummy },
        { Dummy,       Dummy,           Dummy,       Dummy,             Dummy,       Dummy,     Dummy },
        { Dummy,       Dummy,           Dummy,       Dummy,             Dummy,       Dummy,     Dummy },
        { Dummy,       Dummy,           Dummy,       Dummy,             Dummy,       Dummy,     Dummy },
        { Dummy,       Dummy,           Dummy,       Dummy,             Dummy,       Dummy,     Dummy },
        { Dummy,       Dummy,           Dummy,       Dummy,             Dummy,       Dummy,     Dummy }
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


