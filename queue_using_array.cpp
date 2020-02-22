#include<iostream>
using namespace std;
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;

};
void enqueue(queue *q,int data)
{
    if(q->rear == q->size-1)
    {
        cout<<"queue is full"<<endl;

    }
    else
    {
        q->rear++;
        q->Q[q->rear] = data;
    }

}
int dequeue(queue *q)
{
    int x = -1;

    if(q->front == q->rear)
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
        q->front++;
        x= q->Q[q->front];

    }
    return x;
}
void display(queue *q)
{
    int p;
    p = q->front+1;
    if(p == q->rear)
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
            for(int i=0;p!=q->size;i++)
            {
                cout<<q->Q[p++]<<" ";
            }
            cout<<endl;
    }


}
int main()
{
    struct queue q;
    int data;
    int ch;
    cout<<"enter the size of queue"<<endl;
    cin>>q.size;
    q.Q = new int[q.size];
    q.front = -1;
    q.rear = -1;
    while(ch)
    {
            cout<<"enter the choice"<<endl;
            cin>>ch;
            if(ch == 1)
            {
                cout<<"enter the data"<<endl;
                cin>>data;
                enqueue(&q,data);
            }
            else if(ch == 2)
            {
                display(&q);
            }
            else if(ch ==3)
            {
                int x;
                x = dequeue(&q);
                cout<<"deleted element is"<<x<<endl;
            }
            else
            {
                cout<<"invaild choice"<<endl;
            }
    }
}
