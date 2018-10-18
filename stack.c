#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int *arr;
    int top;
};
struct stack* initialize(int x)
{
    struct stack* mem=(struct stack*)malloc(sizeof(struct stack));
    mem->top=-1;
    mem->arr=(int*)malloc(x*4);
    return mem;
}
int isEmpty(struct stack* mem)
{
    if(mem->top==-1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct stack* mem,int x)
{
    if(mem->top==x)
    {
        return 1;
    }
    return 0;
}
void insert(struct stack* mem,int data,int x)
{
    if(isFull(mem,x))
    {
        printf("Stack is Full");
    }
    else
    {
        mem->top=mem->top+1;
        mem->arr[mem->top]=data;
    }
}
void stack()
{
    struct stack* mem;
    int x;
    scanf("%d",&x);
    mem=initialize(x);
    int data;
    int i=0;
    for(i=0;i<x;i++)
    {
        scanf("%d",&data);
        insert(mem,data,x);
    }
    for(i=0;i<=mem->top;i++)
    {
        printf("%d",mem->arr[i]);
    }
}
int main()
{
    stack();

    return 0;
}

