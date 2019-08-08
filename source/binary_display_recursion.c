
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/



#include <stdio.h>

void print_in_reverse(int a);

int main()
{
int a;
printf("Enter any number\n");
scanf("%d",&a);
printf("The number %d in binary is ",a);
print_in_reverse(a);
printf("\n");
}

void print_in_reverse(int a)
{
 if(a==0)
     return;
 else print_in_reverse(a/2);
 printf("%c",(a%2)+0x30);    
}
