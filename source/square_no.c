
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>


int main()
{
    unsigned N,num=0,i=1,flag=0;
    printf("Enter until what number squares should be generated\n");
    scanf("%u",&N);
    printf("The squares are ");
    while(num<N)
    {
        num=i++*(i-1);  //  (i-1)*i++ doesnt work. It gives i-1*i but we need i*i. This is because multiplication evaluates from left unlike printf
        printf("%u ",num);
    }
    printf("\n");
}