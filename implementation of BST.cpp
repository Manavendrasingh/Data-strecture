#include<iostream>
//#include<bits/stdc++.h>
#include<queue>
using namespace std;
int n;
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
  struct stack//stack start from here
     {
         int size;
         int top;
         node** s;

     };//stack end
void traversalmin(node* root)
{
    if(root)
    {
        traversalmin(root->lchild);
        if(root->data < n)
        {

            n = root->data;
        }
        traversalmin(root->rchild);
    }

}
void printOddNodes(node *root)
{
    // Code here
    if(root == NULL) return;
    queue<node*>q;
    q.push(root);
    int size,c =1;
    while(!q.empty())
    {
        size  = q.size();
        while(size--)
        {
            node*p = q.front();
            q.pop();
            if(c%2 !=0) cout<<p->data<<" ";
            if(root->lchild) q.push(root->lchild);
            if(root->rchild) q.push(root->rchild);
           // size--;
        }
        cout<<"hi"<<endl;
        c++;
    }
}

node* insert(node *root,int ele)
{

    struct node *p,*r,*t;
    p = new node;
    p->rchild = NULL;
    p->lchild = NULL;
    p->data  = ele;
    t = root;
    if(root == NULL)
    {
        root = p;
        return root;
    }
    else
    {
      while(t)
      {
               if(ele == t->data)
               {
                   cout<<"element is already present in BST"<<endl;
                   return root;
               }
                if(ele < t->data)
               {
                   r = t;
                   t = t->lchild;
               }
               else
               {
                   r = t;
                   t = t->rchild;
               }
       }
       if(r->data>ele)
       {
           r->lchild = p;
       }
       else
       {
           r->rchild = p;
       }
      return root;
    }


}
node* create(node *root,int a[],int n)
{
     struct node*t,*s;
     for(int i=0;i<n;i++)
     {

        s = root;
        struct node*p;
        p = new node;
        p->data = a[i];
        p->lchild  = NULL;
        p->rchild = NULL;
        if(root == NULL){root = p;}
        while(s)
        {
            t = s;
           // if(p->data == s->data){return NULL;}
             if(s->data < p->data){s = s->rchild;}
             if(s->data > p->data){s = s->lchild;}
        }
        if(t->data > p->data){t->lchild = p;}
        else{t->rchild = p;}
    }
    return root;

}
node* search(node *p,int key)
{

    //RECUSIVE FUNCTION
    if(p==NULL){return NULL;}
    else
    {
       if(p->data == key){ return p;}
       else if(p->data > key){return search(p->lchild,key);}
       else if(p->data < key){return search(p->rchild,key);}
        //return NULL;
    }
   /* struct node *p;//ITREATIVE FUNCTION
    p  =root;
    if(p==NULL){cout<<"BST IS NOT FOUND"<<endl;}
    while(p)
    {
        if(p->data == key){ return p;}
        else if(p->data > key){p = p->lchild;}
        else if(p->data < key){p = p->rchild;}
    }
    return NULL;*/


}
int height(node *p)
{
      int x,y;
      if(p == NULL){return 0;}
      else
      {
          x = height(p->lchild);
          y = height(p->rchild);
          if(x>y){return x+y+1;}
          else{return x+y;}
      }
}
struct node* inpre(node *p)
{
    while(p->rchild)
    {
        p=p->rchild;
    }
    return p;
}
struct node* insucc(node *p)
{
    while(p->lchild)
    {
        p=p->lchild;
    }
    return p;
}s
node *delete_node(node *p,int key)
{
    if(p == NULL){return NULL;}
    if(p->lchild == NULL && p->rchild == NULL && p->data == key  )
    {
        p = NULL;
        delete p;
        return NULL;
    }
    if(key<p->data){p->lchild = delete_node(p->lchild,key);}
    else if(key>p->data){p->rchild = delete_node(p->rchild,key);}
    else
    {
        struct node *q;
         if(height(p->lchild)>height(p->rchild))
         {
             q = inpre(p->lchild);
             p->data = q->data;
             p->lchild = delete_node(p->lchild,q->data);
         }
         else
         {
             q = insucc(p->rchild);
             p->data = q->data;
             p->rchild = delete_node(p->rchild,q->data);
         }
    }
}

void inorder(node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }


}
void preorder(node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }

}
void postorder(node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }


}
void push(struct stack *st,node* data)
{
    if(st->top == st->size-1)
    {
        cout<<"stack is full"<<endl;
    }
    else
    {
        st->top++;
        st->s[st->top] = data;
    }
}
node*  pop(struct stack *st)
{
    node* x;
    if(st->top == -1)
    {
        cout<<"stack is underflow"<<endl;
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}
node* stacktop(struct stack st)
{
    struct node *m;
    m = new node;
    m->data = 32678;
    m->lchild = NULL;
    m->rchild = NULL;
    //cout<<m->data<<endl;
    return st.top!=-1?st.s[st.top]:m;
}
node* pre_create(int pre[],int n)
{
     struct stack st;
     st.size = n;
     st.s = new node* [st.size];
     st.top = -1;
     int i=0;
    //coding of pre_create function
     struct node *root,*p;
     root  = new node;
     root->data = pre[i++];
     root->rchild = NULL;
     root->lchild = NULL;
     p = root;
     //push(&st,p);
     while(i < n)
     {
         if(pre[i] < p->data)
         {
             struct node *t;
             t = new node;
             t->data = pre[i++];
             t->lchild = NULL;
             t->rchild = NULL;
             p->lchild = t;
             push(&st,p);
             p = t;
         }
        if(pre[i] > p->data)
         {
             if(p->data < pre[i] && pre[i] < stacktop(st)->data)
             {
                 struct node *t;
                 t = new node;
                 t->data = pre[i++];
                 t->lchild = NULL;
                 t->rchild = NULL;
                 p->rchild = t;
                 p = t;
             }
             else
             {
                 p = pop(&st);
             }

          }
     }
     return root;

}
node* post_create(int post[],int start,int e)
{
    if(start>e){return NULL;}
    struct node *root;
    int i;
    root = new node;
    root->data = post[e];
    root->lchild = NULL;
    root->rchild = NULL;
    for(i=e;i>=start;i--)
    {
        if(post[i]<root->data){break;}
    }
    root->rchild = post_create(post,i+1,e-1);
    root->lchild = post_create(post,start,i);
    return root;
}

void levelOrder(node* root)
{
  //Your code here

    queue<node*> q;
    if(root)
    {
            cout<<root->data<<" ";
            q.push(root);
    }
    while(!q.empty())
    {
       struct node* p = q.front();
        q.pop();
        if(p->lchild)
        {
            cout<<p->lchild->data<<" ";
            q.push(p->lchild);
        }
        if(p->rchild)
        {
            cout<<p->rchild->data<<" ";
            q.push(p->rchild);
        }

    }
}
int main()
{
    int ch = 1;
    struct node *root = NULL;
    cout<<"enter 1 for insert in binary search tree"<<endl;
    cout<<"enter 2 for inorder "<<endl;
    cout<<"enter 3 for preorder"<<endl;
    cout<<"enter 4 for postorder"<<endl;
    cout<<"enter 5 for searching of key element in BST"<<endl;
    cout<<"enter 6 for create BST"<<endl;
    cout<<"enter 7 for create tree by  preorder"<<endl;
    cout<<"enter 8 for level traversal"<<endl;
    cout<<"enter 9 for create tree by preorder"<<endl;
    cout<<"enter 10 for create tree by postorder "<<endl;
    /*cout<<"enter 11 for for counting the node of tree"<<endl;
    cout<<"enter 12 for insert the node into bst"<<endl;*/
  while(ch)
    {
        cout<<"enter the choice"<<endl;
        cin>>ch;
        if(ch ==1)
        {
                int data;
                cout<<"enter the data"<<endl;
                cin>>data;
                root = insert(root,data);
        }
        else if(ch == 2)
        {
                inorder(root);
                cout<<endl;
        }
        else if(ch==3)
        {
                preorder(root);
                cout<<endl;
        }
        else if(ch ==4)
        {
                postorder(root);
                cout<<endl;
        }
        else if(ch == 5)
        {
                int key;
                struct node *p;
                cout<<"enter the key element"<<endl;
                cin>>key;
                p = search(root,key);
                if(p == NULL){cout<<"key is not found"<<endl;}
                else{cout<<"key"<<p->data<<" is found"<<endl;}
        }
        else if(ch == 6)
        {
                int size;
                struct node *p;
                cout<<"ente the size of data"<<endl;
                cin>>size;
                int a[size];
                cout<<"enter the data"<<endl;
                for(int i=0;i<size;i++)
                {
                    cin>>a[i];
                }
                 p = create(root,a,size);
                 if(p == NULL)
                 {
                     cout<<"element is already present in BST"<<endl;
                 }
                 else
                 {
                     cout<<"BST is created successfully"<<endl;
                     root = p;
                 }
        }
        else if(ch == 7)
        {
                int key;
                cout<<"enter the key element for which is going to delete"<<endl;
                cin>>key;
                root = delete_node(root,key);

        }
        else if(ch ==8)
        {

            levelOrder(root);
            cout<<endl;

        }
        else if(ch == 9)
        {
                int key;
                cout<<"enter the no of element in preorder"<<endl;
                cin>>key;
                int a[key];
                cout<<"enter the data"<<endl;
                for(int i=0;i<key;i++)
                {
                    cin>>a[i];
                }
                root = pre_create(a,key);
        }
        else if(ch == 10)
        {
                /*int key;
                cout<<"enter the no of element in postorder"<<endl;
                cin>>key;
                int a[key];
                cout<<"enter the data"<<endl;
                for(int i=0;i<key;i++)
                {
                    cin>>a[i];
                }
                root = post_create(a,0,key-1);*/
                n = INT_MAX;
                traversalmin(root);
                cout<<n<<endl;

        }

    }
}

