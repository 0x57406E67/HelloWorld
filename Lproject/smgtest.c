#include <ioCC2530.h>

typedef unsigned char uchar;
typedef unsigned int  uint;

#define LED1 P0_0
#define LED2 P0_1
#define LED3 P0_2
#define LED4 P0_3
#define LED5 P0_4
#define LED6 P0_5
#define LED7 P0_6
#define LED8 P0_7

#define LA P1_7
#define LB P1_6
#define LC P1_5
#define LD P1_4
#define LE P1_3
#define LF P1_2
#define LG P1_1
#define LH P1_0
uchar table[2] = {0x28,0xb3};
uchar led[8] = {0,1,2,3,4,5,6,7};
void DelayMS(uint msec)
{ 
    uint i,j;
    
    for (i=0; i<msec; i++)
        for (j=0; j<535; j++);
}

void LedOnOrOff(uchar mode)
{
    LED1 = mode;
    LED2 = mode;
    LED3 = mode; 
    LED4 = mode;
    LED5 = mode;
    LED6 = mode;
    LED7 = mode;
    LED8 = mode;

    // LA = mode;
    // LB = mode;
    // LC = mode;
    // LD = mode;
    // LE = mode;
    // LF = mode;
    // LG = mode;
    // LH = mode;
}

void InitLed(void)
{
    P0DIR |= 0xff;         
    P1DIR |= 0xff;
    // LedOnOrOff(0);      
}
void one(void)
{
    LA = 0;
    LB = 0;
    LC = 1;
    LD = 0;
    LE = 1;
    LF = 0;
    LG = 0;
    LH = 0;
}
void two(void)
{
    LA = 1;
    LB = 0;
    LC = 1;
    LD = 1;
    LE = 0;
    LF = 0;
    LG = 1;
    LH = 1;
}
void main(void)
{
    while(1)
    {
        LedOnOrOff(0);
        P1 = 0x28;
        DelayMS(500);
        LedOnOrOff(1);
        DelayMS(500);
        LedOnOrOff(0);
        P1 = 0xb3;
        DelayMS(500);
        LedOnOrOff(1);
    }
/*    LED7 = 0;
    DelayMS(500);
	LED7 = 1;
    LH = 0;*/
/*    while(1)
    {
        LED1 = 0;
        DelayMS(500);
        LED1 = 1;
        LED2 = 0;
        DelayMS(500);
        LED2 = 1;
    }*/
    /*while(1)
    {
        LED1 = 0;
        // one();
        LED2 = 0;
        two();

    }*/
    /*while(1)
    {
        // LED1 = 0;
        // P1 = 0x28;
        // DelayMS(500);
        // LED1 = 1; 
        // LED2 = 0;
        // P1 = 0xb3;
        // DelayMS(500);
        // LED2 = 1;
        // LED3 = 0;
        // P1 = 0x28;
        LedOnOrOff(0);
        P1 = 0xb3;
        DelayMS(500);
        LedOnOrOff(1);
        LedOnOrOff(0);
        P1 = 0x28;
        DelayMS(500);
        LedOnOrOff(1);
    }*/

}