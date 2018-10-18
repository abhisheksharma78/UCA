#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack <int> s;
    s.push(0);
    int x,n,i;
    x=6;
    int arr[6]={100,60,100,60,75,75},span[6];
    span[0]=1;
    for(i=1;i<x;i++)
    {
        if(arr[i]<=arr[s.top()])
        {
            s.push(i);
            span[i]=s.empty()?(i+1):(i-s.top());
            cout<<endl<<s.top()<<" "<<arr[i];
        }
        else{
            while(!s.empty() && span[s.top()] <= span[i])
            s.pop();
        }
    }
}
