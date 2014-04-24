
#ifndef rs485__h
#define rs485__h
namespace ns_rs485
{
  void init(void);
  unsigned char WriteByte(unsigned char data);
  unsigned char ReadByte(unsigned char *Byte);
  extern unsigned char RxLen;       // ���������� �������
  extern unsigned char RxOverFlow;  // ������������ ��� ������
  extern unsigned char TxLen;       // ���������� �������
  extern unsigned char TxOverFlow;  // ������������ ��� ��������
}
#endif

