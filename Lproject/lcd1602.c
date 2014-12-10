/*
 * RS P2.0
 * RW P2.1
 * EN P2.2
 * OUTPUT P1.0-P1.7
 * 输入A显示E
 */
#include <ioCC2530.h>

typedef unsigned char uchar;
typedef unsigned int  uint;
uchar tab[] = "Wang Wei Jun";
uchar tab1[] = "124102102";
uchar hw[] = "HELLO WORLD";
uchar h[] = "AAAAAAA";

#define RS P0_0
#define RW P0_1
#define EN P0_2

void delayms(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}
/*void initIO()
{
	P1DIR |= 0xff;
	P1SEL |= 0x00;
	P1INP |= 0x60;
	//P2SEL |= 0x00;
	P2SEL |= 0xff;
	P2DIR |= 0xff;
}*/
void initIO1()
{
	P0SEL &= 0xf0; // 设为0 通用IO口
	P0DIR |= 0xff; // 设为1 输出
	P1SEL &= 0x00; // 设为0 通用IO口
	P1DIR |= 0xff; // 设为1 输出
}
void LCD_wcom(uchar com)
{
	RS = 0;
	RW = 0;
	P1 = com;
	delayms(500);
	EN = 1;
	EN = 0;
}
void LCD_wdate(uchar date)
{
	RS = 1;
	RW = 0;
	P1 = date;
	delayms(500);
	EN = 1;
	EN = 0;
}
void LCD_init()
{
	LCD_wcom(0x01);
	// delayms(1000);
	LCD_wcom(0x38);
	// delayms(1000);
    LCD_wcom(0x0c);
    // delayms(1000);
    LCD_wcom(0x06);
    // delayms(1000);
    // LCD_wcom(0x01);
    delayms(1000);
}

/*void main()
{
	uchar n,m;
	initIO1();
	LCD_init();
	LCD_wcom(0x80);
	for (n = 0; n < 12; n++)
	{
		LCD_wdate(tab[n]);
		delayms(1000);
	}
	LCD_wcom(0x80+0x44);
	for (m = 0; m < 9; m++)
	{
		LCD_wdate(tab1[m]);
		delayms(1000);
	}
	while(1);
}*/

void main()
{
	uchar n;
	initIO1();
	LCD_init();
	LCD_wcom(0x80);
	for (n = 0; n < 7; n++)
	{
		LCD_wdate(h[n]);
		delayms(1000);
	}
	while(1);
}