#include<iostream>
using namespace std;
class matrix
{
private:
    int A[10];
    int n;
public:
    matrix(int n);
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
};
matrix::matrix(int n)
{
    this->n = n;
}
void matrix::set(int i,int j,int x)
{
    if(i==j)
    {
        A[i-1]=x;
    }
}
int matrix::get(int i,int  j)
{
    if(i==j)
    {
        return A[i-1];
    }
    else return 0;
}
void matrix::display()
{
    int i,j;
    for(i =1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j==i)
            {
                cout<<A[i-1]<<" ";
            }
            cout<<0<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    matrix m(4);
    m.set(1,1,10);
    m.set(2,2,20);
    m.set(3,3,30);
    m.set(4,4,40);
    m.display();
    return 0;
}
