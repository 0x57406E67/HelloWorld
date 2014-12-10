\
#include <ioCC2530.h>

typedef unsigned char uchar;
typedef unsigned int  uint;

#define LED1 P1_0 
#define KEY1 P0_0


void DelayMS(uint msec)
{ 
    uint i,j;
    
    for (i=0; i<msec; i++)
        for (j=0; j<535; j++);
}

void InitLed(void)
{
    P1DIR |= 0x01;  
    LED1 = 1;  
}

void InitKey(void)
{
    // P0SEL &= ~0x02; 
    // P0DIR &= ~0x02;     
    // P0INP &= ~0x02;    

    P0SEL = 0x00;
    P0DIR = 0x00;
    P0INP &= ~0x02; 
}


uchar KeyScan(void)
{
    if (KEY1 == 0)
    {
        DelayMS(10);
        if (KEY1 == 0)
        {
            while(!KEY1); 
            return 1;     
        }
    }
    
    return 0;             
}


void main(void)
{
    InitLed();		      
    InitKey();            
    
    while(1)
    {
        if (KeyScan())    
            LED1 = ~LED1;       
    }
}
