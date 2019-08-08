
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>
#include <math.h>
#define VERTICAL 1

int tower_of_hanoi(int discs,char *start,char *temp,char *dest);
void print_pole_contents(void);

int n;
char i,first[50],second[50],third[50];
int main()
{

first[0]='S';   //For identifying the  Poles
second[0]='T';
third[0]='D';

first[1]=0;   //For the number of disks currently in the pole.
second[1]=0;
third[1]=0;
printf("Enter number of discs to move\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
   first[i+2]=n-i;
}
first[1]=n;
printf("Src\t\tTemp\t\tDest\n");
printf("Moves taken for Completion=%d\n",tower_of_hanoi(n,first,second,third));
printf("Minimum moves required is 2^n-1=%d\n",(int)pow(2,n)-1);
}

int tower_of_hanoi(int discs,char *start,char *temp,char *dest)
{
    static int moves=0;

if(discs==1)
{
dest[1]++;
dest[dest[1]+1]=start[start[1]+1];
start[start[1]+1]=0;
start[1]--;
printf("-----------------------------------------Disk %d moved from %c to %c-------------\n",dest[dest[1]+1],start[0],dest[0]);
moves++;
print_pole_contents();
}
else 
{    
    tower_of_hanoi(discs-1,start,dest,temp);
    tower_of_hanoi(1,start,temp,dest);
    tower_of_hanoi(discs-1,temp,start,dest);
}
return moves;
}

#if VERTICAL
void print_pole_contents(void)
{
printf("Src = ");
for(i=2;(i<n+2)&&(first[i]!=0);i++)
{
   printf("%d ",first[i]);
}
printf("\ntemp = ");
for(i=2;(i<n+2)&&(second[i]!=0);i++)
{
  printf("%d",second[i]);
}
printf("\nDest = ");
for(i=2;(i<n+2)&&(third[i]!=0);i++)
{
 printf("%d ",third[i]);
}    
 printf("\n");
}

#else

void print_pole_contents(void)
{
for(i=n+1;(i>1);i--)
{
   first[i]?(printf("%d\t\t",first[i])):(printf("\t\t")); 
   second[i]?(printf("%d\t\t",second[i])):(printf("\t\t")); 
   third[i]?(printf("%d\n",third[i])):(printf("\n"));     
}
}
#endif