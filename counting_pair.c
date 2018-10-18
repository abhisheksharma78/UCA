// Complete the countPairs function below.
int comp(void const* a,void const* b)
{
    return *((int*)a)-*((int*)b);
}
int binarys(int n,int *A,int k,int num)
{
    int left=0,right=n-1;
    while(left<right)
    {
        int mid=(left+right)/2;
        if(num==A[mid])
        {
            return 1;
        }
        else if(num>=A[mid])
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    if(A[left]==num)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int countPairs(int numbers_count, int* numbers, int k)
{
    qsort(numbers,numbers_count,sizeof(int),comp);
    int check=0;
    int num,i,count=0;
    for(i=0;i<numbers_count;i++)
    {
        num=k+numbers[i];
        if(check!=num)
        {
            if(binarys(numbers_count,numbers,k,num))
            {
                count++;
                check=num;
            }
        }
    }
    return count;
}
