#include<stdio.h>
#include<stdlib.h>
struct node* right_rotate(struct node* root);
struct node* left_rotate(struct node* root);
struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
};
struct node* insert(struct node* root,int data)
{
    if(root==NULL)
    {
        struct node* nn=(struct node*)malloc(sizeof(struct node));
        nn->data=data;
        nn->left=nn->right=NULL;
        nn->height=1;
        return nn;
    }
    if(data<root->data)
        root->left=insert(root->left,data);
    if(data>root->data)
        root->right=insert(root->right,data);
    int balance = heightf(root->left)-heightf(root->right);
    if(balance>1)
    {
        if(heightf(root->left->left)-heightf(root->left->right)>=0)
        {
            return right_rotate(root);
        }
        else
        {
            root->left=left_rotate(root->left);
            return right_rotate(root);
        }
    }
    else if(balance<-1)
    {
        if(heightf(root->right->left)-heightf(root->right->right)>=0)
        {
          root->right=right_rotate(root->right);
            root= left_rotate(root);
        }
        else
        {
            return left_rotate(root);
        }
    }
    else
    {
        root->height=max(heightf(root->left),heightf(root->right))+1;
        return root;
    }
};
struct node* right_rotate(struct node* root)
{
    struct node* y =root->left;
    struct node* temp=y->right;
    y->right=root;
    root->left=temp;
    root->height=max(heightf(root->left),heightf(root->right))+1;
    y->height=max(heightf(y->left),heightf(y->right))+1;
    return y;
};
struct node* left_rotate(struct node* root)
{
    struct node* y =root->right;
    struct node* temp=y->left;
    y->left=root;
    root->right=temp;
    root->height=max(heightf(root->left),heightf(root->right))+1;
    y->height=max(heightf(y->left),heightf(y->right))+1;
    return y;
};
int heightf(struct node* root)
{
    if(root==NULL)
        return 0;
    return max(heightf(root->left),heightf(root->right))+1;
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