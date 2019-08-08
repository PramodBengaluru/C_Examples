
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>
#include <errno.h>

void change_case(char *word,char casse); //Pass a U or l.

int main()
{
char Word[30];
int num=0,i=0,nby2;
printf("Enter any Word\n");
scanf("%s",Word);
change_case(Word,'U');
while(*(Word+num)!='\0')
{
 num++;   
}
nby2=(num%2)?(num-1)/2:(num/2)-1;

while(i<=nby2)
{
    if(*(Word+i)!=*(Word+num-i-1))
    break;
    i++;
}

if((i-1)!=nby2){
printf("The Word is not a palindrome \n");
}
else
{
    printf("The Word is a palindrome \n");
}
}


void change_case(char *word,char casse) //Pass a U or l.
{
 int i=0;
 while(*(word+i)!='\0')
 {
    if(casse=='l')
    {
   if((*(word+i)>0x40)&&(*(word+i)<0x5B))
   {
       *(word+i)+=32;
   }
    }
    else if(casse=='U')
    {
        if((*(word+i)>0x60)&&(*(word+i)<0x7B))
   {
       *(word+i)-=32;
   }
    }
     i++;
 }
}


