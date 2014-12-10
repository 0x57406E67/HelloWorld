#include<IOcc2530.h>
#define uint unsigned int
#define uchar unsigned char
//1602λ����
#define LCD_1602_EN           P0_2      //ʹ�ܶ�              
#define LCD_1602_RW           P0_1     //Һ��״̬����ѡ���
#define LCD_1602_RS           P0_0      //Һ����������ѡ���
#define LCD_1602_BF           P1_7      //���æ��־λ
uchar const buf[]={"abchij"};
uchar num;
//��ʱ���� ��ʱʱ��ԼΪ 5*n/32us1
void Delay(uint n)
{
  uint i;
  for(i=0;i<n;i++);
  for(i=0;i<n;i++);
  for(i=0;i<n;i++);
  for(i=0;i<n;i++);
  for(i=0;i<n;i++);
}
//��ʼ��CC2530IO
void initIO()
{ 

	P0SEL &= 0xff; // ��Ϊ0 ͨ��IO��
	P0DIR |= 0xff; // ��Ϊ1 ���
	P1SEL &= 0xff; // ��Ϊ0 ͨ��IO��
	P1DIR |= 0xff; // ��Ϊ1 ���
}
//д�����
void write_1602_com(uchar com)
{
  LCD_1602_RS=0;                 //ѡ��д����ģʽ  
  LCD_1602_RW=0; 
   P1=com;                        //��Ҫд���������͵�����������
  Delay(32000);
  LCD_1602_EN=1;
  Delay(32000);
  LCD_1602_EN=0;
}
//д���ݺ���
void write_1602_data(uchar date)
{
  LCD_1602_RS=1;                 //ѡ��д����ģʽ  
  
LCD_1602_RW=0; 
P1=date;                       //��Ҫд�������͵�����������
  Delay(32000);
  LCD_1602_EN=1;
  Delay(32000);
  LCD_1602_EN=0;  
}
//��ʼ��1602
void init_1602()
{
  LCD_1602_EN=0;
LCD_1602_RW=0;
  write_1602_com(0x38);          //����16X2��ʾ��5X7����8λ���ݽӿ�
  write_1602_com(0x0e);          //���ÿ���ʾ������ʾ���
  write_1602_com(0x06);          //дһ���ַ����ַָ���1
  write_1602_com(0xff);          //��ʾ��0������ָ����0
  write_1602_com(0x80);          //���ó�ʼ��ʾΪ��һ�е�һ��
}
void main()
{
  initIO();
  init_1602();
  num=0;
  for(;num<6;num++)
  {
    write_1602_data(buf[num]);
    Delay(32000);
  }
}
