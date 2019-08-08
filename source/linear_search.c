
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>
#include <stdlib.h>

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

printf("Enter the element to search\n");
    scanf("%d",&temp);

for(i=0;i<n;i++)
{
if(*(arr+i)==temp)
{
    printf("%d was found at location %d \n",temp,i);
    exit(-1);
}
}
printf("%d was not found in the list \n",temp);
}