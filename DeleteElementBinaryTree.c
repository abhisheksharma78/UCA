#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    int data;
    tree* left;
    tree* right;
};
int findMax(tree* root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}
tree* delete(tree* root,int item);
{
    if(root->data==item)
    {
        if(root->left==NULL)
        {
            return root->right;
        }
        else if(root->right==NULL)
        {
            return root->left;
        }
        else
        {
            int x=findMax(root->left);
            root->data=x;
            delete(root->left,root->data);
            return root;
        }
    }
}
int main()
{
    int item;
    scanf("%d",&item);
    tree* root=delete(,item)
}
