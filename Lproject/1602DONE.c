/*
 * RS P1.0
 * RW P1.1
 * EN P1.2
 * OUTPUT P0.0-P0.7
 * DONE
 */
#include <ioCC2530.h>

typedef unsigned char uchar;
typedef unsigned int  uint;
uchar tab[] = "Wang Wei Jun";
uchar tab2[]= "1234567890";
uchar tab1[] = "124102102";
uchar hw[] = "HELLO WORLD";
uchar h[] = "12345111187879879";

// #define RS P1_5
// #define RW P1_6
// #define EN P1_7

#define RS P2_0
#define RW P2_1
#define EN P2_2

// #define RS P2_0
// #define RW P2_1
// #define EN P2_2

void delayms(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}

void initIO1()
{
	P2DIR |= 0xff;
	P1DIR |= 0xff;
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
	//LCD_wcom(0x01); 
	// delayms(1000);
	LCD_wcom(0x38); 
	// delayms(1000);
    LCD_wcom(0x0c); 
    //LCD_wcom(0x0e); 
    //LCD_wcom(0x0f); 
    // delayms(1000);
    LCD_wcom(0x06); 
    //LCD_wcom(0x07); 
    // delayms(1000);
    LCD_wcom(0x01);
    delayms(1000);
}

void main()
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
	LCD_wcom(0x80+0x40);
	for (m = 0; m < 10; m++)
	{
		LCD_wdate(tab2[m]);
		delayms(1000);
	}
	while(1);
}

/*void main()
{
	uchar n;
	initIO1();
	LCD_init();
	LCD_wcom(0x80+0x40);
	for (n = 0; n < 16; n++)
	{
		LCD_wdate(h[n]);
		delayms(1000);
	}
	while(1);
}*/