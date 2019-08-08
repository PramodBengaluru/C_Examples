
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>

int main()
{
int a,b,temp;
printf("Enter any 2 number,a and b\n");
scanf("%d%d",&a,&b);
temp=a;
a=b;
b=temp;
printf("Numbers after swapping are a=%d,b=%d\n",a,b);
}
