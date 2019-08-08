
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>

int main()
{
int a,b,*ptra,*ptrb;
ptra=&a;
ptrb=&b;
printf("Enter any 2 numbers, a and b\n");
scanf("%d%d",&a,&b);
printf("a + b = %d\n",*ptra+*ptrb);
printf("a - b = %d\n",*ptra-*ptrb);
printf("a * b = %d\n",*ptra**ptrb);
printf("a / b = %f\n",(float)(*ptra)/(*ptrb));  //USe brackets because /* is comment start
}
