
#ifndef clock__h
#define clock__h
#ifdef CLOCK

// ��� ���� ������� � ������� clock_data[]
#define CC_SECOND          0
#define CC_MINUTE          1
#define CC_HOUR            2
#define CC_DAY             3
#define CC_DATE            4
#define CC_MONTH           5
#define CC_YEAR            6
#define CC_MODE            7

// ��� ���� ������� � ������� time[]
#define CT_SECOND          0
#define CT_MINUTE          1
#define CT_HOUR            2
#define CT_DAY             3
#define CT_DATE            4
#define CT_MONTH           5
#define CT_YEAR            6

namespace clockrt
{
  extern unsigned char clock_data[8]; // ������ �������� �����-���������
  extern unsigned char time[7];       // ������ ���� �������
  //void ClockBuffWrite(void);        // ������ ��������� ���� ������� �� ������
  //void ClockBuffRead();             // ������ ��������� ���� ������� � �����
  extern unsigned int tik_count;
  extern unsigned char tik_cn;
  extern unsigned char tik;
  void RefreshTime(void);             // �������� �������� ������� � ������� time[]
  void init();
  void timer();
  //
  void RefSav();
  void SetYear(unsigned char year);
  void SetMonth(unsigned char mount);
  void SetDate(unsigned char date);
  void SetHour(unsigned char hour);
  void SetMinute(unsigned char minute);
  void SetZeroSecond();
  void Update();
}

#endif
#endif
