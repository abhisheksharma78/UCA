#include<stdio.h>
int main()
{
    int i,num,flag=0;
    num=35;
    int a,j;
    j=num/4;
    for(i=1;i<=j;i++)
    {
        a=num/i;
        if(i==a)
        {
            flag=i;
        }
    }
    printf("%d",flag);
    return 0;
}
