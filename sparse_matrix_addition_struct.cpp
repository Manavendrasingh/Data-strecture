#include<iostream>
using namespace std;

struct element
{
    int i;
    int j;
    int x;
};
struct sparse
{
    int m;
    int n;
    int num;
    struct element *e;
};
void create(struct sparse *s1)
{
    cout<<"enter the dimension"<<endl;
    cin>>s1->m>>s1->n;
    cout<<"enter the no of non_zero ele"<<endl;
    cin>>s1->num;
    s1->e = new element[s1->num];
    cout<<"enter the element"<<endl;
    for(int i =0;i<s1->num;i++)
    {
        cin>>s1->e[i].i>>s1->e[i].j>>s1->e[i].x;

    }

}
struct sparse *Add(struct sparse *s1,struct sparse *s2)
{
  struct sparse *sum;
  int k=0,i=0,j=0;
  if(s1->m!=s2->m && s1->n!=s2->n)
  {

      cout<<"these matrix is not addable"<<endl;
  }
  else
  {
      sum = new sparse;
      sum->m = s1->m;
      sum->n = s1->n;
      sum->e = new element[s1->num +s2->num];
      while(i<s1->num && j<s2->num)
      {
        if(s1->e[i].i < s2->e[j].i)
        {
            sum->e[k++]= s1->e[i++];
        }
        else if(s1->e[i].i > s2->e[j].i)
        {
            sum->e[k++]= s2->e[j++];
        }
        else //s1->e[i].i == s2->[j].i
        {
            if(s1->e[i].j < s2->e[j].j)
            {
                sum->e[k++] = s1->e[i++];
            }
            else if(s1->e[i].j > s2->e[j].j)
            {
               sum->e[k++] = s2->e[j++];
            }
            else //s1->e[i].j == s2->[j].j
            {
                sum->e[k] = s1->e[i++];
                sum->e[k++].x += s2->e[j++].x;
            }
        }

      }
    for(;i<s1->num;i++){
        sum->e[k++] = s1->e[i];
    }
    for(;j<s2->num;j++){
        sum->e[k++] = s2->e[j];
    }
    sum->num = k;
   return sum;
  }

}
void display(struct sparse s)
{
   int i,j,k=0;
   for(i=1;i<=s.m;i++)
   {
       for(j=1;j<=s.n;j++)
       {
           if(i == s.e[k].i && j == s.e[k].j)
           {
               cout<<s.e[k++].x<<" ";
           }
           else {
              cout<<"0 ";
           }

       }
       cout<<endl;
   }
}
int main()
{
    struct sparse *s3;
    struct sparse s1;
    struct sparse s2;
    create(&s1);
    cout<<"matrix a"<<endl;
    display(s1);
    create(&s2);
    cout<<"matrix b"<<endl;
    display(s2);
    s3 = Add(&s1,&s2);
    cout<<"matrix sum"<<endl;
    display(*s3);
    return 0;
}
