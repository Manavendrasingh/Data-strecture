#include<iostream>
using namespace std;
struct matrix
{
    int A[10];
    int n;
};
void set(struct matrix *m,int i,int j,int x)
{
    if(i==j)
    {
        m->A[i-1] = x;

    }
}

int get(struct matrix m,int i,int j)
{
    if(i==j)
    {
        return m.A[i-1];
    }
    else return 0;
}
void display(struct matrix m)
{
    int i,j;
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i==j)
            {
                printf("%d ",m.A[i-1]);
            }
            else printf("0  ");
        }
        printf("\n");
    }
}
int main()
{
    struct matrix m;
    m.n=4;
    set(&m,1,1,10);
    set(&m,2,2,20);
    set(&m,3,3,30);
    set(&m,4,4,40);
    display(m);

    return 0;



}
