#include<iostream>
using namespace std;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *root= NULL,*last = NULL;

void create(int data[],int n)
{
     struct node *p;
     p = new node;
     p->next = NULL;
     p->prev = NULL;
     for(int i=0;i<n;i++)
     {
         p->data = data[i];
         if(root == NULL)
         {

             root = p;
             last = p;

         }
         else
         {

             root->prev = p;
             p->next = root;
             root = p;

         }
     }
}
void display()
{

  if(root == NULL)
    {
        cout<<"linked list is not found"<<endl;

    }
    else
    {
        struct node *p;
        p = root;
        cout<<"linked list data is this"<<" ";
        while(p!= NULL)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}

void append(int data)
{
    if(root == NULL)
    {
        struct node *p;
        p = new node;
        root = p;
        last = p;
        p->data = data;
        p->next = NULL;
        p->prev = NULL;
    }
    else
    {
       struct node *p;
       p = new node;
       p->data = data;
       root->prev = p;
       p->next = root;
       root = p;
    }
}
int count()
{
    if(root == NULL)
    {
        cout<<"0 node in linked list"<<endl;
    }
    else
    {
        int c =0;
        struct node *p;
        p = root;
        while(p!= NULL)
        {
           c++;
           p = p->next;

        }

       return c;
    }

}
int allsum()
{
    if(root == NULL)
    {
        cout<<"linked list not found"<<endl;
        return 0;
    }
    else
    {
        int sum = 0;
        struct node *p;
        p = root;
        while(p!=NULL)
        {
            sum += p->data;
            p = p->next;
        }
        return sum;

    }
}
int maximum()
{
    if(root == NULL)
    {
        return 0;
    }
    else
     {
      int m= -32768;
      struct node *p;
      p = root;
      while(p!=NULL)
      {
          if(m < p->data)
          {
              m = p->data;
          }
          p = p->next;

      }
      return m;
     }
}
int minimum()
{
    if(root == 0)
    {
        return 0;
    }
    else
    {
        int m = 32765;
        struct node *p;
        p = root;
        while(p !=NULL)
        {
            if(m > p->data)
            {
                m = p->data;
            }
            p = p->next;
        }
        return m;
    }
}
int searching(int key)
{
    if(root == NULL)
    {
        cout<<"linked list is not found"<<endl;
    }
    else
    {
        int c = 0;
        struct node *p;
        p = root;
        while(p != NULL)
        {
            if(key == p->data)
            {
                return c+1;
            }
            c++;
            p = p->next;
        }
        return 0;

    }


}
void insert(int index,int data)
{
    if(root == NULL)
    {
        cout<<"linked list is not found "<<endl;
    }
    else
    {
        struct node *p,*q,*r;
        p = new node;
        p->data = data;
        p->next = NULL;
        p->prev = NULL;
        q = root;
        if(index == 1)
        {
           root->prev = p;
           p->next = root;
           root = p;
           cout<<"data is inserted successfully"<<endl;
        }
        else
        {
               int c=0;

                while((index-2!= c) && (q!= NULL))
                {
                    c++;
                    q = q->next;
                }
                r = q->next;
                if(index-2 == c)
                {
                    q->next = p;
                    r->prev = p;
                    p->prev = q;
                    p->next = r;

                   cout<<"data is inserted successfully"<<endl;
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
    if(root == NULL)
    {
        cout<<"linked list is not found"<<endl;
    }
    else if(index == 1)
    {
        struct node *p;
        p = root;
        root = p->next;
        root->prev = NULL;
        p->next = nullptr;
        delete p;
    }
    else
    {
        struct node *p,*q,*r;
        p = root;
        int c=0;
        while(index -2 != c && p!=NULL)
        {
            c++;
            p = p->next;
        }
        if(index -2 == c)
        {
             q = p->next;
              if(q->next == NULL)
              {
                  last = p;
                  p->next = NULL;
                  q->prev = nullptr;
                  q->next = nullptr;
                  delete q;
              }
              else
              {
                 r = q->next;
                 p->next = r;
                 r->prev = p;
                 q->next = nullptr;
                 q->prev = nullptr;
                 delete q;
              }


        }
        else
        {
            cout<<"index out of range"<<endl;
        }
    }
}
void append_last(int data)
{
        struct node *p;
        p = new node;
        p->data = data;
        p->next = NULL;
        p->prev = NULL;
    if(root == NULL)
    {
       root = p;
       last = p;
    }
    else
    {
        struct node *q;
        q = last;
        q->next = p;
        p->prev = q;
        last = p;


    }
}
bool issorted()
{
    if(root == NULL)
    {
        cout<<"linkes list is not found"<<endl;
    }
    else
    {
        struct node *p;
        p = root;
        int m = -32768;
        while(p!=NULL)
        {
            if(m > p->data)
            {
                return false;
            }
            m = p->data;
            p = p->next;
        }
        return true;
    }
}
void reduplacates()
{
    if(root == NULL)
    {
        cout<<"linked list is not found"<<endl;
    }
    else
    {
        struct node *p,*q,*r;
        p = root;
        q = p->next;
        while(q!=NULL)
        {
           if(p->data!=q->data)
            {
                q = q->next;
                p = p->next;

            }
           else
            {

             if(q->next == NULL)
                {
                    last = p;
                    p->next = NULL;
                    q->prev = nullptr;
                    q->next = nullptr;
                    delete q;
                    q = p->next;
                }
                else
                {
                    r = q->next;
                    p->next = r;
                    r->prev = p;
                    q->prev = nullptr;
                    q->next = nullptr;
                    delete q;
                    q = p->next;
                }
            }
        }
    }
}
void reverse_list()
{
    struct node *p,*temp;
    p = root;
    while(p!=NULL)
    {
       temp = p->next;
       p->next = p->prev;
       p->prev = temp;
       p = p->prev;
       delete temp;
       temp = last;
       last = root;
       root = temp;

    }
}
int main()
{
    int ch;
    cout<<"enter 1 for create linked list"<<endl;
    cout<<"enter 2 for display linked list"<<endl;
    cout<<"enter 3 for Append at fist position in  linked list"<<endl;
    cout<<"enter 4 for count nodes linked list"<<endl;
    cout<<"enter 5 for find the sum of all element of linked list"<<endl;
    cout<<"enter 6 for maximum of element of linked list"<<endl;
    cout<<"enter 7 for minimum of element of linked list"<<endl;
    cout<<"enter 8 for searching a element in linked list"<<endl;
    cout<<"enter 9 for insert a element in linked list"<<endl;
    cout<<"enter 10 for Delete a element in linked list"<<endl;
    cout<<"enter 11 for Append node at last linked list"<<endl;
    cout<<"enter 12 for checking whether a linked list already sorted or not"<<endl;
    cout<<"enter 13 for removing continuous duplicates data linked list"<<endl;
    cout<<"enter 14 for reverse the  linked list "<<endl;

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
           int c;
           c = count();
           cout<<"no of node in linked list is "<<c<<endl;
       }
       else if(ch == 5)
       {
           int sum;
           sum = allsum();
           cout<<"sum of all element is "<<sum<<endl;
       }
       else if(ch ==6)
       {
           int m;
           m = maximum();
           if(m == 0)
           {
            cout<<"linked list is not found"<<endl;
           }
           else
           {
           cout<<"maximum no is"<<m<<endl;
           }
       }
       else if(ch==7)
       {
           int m;
           m = minimum();
            if(m == 0)
           {
            cout<<"linked list is not found"<<endl;
           }
           else
           {
           cout<<"minimum no is"<<m<<endl;
           }
       }
       else if(ch == 8)
       {
          int k;
          int f;
          cout<<"enter the searching key"<<endl;
          cin>>k;
          f = searching(k);
          if(f == 0)
          {
              cout<<"key element is not found in linked list"<<endl;
          }
          else
          {
              cout<<"key element "<<k<<" is found at position "<<f<<endl;
          }


       }
       else if(ch == 9)
       {
           int index,data;
           cout<<"enter the index and data"<<endl;
           cin>>index>>data;
           insert(index,data);
       }
       else if(ch == 10)
       {
           int index;
           cout<<"enter the index"<<endl;
           cin>>index;
           Delete(index);
       }
       else if(ch ==11)
       {
           cout<<"enter the data"<<endl;
           cin>>data;
           append_last(data);
       }
       else if(ch == 12)
       {
           bool b;
           b = issorted();
           if(b == false)
           {
           cout<<"linked list is not sorted"<<endl;
           }
           else
            cout<<"linked list is sorted"<<endl;
       }
       else if(ch == 13)
       {
           reduplacates();
       }
       else if(ch == 14)
       {
           reverse_list();
       }

       else
       {
           cout<<"invalid choice"<<endl;
       }
    }
}
