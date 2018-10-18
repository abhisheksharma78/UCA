#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
node* newnode()
{
    node* nn=(node*)malloc(sizeof(node));
    nn->next=NULL;
    return nn;
}
void addatbeginning(node** head,int d)
{
    node* nn=newnode();
    nn->data=d;
    nn->next=*head;
    *head=nn;
}
void addatend(node** head,int d)
{
    if(*head==NULL)
    {
        addatbeginning(head,d);
    }
    else
    {
        node* nn=newnode();
        nn->data=d;
        nn->next=NULL;
        node* curr=*head;
        while(curr->next)
        {
            curr=curr->next;
        }
        curr->next=nn;
    }
}
void insert(node** head,int d)
{
    node* prev,*curr;
    prev=curr=*head;
    curr=curr->next;
    while(curr)
    {
        if(d>(prev->data)&&d<(curr->data))
        {
            node* nn=newnode();
            nn->data=d;
            prev->next=nn;
            nn->next=curr;
        }
        prev=prev->next;
        curr=curr->next;
    }
}
void delete(node** head,int d)
{
    node* prev,*curr;

}
int main()
{
    node* head=NULL;
    int d=7;
    addatend(&head,d);
    addatend(&head,9);
    d=8;
    insert(&head,d);
    addatend(&head,10);
    addatend(&head,11);
    node* head2=head;
    while(head2!=NULL)
    {
        printf("%d\n",head2->data);
        head2=head2->next;
    }
    delete(&head,d);
    head2=head;
    while(head2!=NULL)
    {
        printf("%d\n",head2->data);
        head2=head2->next;
    }
    return 0;
}
