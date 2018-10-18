#include<stdio.h>

int func(int a, int b)
{
    return (b + 2 * a);
}
int main()
{
    int a = 4, b = 2, c = 5;
    a = func(c, b);
    c = func(b, a);
    printf("%d %d %d",a,b,c);
}
