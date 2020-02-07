#include<iostream>
using namespace std;
class element
{
public:
    int i;
    int j;
    int x;
};
class sparse{
private:
    int m;
    int n;
    int num;
    element *e;
public:
    sparse(int m,int n,int num)//creation of sparse
    {
        this->m = m;
        this->n = n;
        this->num = num;
        e = new element[this->num];

    }
    ~sparse()
    {
        delete []e;
    }
    void read();
    void display();
    sparse operator+(sparse &s2);

};
void sparse::read()
{
    cout<<"enter the non zero element"<<endl;
    for(int i=0;i<num;i++)
    {
      cin>>e[i].i>>e[i].j>>e[i].x;
    }

}
sparse sparse::operator+(sparse &s2)
{
    int k=0,i=0,j=0;
    if(m!= m || n!= s2.n)
    {
        cout<<"matrix is not addable"<<endl;
    }
    else
    {

        sparse *sum;
        sum = new sparse(m,n,num+s2.num);
        sum->e = new element[num + s2.num];
        while(i<num && j<s2.num)
        {
           if(e[i].i < s2.e[j].i)
           {
               sum->e[k++] = e[i++];
           }
           else  if(e[i].i > s2.e[i].i)
           {
              sum->e[k++] = s2.e[j++];
           }
           else //s1.e[i].i == s2.e[i].i
           {
               if(e[i].j < s2.e[j].j)
               {
                 sum->e[k++] = e[i++];
               }
               else if(e[i].j > s2.e[j].j)
               {
                   sum->e[k++] = s2.e[j++];
               }
               else //s1.e[i].j == s2.e[j].j
               {
                   sum->e[k] = e[i++];
                   sum->e[k++].x += s2.e[j++].x;
               }
           }

        }
        for(;i<num;i++){sum->e[k++] = e[i];}
        for(;j<s2.num;j++){sum->e[k++] = s2.e[j];}
        sum->num = k;
        return *sum;
    }

}
void sparse::display()
{
    int k=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i == e[k].i && j == e[k].j)
            {
                cout<<e[k++].x<<" ";
            }
            else{
            cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    sparse s1(4,5,6);
    sparse s2(4,5,6);
    //sparse s3;
    s1.read();
    cout<<"matrix A is "<<endl;
    s1.display();
    s2.read();
    cout<<"matrix B is "<<endl;
    s2.display();
    cout<<"sum of matrix is "<<endl;
    sparse s3 = s1+s2;
    s3.display();

    return 0;
}
