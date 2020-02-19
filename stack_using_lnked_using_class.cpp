#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class stack
{
private:
    node *top ;
public:
    stack()
    {
        top == NULL;
    }
    void push(int data);
    void display();
    int pop();
    int peek(int pos);
    int stacktop();
};
void stack::push(int data)
{
    node *p;
    p = new node;
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
int stack::pop()
{
    node *p;
    int x;
    if(top == NULL)
    {
        cout<<"stack is not created"<<endl;
    }
    else
    {
     node *p;
     p = top;
     top = top->next;
     p->next;
     x =  p->data;
     delete p;

    }
  return x;
}
void stack::display()
{
    if(top == NULL )
    {
        cout<<"stack is not created"<<endl;
    }
    else
    {
        node *p;
        p = top;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
    }
}
int stack::peek(int pos)
{
    node *p;
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
int stack::stacktop()
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


    cout<<"enter 1 for push"<<endl;
    cout<<"enter 2 for pop"<<endl;
    cout<<"enter 3 for display"<<endl;
    cout<<"enter 4 for peek"<<endl;
    cout<<"enter 5 for top element"<<endl;

    int ch;
    stack st;
    while(ch!=0)
    {
        cout<<"enter the choice"<<endl;
        cin>>ch;
        if(ch == 1)
        {

            int data;
            cout<<"enter the data"<<endl;
            cin>>data;
            st.push(data);
        }
        else if(ch == 2)
        {
            int x;
            x = st.pop();
            cout<<"the poping element is"<<x<<endl;

        }
        else if(ch == 3)
        {
            st.display();
        }
        else if(ch == 4)
        {
            int pos;
            int x;
            cout<<"enter the position"<<endl;
            cin>>pos;
            x = st.peek(pos);
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
            x = st.stacktop();
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
