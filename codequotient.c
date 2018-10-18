#include <stdio.h>
/* Include other headers as needed */
int main()
{
  int rem,n,sum=0,i;
  scanf("%d",&i);
  int j;
  for(j=0;j<i;j++)
  {
  scanf("%d",&n);
  while(n!=0)
  {
    rem=n%10;
    sum=rem+sum;
    n=n/10;
  }
    printf("%d\n",sum);
    sum=0;
  }
    return 0;
}
