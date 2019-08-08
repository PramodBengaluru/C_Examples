
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>

int main()
{
int no_of_lines=0,current_line=0,i=0,val=1;
    printf("Enter the number of lines\n");
    scanf("%d",&no_of_lines);
    
while(current_line<=no_of_lines)
{
    for(i=0;i<current_line;i++,val++)
        printf("%d ",val);
    printf("\n");
    current_line++;
    }
}