
/********************************
 * Author : Pramod Bengaluru
 * mail : pramodjb2808@gmail.com
 *
 * Oct 2017
 *******************************/


#include <stdio.h>

int factorial_without_recursion(int n);
int factorial(int n);

int main()
{
int n,r;
int ncr,npr;
printf("Enter n and r\n");
scanf("%d%d",&n,&r);
npr=factorial_without_recursion(n)/factorial_without_recursion(n-r);
ncr=factorial(n)/(factorial(n-r)*factorial(r));
printf("%dP%d is equal to %d\n",n,r,npr);
printf("%dC%d is equal to %d\n",n,r,ncr);
}

int factorial(int n)
{
 if((n==0)||(n==1))
     return 1;
 else return factorial(n-1);    
}

int factorial_without_recursion(int n)
{
    int result=1;
  if((n==0)||(n==1))
     return 1;
  else
  while(n>1)
  {
      result*=n--;
  }
  return result;
}