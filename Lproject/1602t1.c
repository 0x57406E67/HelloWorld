
#include<ioCC2530.h>
#define uchar unsigned char
#define uint  unsigned int

#define E  P0_2		
#define RW P0_1		
#define RS P0_0		


void delay()
{
	int i,j;
	for(i=0; i<=10; i++)
	for(j=0; j<=2; j++)
;
}
void initIO1()
{
	// P0SEL &= 0xf0; 
	// P0DIR |= 0xff; 
	P0SEL = 0xf0;
	P0DIR = 0xff;
	P0INP = 0x88;
	// P1SEL &= 0x00; 
	// P1DIR |= 0xff;
	P1SEL = 0x00;
	P1DIR = 0xff;
}
uchar Convert(uchar In_Date)
{
    uchar i, Out_Date = 0, temp = 0;
    for(i=0; i<8; i++)
    {
        temp = (In_Date >> i) & 0x01;
        Out_Date |= (temp << (7 - i));
    }
    return Out_Date;
}

void enable(uchar del)
{
	// P1 = Convert(del);
	P1 = del;
	RS = 0;
	RW = 0;
	E = 0;
	delay();
	E = 1;
	delay();
}


void write(uchar del)
{
	// P1 = Convert(del);
	P1 = del;
	RS = 1;
	RW = 0;
	E = 0;
	delay();
	E = 1;
	delay();
}

void L1602_init(void)
{
	enable(0x01);
	enable(0x38);
	enable(0x0c);
	enable(0x06);
	enable(0xd0);
}

void L1602_char(uchar hang,uchar lie,char sign)
{
	uchar a;
	if(hang == 1) a = 0x80;
	if(hang == 2) a = 0xc0;
	a = a + lie - 1;
	enable(a);
	write(sign);
}

void L1602_string(uchar hang,uchar lie,uchar *p)
{
	uchar a;
	if(hang == 1) a = 0x80;
	if(hang == 2) a = 0xc0;
	a = a + lie - 1;
	enable(a);
	while(1)
	{
		if(*p == '\0') break;
		write(*p);
		p++;
	}
}

void main()
{
	uchar i = 48;
	initIO1();
	L1602_init();
	L1602_string(1,1,"   0123456789 ");
	L1602_string(2,1,"   ABCDEDGHIJ ");
	while(1);	
}