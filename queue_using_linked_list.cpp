#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int data)
{
    struct node *p;
    p = new node;
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
int dequeue()
{
    int x = -1;
    struct node *p;
    p = front;
    if( front == NULL )
    {
        cout<<"queue is empty"<<endl;
    }

    else
    {
        p = front;
        front  = front->next;
        x  =p->data;
        p->next = NULL;
        delete p;

    }
}
void display()
{

  if(front == NULL)
    {
        cout<<"queue is empty"<<endl;

    }
    else
    {
        struct node *p;
        p = front;
        cout<<"queue is this"<<" ";
        while(p!= NULL)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}
int main()
{
    int ch;
    int data;
    while(ch)
    {
        cout<<"enter the choice"<<endl;
        cin>>ch;
        if(ch == 1)
        {
            cout<<"ente the data"<<endl;
            cin>>data;
            enqueue(data);
        }
        else if(ch == 2)
        {
            dequeue();
        }
        else if(ch == 3)
        {
            display();

        }
        else
        {

            cout<<"invaild choice"<<endl;
        }
    }
}
