#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isPrime(int num)
{
  int i,flag=0;
  for(i=2;i<=sqrt(num);i++)
  {
    if(num%i==0)
    {flag=1;}
  }
  return ((flag)?0:1);
}
int printPrimeFactors(int num)
{
  int i;
    for(i=2; i <= (num); i++)
    {
        if(num%i ==0)
        {
          printf("%d\n",i);
          printPrimeFactors(num/i);
          break;
        }
    }
}
int main()
{
   int no;
   scanf("%d",&no);
  if(!isPrime(no))
  {
    printPrimeFactors(no);
  }
  else
  {
    printf("%d",no);
  }
   return 0;
}
