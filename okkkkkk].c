#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;
node* createBinary(node* root, int d)
{
    if( root == NULL)
    {
        node* nn = (node*)malloc(sizeof(node));
        nn->data = d;
        nn->left = NULL;
        nn->right = NULL;
        return nn;
    }
    else if(d < root->data)
    {
        root->left = createBinary(root->left, d);
    }
    else
    {
        root->right = createBinary(root->right,d);
    }
    return root;
}
int checkBST(struct node* node, int min, int max)
{
  if (node==NULL)
     return 1;

  if (node->data < min || node->data > max)
     return 0;

  return (checkBST(node->left, min, node->data-1) && checkBST(node->right, node->data+1, max));
}
int isBST(struct node* node)
{
  return(checkBST(node, INT_MIN, INT_MAX));
}
int main()
{
    int i,n,j,d,t;
    node* root;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&d);
            createBinary(root,d);
        }
        if(isBST(root))
            printf("YES\n");
        else
            printf("NO\n");
        free(root);
        root==NULL;
    }
    return 0;
}
