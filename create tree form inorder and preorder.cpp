#include<iostream>
#include<bits/stdc++.h>
using namespace std;
static int i;
struct node
{
    node * lchild;
    int data;
    node * rchild;

};
node* newnode(int data)
{
    node *p = new node;
    p->lchild = NULL;
    p->rchild = NULL;
    p->data = data;
    return p;
}
int insearch(int inorder[],int start,int end,int value)
{
    int i = 0;
    for(int i=start;i<=end;i++)
    {
        if(inorder[i] == value)
        {
             return i;

        }
    }


}
node *cr(int inorder[],int preorder[],int start,int end)
{
    static int fist = 0;
    if(start > end)
        return NULL;
    //cout<<fist<<endl;
    node* root = newnode(preorder[i++]);
    (fist)++;
    if(start == end)
        return root;

    int index = insearch(inorder,start,end,root->data);
    root->lchild = cr(inorder,preorder,start,index-1);
    root->rchild = cr(inorder,preorder,index+1,end);
    return root;
}
node*create(int inorder[],int preorder[],int start,int end)
{
   i= 0;
   node *root = cr(inorder,preorder,start,end);
   return root;


}
void inordert(node*p)
{
    if(p)
    {
        inordert(p->lchild);
        inordert(p->rchild);
        cout<<p->data<<" ";
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        struct node* root = NULL;
        int inorder[n];
        int preorder[n];
        for(int i=0;i<n;i++)
        {
            cin>>inorder[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>preorder[i];
        }
        int fist  = 0;
        root = create(inorder,preorder,0,n-1);
        inordert(root);
    }
}
