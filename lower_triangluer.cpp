#include<iostream>
using namespace std;
class lower_trinaguler_matrix
{
 private:
     int *A;
     int n;
 public:
     lower_trinaguler_matrix();
     lower_trinaguler_matrix(int n);
     ~lower_trinaguler_matrix();
     void set(int i,int j,int x);
     int get(int i,int j);
     void display();

};
lower_trinaguler_matrix::lower_trinaguler_matrix()
{
    n =10;
    A = new int[n];
}

lower_trinaguler_matrix::lower_trinaguler_matrix(int n)
{
    this->n = n;
    A = new int[n];
}
lower_trinaguler_matrix::~lower_trinaguler_matrix(){
 delete []A;
}

void lower_trinaguler_matrix::set(int i,int j,int x)
{
    if(i>=j)
    {
        A[(i*(i-1)/2)+j-1]=x;
    }
}
int lower_trinaguler_matrix::get(int i,int j)
{
  if(i>=j){
    return A[(i*(i-1)/2)+j-1];
  }
  else return 0;
}
void lower_trinaguler_matrix::display()
{
    for(int i = 1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)
            {
             cout<<A[(i*(i-1)/2)+j-1]<<" ";
            }
            else{
            cout<<"0 ";
            }
        }
        cout<<"\n";

    }
}
int main()
{
   lower_trinaguler_matrix m(15);
   m.set(1,1,5);
   m.set(2,1,6);
   m.set(3,1,7);
   m.set(4,1,8);
   m.set(5,1,9);
   m.set(2,2,10);
   m.set(3,2,11);
   m.set(4,2,12);
   m.set(5,2,13);
   m.set(3,3,14);
   m.set(4,3,15);
   m.set(5,3,16);
   m.set(4,4,17);
   m.set(5,4,18);
   m.set(5,5,19);
   m.display();
   return 0;

}
