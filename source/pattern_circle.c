
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
    float point_start=0;
    float i,j;
    int radius;
    char charr;
    printf("Enter the character to be used\n");
    scanf("%c",&charr);
    printf("Enter no representing radius\n");
    scanf("%d",&radius);      
    for(i=0;i<=radius/2;i+=0.55)
    {
        point_start=radius-(sqrt(pow(radius,2)-pow(radius-i,2)));
        for(j=0;j<point_start;j+=0.5)          //first half until perpendicular to circle
        {
            printf(" ");
        }
           for(j=point_start;j<2*radius-point_start;j+=0.5)          //2nd half after perpendicular to circle
        {
            printf("%c",charr);
        }
        printf("\n");
    }
        for(i=radius/2;i>0;i-=0.55)
    {
        point_start=radius-(sqrt(pow(radius,2)-pow(radius-i,2)));
        for(j=0;j<point_start;j+=0.5)          //first half until perpendicular to circle
        {
            printf(" ");
        }
           for(j=point_start;j<2*radius-point_start;j+=0.5)          //2nd half after perpendicular to circle
        {
            printf("%c",charr);
        }
        printf("\n");
    }
}




/*                   i=0        * ****           |
 *                      |   *                    |
 *                  i=2 |--*                     |      --=required distance.=val=r-(distance from perpendicular to centre and the point on circle)
 *                      |  | *                    |
 *                      |__|___*___Centre_________|   
 *                           r
 * 
 * 
 * 
 * (r-i)^2+x^2=r^2==> x=sqrt(r^2
 */
