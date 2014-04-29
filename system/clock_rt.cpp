
#include "../main.h"
#ifdef CLOCK
#include "clock_rt.h"

//i2c
#define SCLK_IO  DDRA_DDA7      // ����������� ����� ������������
#define SDA_IO   DDRA_DDA6      // ����������� ����� ������
#define SCLK_WR  PORTA_PORTA7   // ������ ����� ������������
#define SDA_WR   PORTA_PORTA6   // ������ �� ����� ������
#define SCLK_RD  PINA_PINA7
#define SDA_RD   PINA_PINA6

// ========== DDR ============================
#define SCLK_IO_HI  SCLK_IO=1   // ����� ������������ �� ��������
#define SDA_IO_HI   SDA_IO=1    // ����� ������ �� ��������
#define SCLK_IO_LO  SCLK_IO=0   // ����� ������������ �� �����
#define SDA_IO_LO   SDA_IO=0    // ����� ������ �� �����

// ========== DATA ============================
#define SCLK_WR_HI  SCLK_WR=1   // ������ ����� ������������ "1"
#define SDA_WR_HI   SDA_WR=1    // ������ �� ����� ������ "1"
#define SCLK_WR_LO  SCLK_WR=0   // ������ ����� ������������ "0"
#define SDA_WR_LO   SDA_WR=0    // ������ �� ����� ������ "0"

// �������� 8 �����������
#define clockrt_delay 20

namespace clockrt
{
    void init();
    void timer();
    // ���������� ������� �������
    void RefreshTime();
    // ������ ����� ������
    unsigned char InByte();
    unsigned char WrPoll();
    // �������� �����
    void OutByte(unsigned char dByte);
    // ������� ������������
    void Clc();
    void Start();
    void RecAck();
    void Ack();
    void Nack();
    // ==========================
    // ������ ��������� ����/������� � �����
    unsigned char ClockBuffRead();
    void RefSav();
    void SetUpdate();
    void Stop();
    // �������� ��������� ����/������� �� ������
    void ClockBuffSend();
    // ==========================
    unsigned char time[7];          // ������ ���� �������
    unsigned char clockData[8];    // ������ �������� �����-���������
    unsigned char clockDatas[8];   // ������ �������� �����-��������� ��� ������
#define tikCountMax 500
    unsigned int tikCount = tikCountMax;
    unsigned char oldSec = 254;
    unsigned char tik_cn = 0;
    unsigned char tik = 0;
    unsigned char workTime = 0;
    // --------------------------
    unsigned char levelSda;
    // ==========================
    void init()
    {
        SCLK_IO_HI;             // ����� ������������ �� ��������
        SCLK_WR_HI;             // ������ ����� ������������ "1"
        SDA_IO_HI;              // ����� ������ �� ��������
        SDA_IO_HI;              // ����� ������ �� ��������
        _delay_ms(100);
    }
    void timer()
    {
        if (--tikCount>0)
            return;
        tikCount = tikCountMax;
        RefreshTime();
        if (++tik_cn>1)
            tik_cn = 0;
        if (oldSec==time[CT_SECOND])
            return;
        oldSec=time[CT_SECOND];
        tik = 1;
    }
    // -------------------------------------------------------------------------
    // ������� ������������
    void Clc()
    {
        SCLK_WR_HI;             // ������ ����� ������������ "1"
        _delay_us(clockrt_delay);
        if (SDA_RD)
            levelSda = 1;
        else
            levelSda = 0;
        SCLK_WR_LO;             // ������ ����� ������������ "0"
        _delay_us(clockrt_delay);
    }
    // -------------------------------------------------------------------------
    void RecAck()
    {
        SDA_IO_LO;              // ����� ������ �� �����
        Clc();                  // ������� ������������
        SDA_IO_HI;              // ����� ������ �� ��������
    }
    void Ack()
    {
        SDA_WR_LO;              // ������ �� ����� ������ "0"
        Clc();
        SDA_WR_HI;              // ������ �� ����� ������ "1"
    }
    void Nack()
    {
        SDA_WR_HI;              // ������ �� ����� ������ "1"
        Clc();
    }
    unsigned char WrPoll()
    {
        OutByte(0xD0);
        RecAck();
        return levelSda;
    }
    // -------------------------------------------------------------------------
    // ����� ����� ������
    unsigned char InByte()
    {
        unsigned char dataI2c = 0;
        SDA_IO_LO;              // ����� ������ �� �����
        for (unsigned char i=0; i<8; i++)
        {
            SCLK_WR_HI;         // ������ ����� ������������ "1"
            _delay_us(clockrt_delay);
            dataI2c = dataI2c<<1;
            if (SDA_RD)
                dataI2c |=  (1<<0);
            else
                dataI2c &= ~(1<<0);
            SCLK_WR_LO;         // ������ ����� ������������ "0"
            _delay_us(clockrt_delay);
        }
        SDA_IO_HI;              // ����� ������ �� ��������
        return dataI2c;
    }
    // �������� �����
    void OutByte(unsigned char dByte)
    {
        for (unsigned char i=0;i<8;i++)
        {
            if (dByte & 0x80)
                SDA_WR_HI;      // ������ �� ����� ������ "1"
            else
                SDA_WR_LO;      // ������ �� ����� ������ "0"
            Clc();              // ������� ������������
            dByte = dByte<<1;
        }
    }
    // -------------------------------------------------------------------------
    void Start()
    {
        SCLK_WR_HI;             // ������ ����� ������������ "1"
        SDA_WR_HI;              // ������ �� ����� ������ "1"
        _delay_us(clockrt_delay);
        SDA_WR_LO;              // ������ �� ����� ������ "0"
        _delay_us(clockrt_delay);
        SCLK_WR_LO;             // ������ ����� ������������ "0"
    }
    void Stop()
    {
        SDA_WR_LO;              // ������ �� ����� ������ "0"
        _delay_us(clockrt_delay);
        SCLK_WR_HI;             // ������ ����� ������������ "1"
        _delay_us(clockrt_delay);
        SDA_WR_HI;              // ������ �� ����� ������ "1"
    }
    // -------------------------------------------------------------------------
    // ������ ��������� ����/������� � �����
    unsigned char ClockBuffRead()
    {
        unsigned char st = 0;
        Start();
        if (WrPoll() )
        {
            workTime = 0;
            st = 1;
        }
        else
        {
            OutByte(0);
            RecAck();
            Start();
            OutByte(0xD1);
            RecAck();
            for (unsigned char i=0; i<8; i++)
            {
                clockData[i] = InByte();
                if (i!=7)
                    Ack();
                else
                    Nack();
            }
        }
        Stop();
        return st;
    }
    // �������� ��������� ����/������� �� ������
    void ClockBuffSend()
    {
        Start();
        if ( WrPoll() )
        {
            Stop();
        }
        else
        {
            OutByte(0);
            RecAck();
            for (unsigned char i=0; i<8; i++)
            {
                OutByte(clockDatas[i]);
                RecAck();
            }
            Stop();
        }
    }
    // -------------------------------------------------------------------------
    // ���������� ������� �������
    void RefreshTime()
    {
        CritSec cs;
        // ������ ��������� ����/������� � �����
        if ( ClockBuffRead() )
            return;
        time[CT_SECOND]=(clockData[CC_SECOND]&0x0F)+(clockData[CC_SECOND]>>4)*10;         // �������
        time[CT_MINUTE]=(clockData[CC_MINUTE]&0x0F)+(clockData[CC_MINUTE]>>4)*10;         // ������
        time[CT_HOUR]  =(clockData[CC_HOUR]  &0x0F)+((clockData[CC_HOUR]>>4)&0x03)*10;    // ����
        time[CT_DAY]   =(clockData[CC_DAY]   &0x07);                                       // ���� ������
        time[CT_DATE]  =(clockData[CC_DATE]  &0x0F)+((clockData[CC_DATE]>>4)&0x03)*10;    // ����
        time[CT_MONTH] =(clockData[CC_MONTH] &0x0F)+((clockData[CC_MONTH]>>4)&0x01)*10;   // �����
        time[CT_YEAR]  =(clockData[CC_YEAR]  &0x0F)+(clockData[CC_YEAR]>>4)*10;           // ���
        if ( (time[CT_YEAR]==0) || (time[CT_YEAR]>99) )
            workTime = 0;
        else
            workTime = 1;
    }
    void SetUpdate()
    {
        clockDatas[CT_SECOND] = 0;
        ClockBuffSend();
    }
    // ==========================
    void RefSav()
    {
        CritSec cs;
        for (unsigned char i=0; i<8; i++)
            clockDatas[i] = clockData[i];
    }
    void SetYear(unsigned char year)
    {
        clockDatas[CC_YEAR] = ((year/10)<<4)+(year%10);
    }
    void SetMonth(unsigned char mount)
    {
        clockDatas[CC_MONTH] = ((mount/10)<<4)+(mount%10);
    }
    void SetDate(unsigned char date)
    {
        clockDatas[CC_DATE] = ((date/10)<<4)+(date%10);
    }
    void SetHour(unsigned char hour)
    {
        clockDatas[CC_HOUR] = ((hour/10)<<4)+(hour%10);
    }
    void SetMinute(unsigned char minute)
    {
        clockDatas[CC_MINUTE] = ((minute/10)<<4)+(minute%10);
    }
}
#endif

