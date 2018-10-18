#include <stdio.h>
#include "extern_age.c"
int main()
{
    extern int age;
    fun(age);
    return 0;
}
