#include<stdio.h>
int main()
{
    int lengths[] = {5, 4, 4, 2, 2, 8};
    int lengths_size=6;
 int i,j=0,count=0,min;
  int *arr=(int *)malloc(lengths_size*sizeof(int));
  while(1)
  {
    for(i=0;i<lengths_size;i++)
    {
      if(lengths[i]<min && lengths[i]!=0)
      {
        min=lengths[i];
      }
    }
    for(i=0;i<lengths_size;i++)
    {
      if(lengths[i]!=0)
      {
        count++;
      }
    }
    if(count==0)
    {
      break;
    }
    else
    {
      arr[j]=count;
      j++;
    }
    count=0;
    for(i=0;i<lengths_size;i++)
    {
      if(lengths[i]!=0)
      {
        lengths[i]=lengths[i]-min;
      }
    }
  }
  for(i=0;i<j;i++)
  {
      printf("%d\n",arr[i]);
  }
}
