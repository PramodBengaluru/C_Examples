
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
    char quer;
int i,n,j,temp,temp1;
int *arr;
printf("Enter number of values n followed by values\n");
scanf("%d",&n);
arr=(int *)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
    scanf("%d",arr+i);
}

while(1)
{
printf("Enter the postion of the element to insert/delete\n");
scanf("%d",&i);
printf("Enter the operation to perform\n");
printf("1.Add 2.Delete\n");
scanf("%d",&j);

if(j==1)
{
printf("Enter the element to add\n");
scanf("%d",&temp1);
    n=n+1;
   arr=realloc(arr,(sizeof(int)*n));   
    XCH(temp1,*(arr+i));
for(j=i+1;j<n;j++)
{
 XCH(temp1,*(arr+j));
}
}
else if(j==2)
{
//XCH(temp1,*(arr+i);
for(j=i;j<n;j++)
{
 XCH(*(arr+j),*(arr+j+1));
}
n=n-1;
//arr=realloc(arr,(sizeof(int)*n));
}
else
{
    printf("Incorrect option\n");
    break;
}

printf("The modified list is \n");
for(i=0;i<n;i++)
{
    printf("%d ",*(arr+i));
}

printf("\n Do you want to do another operation?Y/N \n");
scanf("%c",&quer);
scanf("%c",&quer);
if((quer!='Y')&&(quer!='y')) exit(-1);
}



}