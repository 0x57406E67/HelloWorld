#include<ioCC2530.h>
#define uint unsigned int
#define uchar unsigned char
uchar table[16] = {0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff,0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00};
//0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00单个点亮
void Delay_1ms(uint i)
{
	uchar x,j;
	for(j=0;j<i;j++)
	for(x=0;x<=148;x++);	
}
void InitKey(void)//初始化Key
{
	P0DIR |= 0xff;
}

void InitLed(void)//初始化led
{	
        P1DIR |= 0xff;
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
				return (i+j*4);		  //返回取得的按键值
			}
			temp <<= 1;
		}	
	}
}
void main(void)
{
	uchar Key_Value;  //读出的键值		
	InitLed();
	InitKey();
	while(1)
	{
		P0 = 0xf0;//亮P0 = 0xff闪
                 //P1 = 0xff;			
		if(P0 != 0xf0)
		{
			Delay_1ms(15);	//按键消抖
			if(P0 != 0xf0)
			{
				Key_Value = Keyscan();		
			}
		}	         
		P1 = table[Key_Value % 16];		//显示低位键值		
		Delay_1ms(5);
	}
}
