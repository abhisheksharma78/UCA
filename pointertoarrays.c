#include<stdio.h>
void func1(int x,int y,int (*arr)[x][y])
{
    int i,j;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("%d\n",*(*(*arr+i)+j));
        }
    }
}
void func2(int x,int y,int (*a)[y])
{
    int i,j;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("%d\n",*(*(*arr+i)+j));
        }
    }
}
void func3(int x,int y,int *arr)
{
    int i,j;
    for(i=0;i<x*y;i++)
    {
            printf("%d\n",*(arr+i));

    }
}
int main()
{
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    func1(3,3,&a);
    func3(3,3,&a);
    return 0;
}
