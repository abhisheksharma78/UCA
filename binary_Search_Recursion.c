#include <stdio.h>
#include <stdlib.h>
int Binary(int l, int r, int* a, int num)
{
    if(l >= r)
    {
        return l;
    }
    else
    {
        int mid = (l + r)/2;
        if(num == a[mid])
        {
            return mid;
        }
        if(num > a[mid])
        {
            Binary(mid, r, a, num);
        }
        if(num < a[mid])
        {
            Binary(l, mid, a, num);
        }
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int l = 0, r = 11, num = 4;
    int res = Binary(l, r, a, num);
    printf("%d", res);
    return 0;
}
