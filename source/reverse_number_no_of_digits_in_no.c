
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>

int main()
{
int num;
int temp=0;
int no_of_digits=0;
int temp2=0;
int dig;
printf("Enter any number upto 10 digits\n");
scanf("%d",&num);

 while(num>temp)
 {
     temp=temp*10+9;
     no_of_digits++;
 }
temp=(temp+1)/10;
printf("Number of digits in the number is %d\n",no_of_digits);
while(no_of_digits>0)
{
 temp2+=((num%10)*temp);
 temp/=10;
 num/=10;
no_of_digits--;
}
printf("Reversed number is %d\n",temp2);
}
