#include<iostream>
using namespace std;
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
void push(int data)
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
int pop()
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
void display()
{
    if(top == NULL )
    {
        cout<<"stack is not created"<<endl;
    }
    else
    {
        struct stack *p;
        p = top;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
    }
}
int peek(int pos)
{
    struct stack *p;
    p = top;
    for(int i=0;p!=NULL && i<pos-1;i++)
    {
        p = p->next;
    }
    if(p!=NULL)
    {
        return p->data;

    }
    else
        return -1;
}
int stacktop()
{
    if(top)
    {
        return top->data;
    }
    else
        return -1;
}
int main()
{

    cout<<"enter the size of stack"<<endl;
    cout<<"enter 1 for push"<<endl;
    cout<<"enter 2 for pop"<<endl;
    cout<<"enter 3 for display"<<endl;
    cout<<"enter 4 for peek"<<endl;
    cout<<"enter 5 for top element"<<endl;

    int ch;
    while(ch!=0)
    {
        cout<<"enter the choice"<<endl;
        cin>>ch;
        if(ch == 1)
        {
            int data;
            cout<<"enter the data"<<endl;
            cin>>data;
            push(data);
        }
        else if(ch == 2)
        {
            int x;
            x = pop();
            cout<<"the poping element is"<<x<<endl;

        }
        else if(ch == 3)
        {
            display();
        }
        else if(ch == 4)
        {
            int pos;
            int x;
            cout<<"enter the position"<<endl;
            cin>>pos;
            x = peek(pos);
            if(x == -1)
            {
                cout<<"either choice is invaild or stackis not created"<<endl;
            }
            else
             cout<<"the element at given position is"<<x<<endl;
        }
        else if(ch == 5)
        {
            int x;
            x = stacktop();
            if(x == -1)
            {
                cout<<"stack is empty"<<endl;
            }
            else
            cout<<"top of the stack is"<<x<<endl;
        }
        else
            cout<<"choice is invaild"<<endl;


    }
}

