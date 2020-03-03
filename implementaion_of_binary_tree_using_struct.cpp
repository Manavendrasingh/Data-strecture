#include<iostream>
using namespace std;
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
struct node *root;
struct queue
{
    node *data;
    struct queue *next;
};
struct queue *rear= NULL,*front = NULL;
struct stack
{
    node *data;
    struct stack *next;
};
struct stack *top = NULL;
void push(node *data)
{
    struct stack *p;
    p = new stack;
    p->data = data;
    p->next = NULL;
    if(top == NULL)
    {
        top = p;
    }
    else
    {
        p->next = top;
        top = p;
    }

}
node* pop()
{

    if(top == NULL)
    {
        cout<<"stack is not created"<<endl;
    }
    else
    {
     struct stack *p;
     p = top;
     top = top->next;
     p->next;
     return p->data;
     delete p;

    }
}
int isstackempty()
{
    if(top == NULL)
    {
        return 1;
    }
    else
        return 0;
}
void enqueue(node *data)
{
    struct queue *p;
    p = new queue;
    p->data = data;
    p->next = NULL;
    if(rear == NULL && front == NULL)
    {
         front  = p;
         rear = p;

    }
    else
    {
        rear->next = p;
        rear = p;
    }
}
node *dequeue()
{
    node *x = NULL;
    struct queue *p;
    p = front;
    if( front == NULL&&rear == NULL)
    {
        cout<<"queue is empty"<<endl;
    }

    else
    {
        p = front;
        front  = front->next;
        x  =p->data;
        p->next = NULL;
        if(p == rear)
        {
            rear = NULL;
        }
        delete p;

    }
    return x;
}
int isempty()
{
    if(front ==NULL && rear == NULL)
    {
        return 1;
    }
    else
        return 0;
}
void create()
{
    struct node *p,*t;
    int x;
    cout<<"enter the  value of root node"<<endl;
    cin>>x;
    root = new node;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    enqueue(root);
    while(!isempty())
    {
        p = dequeue();
        cout<<"enter the left child of  "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            struct node *t;
            t = new node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            enqueue(t);

        }
        cout<<"enter the right child  "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            struct node *t;
            t = new node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            enqueue(t);
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
void itretive_inorder(node *p)
{
   while(p||!isstackempty())
    {
        if(p)
        {
            push(p);
            p = p->lchild;
        }
        else
        {
            p = pop();
            cout<<p->data<<" ";
            p = p->rchild;
        }
    }
}
void itretive_preorder(node* p)
{
    while(p||!isstackempty())
    {
        if(p)
        {
            cout<<p->data<<" ";
            push(p);
            p=p->lchild;
        }
        else
            {
                p = pop();
                p = p->rchild;
            }
        }
}
void itretive_postorder(node *p)
{
    long int temp;
    while(p||!isstackempty())
    {
        if(p)
        {
            push(p);
            p=p->lchild;
        }
        else
        {
           temp = (long int)pop();
           if(temp>0)
           {
               push((node *)(-temp));
               p = ((node *)temp)->rchild;
           }
           else
           {
               cout<<((node *)temp)->data<<" ";
               p = NULL;
           }
        }
    }
}
void level_traversal(node *p)
{
    cout<<p->data<<" ";
    enqueue(p);
    while(!isempty())
    {
        p=dequeue();
        if(p->lchild)
        {
            cout<<p->lchild->data<<" ";
            enqueue(p->lchild);
        }
        if(p->rchild)
        {
            cout<<p->rchild->data<<" ";
            enqueue(p->rchild);
        }

    }

}
int  all_sum(node *p)
{
    int x =0,y=0;
    if(p)
    {
        x = all_sum(p->lchild);
        y = all_sum(p->rchild);
        return x+y+p->data;
    }
    return 0;
}
int height(node *p)
{
    int x =0,y=0;
    if(p)
    {
        x  = height(p->lchild);
        y = height(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}
int  count_node(node *p)
{
   int x,y;
    if(p)
    {
        x  = count_node(p->lchild);
        y = count_node(p->rchild);
        return x+y+1;
    }
    return 0;
}

int main()
{
    int ch;
    cout<<"enter 1 for create binary tree"<<endl;
    cout<<"enter 2 for inorder "<<endl;
    cout<<"enter 3 for preorder"<<endl;
    cout<<"enter 4 for postorder"<<endl;
    cout<<"enter 5 for itretive inorder "<<endl;
    cout<<"enter 6 for itretive preorder"<<endl;
    cout<<"enter 7 for itretive postorder"<<endl;
    cout<<"enter 8 for level traversal"<<endl;
    cout<<"enter 9 for sum of all the element of tree"<<endl;
    cout<<"enter 10 for finding height of tree"<<endl;
    cout<<"enter 11 for for counting the node of tree"<<endl;
    while(ch)
    {
        cout<<"enter the choice"<<endl;
        cin>>ch;
        if(ch == 1)
        {
            create();
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
        else if(ch ==5)
        {
            itretive_inorder(root);
            cout<<endl;
        }
        else if(ch ==6)
        {
            itretive_preorder(root);
            cout<<endl;
        }
        else if(ch ==7)
        {
            itretive_postorder(root);
            cout<<endl;
        }
        else if(ch ==8)
        {
            level_traversal(root);
            cout<<endl;
        }
        else if(ch ==9)
        {
            int s;
            s = all_sum(root);
            cout<<"sum of element is "<<s<<endl;
        }
        else if(ch ==10)
        {
            int h;
            h = height(root);
            cout<<"height of tree is"<<h-1<<endl;
        }
        else if(ch ==11)
        {
            int n;
            n = count_node(root);
            cout<<"no of node in tree is"<<n<<endl;
        }
       /* else if(ch ==11)
        {
            count_node_2degree();
        }*/
        else
        {
            cout<<"invaild choice"<<endl;
        }
    }
}



