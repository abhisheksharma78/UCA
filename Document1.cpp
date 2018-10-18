#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct trie_tree
{
  int eow;
  struct trie_tree *arr[26];
}trie;
int search(trie* root,char str[],int index)
{
    if(index==strlen(str))
    {
        if(root->eow)
            return 1;
        return 0;
    }
    int i=str[index]-'a';
    trie* node=root->arr[i];
    if(node==NULL)
        return 0;
    return search(node,str,index+1);
}
trie* createNode()
{
    trie* nn=(trie*)malloc(sizeof(trie));
    int i;
    for(i=0;i<26;i++)
    {
        nn->arr[i]=NULL;
    }
    nn->eow=0;
    return nn;
}

void insert(trie* curr,char str[])
{
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(curr->arr[str[i]-'a'])
            curr=curr->arr[str[i]-'a'];
        else
        {
            trie* nn=createNode();
            curr->arr[str[i]-'a']=nn;
            curr=nn;
        }
        curr->eow=1;
    }
    printf("%s inserted\n",str);
}
int delete(trie* root,char str[],int index)
{

    if(index==strlen(str))
    {
        if(!root->eow)
            return 0;
        root->eow=0;
        int i;
        for(i=0;i<26;i++)
        {
            if(root->arr[i])
                return 0;
        }
        return 1;
    }
    int i=str[index]-'a';
    if(root->arr[i]==NULL)
       return 0;
    trie* node = root->arr[i];
    int val=delete(node,str,index+1);
    if(val==1)
        {
            trie* temp=root->arr[i];
            root->arr[i]=NULL;
            free(temp);temp=NULL;
            if(root->eow)
                return 0;
            else
            {
                for(i=0;i<26;i++)
                {
                    if(root->arr[i])
                    return 0;
                }
                return 1;
            }
        }
}
int main()
{
    trie* root=NULL;
    char a[][6]={"the","world","is","about","to","end"};
    root=createNode();
    int i;
    for(i=0;i<6;i++)
        insert(root,a[i]);
    int index=0;
    delete(root,"end",index);
    int b=search(root,"end",index);
    printf("%d",b);

}
