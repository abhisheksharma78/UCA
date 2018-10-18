#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
}node;
struct node* rightrotate(node* root)
{
	node* y=root->left;
	node* temp=root->right;
	y->right=root;
	root->left=temp;
	root->height=max(hfun(root->left)-hfun(root->right))+1;
	y->height=max(hfun(y->left)-hfun(y->right))+1;
}
struct node* leftrotate(node* root)
{
	node* y=root->right;
	node* temp=root->left;
	y->left=root;
	root->right=temp;
	root->height=max(hfun(root->left)-hfun(root->right))+1;
	y->height=max(hfun(y->left)-hfun(y->right))+1;
}
struct node* insert(struct node* root,int key)
{
    if(root==NULL)
    {
        struct node* nn=(struct node*)malloc(sizeof(struct node));
        nn->data=key;
        nn->left=nn->right=NULL;
        nn->height=1;
        return nn;
    }
    if(root->data<key)
    {
        root->right=insert(root->right,key);
    }
    if(root->data>key)
    {
        root->right=insert(root->left,key);
    }
    int balance=hfun(root->left)-hfun(root->right)+1;
    if(balance>1)
    {
        if(hfun(root->left->left)-hfun(root->left->right)>=0)
        {
            return rightrotate(root);
        }
        else
        {
            root->left=leftrotate(root->left);
            return rightrotate(root);
        }
    }
    else if(balance<-1)
    {
        if(hfun(root->right->right)-hfun(root->right->left)<=0)
        {
            return leftrotate(root);
        }
        else
        {
            root->right=rightrotate(root->right);
            return rightrotate(root);
        }
    }
    else
    {
        root->height=max(hfun(root->left)-hfun(root->right))+1;
        return root;
    }
}
int hfun(struct node* root)
{
    if(root==NULL)
        return 0;
    return max(hfun(root->left),hfun(root->right))+1;
}
int print(struct node* root)
{

    if(root==NULL)
        return 0;
    else
        print(root->left);
        printf("%d  ",root->data);
        print(root->right);
}
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    struct node* root=NULL;
    int i;
    int n;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        root=insert(root,arr[i]);
    }
    print(root);

}
