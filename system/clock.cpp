
#include "../main.h"
#ifdef CLOCK
#include "clock.h"

//i2c
#define SCLK_IO  DDRA_DDA7    // ����������� ����� ������������
#define SDA_IO   DDRA_DDA6    // ����������� ����� ������
#define SCLK_WR  PORTA_PORTA7 // ������ ����� ������������
#define SDA_WR   PORTA_PORTA6 // ������ �� ����� ������
#define SCLK_RD  PINA_PINA7
#define SDA_RD   PINA_PINA6
#define SDA_SCLK_HI {SCLK_WR=1;SDA_WR=1;} // ������ "1" �� ����� ������ � ������������ I2C
#define clc_zad 4
namespace clockrt
{
  unsigned char clock_data[8]; // ������ �������� �����-���������
  unsigned char time[7];       // ������ ���� �������
  unsigned char clock_datas[8]; // ������ �������� �����-���������
  unsigned char level_sda;
      unsigned int tik_count = 1;
      unsigned char tik_cn = 0;
      unsigned char tik = 0;
      unsigned char old_sec = 255;
  
  inline void Start(void)  // �������� ������� ������ ������
  {
    SDA_SCLK_HI;
    _delay_us(clc_zad);   // ������� ���������
    SDA_WR=0;       // ������ "0" �� ����� ������ I2C
    _delay_us(clc_zad);   // ������� ���������
    SCLK_WR=0;      // ������ "0" �� ����� ������������ I2C
  }
  inline void Stop(void)   // ������ ������� ���� ������
  {
    SDA_WR=0;       // ������ "0" �� ����� ������ I2C
    _delay_us(clc_zad);   // ������� ���������
    SCLK_WR=1;      // ������ "1" �� ����� ������ � ������������ I2C
    _delay_us(clc_zad);   // ������� ���������
    SDA_WR=1;       // ������ "1" �� ����� ������ I2C
  }
  inline void Clock(void)  // ������������ ������� ������������
  {                 // ������� ����� SDA ��������� � �������� level_sda
    SCLK_WR=1;      // ������ "1" �� ����� ������ � ������������ I2C
    level_sda = 1;  // �� ��������� ��� ������ �� eeprom level_sda=1
    _delay_us(clc_zad);   // ������� ���������
    if(!SDA_RD) level_sda = 0; // ���� SDA = 0, �� �������� ������������� �� eeprom
    SCLK_WR=0;      // ������ "0" �� ����� ������������ I2C
    _delay_us(clc_zad);   // ������� ���������
  }
  void Ack(void)    // ������ ������� ack - ���������� ������ ��������
  {
    SDA_WR=0;       // ������ "0" �� ����� ������ I2C
    Clock();        // ������������ ������� ������������
    SDA_WR=1;       // ������ "1" �� ����� ������ I2C
  }
  void Nack(void)   // ������ ������� nack - ��������� ������ �����
  {
    SDA_WR=1;       // ������ "1" �� ����� ������ I2C
    Clock();        // ������������ ������� ������������
  }
  void RecAck(void) // �������� �� ����� ������������� �� eeprom (��������� � level_sda)
  {
    SDA_IO=0;       // ����� ������ I2C �� �����
    Clock();        // ������������ ������� ������������
    SDA_IO=1;       // ����� ������ I2C �� ��������
  }
  unsigned char InByte()
  {
    unsigned char bit_count;
    unsigned char data_i2c;
    data_i2c = 0;
    SDA_IO=0;         // ����� ������ I2C �� �����
    for(bit_count=0;bit_count<8;bit_count++) {
      SCLK_WR=1;      // ������ "1" �� ����� ������ � ������������ I2C
      _delay_us(clc_zad);   // ������� ���������
      data_i2c <<= 1;
      if(SDA_RD==1)      // ���� SDA = 0, �� �������� ������������� �� eeprom
        data_i2c += 1;
      SCLK_WR=0;      // ������ "0" �� ����� ������������ I2C
      _delay_us(clc_zad);   // ������� ���������
    }
    SDA_IO=1;         // ����� ������ I2C �� ��������
    return data_i2c;
  }
  void OutByte(unsigned char data_i2c) // �������� ������������ ������
  {
    unsigned char bit_count;
    for(bit_count=0;bit_count<8;bit_count++) {
      if(data_i2c & 0x80)
        SDA_WR=1;     // ������ "1" �� ����� ������ I2C
      else
        SDA_WR=0;     // ������ "0" �� ����� ������ I2C
      Clock();        // ������������ ������� ������������
      data_i2c <<= 1;
    }
  }
  void WrPoll(void)
  {
    /*
    unsigned char ack_count;
    ack_count=0xFF;
    do
    {
      ack_count--;
    */
    Start();          // �������� ������� ������ ������
    OutByte(0xD0);    // �������� ����� ����������
    RecAck();         // �������� �� ����� ������������� �� eeprom (��������� � level_sda)
    /*
    if(!level_sda)
      return;
    }
    while(ack_count);
    */
    // Start();   // �������� ������� ������ ������
    // Stop();    // ������ ������� ���� ������
  }

  void ClockBuffWrite() // ������ ��������� ���� ������� �� ������
  {
    unsigned char count_byte;
    WrPoll();
    OutByte(0);       // ��������� �����
    RecAck();         // �������� �� ����� ������������� �� eeprom (��������� � level_sda)
    for(count_byte=0;count_byte<8;count_byte++) {
      OutByte(clock_datas[count_byte]);  // ��������� ������ �������� �����-���������
      RecAck();                         // �������� �� ����� ������������� �� eeprom (��������� � level_sda)
    }
    Stop();         // ������ ������� ���� ������
  }
  void ClockBuffRead() // ������ ��������� ���� ������� � �����
  {
    unsigned char count_byte;
    WrPoll();
    OutByte(0x00);  // ��������� �����
    RecAck();       // �������� �� ����� ������������� �� eeprom (��������� � level_sda)
    Start();        // �������� ������� ������ ������
    OutByte(0xD1);  // ����������� �� ������
    RecAck();       // �������� �� ����� ������������� �� eeprom (��������� � level_sda)
    for(count_byte=0;count_byte<8;count_byte++) {
      clock_data[count_byte] = InByte();    // ��������� ������ �������� �����-���������
      if(count_byte!=7)
        Ack();      // ������ ������� ack - ���������� ������ ��������
      else
        Nack();     // ������ ������� nack - ��������� ������ �����
    }
    Stop(); /* ������ ������� ���� ������ */
  }
  void RefreshTime(void) // �������� �������� ������� � ������� time[]
  {
      CritSec cs;
      ClockBuffRead(); /* ������ ��������� ����/������� � ����� */
      time[CT_SECOND]=(clock_data[CC_SECOND]&0x0F)+(clock_data[CC_SECOND]>>4)*10; /* ������� */
      time[CT_MINUTE]=(clock_data[CC_MINUTE]&0x0F)+(clock_data[CC_MINUTE]>>4)*10; /* ������ */
      time[CT_HOUR]=(clock_data[CC_HOUR]&0x0F)+((clock_data[CC_HOUR]>>4)&0x03)*10; /* ���� */
      time[CT_DAY]=(clock_data[CC_DAY] & 0x07); // ���� ������
      time[CT_DATE]=(clock_data[CC_DATE]&0x0F)+((clock_data[CC_DATE]>>4)&0x03)*10; /* ���� */
      time[CT_MONTH]=(clock_data[CC_MONTH]&0x0F)+((clock_data[CC_MONTH]>>4)&0x01)*10; /* ����� */
      time[CT_YEAR]=(clock_data[CC_YEAR]&0x0F)+(clock_data[CC_YEAR]>>4)*10; /* ��� */
  }
  void RefSav()
  {
      CritSec cs;
      for (unsigned char i=0;i<8;i++) clock_datas[i] = clock_data[i];
  }
  void SetYear(unsigned char year)
  {
      clock_datas[CC_YEAR] = ((year/10)<<4)+(year%10);
  }
  void SetMonth(unsigned char mount)
  {
      clock_datas[CC_MONTH] = ((mount/10)<<4)+(mount%10);
  }
  void SetDate(unsigned char date)
  {
      clock_datas[CC_DATE] = ((date/10)<<4)+(date%10);
  }
  void SetHour(unsigned char hour)
  {
      clock_datas[CC_HOUR] = ((hour/10)<<4)+(hour%10);
  }
  void SetMinute(unsigned char minute)
  {
      clock_datas[CC_MINUTE] = ((minute/10)<<4)+(minute%10);
  }
  void SetZeroSecond()
  {
      clock_datas[CC_SECOND] = 0;
  }
  void Update()
  {
      CritSec cs;
      ClockBuffWrite();
  }
  void init()
  {
    SCLK_IO=1;
    SDA_IO=1;
    SDA_SCLK_HI;
    RefreshTime();
    RefSav();
    if (time[CT_HOUR]>23)   SetHour(0);
    if (time[CT_MINUTE]>59) SetMinute(0);
    if (time[CT_SECOND]>59) SetZeroSecond();
    clock_datas[CC_MODE] = 0x13;
    Update();
  }
  void timer()
  {
      if (--tik_count>0) return;
      tik_count = 200;
      RefreshTime();
      if (++tik_cn>1) tik_cn = 0;
      if (old_sec==time[CT_SECOND]) return;
      old_sec=time[CT_SECOND];
      tik = 1;
  }
}
#endif
