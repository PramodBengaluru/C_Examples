
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>

int main()
{
int n,i;
int cur_val=0;
int min=0,max=10;
printf("Enter No of elements to compare\n");
scanf("%d",&n);
printf("Enter the elements\n");
for(i=0;i<n;i++)
{
 scanf("%d",&cur_val);
 if(cur_val>max)
     max=cur_val;
 if(cur_val<min)
     min=cur_val;
}
printf("Maximumum among the entered numbers is %d \n",max);
printf("Minimumum among the entered numbers is %d \n",min);
}
