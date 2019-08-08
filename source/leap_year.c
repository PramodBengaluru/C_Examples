
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>

//Nested if else
int main()
{
unsigned int a;
printf("Enter a year\n");
scanf("%d",&a);
if(!(a%4))
{
if(!(a%100))
{
if(!(a%400))
{
printf("%u is a leap year\n",a);
}
else
{
printf("%u is not a leap year\n",a);
}
}
else {
printf("%u is a leap year\n",a);
}
}
else
{
printf("%u is not a leap year\n",a);
}
}
