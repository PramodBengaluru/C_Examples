
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>
#define MAX 40

/*
 1 of the Algo for LCM.
 Take the largest elemnt
 Divide it by each of the smaller element. If divisible it is the LCM
 else take next multiple of largest element and try to divide by lower numbers, i.e if it is a multiple of number.repeat
 */

int hcf(int a,int b);

int main()
{
int i,n,GCD,LCM;
int values[MAX];
printf("Enter number of values n upto %d followed by values\n",MAX);
scanf("%d",&n);
for(i=0;i<n;i++)
{
    scanf("%d",&values[i]);
}
GCD=values[0];
LCM=values[0];
for(i=1;i<n;i++)
{    
    GCD=hcf(GCD,values[i]);
    LCM=(LCM*values[i])/hcf(LCM,values[i]);
}
printf("The GCD of inputted numbers is %d\n",GCD);
printf("The LCM of given numbers is %d\n",LCM);
}



int hcf(int a,int b)
{
int divsr,divdnd,temp;
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
return divsr;
}
