
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>

int main()
{
    int side=0;
    int i,j;
    char charr;
    printf("Enter the character to be used\n");
    scanf("%c",&charr);                              
    printf("Enter the side length in no of characters\n");
    scanf("%d",&side);    
    for(j=0;j<=side;j++)
    {
    for(i=0;i<=(side*0.5);i++)
    {
        printf(" ");
    }
    for(i=(side*0.5);i<=(side+(side*0.5));i++)
    {
        printf(" %c",charr);
    }
    printf("\n");
}
}
