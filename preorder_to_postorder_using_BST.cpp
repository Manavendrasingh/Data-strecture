#include <iostream>
using namespace std;
#include<stack>
struct node
{

    node *lchild;
    int data;
    node *rchild;

};
struct node* create(struct node* root,int arr[],int n)
{
    stack<node*>s;
    struct node *p;
    for(int i=0;i<n;i++)
    {
         struct node *t;
         if(root == NULL)
          {
              t = new node;
              t->data = arr[i];
              t->rchild = NULL;
              t->lchild = NULL;
              root = t;
              p = t;


          }
          if(p->data == arr[i]){ continue;}
          if(p->data > arr[i])
          {
              t = new node;
              t->data = arr[i];
              t->rchild = NULL;
              t->lchild = NULL;
              p->lchild = t;
              s.push(p);
              p = t;

          }
          else
          {
              while(!s.empty()&&s.top()->data < arr[i])
              {
                  p = s.top();
                  s.pop();
              }

                t = new node;
                t->data = arr[i];
                t->rchild = NULL;
                t->lchild = NULL;
                p->rchild = t;
                p = t;


            }
    }
    return root;
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
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    struct node * root = NULL;
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    root = create(root,arr,n);
	    postorder(root);
	    cout<<endl;
	}

	return 0;

}
