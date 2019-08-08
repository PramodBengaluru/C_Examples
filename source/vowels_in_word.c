
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>


int main()
{
char word[25],i;
printf("Enter a word\n");
scanf("%s",word);
printf("The vowels in the word are at following positions\n");
for(i=0;word[i]!='\0';i++)
{
 switch(word[i])
 {
     case 'a':
     case 'A':
     case 'e':
     case 'E':         
     case 'I':
     case 'i':
     case 'O':
     case 'o':
     case 'U':
     case 'u':printf("%d ",i+1);
     break;
     default:break;
 }
}
}