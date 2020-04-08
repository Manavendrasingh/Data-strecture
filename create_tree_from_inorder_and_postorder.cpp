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
node*create(int inorder[],int postorder[],int start,int end,int* last)
{
    //static int fist = end;
    if(start > end)
        return NULL;
    node* root = newnode(postorder[*last]);
    (*last)--;
    if(start == end)
        return root;

    int index = insearch(inorder,start,end,root->data);
    root->rchild = create(inorder,postorder,index+1,end,last);
    root->lchild = create(inorder,postorder,start,index-1,last);
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
    int postorder[n];
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>postorder[i];
    }
    int last  = n-1;
    root = create(inorder,postorder,0,n-1,&last);
    inordert(root);
}

