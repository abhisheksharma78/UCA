#include <iostream>
#include <string>
using namespace std;
struct Trie
{
    struct Trie *arr[26];
    bool isEndOfWord;
};
struct Trie *getNode()
{
    struct Trie *nn =  new Trie;
    nn->isEndOfWord = false;
    for (int i = 0; i < 26; i++)
    {
        nn->arr[i] = NULL;
    }
    return nn;
}
void insert(struct Trie *root, string key)
{
    struct Trie *curr = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!curr->arr[index])
        {
            curr->arr[index] = getNode();
        }
        curr = curr->arr[index];
    }
    curr->isEndOfWord = true;
}

bool search(struct Trie *root, string key)
{
    struct Trie *curr = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!curr->arr[index])
        {
            return false;
        }
        curr = curr->arr[index];
    }

    return (curr!= NULL && curr->isEndOfWord);
}
void del(struct Trie *root, string key, int index)
{
    if(index==key.length())
    {

    }
}
int main()
{
    string keys[] = {"the", "a","hell" ,"hello","answer", "any", "by","bye", "their" };
    struct Trie *root = getNode();
    for (int i = 0; i < 8; i++)
    {
        insert(root, keys[i]);
    }
    if(search(root, "hell"))
    {
       cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}
