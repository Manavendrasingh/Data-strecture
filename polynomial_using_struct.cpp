#include<iostream>
#include<math.h>
using namespace std;
struct term
{
    int coff;
    int exp;

};
struct poly
{
    int n;
    term *t;
};
void create(struct poly *p)
{
    cout<<"enter the no of term"<<endl;
    cin>>p->n;
    p->t = new term[p->n];
    cout<<"enter the coff and exp"<<endl;
    for(int  i=0;i<p->n;i++)
    {
        cin>>p->t[i].coff>>p->t[i].exp;
    }
}
void evaluation(struct poly p)
{
    int x ;
    int sum =0;
    cout<<"enter the value of x"<<endl;
    cin>>x;
    cout<<"the polynomial is"<<endl;
    for(int i =0;i<p.n;i++)
    {
      sum += (p.t[i].coff)*pow(x,p.t[i].exp);

    }
    cout<<sum<<endl;

}
struct poly *Addition(struct poly *p1,struct poly *p2)
{
    int i=0,j=0,k=0;

    if(p1->n == 0)
    {

        return p1;
    }
    else if(p2->n == 0)
    {

        return p1;
    }
    else {
        struct poly *p3;
        p3 = new poly;
        p3->n = p1->n+p2->n;
        p3->t = new term[p3->n];
        while(i<p1->n && j<p2->n)
        {
            if(p1->t[i].exp>p2->t[j].exp)
            {
                p3->t[k++] = p1->t[i++];

            }
            else if(p1->t[i].exp<p2->t[j].exp)
            {
              p3->t[k++] = p2->t[j++];
            }
            else
            {
                p3->t[k] = p1->t[i++];
                p3->t[k++].coff += p2->t[j++].coff;

            }
        }
        for(;i<p1->n;i++){p3->t[k++] = p1->t[i];}
        for(;i<p2->n;i++){p3->t[k++] = p1->t[j];}
        p3->n = k;
        return p3;

    }


};
int main()
{
    struct poly p1;
    struct poly p2;
    struct poly *p3;
    create(&p1);
    create(&p2);
    p3 = Addition(&p1,&p2);
    cout<<"addition is this"<<endl;
    evaluation(*p3);
    return 0;

}
