#include<bits/stdc++.h>
using namespace std;

void bubble(int arr[],int n)
{
    int flag;
    for(int i=0;i<n-1;i++)
    {
        flag = 0;
        for(int j =0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[i],arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}
int main()
{
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the array element"<<endl;
    for(int i= 0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubble(arr,n);
    for(int i= 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
