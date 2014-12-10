#include <ioCC2530.h>

typedef unsigned char uchar;
typedef unsigned int  uint;

#define LED1 P1_0
#define LED2 P1_1
#define LED3 P1_2
#define LED4 P1_3
#define LED5 P1_4
#define LED6 P1_5
#define LED7 P1_6
#define LED8 P1_7

void DelayMS(uint msec)//延时
{ 
    uint i,j;
    
    for (i=0; i<msec; i++)
        for (j=0; j<535; j++);
}
void LedOnOrOff(uchar mode)//开关led
{
	LED1 = mode;
	LED2 = mode;
	LED3 = mode;
	LED4 = mode;
	LED5 = mode;
	LED6 = mode;
	LED7 = mode;
	LED8 = mode;
}
void InitLed(void)//初始化led
{
	P1DIR |= 0xff;
	//LedOnOrOff(1);
}
void InitKey(void)//初始化Key
{
	P0DIR &= 0x00;
	P0SEL &= 0x00;
	P2INP &= 0xd7;
	P0INP &= 0x00;
}
/*uchar matrixkeyscan()// 扫描矩阵键盘函数
{
	uchar temp,key;
	P0 = 0xfe;// 1111 1110 第一行送低电平 
	temp = P0; 
	temp &= 0xf0;// 0xfe & 0xf0 = 1111 1110 & 1111 0000
	if (temp != 0xf0)
	{
		DelayMS(10);
		temp = P0;
		temp &= 0xf0;
		if (temp != 0xf0)
		{
			temp = P0;
			switch(temp)
			{
				case 0xee: LED1 = 1;//key = 1;//1110 1110 第一行第一列
				break;
				case 0xde: key = 2;//1101 1110 第一行第二列
				break;
				case 0xbe: key = 3;//1011 1110 第一行第三列
				break;
				case 0x7e: key = 4;//0111 1110 第一行第四列
				break;
			}
			while(temp != 0xf0)//等待按键释放
			{
				temp = P0;
				temp &= 0xf0;
			}
			return key;//显示，可改return
 		}
	}
	P0 = 0xfd;// 1111 1101 第二行送低电平
	temp = P0;
	temp &= 0xf0;// 0xfd & 0xf0 = 1111 1101 & 1111 0000
	if (temp != 0xf0)
	{
		DelayMS(10);
		temp = P0;
		temp &= 0xf0;
		if (temp != 0xf0)
		{
			temp = P0;
			switch(temp)
			{
				case 0xed: key = 5;// 1110 1101
				break;
				case 0xdd: key = 6;// 1101 1101
				break;
				case 0xbd: key = 7;// 1011 1101
				break;
				case 0x7d: key = 8;// 0111 1101
				break;
			}
			while(temp != 0xf0)
			{
				temp = P0;
				temp &= 0xf0;
			}
			return key;
		}
	}
	P0 = 0xfb;// 1111 1011 第三行送低电平
	temp = P0;
	temp &= 0xf0;// 0xfb & 0xf0 = 1111 1011 & 1111 0000
	if (temp != 0xf0)
	{
		DelayMS(10);
		temp = P0;
		temp &= 0xf0;
		if (temp != 0xf0)
		{
			temp = P0;
			switch(temp)
			{
				case 0xeb: key = 9;// 1110 1011
				break;
				case 0xdb: key = 10;// 1101 1011
				break;
				case 0xbb: key = 11;// 1011 1011
				break;
				case 0x7b: key = 12;// 0111 1011
				break;
			}
			while(temp != 0xf0)
			{
				temp = P0;
				temp &= 0xf0;
			}
			return key;
		}
	}
	P0 = 0xf7;// 1111 0111 第四行送低电平
	temp = P0;
	temp &= 0xf0;// 0xf7 & 0xf0 = 1111 0111 & 1111 0000
	if (temp != 0xf0)
	{
		DelayMS(10);
		temp = P0;
		temp &= 0xf0;
		if (temp != 0xf0)
		{
			temp = P0;
			switch(temp)
			{
				case 0xe7: key = 13;// 1110 0111
				break;
				case 0xd7: key = 14;// 1101 0111
				break;
				case 0xb7: key = 15;// 1011 0111
				break;
				case 0x77: key = 16;// 0111 0111
				break;
			}
			while(temp != 0xf0)
			{
				temp = P0;
				temp &= 0xf0;
			}
			return key;
		}
	}
	return 0;
}*/
uchar matrixkeyscan()// change
{
	uchar temp,key;
	P0 = 0xfe;// 1111 1110 第一行送低电平 
	temp = P0; 
	temp &= 0xf0;// 0xfe & 0xf0 = 1111 1110 & 1111 0000
	if (temp != 0xf0)
	{
		DelayMS(10);
		temp = P0;
		temp &= 0xf0;
		if (temp != 0xf0)
		{
			temp = P0;
			switch(temp)
			{
				case 0xee: key = 1;//key = 1;//1110 1110 第一行第一列
				break;
				case 0xde: key = 2;//1101 1110 第一行第二列
				break;
				case 0xbe: key = 3;//1011 1110 第一行第三列
				break;
				case 0x7e: key = 4;//0111 1110 第一行第四列
				break;
			}
			while(temp != 0xf0)//等待按键释放
			{
				temp = P0;
				temp &= 0xf0;
			}
			return key;//显示，可改return
 		}
	}
	P0 = 0xfd;// 1111 1101 第二行送低电平
	temp = P0;
	temp &= 0xf0;// 0xfd & 0xf0 = 1111 1101 & 1111 0000
	if (temp != 0xf0)
	{
		DelayMS(10);
		temp = P0;
		temp &= 0xf0;
		if (temp != 0xf0)
		{
			temp = P0;
			switch(temp)
			{
				case 0xed: key = 5;// 1110 1101
				break;
				case 0xdd: key = 6;// 1101 1101
				break;
				case 0xbd: key = 7;// 1011 1101
				break;
				case 0x7d: key = 8;// 0111 1101
				break;
			}
			while(temp != 0xf0)
			{
				temp = P0;
				temp &= 0xf0;
			}
			return key;
		}
	}
	P0 = 0xfb;// 1111 1011 第三行送低电平
	temp = P0;
	temp &= 0xf0;// 0xfb & 0xf0 = 1111 1011 & 1111 0000
	if (temp != 0xf0)
	{
		DelayMS(10);
		temp = P0;
		temp &= 0xf0;
		if (temp != 0xf0)
		{
			temp = P0;
			switch(temp)
			{
				case 0xeb: key = 9;// 1110 1011
				break;
				case 0xdb: key = 10;// 1101 1011
				break;
				case 0xbb: key = 11;// 1011 1011
				break;
				case 0x7b: key = 12;// 0111 1011
				break;
			}
			while(temp != 0xf0)
			{
				temp = P0;
				temp &= 0xf0;
			}
			return key;
		}
	}
	P0 = 0xf7;// 1111 0111 第四行送低电平
	temp = P0;
	temp &= 0xf0;// 0xf7 & 0xf0 = 1111 0111 & 1111 0000
	if (temp != 0xf0)
	{
		DelayMS(10);
		temp = P0;
		temp &= 0xf0;
		if (temp != 0xf0)
		{
			temp = P0;
			switch(temp)
			{
				case 0xe7: key = 13;// 1110 0111
				break;
				case 0xd7: key = 14;// 1101 0111
				break;
				case 0xb7: key = 15;// 1011 0111
				break;
				case 0x77: key = 16;// 0111 0111
				break;
			}
			while(temp != 0xf0)
			{
				temp = P0;
				temp &= 0xf0;
			}
			return key;
		}
	}
	return 0;
}
void main(void)
{
	uchar key = P0;
	InitLed();
	InitKey();
	LedOnOrOff(0);
	//key = matrixkeyscan();
/*	while(1)
	{
		key = matrixkeyscan();
		if (key != 0)
		{
			switch(key)
			{
				case 1: LED1 = ~LED1;
				break;
				case 2: LED2 = ~LED2;
				break;
				case 3: LED3 = ~LED3;
				break;
				case 4: LED4 = ~LED4;
				break;
				case 5: LED5 = ~LED5;
				break;
				case 6: LED6 = ~LED6;
				break;
				case 7: LED7 = ~LED7;
				break;
				case 8: LED8 = ~LED8;
				break;
				case 9: LED1 = ~LED1;
				break;
				case 10: LED2 = ~LED2;
				break;
				case 11: LED3 = ~LED3;
				break;
				case 12: LED4 = ~LED4;
				break;
				case 13: LED5 = ~LED5;
				break;
				case 14: LED6 = ~LED6;
				break;
				case 15: LED7 = ~LED7;
				break;
				case 16: LED8 = ~LED8;
				break;
			}
		}
		switch(key)
		{
			case 0: LED1 = ~LED1;
			break;
			case 1: LED2 = ~LED2;
			break;
			case 2: LED3 = ~LED3;
			break;
			case 3: LED4 = ~LED4;
			break;
			case 4: LED5 = ~LED5;
			break;
			case 5: LED6 = ~LED6;
			break;
			case 6: LED7 = ~LED7;
			break;
			case 7: LED8 = ~LED8;
			break;
			case 8: LED1 = ~LED1;
			break;
			case 9: LED2 = ~LED2;
			break;
			case 10: LED3 = ~LED3;
			break;
			case 11: LED4 = ~LED4;
			break;
			case 12: LED5 = ~LED5;
			break;
			case 13: LED6 = ~LED6;
			break;
			case 14: LED7 = ~LED7;
			break;
			case 15: LED8 = ~LED8;
			break;
		}
	}*/
	while(1)
	{
		matrixkeyscan();
	}
}