
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


/* Armstrong number or a narcisstic number is the one that can be expressed as sum of its (digits squared to number of total digits) 
 Example is 371 = 3^3+7^3+1^3=371
 */


#include <stdio.h>
#include <math.h>

int main()
{
int num=1;
int max;
int temp=0,i=0;
int no_of_digits=0;
int sum=0;
printf("Enter upto what number armstrong numbers are to be printed\n");
scanf("%d",&max);

printf("The armstrong numbers are ");
while(num<=max)
{
    no_of_digits=0;i=0;
    temp=0;sum=0;
while(num>temp)
 {
     temp=temp*10+9;
     no_of_digits++;
 }
 
temp=num;
 
 while(i++<no_of_digits)
 {
     sum=sum+pow(temp%10,no_of_digits);
     temp/=10;
 }
 
 if(sum==num)
 {
  printf("%d ",num);
 }
 num++;
}
}




