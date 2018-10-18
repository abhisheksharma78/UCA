#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
using namespace std;
void print(struct node* nn,int n );
void postorder(struct node* root);
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int disp;
};
struct node *newnode()
{
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    return nn;

};
struct node* create_tree(node *root,int data)
{
    struct node *nn=newnode();
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    if(root==NULL)
    {
        return nn;
    }
    else
    {
        queue<node*>stk;
        stk.push(root);
        while(!stk.empty())
        {

            struct node *s=stk.front();
            stk.pop();
            if(s->left)
                stk.push(s->left);
            else
            {
                s->left=nn;
                return root;

            }
            if(s->right)
                stk.push(s->right);
            else
            {
                s->right=nn;
                return root;

            }
        }
}
}

int main()
{
    struct node* root=NULL;
    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
    {

        root=create_tree(root,i);
    }
    print(root,i);
    cout<<"\n";
    cout<<"postorder traversal   ";



}
void print(struct node* nn,int n )
{
    queue<struct node*>q;
    q.push(nn);
    while(!q.empty())
    {
        struct node* s=q.front();
        cout<<s->data<<"  ";
        q.pop();
        if(s->left)
            q.push(s->left);
        if(s->right)
            q.push(s->right);
    }


}
void postorder(struct node* root)
{

    stack<struct node*>stk;
    do
    {
        if(root)
        {
            stk.push(root);
            root=root->left;
        }
        else
        {
            if(stk.top()->right==NULL)
            {
                cout<<stk.top()->data<<"  ";
                root=stk.top();
                stk.pop();
                while(!stk.empty()&&stk.top()->right==root)
                {

                    root=stk.top();
                    stk.pop();
                    cout<<root->data<<"  ";

                }

          }
          root=stk.top()->right;
        }
    }while(!stk.empty());
}
