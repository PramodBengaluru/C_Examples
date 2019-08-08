
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>

int main()
{
int sum=0,val,i,n;
printf("Enter number of values n followed by values\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    scanf("%d",&val);
    sum+=val;
}
printf("The average of numbers is %f\n",(float)sum/n);
}