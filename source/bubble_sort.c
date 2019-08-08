
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>
#include <stdlib.h>
#define XCH(a,b) temp=a;a=b;b=temp;

int main()
{
int i,n,j,temp;
int *arr;
printf("Enter number of values n followed by values\n");
scanf("%d",&n);
arr=(int *)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
    scanf("%d",arr+i);
}

for(i=0;i<n-1;i++)
{
for(j=1;j<n-i;j++)
{

 if(*(arr+j-1)>*(arr+j)) {
  XCH(*(arr+j),*(arr+j-1));
 }    
}
}

printf("The sorted list is \n");
for(i=0;i<n;i++)
{
    printf("%d ",*(arr+i));
}



}