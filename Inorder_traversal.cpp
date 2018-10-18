#include <iostream>
#include <queue>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
Node* createNode(node* root,int data)
{
    node *nn=neNode();
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    if(root==NULL)
        return nn;
    else{
        queue<node*> stk;
        stk.push(root);
        node* s=stk.front();
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
int main()
{

    return ;
}
