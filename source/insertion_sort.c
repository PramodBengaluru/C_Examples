
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
int i,boundary,n,j,temp,temp1=0;
int *arr;
printf("Enter number of values n followed by values\n");
scanf("%d",&n);
arr=(int *)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
    scanf("%d",arr+i);
}

//Array start has a list of sorted elements as in selection sort. But instead of searching for smalles element in the unsorted part and putting it to the end of sorted list as in selection sort, we take the next element after sorted boundary and put it in corresponding place.


//  for(i=0;i<n-1;i++) //-1 because largest element will already be at end of list after n-1 iteration
//     {
//         temp1=i;    //Start from first position
//      for(j=i+1;j<n;j++)   //i+1 because temp1 initialized to i. Skip comparing with self
//      {
//     if(((*(arr+temp1)))>(*(arr+j))) 
//         {
//             temp1=j;            //Get the smallest element in array.   
//         }
//      }
//      XCH(*(arr+temp1),*(arr+i));    //Place it into the end of sorted part.
//     }
//     
    

for(boundary=0;boundary<n;boundary++)
{
temp1=*(boundary+arr);
for(j=0;j<boundary;j++)
{
    if(*(arr+j)>temp1)
    {
        XCH(temp1,*(arr+j));
    }   
}
XCH(temp1,*(boundary+arr));
}

printf("The sorted list is \n");
for(i=0;i<n;i++)
{
    printf("%d ",*(arr+i));
}
}


