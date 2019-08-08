
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>
#include <stdlib.h>
#define XCH(a,b) temp=a;a=b;b=temp;

void divide_sort_merge(int *array,int l1);
void merge(int *arr1,int *arr2,int l1,int l2);
int *arr;

int main()
{
int i,n,j,temp;
printf("Enter number of values n followed by values\n");
scanf("%d",&n);
arr=(int *)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
    scanf("%d",arr+i);
}
divide_sort_merge(arr,n);
printf("The sorted list is \n");
for(i=0;i<n;i++)
{
    printf("%d ",*(arr+i));
}
}

/**************************************************************Function for merging 2 sorted arrays and give a 3rd sorted array**********************************/

void merge(int *arr1,int *arr2,int l1,int l2)
// int *merge(int *arr1,int *arr2,int l1,int l2)
{
 int *merged=malloc(sizeof(int)*(l1+l2));    //Temperory array.
 int i=0,j=0;
while((i<l1)&&(j<l2))
{
    if((*(arr1+i)<(*(arr2+j))))
    {
        *(merged+i+j)=*(arr1+i);
        i++;
    }
    else
    {
        *(merged+i+j)=*(arr2+j);
        j++;  
    }   
}
/*************If i<l1 or j<l2**************/
while(i<l1)
{
*(merged+i+j)=*(arr1+i);
i++;    
}
while(j<l2)
{
*(merged+i+j)=*(arr2+j);
j++;    
}    
for(i=0;i<(l1+l2);i++)
{
 *(arr1+i)=*(merged+i);
}
free(merged);
}

/****************************************Function for dividing the array recursively into smaller peices********************************************************/
void divide_sort_merge(int *array,int l1)   //Array pointer, Length of the array
{
    if(l1==1) return;  
    int div2=(l1%2)?(l1/2+1):l1/2;  //If odd send more than half else half.    
 /*Left*/  divide_sort_merge(array,div2);
 /*Right*/ divide_sort_merge(array+div2,l1-div2);
           merge(array,array+div2,div2,l1-div2);    
}
