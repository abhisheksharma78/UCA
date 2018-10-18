#include<stdio.h>
int main()
{
    double x=5.5;
    int i;
    unsigned char *ch=(unsigned char*)(&x);
    for(i=0;i<16;i++)
    {
        printf("%d\n",*(ch+i));
    }
    return 0;
}
