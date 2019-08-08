
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>

int main()
{
int no_of_lines=0,current_line=0,i=0,j=0,k=0;

int val[70][70];
    printf("Enter the number of lines\n");
    scanf("%d",&no_of_lines);
    val[0][0]=1;
while(current_line<=no_of_lines)
{
   for(k=0;k<(no_of_lines-current_line)/2;k++)
    {
        printf("  ");        
    }
    for(i=0;i<current_line;i++)
    {
        val[current_line][i]=((val[current_line-1][i])?(val[current_line-1][i]):0)+((val[current_line-1][i-1])?(val[current_line-1][i-1]):0);
        printf("%d ",val[current_line][i]);        
    }
    printf("\n");
    current_line++;
    }
}