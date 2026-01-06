#include <reg51.h>

sbit LED = P1^0;      
sbit BUTTON = P3^2;

void delay(unsigned int time);

void main()
{
    LED = 0;
    
    while(1)
    {
        if(BUTTON == 0)       
        {
            delay(20);
            
            if(BUTTON == 0)
            {
                LED = ~LED;
                while(BUTTON == 0);
            }
        }
    }
}

void delay(unsigned int time)
{
    unsigned int i, j;
    for(i = 0; i < time; i++)
    {
        for(j = 0; j < 1275; j++);
    }
}
