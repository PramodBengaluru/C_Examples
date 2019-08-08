
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>

int main()
{
int a,b,divsr,divdnd,temp;
printf("Enter any 2 number,a and b\n");
scanf("%d%d",&a,&b);
if(a<=b)
{
    divsr=a;
    divdnd=b;    
}
else
{
    divsr=b;
    divdnd=a;    
}
while((divdnd%divsr)!=0)
{
 temp=divsr;
 divsr=divdnd%divsr;
 divdnd=temp;
}
printf("The GCD of %d and %d is %d\n",a,b,divsr);
printf("The LCM of %d and %d is %d\n",a,b,(a*b)/divsr);
}
