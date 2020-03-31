
#include<iostream>
using namespace std;
struct node
{
    struct node *lchild;
    int height;
    int data;
    struct node *rchild;
};
struct node *root = NULL;
int nodeheight(node *p)
{
    int hl,hr;
    hl = p&&p->lchild ?p->lchild->height:0;
    hr = p&&p->rchild ?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}
int balancefactor(struct node *p)
{
    int hl,hr;
    hl = p&&p->lchild ?p->lchild->height:0;
    hr = p&&p->rchild ?p->rchild->height:0;
    return hl-hr;
}
struct node* LLRotation(node *p)
{
   struct node* pl = p->lchild;
   struct node* plr = pl->rchild;
   pl->rchild = p;
   p->lchild = plr;
   p->height = nodeheight(p);
   pl->height = nodeheight(p);
   if(root == p){root = pl;}
   return pl;
}
struct node* LRRotation(node *p)
{
    struct node* pl = p->lchild;
    struct node* plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    plr->height = nodeheight(plr);
    p->height = nodeheight(p);
    pl->height = nodeheight(pl);
    if(root == p){root = plr;}
    return plr;

}
struct node* RRRotation(struct node*p)
{
   struct node* pr = p->rchild;
   struct node* prl = pr->lchild;
   p->rchild = prl;
   pr->lchild = p;
   p->height = nodeheight(p);
   pr->height = nodeheight(pr);
   if(root == p){root = pr;}
   return pr;
}
struct node* RLRotation(node *p)
{
    struct node* pr = p->lchild;
    struct node* prl = pr->lchild;
    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;
    prl->height = nodeheight(prl);
    p->height = nodeheight(p);
    pr->height = nodeheight(pr);
    if(root == p){root = prl;}
    return prl;

}
node* insert(struct node*p,int a)
 {
     struct node*t=NULL;

     if(p == NULL)
     {
         t = new node;
         t->data = a;
         t->height = 1;
         t->lchild = NULL;
         t->rchild = NULL;
         return t;
     }
     if(p->data > a)
     {
         p->lchild = insert(p->lchild,a);
     }
     else if( p->data < a)
     {
         p->rchild = insert(p->rchild,a);
     }
     p->height = nodeheight(p);
     if(balancefactor(p)==2 && balancefactor(p->lchild)== -1)
             {
                   return LLRotation(p);
             }
     else if(balancefactor(p)==2&&balancefactor(p->lchild) == 1)
             {
                   return LRRotation(p);
             }
     else if(balancefactor(p)==-2&&balancefactor(p->lchild) == -1)

            {
                   return RRRotation(p);
            }
     else if(balancefactor(p)==-2&&balancefactor(p->lchild) == 1)
            {
                   return RLRotation(p);

            }
     return p;
 }
 void inorder(node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }


}
void preorder(node *p)
{

    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }

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
node* search(node *p,int key)
{

    //RECUSIVE FUNCTION
    if(p==NULL){return NULL;}
    else
    {
       if(p->data == key){ return p;}
       else if(p->data > key){return search(p->lchild,key);}
       else if(p->data < key){return search(p->rchild,key);}
        //return NULL;
    }
}
struct node* inpre(node *p)
{
    while(p->rchild)
    {
        p=p->rchild;
    }
    return p;
}
struct node* insucc(node *p)
{
    while(p->lchild)
    {
        p=p->lchild;
    }
    return p;
}
node *delete_node(node *p,int key)
{
    if(p == NULL){return NULL;}
    if(p->lchild == NULL && p->rchild == NULL  )
    {
        p = NULL;
        delete p;
        return NULL;
    }
    if(key<p->data){p->lchild = delete_node(p->lchild,key);}
    else if(key>p->data){p->rchild = delete_node(p->rchild,key);}
    else
    {
         struct node *q;
         if(height(p->lchild)>height(p->rchild))
         {
             q = inpre(p->lchild);
             p->data = q->data;
             p->lchild = delete_node(p->lchild,q->data);

         }
         else
         {
             q = insucc(p->rchild);
             p->data = q->data;
             p->rchild = delete_node(p->rchild,q->data);
         }
    }
}


int main()
{

    int ch;

    cout<<"enter 1 for insert in AVL tree"<<endl;
    cout<<"enter 2 for inorder "<<endl;
    cout<<"enter 3 for preorder"<<endl;
    cout<<"enter 4 for postorder"<<endl;
    cout<<"enter 5 for  searching of key element in BST"<<endl;
    cout<<"enter 6 for create AVL"<<endl;
    cout<<"enter 7 for delete a node"<<endl;
    /*cout<<"enter 8 for level traversal"<<endl;
    cout<<"enter 9 for create tree by preorder"<<endl;
    cout<<"enter 10 for create tree by postorder "<<endl;
    /*cout<<"enter 11 for for counting the node of tree"<<endl;
    cout<<"enter 12 for insert the node into bst"<<endl;*/
    while(ch)
    {
        cout<<"enter the choice"<<endl;
        cin>>ch;
         if(ch ==1)
        {
            int data;
            cout<<"enter the data"<<endl;
            cin>>data;
            root = insert(root,data);
        }
        else if(ch == 2)
        {
            inorder(root);
            cout<<endl;
        }
        else if(ch==3)
        {
            preorder(root);
            cout<<endl;
        }
        else if(ch ==4)
        {
            postorder(root);
            cout<<endl;
        }
        else if(ch == 5)
        {
            int key;
            struct node *p;
            cout<<"enter the key element"<<endl;
            cin>>key;
            p = search(root,key);
            if(p == NULL){cout<<"key is not found"<<endl;}
            else{cout<<"key"<<p->data<<" is found"<<endl;}
        }
        else if(ch == 6)
        {
            int size;
            cout<<"ente the size of data"<<endl;
            cin>>size;
            int a[size];
            struct node *p;
            cout<<"enter the data"<<endl;
            for(int i=0;i<size;i++)
            {
                cin>>a[i];
                root = insert(root,a[i]);
            }

        }
        else if(ch == 7)
        {
            int key;
            cout<<"enter the key element for which is going to delete"<<endl;
            cin>>key;
            //struct node *p;
            delete_node(root,key);
            //cout<<p->data<<endl;
        }
        /*else if(ch == 9)
        {
            int key;
            cout<<"enter the no of element in preorder"<<endl;
            cin>>key;
            int a[key];
            cout<<"enter the data"<<endl;
            for(int i=0;i<key;i++)
            {
                cin>>a[i];
            }
            root = pre_create(a,key);
        }
        else if(ch == 10)
        {
            int key;
            cout<<"enter the no of element in postorder"<<endl;
            cin>>key;
            int a[key];
            cout<<"enter the data"<<endl;
            for(int i=0;i<key;i++)
            {
                cin>>a[i];
            }
            root = post_create(a,0,key-1);

        }*/

    }
}
