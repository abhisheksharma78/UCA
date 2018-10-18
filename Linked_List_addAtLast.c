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
void addAtBeginning(struct node** h,int data)
{
    struct node* nn=createNewNode();
    nn->data=data;
    nn->next=*h;
    *h=nn;
}
int main()
{
    struct node* head=NULL;
    addAtBeginning(&head,10);
    addAtLast();
    return 0;
}
