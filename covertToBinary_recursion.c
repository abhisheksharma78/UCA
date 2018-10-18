int decimalToBinary(int n)
{
   if(n==0)
   {return n;}
  if(n&1==1)
  {
    return 1+10*decimalToBinary(n>>1);
  }else{
    return 0+10*decimalToBinary(n>>1);
  }
}
