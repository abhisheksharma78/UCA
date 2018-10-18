#include<stdio.h>
#include<stdlib.h>
int comp(const void *a,const void*b)
{
    return  *((int*)a)-*((int*)b);
}
int main()
{
    int arr[6]={5,3,4,1,2,6};
    qsort(arr,6,sizeof(int),comp);
    int i;
    for(i=0;i<6;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
