/*
 * Complete the function below.
 * Please store the size of the int array to be returned in result_size pointer. For example,
 * int a[3] = {1, 2, 3};
 * *result_size = 3;
 * return a;
 *
 */

int* cutSticks(int lengths_size, int *lengths, int *result_size)
{
 int i,j=0,count=0,min,max=0;
  int *arr=(int *)malloc(lengths_size*sizeof(int));
  while(1)
  {
    for(i=0;i<lengths_size;i++)
    {
      if(lengths[i]<=min && lengths[i]!=0)
      {
        min=lengths[i];
      }
      if(lengths[i]>=max)
      {max=lengths[i];}
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
    min=max;
  }
  *result_size=j;
  return arr;
}

