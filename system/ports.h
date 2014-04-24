
#ifndef ports__h
#define ports__h
class tc_ports
{
private:
  void init(unsigned char p, unsigned char InBit, unsigned char OutOn, unsigned char porog, unsigned char OutBit);
  unsigned tr;
  unsigned char count;
  unsigned char v_porog;
public:
  unsigned char volatile __tiny *p_ddr;
  unsigned char volatile __tiny *p_in;
  unsigned char volatile __tiny *p_out;
  unsigned char maska_in;
  unsigned char maska_out;
  tc_ports(unsigned char p='g', unsigned char InBit=4); // ������, ����� 100, �������� ��� 0
  tc_ports(unsigned char p, unsigned char InBit, unsigned char OutOn); // ����� 100, �������� ��� 0
  tc_ports(unsigned char p, unsigned char InBit, unsigned char OutOn, unsigned char porog); // �������� ��� 0
  tc_ports(unsigned char p, unsigned char InBit, unsigned char OutOn, unsigned char porog, unsigned char OutBit);
  unsigned fl;  // ������ � ��������
  unsigned char *u_porog;
  unsigned char ddr(void);
  void ddr(unsigned char d);
  unsigned char pin(void);
  unsigned char pout(void);
  void pout(unsigned char d);
  void for_timer(void);
};
#endif

