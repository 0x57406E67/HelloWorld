/*
 * RS P0.5
 * RW P0.6
 * EN P0.7
 * OUTPUT P1.0-P1.7
 * DONE
 */
#include <ioCC2530.h>

typedef unsigned char uchar;
typedef unsigned int  uint;
uchar tab[] = "Wang Wei Jun";
uchar tab2[]= "Zhang jian zao";
uchar table[16] = {0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff,0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00};
#define RS P0_5
#define RW P0_6
#define EN P0_7


void delayms(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}

void InitKey(void)
{
	P0DIR |= 0xff;
}

uchar Keyscan(void)
{
	uchar i,j, temp, Buffer[4] = {0xef, 0xdf, 0xbf, 0x7f};
	for(j=0; j<4; j++)
	{      
		P0 = Buffer[j];
		temp = 0x01;                                                                                                                                                                    
		for(i=0; i<4; i++)
		{
			if(!(P0 & temp)) 
			{
				return (i+j*4);	
			}
			temp <<= 1;
		}	
	}
}

void initIO1()
{
	//P1SEL &= 0x00;
	//P2SEL &= 0xf0;
	P0DIR |= 0xff;
	P1DIR |= 0xff;
	// P2INP &= 0xf0;
	//P2INP = 0xf0;
}
void LCD_wcom(uchar com)
{
	RS = 0;
	RW = 0;
	P1 = com;
	delayms(1000);
	EN = 1;
	EN = 0;
}
void LCD_wdate(uchar date)
{
	RS = 1;
	RW = 0;
	P1 = date;
	delayms(1000);
	EN = 1;
	EN = 0;
}
void LCD_init()
{
	// LCD_wcom(0x01); 
	// delayms(1000);
	LCD_wcom(0x38); 
	// delayms(1000);
    LCD_wcom(0x0c); 
    //LCD_wcom(0x0e); 
    // LCD_wcom(0x0f); 
    // delayms(1000);
    LCD_wcom(0x06); 
    // LCD_wcom(0x07); 
    // delayms(1000);
    LCD_wcom(0x01);
    delayms(1000);
}

void main()
{
	uchar Key_Value;
	uchar n,m;
	uchar Answer;
	InitKey();
	initIO1();
	LCD_init();
/*	LCD_wcom(0x80);
	for (n = 0; n < 12; n++)
	{
		LCD_wdate(tab[n]);
		delayms(1000);
	}
	LCD_wcom(0x80+0x40);
	for (m = 0; m < 14; m++)
	{
		LCD_wdate(tab2[m]);
		delayms(1000);
	}*/
	while(1)
	{
		P0 = 0xf0;
                 		
		if(P0 != 0xf0)
		{
			delayms(15);
			if(P0 != 0xf0)
			{
				Key_Value = Keyscan();		
			}
		}	         
		// P1 = table[Key_Value % 16];
		Answer = (Key_Value % 16);
		LCD_wcom(0x80);		
		LCD_wdate(Answer);
		delayms(1000);
		LCD_wcom(0x01);
		delayms(5);
	}
}

