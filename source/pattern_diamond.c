
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>
#include <math.h>

int main()
{
    int side=0;
    int i,j;
    float height;
    char charr;
    printf("Enter the character to be used\n");
    scanf("%c",&charr);                              
    //If the 2 scanfs are interchanged places, the character read scanf is getting skipped.The reason for this is, the scanf does not take the new line that is entered when an integer is input and enter is pressed. The next scanf which is searching for character considers this new lin as char and skips. Suggested is to use fgets and extract from it using scanf. Or interchange the order as done here.
    printf("Enter the side length in no of characters\n");
    scanf("%d",&side);    
    height=2*sqrt(side*side/2);
    for(j=0;j<height/2;j++)
    {
    for(i=0;i<=((height/2)-j);i++)
    {
        printf("  ");
    }
    for(i=((height/2)-j);i<=((height/2)+j);i++)
    {
        printf("%c ",charr);
    }
    printf("\n");
}

  for(i=((height/2)-j);i<=((height/2)+j+1);i++)
    {
        printf("%c ",charr);
    }
    
 printf("\n");

    for(j=height/2;j>=0;j--)
    {
    for(i=0;i<=((height/2)-j);i++)
    {
        printf("  ");
    }
    for(i=((height/2)-j);i<=((height/2)+j);i++)
    {
        printf("%c ",charr);
    }
    printf("\n");
}
}
