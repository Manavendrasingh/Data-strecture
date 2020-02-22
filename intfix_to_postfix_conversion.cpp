#include<iostream>
#include<string.h>
using namespace std;
struct stack
{
    int size;
    int top;
    char *s;
};
void push(struct stack *st,char data)
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
int isoprand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
        return 1;
}
int pre(char x)
{
    if(x == '+' || x == '-'  )
    {
        return 1;
    }
    else if(x == '*' || x == '/')
        return 2;
    else
        return 0;
}
int isempty(struct stack st)
{
    return st.top == -1?1:0;
}
char *infix_to_post(char *infix)
{
    struct stack st;
    st.size = strlen(infix);
    st.s = new char[st.size];
    st.top = -1;
    char *postfix;
    postfix = new char[strlen(infix)+1];
    int i=0;int j=0;
    while(infix[i]!='\0')
    {
        if(isoprand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if(pre(infix[i])>pre(st.s[st.top]))
            {
                push(&st,infix[i++]);
            }
            else
            {
                postfix[j++] = pop(&st);
            }
        }
    }
    while(!isempty(st))
    {
        postfix[j++] = pop(&st);
    }
    return postfix;

}

int main()
{
    char *infix = "a+b*c-d/e";
    char *p;
    p = infix_to_post(infix);
    cout<<"the postfix expression is this"<<endl;
    for(int i=0;p[i]!='\0';i++)
    {
        cout<<p[i];
    }
}
