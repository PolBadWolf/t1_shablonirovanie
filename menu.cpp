
#include "main.h"
#ifdef MENU
#include "menu.h"

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//            ����� ������� ������ ��� ��������� ������ ������
// #define ShowPass
//              ��������� ����������� ����� �������� ������
#define ShowStar
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


namespace ns_menu
{
    unsigned char key;
    unsigned int  keyTout = 0;
    unsigned int  keyToutx;
    unsigned int  keyTout1 = 0;
    unsigned int  keyTout1x;
    // ==========================
    //      for work password
    // new password
    T_psw vvPasword;
    // count for input password
    unsigned char vvPaswordCount;
    // massive user passwords
    __eeprom T_psw ee_psw[8];
    // back door
    __flash T_psw flPsw= {2,2,3,6,0};
    // flag status checked password
    unsigned char flPasswordStatus = 0;
    //=================================
    //     select configure
    // path select menu
    unsigned char menu_nap = 0;
    // ==============================
    //     Time out
    // count time out menu
    unsigned int  menuTimeOut;
    // ==============================
  unsigned int  menuTimeOutx;
  unsigned char vNastSel;
  unsigned char vNastSelx;
  signed int  position_min;
  signed int  position_max;
  signed int  position_cur;
//  unsigned char TimeViewInd;
    // bad eeprom - restore to default
    void InitEeprom()
    {
        ns_menu::ee_psw[0].pin[0] = 1;
        ns_menu::ee_psw[0].pin[1] = 2;
        ns_menu::ee_psw[0].pin[2] = 3;
        ns_menu::ee_psw[0].pin[3] = 4;
        ns_menu::ee_psw[0].pin[4] = 5;
    }
    // init to start system 
    void init()
    {
        // reset status password
        flPasswordStatus = 0;
        // set work screen
        void workscr_i();
        workscr_i();
    }
  //
#define md_init      0
  unsigned char mode = md_init;
  void init();
#define md_workscr   1
    void workscr_i();
  void workscr_0(void);
#define md_PassWrd   2
  void PassWrd_i(void);
  void PassWrd_0(void);
  void PassWrd_2(void);
  void PassWrd_3(void);
  void PassWrd_4(void);
#define md_TimeOut   3
  void TimeOut_i(unsigned int TimeOut);
  void TimeOut_0(void);
  void PassChkSet(void);
#define md_NastSel  4
  void NastSel_i(void);
  void NastSel_0(void);
  void NastSel_1(void);
  void NastSel_2(void);
  void NastSel_3(void);
  void NastSel_4(void);
#define md_PaswSel  5
  // ����� ������
  unsigned PaswSel_OldPsw;
  unsigned PaswSel_CntPsw;
  void PaswSel_i();
  void PaswSel_0();
  void PaswSel_1();
  void PaswSel_2();
  void PaswSel_3();
  void PaswSel_4();
#define md_PaswSetPsw 6
  // ��������� ������
  unsigned char PaswSetPsw_Pasw[5];
  unsigned char PaswSetPsw_Count;
  void PaswSetPsw_i();
  void PaswSetPsw_0();
  void PaswSetPsw_1();
  void PaswSetPsw_2();
  void PaswSetPsw_3();
  void PaswSetPsw_4();
#define md_PaswSetAcs 7
  // ��������� ������
  unsigned char PaswSetAcs_mask;
  unsigned char PaswSetAcs_count;
  void PaswSetAcs_i();
  void PaswSetAcs_0();
  void PaswSetAcs_1();
  void PaswSetAcs_2();
  void PaswSetAcs_3();
  void PaswSetAcs_4();
#define md_DateYear 8
  // ���� ����
  unsigned char Date_Year;
  void DateYear_i();
  void DateYear_0();
  void DateYear_1();
  void DateYear_2();
  void DateYear_3();
  void DateYear_4();
#define md_DateMonth 9
  // ���� ������
  unsigned char Date_Month;
  void DateMonth_i();
  void DateMonth_0();
  void DateMonth_1();
  void DateMonth_2();
  void DateMonth_3();
  void DateMonth_4();
#define md_DateDate 10
  // ���� �����
  unsigned char Date_Date;
  unsigned char DateDate_Max;
  void DateDate_i();
  void DateDate_0();
  void DateDate_1();
  void DateDate_2();
  void DateDate_3();
  void DateDate_4();
#define md_DateHour 11
  // ���� �����
  unsigned char Date_Hour;
  void DateHour_i();
  void DateHour_0();
  void DateHour_1();
  void DateHour_2();
  void DateHour_3();
  void DateHour_4();
#define md_DateMinute 12
  // ���� �����
  unsigned char Date_Minute;
  void DateMinute_i();
  void DateMinute_0();
  void DateMinute_1();
  void DateMinute_2();
  void DateMinute_3();
  void DateMinute_4();
#define md_DateSet 13
  // ������������ ��� ����� �� ��������� ����
  void DateSet_i();
  void DateSet_2();
  void DateSet_3();
#define md_Zero 14
  // ���������� ������ ������
#define md_ZaSmenu 15
  // �� �����
  unsigned long ZaSmenu_Old;
  unsigned long K_Metr;
  void ZaSmenu_i();
  void ZaSmenu_0();
#define md_Archiv 16
  // �����
  //unsigned int  ZaSmenu_Old;
  unsigned long K_Kg;
  unsigned int vArchivIndx;
  void Archiv_i();
  void Archiv_s();
  void Archiv_2();
  void Archiv_3();
#define md_Kmetr 17
  // �������� ��������
  char Kedit[20];
  unsigned char Kediti;
  void Kmetr_i();
  void Kmetr_s();
  void Kmetr_0();
  void Kmetr_2();
  void Kmetr_3();
  void Kmetr_4();
#define md_KmetrSav 18
  // �������� �������� ����������
  void KmetrSav_i();
  void KmetrSav_2();
  void KmetrSav_3();
#define md_Kkg 19
  // �������� ��������
  void Kkg_i();
  void Kkg_s();
  void Kkg_0();
  void Kkg_2();
  void Kkg_3();
  void Kkg_4();
#define md_KkgSav 20
  // �������� �������� ����������
  void KkgSav_i();
  void KkgSav_2();
  void KkgSav_3();

  //
  extern void (* const __flash MassMenu[][6])(void);
  void timer(void)
  {
    if (keyTout>0) keyTout--;
    if (keyTout1>1) keyTout1--;
    if (menuTimeOut>0) menuTimeOut--;
  }
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
  void main(void)
  {
    #ifdef KEY4
    if ( !key_read(&key) )
    {
      key = 0;
    }
    else
    {
      if ( key==1 || key==4 )
      {
        __disable_interrupt();
        keyToutx = keyTout;
        __enable_interrupt();
        if ( keyToutx==0 )
        {
          __disable_interrupt();
          keyTout = 100;
          __enable_interrupt();
        }
        else
        {
          __disable_interrupt();
          keyTout = 250;
          __enable_interrupt();
          key = 0;
        }
      }
    }
    if ( key==0 )
    {
      __disable_interrupt();
      keyTout1x = keyTout1;
      __enable_interrupt();
      if ( keyTout1x==1 )
      {
        __disable_interrupt();
        keyTout1 = 0;
        __enable_interrupt();
        key = 5;
      }
    }
    else
    {
      __disable_interrupt();
      keyTout1 = 60000;
      __enable_interrupt();
    }
    #else
      key = 0;
    #endif
    MassMenu[mode][key]();
  }
  void workscr_i(void)
  {
    #ifdef CLOCK
    if (clockrt::time[CT_YEAR]==0) {
      zero();
      return;
    }
    #endif
    scr->Clear();
    mode = md_workscr;
    scr->ShowChar(2, '.');
    scr->ShowChar(5, '.');
    scr->ShowString(9, "�����");
    //scr->ShowChar(c_stolbcov +  9, '�');
    //scr->ShowChar(c_stolbcov + 12, '�');
  }
  void workscr_0(void)
  {
    #ifdef CLOCK
    if (clockrt::tik_cn==0) {
          scr->ShowChar(c_stolbcov + 2, ':');
          scr->ShowChar(c_stolbcov + 5, ':');
    }
    if (clockrt::tik_cn==1) {
          scr->ShowChar(c_stolbcov + 2, ' ');
          scr->ShowChar(c_stolbcov + 5, ' ');
    }
    if (clockrt::tik)
    {
      clockrt::tik = 0;
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
    //scr->ShowChar(c_stolbcov + 10, '0'+og::D_Tok->fl);
    //scr->ShowChar(c_stolbcov + 13, '0'+og::D_Tahometr->fl);
    if ( og::D_Tok->fl ) {
      scr->ShowChar(c_stolbcov +  9, '_');
      scr->ShowChar(c_stolbcov + 10, '_');
      scr->ShowChar(c_stolbcov + 11, '_');
    }
    else {
      scr->ShowChar(c_stolbcov +  9, '�');
      scr->ShowChar(c_stolbcov + 10, '�');
      scr->ShowChar(c_stolbcov + 11, '�');
    }
    if ( og::D_Tahometr->fl ) {
      scr->ShowChar(c_stolbcov + 13, '�');
      scr->ShowChar(c_stolbcov + 14, '�');
      scr->ShowChar(c_stolbcov + 15, '�');
    }
    else {
      scr->ShowChar(c_stolbcov + 13, '�');
      scr->ShowChar(c_stolbcov + 14, '�');
      scr->ShowChar(c_stolbcov + 15, '�');
    }
  }
  // ===================================================
    void PassWrd_i(void)
    {
        scr->Clear();
        scr->ShowString(0, "������� ������ :" );
        // clear massive
        for (unsigned char i=0;i<5;i++)
            vvPasword.pin[i] = 0;
        // reset count
        vvPaswordCount = 0;
        // set mode input password
        mode = md_PassWrd;
    }
    // mode input password, view
    void PassWrd_0()
    {
        unsigned char i;
        for (i=0;i<vvPaswordCount;i++)
            scr->ShowChar(c_stolbcov +i, '*');
        scr->ShowChar(c_stolbcov +i, vvPasword.pin[i]+'0');
        scr->ShowChar(c_stolbcov + 1 +i, '_');
    }
    // mode input password, select digital
    void PassWrd_2(void)
    {
        if (vvPasword.pin[vvPaswordCount]>0)
        {
            vvPasword.pin[vvPaswordCount]--;
            PassWrd_0();
        }
    }
    // mode input password, select digital
    void PassWrd_3(void)
    {
        if (vvPasword.pin[vvPaswordCount]<9)
        {
            vvPasword.pin[vvPaswordCount]++;
            PassWrd_0();
        }
    }
    // mode input password, next digital passwrd or end input
    void PassWrd_4(void)
    {
        vvPaswordCount++;
        if (vvPaswordCount<5)
            PassWrd_0();
        else
            PassChkSet(); // end input, checked password
    }
// ==================================
    // init time out for delay
    void TimeOut_i(unsigned int TimeOut)
    {
        CritSec csMn;
        menuTimeOut = TimeOut;
        mode = md_TimeOut;
    }
  void TimeOut_0(void)
  {
    __disable_interrupt();
    menuTimeOutx = menuTimeOut;
    __enable_interrupt();
    if (menuTimeOutx==0) workscr_i();
  }
// ==================================
    // checked password
    void PassChkSet(void)
    {
        // reset flag status checked password
        flPasswordStatus = 0;
        unsigned char tempFlag;
        for (unsigned char n_par=0;n_par<8;n_par++)
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
        if (tempFlag)
        {
            // init configuration
            NastSel_i();
        }
        else
        {
            // password no correction
            scr->Clear();
            scr->ShowString(0, "������ �� �����" );
            /*
      __disable_interrupt();
      menuTimeOut = 6000;
      __enable_interrupt();
      TimeOut_i();
            */
            TimeOut_i(6000);
        }
  }
// ==================================
    //            mode configure
    // init configure
    void NastSel_i()
    {
        // set mode
        mode = md_NastSel;
        // show scr
        scr->Clear();
        scr->ShowString(0, "  ���� :        " );
    vNastSel = 0;
    vNastSelx = 255;
        // path select menu
        menu_nap = 0;
    }
    // view
    void NastSel_0(void)
    {
        if (vNastSelx!=vNastSel)
    {
      if (vNastSel==0 ) scr->ShowString(c_stolbcov, "����� ��������� " );

      // ������� ������� "0"
      // ���.����/�����
      if ( vNastSel<10 ) {
//        if (mask_menu & (1<<0))
        {
          if (vNastSel>1)
          {
            if (menu_nap) vNastSel = 1;
            else          vNastSel = 10;
          }
          else vNastSelx = vNastSel;
        }
//        else
        {
          if (menu_nap) vNastSel = 79;
          else          vNastSel = 10;
        }
      }

      // ������� ������� "1"
      // �������� �� ������� �����
      if ( (vNastSel>=10 ) && (vNastSel<20) ) {
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
      }

      // ������� ������� "2"
      // �������� ������
      if ( (vNastSel>=20 ) && (vNastSel<30) ) {
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
      }

      // ������� ������� "3"
      // ��������� ����������
      if ( (vNastSel>=30 ) && (vNastSel<40) )
      {
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
      }

      // ������� ������� "4"
      // ������
      if ( (vNastSel>=40 ) && (vNastSel<50) ) {
        if (menu_nap) vNastSel = 39;
        else          vNastSel = 50;
      }

      // ������� ������� "5"
      // ������
      if ( (vNastSel>=50 ) && (vNastSel<60) ) {
        if (menu_nap) vNastSel = 49;
        else          vNastSel = 60;
      }

      // ������� ������� "6"
      // ������
      if ( (vNastSel>=60 ) && (vNastSel<70) ) {
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
      }

      // ������� ������� "7"
      // ������� ����� - ��������� ������ � ������� ������
      if ( vNastSel>=70 ) {
        if (menu_nap) vNastSel = 69;
        else          vNastSel = 1;
      }

      if (vNastSel==1 ) scr->ShowString(c_stolbcov, "���.����/�����  " );
      if (vNastSel==10) scr->ShowString(c_stolbcov, "������� �����   " );
      if (vNastSel==20) scr->ShowString(c_stolbcov, "�����           " );
      if (vNastSel==30) scr->ShowString(c_stolbcov, "���� � �����    " );
      if (vNastSel==31) scr->ShowString(c_stolbcov, "���� � ����     " );
      if (vNastSel==60) scr->ShowString(c_stolbcov, "���. �������    " );
      // vNastSelx = vNastSel;
    }
  }
  void NastSel_1(void)
  {
    scr->Clear();
    scr->ShowString(0, "�����");
    /*
    __disable_interrupt();
    menuTimeOut = 200;
    __enable_interrupt();
    */
    TimeOut_i(200);
  }
  void NastSel_2(void)
  {
    menu_nap = 1;
    if (vNastSel>1)
      vNastSel--;
    else
      vNastSel = 254;
    NastSel_0();
  }
  void NastSel_3(void)
  {
    menu_nap = 0;  
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
    scr->ShowString(0, "������ � ����");
    TimeOut_i(6000);
  }
  //========================================================
  // ����� ������
  void PaswSel_i()
  {
    mode = md_PaswSel;
    PaswSel_CntPsw = 0;
    PaswSel_OldPsw = 255;
    scr->Clear();
    scr->ShowString(             0, "user N   view");
    scr->ShowString(c_stolbcov + 0, "��� �������:");
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
      /*
      accs = ee_psw[PaswSel_CntPsw].mask;
      scr->ShowChar(        7,'0'+PaswSel_CntPsw);
      scr->Hex(c_stolbcov + 12,accs);
      */
    }
  }
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
  //========================================================
  // ��������� ������
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
    scr->ShowString(c_stolbcov + 0, "������ :");
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
  // ��������� ��������
  void PaswSetAcs_i() {
    mode = md_PaswSetAcs;
    PaswSetAcs_mask = 0;
    PaswSetAcs_count = 0;
    scr->Clear();
    scr->ShowString(             0, "user N   enter");
    scr->ShowChar  (        7,'0'+PaswSel_CntPsw);
    scr->ShowString(c_stolbcov + 0, "��� �������:");
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
  // ��������� ����
  void DateYear_i() {
    mode = md_DateYear;
    Date_Year = clockrt::time[CT_YEAR];
    if (Date_Year>99) Date_Year = 0;
    scr->Clear();
    scr->ShowString(             0, "���.����:");
    scr->ShowString(c_stolbcov + 0, "���. +1X +1 ����");
  }
  void DateYear_0() {
    scr->dig_uz(             9, 2, Date_Year);
  }
  void DateYear_1() {
    NastSel_i();
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
  // ��������� ������
  void DateMonth_i() {
    mode = md_DateMonth;
    Date_Month = clockrt::time[CT_MONTH];
    if (Date_Month>12) Date_Month = 1;
    scr->Clear();
    scr->ShowString(             0, "���.������:");
    scr->ShowString(c_stolbcov + 0, "���. +1X +1 ����");
  }
  void DateMonth_0() {
    scr->dig_uz(             11, 2, Date_Month);
  }
  void DateMonth_1() {
    NastSel_i();
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
  // ��������� ����
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
    scr->ShowString(             0, "���.����:");
    scr->ShowString(c_stolbcov + 0, "���. +1X +1 ����");
  }
  void DateDate_0() {
    scr->dig_uz(             9, 2, Date_Date);
  }
  void DateDate_1() {
    NastSel_i();
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
  // ��������� �����
  void DateHour_i() {
    mode = md_DateHour;
    Date_Hour = clockrt::time[CT_HOUR];
    if (Date_Hour>23) Date_Hour = 0;
    scr->Clear();
    //scr->ShowString( 0, "����� ��:��:��");
    scr->ShowString(             0, "���.�����:");
    scr->ShowString(c_stolbcov + 0, "���. +1X +1 ����");
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
    NastSel_i();
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
  // ��������� �����
  void DateMinute_i() {
    mode = md_DateMinute;
    Date_Minute = clockrt::time[CT_MINUTE];
    if (Date_Minute>59) Date_Minute = 0;
    scr->Clear();
    //scr->ShowString( 0, "����� ��:��:��");
    scr->ShowString(             0, "���.�����:");
    scr->ShowString(c_stolbcov + 0, "���. +1X +1 ����");
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
    NastSel_i();
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
  // ������������ ��� ����� �� ��������� ����
  void DateSet_i() {
    mode = md_DateSet;
    scr->Clear();
    scr->ShowString( 0,             "���.����/����?");
    //scr->ShowString(c_stolbcov + 0, "�������� ?");
    scr->ShowString(c_stolbcov + 0, "     ��� ��     ");
  }
  void DateSet_2() {
    NastSel_i();
  }
  void DateSet_3() {
    scr->Clear();
    scr->ShowString( 0, "time set");
    clockrt::RefSav();
    clockrt::SetYear(Date_Year);
    clockrt::SetMonth(Date_Month);
    clockrt::SetDate(Date_Date);
    clockrt::SetHour(Date_Hour);
    clockrt::SetMinute(Date_Minute);
    clockrt::SetZeroSecond();
    clockrt::Update();
    NastSel_i();
    /*
    {
      CritSec cs;
      menuTimeOut = 500;
      TimeOut_i();
    }
    */
  }
  //========================================================
  void zero() {
    mode = md_Zero;
    scr->Clear();
    scr->ShowString( 0, "������� !!!");
    scr->ShowString( c_stolbcov + 0, "���. ����� �����");
  }
  //========================================================
  // �� �����
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
    scr->ShowString( 0, "���.�����");
//  scr->ShowChar(  9, '1' + sm.Smena);
    scr->ShowChar( c_stolbcov + 3, '.');
    scr->ShowString( c_stolbcov + 7, "�");
    scr->ShowChar(c_stolbcov + 12, '.');
    scr->ShowChar(c_stolbcov + 14, '�');
    scr->ShowChar(c_stolbcov + 15, '�');
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
  // �����
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
    scr->ShowChar(c_stolbcov + 7, '�');
    scr->ShowChar(c_stolbcov + 12, '.');
    scr->ShowChar(c_stolbcov + 14, '�');
    scr->ShowChar(c_stolbcov + 15, '�');
    scr->ShowString( 9, "�����:");
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
  // �������� ��������
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
    scr->ShowString(             7, "��/���.");
    scr->ShowString(c_stolbcov + 0, "���.  -  +  ����");
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
  // �������� �������� ����������
  void KmetrSav_i() {
    mode = md_KmetrSav;
    scr->Clear();
    scr->ShowString(             0, "��������� ?");
    scr->ShowString(c_stolbcov + 0, "     ��� ��     ");
  }
  void KmetrSav_2() {
    NastSel_i();
  }
  void KmetrSav_3() {
    unsigned long x = 0;
    for(unsigned char i=0;i<6;i++) {
      if (i==2) continue;
      x = x * ((unsigned long)10);
      x = x + (unsigned long)(Kedit[i] - '0');
    }
//  vg::ee_K_Metr = x;
    NastSel_i();
  }
  //========================================================
  // �������� ��������
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
    scr->ShowString(             7, "�/���.");
    scr->ShowString(c_stolbcov + 0, "���.  -  +  ����");
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
  // �� �������� ����������
  void KkgSav_i() {
    mode = md_KkgSav;
    scr->Clear();
    scr->ShowString(             0, "��������� ?");
    scr->ShowString(c_stolbcov + 0, "     ��� ��     ");
  }
  void KkgSav_2() {
    NastSel_i();
  }
  void KkgSav_3() {
    unsigned long x = 0;
    for(unsigned char i=0;i<6;i++) {
      if (i==2) continue;
      x = x * ((unsigned long)10);
      x = x + (unsigned long)(Kedit[i] - '0');
    }
//  vg::ee_K_Kg = x;
    NastSel_i();
  }
  //========================================================
  // ��������� ������ �������
  //========================================================
  void Dummy(void){}
  void (* const __flash MassMenu[][6])(void) = {
    { init,        init,        init,        init,        init,        init  },
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
    { Dummy,       Dummy,       Dummy,       Dummy,       Dummy,       Dummy },
    { Dummy,       Dummy,       Dummy,       Dummy,       Dummy,       Dummy },
    { Dummy,       Dummy,       Dummy,       Dummy,       Dummy,       Dummy },
    { Dummy,       Dummy,       Dummy,       Dummy,       Dummy,       Dummy },
    { Dummy,       Dummy,       Dummy,       Dummy,       Dummy,       Dummy },
    { Dummy,       Dummy,       Dummy,       Dummy,       Dummy,       Dummy },
    { Dummy,       Dummy,       Dummy,       Dummy,       Dummy,       Dummy }
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


