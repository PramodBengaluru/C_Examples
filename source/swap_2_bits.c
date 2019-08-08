
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>

int main()
{
unsigned int a,pos1,pos2;
unsigned int temp=0,temp1=0;
printf("Enter any number\n");
scanf("%d",&a);
printf("Enter bit position to be exchanged\n");
scanf("%u",&pos1);
scanf("%u",&pos2);
if(pos1>pos2)
{
    pos1+=pos2;
    pos2=pos1-pos2;
    pos1-=pos2;
}
temp|=(a&(1<<pos1));
temp1|=(a&(1<<pos2));
a&=(~(1<<pos1));
a&=(~(1<<pos2));
a|=temp<<(pos2-pos1);
a|=temp1>>(pos2-pos1);
printf("The number after exchange is %u \n",a);
}
