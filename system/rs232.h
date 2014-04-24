
#ifndef rs232__h
#define rs232__h
namespace ns_rs232
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

