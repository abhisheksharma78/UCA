#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* createNewNode()
{
    struct node* newNode=(struct node*) malloc(sizeof(struct node));
    return newNode;
}
int main()
{
    struct node* head=NULL;
    return 0;
}
