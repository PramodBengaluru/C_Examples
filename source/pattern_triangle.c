
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
    int height;
    char charr;
    printf("Enter the character to be used\n");
    scanf("%c",&charr);
    printf("Enter the height in number of lines\n");
    scanf("%d",&height);        
    for(j=0;j<height;j++)
    {
    for(i=0;i<=(height-j);i++)
    {
        printf("  ");
    }
    for(i=(height)-j;i<=(height)+j;i++)
    {
        printf("%c ",charr);
    }
    printf("\n");
}
}
