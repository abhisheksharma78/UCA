#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

void inorderTraversal(struct Node* root)
{
    if (root)
    {
        inorderTraversal( root->left );
        cout << root->data << " ";
        inorderTraversal( root->right );
    }
}

struct Node *newNode()
{
    struct Node *nn=(struct Node*)malloc(sizeof(struct Node));
    return nn;
}

struct Node* createTree(Node* root,int data)
{
    Node* nn=newNode();
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    if(root==NULL)
    {
        return nn;
    }
    else{
        queue<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            Node* s=stk.front();
            if(s->left)
            {
                stk.push(s->left);
            }
            else{
                s->left=nn;
                return root;
            }
            if(s->right)
            {
                stk.push(s->right);
            }
            else{
                s->right=nn;
                return root;
            }
        }
    }
}

int main()
{
    struct Node *root=NULL;
    for(int i=0;i<7;i++)
    {
        root=createTree(root,i);
    }
    cout << "Inorder Traversal of the constructed Binary Tree is: \n";
    inorderTraversal(root);
    return 0;
}
