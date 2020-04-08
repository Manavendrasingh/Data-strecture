#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
node*create(int inorder[],int preorder[],int start,int end)
{
    static int fist = start;
    if(start > end)
        return NULL;
    node* root = newnode(preorder[fist]);
    (fist)--;
    if(start == end)
        return root;

    int index = insearch(inorder,start,end,root->data);
    root->lchild = create(inorder,preorder,start,index-1);
    root->rchild = create(inorder,preorder,index+1,end);
    return root;

}
void inordert(node*p)
{
    if(p)
    {
        inordert(p->lchild);
        cout<<p->data<<" ";
        inordert(p->rchild);
    }
}
int main()
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
    int fist  = n-1;
    root = create(inorder,preorder,0,n-1);
    inordert(root);
}

