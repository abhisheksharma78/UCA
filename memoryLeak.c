#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[5] ={1,2,3,4,5};
    int i;
    for(i = 1; i < 4; i++)
    {
        a[i]=(a[i-1])–(a[i])+(a[i+1]);
    }
    for(i = 0; i < =4; i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}
