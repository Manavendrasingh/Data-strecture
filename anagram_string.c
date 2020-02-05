#include<iostream>
using namespace std;

int main()
{
    char A[]="decimal";
    char B[]="medical";
    int H[26]={0};
    int i=0;
    for(i=0;A[i]!='\0';i++)
    {
        H[A[i]-97] +=  1;


    }
    for(int i=0;B[i]!='\0';i++)
    {
        H[A[i]-97] -= 1;
        if(H[A[i]-97]<0)
        {
            //cout<<"not nagram"<<endl;
            printf("not anagram \n");
            break;
        }
    }

    if(B[i]=='\0')
    {
        //cout<<"anagram"<<endl;
        printf("nagram \n");

    }
    return 0;
}

