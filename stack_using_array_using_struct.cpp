#include<iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    int *s;
};
void push(struct stack *st,int data)
{
    if(st->top == st->size-1)
    {
        cout<<"stacak is full"<<endl;
    }
    else
    {
        st->top++;
        st->s[st->top]= data;
    }
}
int  pop(struct stack *st)
{
    int x;
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
void display(struct stack st)
{
    if(st.top == -1)
    {
        cout<<"stack is under flow"<<endl;

    }
    else
    {
        while(st.top != -1)
        {
            cout<<st.s[st.top]<<" ";
            st.top--;
        }
    }

}
int isempty(struct stack st)
{
    return st.top == -1?1:0;
}
int isfull(struct stack st)
{
    return st.top == st.size -1?1:0;
}
int peek(struct stack st,int pos)
{
    int x;
    if(st.top-pos+1 < 0 || st.top-pos+1 >st.size -1)
    {
         cout<<"invaild choice"<<endl;
    }
    else
    {
        x = st.s[st.top - pos +1];
    }
    return x;
}
int stacktop(struct stack st)
{
    return st.top!=-1?st.s[st.top]:-1;
}
int main()
{
    struct stack st;
    cout<<"enter the size of stack"<<endl;
    cin>>st.size;
    cout<<"enter 1 for push"<<endl;
    cout<<"enter 2 for pop"<<endl;
    cout<<"enter 3 for display"<<endl;
    cout<<"enter 4 for peek"<<endl;
    cout<<"enter 5 for top element"<<endl;
    cout<<"enter 6 for isempty"<<endl;
    cout<<"enter 7 for "<<endl;
    st.s  = new int[st.size];
    st.top = -1;
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
            push(&st,data);
        }
        else if(ch == 2)
        {
            int x;
            x = pop(&st);
            cout<<"the poping element is"<<x<<endl;

        }
        else if(ch == 3)
        {
            display(st);
        }
        else if(ch == 4)
        {
            int pos;
            int x;
            cout<<"enter the position"<<endl;
            cin>>pos;
            x = peek(st,pos);
            cout<<"the element at given position is"<<x<<endl;
        }
        else if(ch == 5)
        {
            int x;
            x = stacktop(st);
            if(x == -1)
            {
                cout<<"stack is empty"<<endl;
            }
            else
            cout<<"top of the stack is"<<x<<endl;
        }
        else if(ch == 6)
        {
            int x;
            x = isempty(st);
            if(x == 1)
            {
                cout<<"stack is empty"<<endl;
            }
            else if(x == 0)
            {
                cout<<"stack is not empty"<<endl;
            }
        }
        else if(ch == 7)
        {
            int x;
            x = isfull(st);
             if(x == 1)
            {
                cout<<"stack is full"<<endl;
            }
            else if(x == 0)
            {
                cout<<"stack is not full"<<endl;
            }
        }

    }
}
