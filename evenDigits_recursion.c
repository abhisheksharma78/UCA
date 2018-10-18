int evenDigits(int n)
{
  if(n==0)
  {return n;}
  if((n%10)%2==0)
  {
    return (n%10)+10*evenDigits(n/10);
  }
  else
  {
    evenDigits(n/10);
  }
}

