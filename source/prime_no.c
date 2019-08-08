
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>


int main()
{
//     unsigned N,num=2,i=0,flag=0;
    unsigned N,num=3,i=0,flag=0;
    printf("Enter until what number primes should be generated\n");
    scanf("%u",&N);
//       printf("The prime numbers are ");
      printf("The prime numbers are 2 ");
    while(num<=N)
    {
        flag=1;
        for(i=2;i<=num/2;i++)
        {
         if(!(num%i))   //if divisible
         {
             flag=0;
             break;
        }   
    }
    if(flag) printf("%u ",num);
//     num+=1;
    num+=2;
}
}
//Check these 2 for upto 2L.
//inc by 1 took 12s
//inc by 2 also took 12s        ??
//For num/2 takes less than 6s
//For num/2 inc by 1 takes 7s