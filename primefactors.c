void primeFactors(int n)
{
  int i,new=n,flag=0;
  for(i=2;i<=n/2;)
  {
    if(new%i==0)
    {
      flag++;
      new=new/i;
      printf("%d\n",i);
    }
    else
    {
      i++;
    }
  }
  if(flag==0)
  {
    printf("%d",n);
  }
}
