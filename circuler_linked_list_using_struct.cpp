#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL,*last = NULL;
void create(int data[],int n)
{

    for(int i=0;i<n;i++)
    {
        struct node *p;
        p = new node;
        if(head == NULL)
        {
            p->data = data[i];
            p->next = p;
            head= p;
            last = p;
        }
        else
        {
           p->data = data[i];
           p->next = head;
           head = p;
           last->next = p;

        }


    }


}
void append(int data)
{
    struct node *p;
    p = new node;
    p->data = data;
    p->next = NULL;
    if(head == NULL)
    {
        head = p;
        p->next = p;
        last = p;
    }
    else
    {
         p->next = head;
         head = p;
         last->next = p;
    }

}
void display()
{
  if(head== NULL)
    {
        cout<<"linked list is not found"<<endl;

    }
    else
    {
         struct node *p;
         p = head;
         int flag = 0;
       cout<<"linked list data is this"<<" ";
       while(p!= head || flag == 0)
        {
            flag = 1;
            cout<<p->data<<" ";
            p = p->next;
        }
        flag = 0;
        cout<<endl;
    }
}
void Insert(int index,int data)
{
    if(head == NULL)
    {
        cout<<"linked list is not found "<<endl;
    }
    else
    {
        struct node *p,*q;
        q = new node;
        q->data = data;
        q->next = NULL;
        p = head;
        if(index == 1)
        {
           q->next = head;
           head = q;
           last->next = head;

           cout<<"data is inserted successfully"<<endl;
        }
        else
        {
               int c=0;

                while((index-2!= c) && (p->next!= head))
                {
                    c++;
                    p = p->next;
                }

                if(index-2 == c && p->next!=head)
                {
                   q->next = p->next;
                   p->next = q;
                   cout<<"data is inserted successfully"<<endl;
                }
                else if(index-2 == c && p->next==head)
                {
                    p->next = q;
                    last = q;
                    q->next = head;
                }
                else
                {
                    cout<<"index out of range"<<endl;
                }

     }

}
}
void Delete(int index)
{
    if(head == NULL)
    {
        cout<<"linked list is not found"<<endl;
    }
    else if(index == 1)
    {
        struct node *p;
        p = head;
        head = p->next;
        last->next = head;
        p->next = nullptr;
        delete p;
    }
    else
    {
        struct node *p,*q;
        p = head;
        int c=0;
        while(index -2 != c && p->next!=head)
        {
            c++;
            p = p->next;
        }
        if(index -2 == c)
        {
              q = p->next;
              if(q->next == head)
              {
                  last = p;
                  p->next = q->next;
                  q->next = nullptr;
                  delete q;
              }
              else
              {
                 p->next = q->next;
                 q->next = nullptr;
                 delete q;
              }


        }
        else
        {
            cout<<"index out of range"<<endl;
        }
    }
}
int main()
{
    int ch;
    cout<<"enter 1 for create linked list"<<endl;
    cout<<"enter 2 for display linked list"<<endl;
    cout<<"enter 3 for Append at fist position in  linked list"<<endl;
    cout<<"enter 4 for insert a node at given position in  linked list"<<endl;
    cout<<"enter 5 for delete a node from a given position in  linked list"<<endl;
     while(ch != 0)
    {

        cout<<"enter the choice"<<endl;
        cin>>ch;
        int data;
        if(ch ==  1)
        {

                int n;
                cout<<"enter the size of data"<<endl;
                cin>>n;
                int data[n];
                cout<<"enter the data"<<endl;
                for(int i=0;i<n;i++)
                {
                     cin>>data[i];

                }
                create(data,n);
        }
       else if(ch ==  2)
       {
                display();
       }
       else if(ch == 3)
       {
                cout<<"enter the data"<<endl;
                cin>>data;
                append(data);
       }
        else if(ch == 4)
       {
                int index,data;
                cout<<"enter the index and data"<<endl;
                cin>>index>>data;
                Insert(index,data);
       }
       else if(ch == 5)
       {
                int index;
                cout<<"enter the index"<<endl;
                cin>>index;
                Delete(index);
       }

   }
}
