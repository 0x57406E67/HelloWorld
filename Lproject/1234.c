#include<IOcc2530.h>
#define uint unsigned int
#define uchar unsigned char
//1602位控制
#define LCD_1602_EN           P0_2      //使能端              
#define LCD_1602_RW           P0_1     //液晶状态数据选择端
#define LCD_1602_RS           P0_0      //液晶数据命令选择端
#define LCD_1602_BF           P1_7      //检测忙标志位
uchar const buf[]={"abchij"};
uchar num;
//延时函数 延时时间约为 5*n/32us1
void Delay(uint n)
{
  uint i;
  for(i=0;i<n;i++);
  for(i=0;i<n;i++);
  for(i=0;i<n;i++);
  for(i=0;i<n;i++);
  for(i=0;i<n;i++);
}
//初始化CC2530IO
void initIO()
{ 

	P0SEL &= 0xff; // 设为0 通用IO口
	P0DIR |= 0xff; // 设为1 输出
	P1SEL &= 0xff; // 设为0 通用IO口
	P1DIR |= 0xff; // 设为1 输出
}
//写命令函数
void write_1602_com(uchar com)
{
  LCD_1602_RS=0;                 //选择写命令模式  
  LCD_1602_RW=0; 
   P1=com;                        //将要写的命令字送到数据总线上
  Delay(32000);
  LCD_1602_EN=1;
  Delay(32000);
  LCD_1602_EN=0;
}
//写数据函数
void write_1602_data(uchar date)
{
  LCD_1602_RS=1;                 //选择写数据模式  
  
LCD_1602_RW=0; 
P1=date;                       //将要写的数据送到数据总线上
  Delay(32000);
  LCD_1602_EN=1;
  Delay(32000);
  LCD_1602_EN=0;  
}
//初始化1602
void init_1602()
{
  LCD_1602_EN=0;
LCD_1602_RW=0;
  write_1602_com(0x38);          //设置16X2显示，5X7点阵，8位数据接口
  write_1602_com(0x0e);          //设置开显示，不显示光标
  write_1602_com(0x06);          //写一个字符后地址指针加1
  write_1602_com(0xff);          //显示清0，数据指针清0
  write_1602_com(0x80);          //设置初始显示为第一行第一列
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
