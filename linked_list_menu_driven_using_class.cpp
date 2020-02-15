#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class linked_list
{
private:
    node *root;
    node *last;
public:
    linked_list()
    {
        root = NULL;
        last = NULL;
    }
    void create(int data[],int n);
    void display();
    void append(int data);
    void append_last(int data);
    int allsum();
    int maximum();
    int minimum();
    int searching(int key);
    void Delete(int index);
    void insert(int index,int data);
    void reverse_list();
    void reduplacates();
    void issorted();
    int count();
};
void linked_list::create(int data[],int n)
{
    for(int i=0;i<n;i++)
    {
            node *p;
            p = new node;
            if(root == NULL)
            {
                p->data = data[i];
                p->next = root;
                root = p;
                last = p;

            }
            else
            {

                p->data = data[i];
                p->next = root;
                root = p;
            }
    }


}
void linked_list::display()
{
  if(root == NULL)
    {
        cout<<"linked list is not found"<<endl;

    }
    else
    {
        node *p;
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
void linked_list::append(int data)
{
    node *p;
    p = new node;
    p->data = data;
    p->next = NULL;
    if(root == NULL)
    {
        root = p;
        last = p;
    }
    else
    {
        p->next = root;
        root = p;
    }
}
void linked_list::append_last(int data)
{
    node *p;
    p = new node;
    p->data = data;
    p->next = NULL;
    if(root == NULL)
    {
        root  = p;
        last = p;
    }
    else
    {
        last->next = p;
        last = p;
    }
}
int linked_list::allsum()
{
    if(root == NULL)
    {
        cout<<"linked list not found"<<endl;
        return 0;
    }
    else
    {
        int sum = 0;
        node *p;
        p = root;
        while(p!=NULL)
        {
            sum += p->data;
            p = p->next;
        }
        return sum;

    }
}
int linked_list::maximum()
{
    if(root == NULL)
    {
        return 0;
    }
    else
     {
      int m= -32768;
      node *p;
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
int linked_list::minimum()
{
    if(root == 0)
    {
        return 0;
    }
    else
    {
        int m = 32765;
        node *p;
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
int linked_list::searching(int key)
{
    if(root == NULL)
    {
        cout<<"linked list is not found"<<endl;
    }
    else
    {
        int c = 0;
         node *p;
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
void linked_list::insert(int index,int data)
{
    if(root == NULL)
    {
        cout<<"linked list is not found "<<endl;
    }
    else
    {
        node *p,*q;
        q = new node;
        q->data = data;
        q->next = NULL;
        p = root;
        int c=0;
        while((index-2!= c) && (p!= NULL))
        {
            c++;
            p = p->next;
        }
        if(index-2 == c)
        {
           q->next = p->next;
           p->next = q;
           cout<<"data is inserted successfully"<<endl;
        }
        else
        {
            cout<<"index out of range"<<endl;
        }

    }

}
void linked_list::Delete(int index)
{
    if(root == NULL)
    {
        cout<<"linked list is not found"<<endl;
    }
    else if(index == 1)
    {
        node *p;
        p = root;
        root = p->next;
        p->next = nullptr;
        delete p;
    }
    else
    {
        node *p,*q;
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
int linked_list::count()
{
    if(root == NULL)
    {
        cout<<"0 node in linked list"<<endl;
    }
    else
    {
        int c =0;
        node *p;
        p = root;
        while(p!= NULL)
        {
           c++;
           p = p->next;

        }

       return c;
    }

}
void linked_list::issorted()
{
    if(root == NULL)
    {
        cout<<"linkes list is not found"<<endl;
    }
    else
    {
        node *p;
        p = root;
        int m = -32768;
        int n =  32768;
        while(p!=NULL)
        {
            if(m > p->data)
            {
                cout<<"linked is sorted is not sorted" <<end;
            }
            m = p->data;
            p = p->next;
        }
        cout<<"linked list is sorted"<<endl;
    }
}
void linked_list::reduplacates()
{
    if(root == NULL)
    {
        cout<<"linked list is not found"<<endl;
    }
    else
    {
        node *p,*q;
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
                    q->next = nullptr;
                    delete q;
                    q = p->next;
                }
                else
                {
                    p->next = q->next;
                    q->next = nullptr;
                    delete q;
                    q = p->next;
                }
            }
        }
    }
}
void linked_list::reverse_list()
{
    node *p,*q,*r,*temp;
    p = root;
    q = NULL;
    r = NULL;
    while(p!=NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    temp = root;
    root =last;
    last = temp;
    delete temp;
}
int main()
{
    int ch;
    linked_list L;
    cout<<"enter 1 for create linked list"<<endl;
    cout<<"enter 2 for display linked list"<<endl;
    cout<<"enter 3 for Append at fist position in  linked list"<<endl;
    cout<<"enter 4 for Append node at last linked list"<<endl;
    cout<<"enter 5 for find the sum of all element of linked list"<<endl;
    cout<<"enter 6 for maximum of element of linked list"<<endl;
    cout<<"enter 7 for minimum of element of linked list"<<endl;
    cout<<"enter 8 for searching a element in linked list"<<endl;
    cout<<"enter 9 for insert a element in linked list"<<endl;
    cout<<"enter 10 for Delete a element in linked list"<<endl;
    cout<<"enter 11 for count nodes linked list"<<endl;
    cout<<"enter 12 for checking whether a linked list already sorted or not"<<endl;
    cout<<"enter 13 for removing continuous duplicates data linked list"<<endl;
    cout<<"enter 14 for reverse the  linked list "<<endl;
    /*cout<<"enter 15 for concatenation of two string "<<endl;*/
    while(ch != 0)
    {
        cout<<"enter the choice"<<endl;
        cin>>ch;
        if(ch ==  1)
        {
            int n;
            cout<<"enter the no of data"<<endl;
            cin>>n;
            int data[n];
            cout<<"enter the data"<<endl;
            for(int i=0;i<n;i++)
            {
                 cin>>data[i];
            }
            L.create(data,n);
        }
       else if(ch ==  2)
       {
            L.display();
       }
       else if(ch == 3)
       {
           int data;
           cout<<"enter the data"<<endl;
           cin>>data;
           L.append(data);
       }
       else if(ch ==4)
       {
           int data;
           cout<<"enter the data"<<endl;
           cin>>data;
           L.append_last(data);
       }

       else if(ch == 5)
       {
           int sum;
           sum = L.allsum();
           cout<<"sum of all element is "<<sum<<endl;
       }
       else if(ch ==6)
       {
           int m;
           m = L.maximum();
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
            m = L.minimum();
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
          f = L.searching(k);
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
           L.insert(index,data);
       }
       else if(ch == 10)
       {
           int index;
           cout<<"enter the index"<<endl;
           cin>>index;
           L.Delete(index);
       }
       else if(ch ==11)
       {
           int c;
           c = L.count();
           cout<<"no of node in linked list is "<<c<<endl;
       }
       else if(ch == 12)
       {
          L.issorted();
       }
       else if(ch == 13)
       {
           L.reduplacates();
       }
       else if(ch == 14)
       {
           L.reverse_list();
       }
       else if(ch == 15)
       {
           linked_list L1;
           L1.cer
           L.concatenation();
       }

       else
       {
           cout<<"invalid choice"<<endl;
       }
    }
}



