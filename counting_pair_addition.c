
// Complete the numberOfPairs function below.
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
int numberOfPairs(int a_count, int* a, long k)
{
    qsort(a,a_count,sizeof(int),comp);
    int check1=0,check2=0;
    int num,i,count=0;
    for(i=0;i<a_count;i++)
    {
        num=k-a[i];
        if(check2!=num && a[i]!=check1)
        {
            if(binarys(a_count,a,k,num))
            {
                count++;
                check1=num;
                check2=a[i];
            }
        }
    }
    return count;

}

