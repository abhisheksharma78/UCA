#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
void main()
{
    struct timeval start,end;
    struct timezone tzp;
    int a[16000];
    int i,j,n;
    n=16000;
    for(i=0;i<n;i++)
    {
        j=rand();
        a[i]=j;
    }
    int temp;
    gettimeofday(&start,&tzp);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    gettimeofday(&end,&tzp);
    int timetaken;
    timetaken=end.tv_usec-start.tv_usec;
    printf("%d\n",timetaken);

    struct timeval start1,end1;
    struct timezone tzp1;
    int b[32000];
    n=32000;
    for(i=0;i<n;i++)
    {
        j=rand();
        b[i]=j;
    }
    gettimeofday(&start1,&tzp1);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(b[j]<b[i])
            {
                temp=b[j];
                b[j]=b[i];
                b[i]=temp;
            }
        }
    }
    gettimeofday(&end1,&tzp);
    int timetaken1;
    timetaken=end1.tv_usec-start1.tv_usec;
    printf("%d\n",timetaken1);
    printf("%d",timetaken/timetaken1);
}
