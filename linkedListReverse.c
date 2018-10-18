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
void addAtLast(struct node** h,int n)
{
    if(*h==NULL)
    {
        addAtBeginning(h,n);
    }
    else
    {
        struct node *nn=createNewNode();
        nn->data=n;
        nn->next=NULL;
        struct node* currentNode=*h;
        while(currentNode->next)
        {
            currentNode=currentNode->next;
        }
        currentNode->next=nn;
    }
}
int main()
{
    struct node* head=NULL;
    int i,n,d;
    printf("Enter no of Elements: \n");
    scanf("%d",&n);
    printf("Enter Values of Elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&d);
        addAtLast(&head,d);
    }
    printf("%d\n",&head);
    while(head!=NULL)
    {
        printf("%d ",head->data);
        printf("| %d \n",head->next);
        head=head->next;
    }
    // Enter Function here //
    struct node* head=NULL;
    while(head!=NULL)
    {
        printf("%d ",head->data);
        printf("| %d \n",head->next);
        head=head->next;
    }
    return 0;
}
