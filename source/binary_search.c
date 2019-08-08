
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
int i,n,j,temp,mid,k;
int *arr;
char quer;
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
printf("\n");

while(1)
{
printf("Enter the element to search\n");
scanf("%d",&temp);
i=0;j=n;mid=(j-i)/2;

while(1)
{
mid=i+(j-i)/2;
 if(temp>*(arr+mid))
 {
  i=mid;
 } else if(temp<*(arr+mid))
 {
     j=mid;  
 }
 else if(temp==*(arr+mid))
 {
     printf("%d found at %d \n",temp,mid);
     break;
 }
 if((mid==0)||(mid==n-1))
 {
     printf("%d not found in the list \n",temp);
     break;
 }
}
printf("Do you want to search for different element?Y/N\n");
scanf("%c",&quer);  //
scanf("%c",&quer);
if((quer=='n')||(quer=='N'))
exit(-1);
}
}