#include<bits/stdc++.h>
#include<ctime>
using namespace std;
struct node//used in Bin sort and radix sort
{
    int data;
    node *next;
    node(int key)
    {
        data = key;
        next = NULL;
    }
};
int Delete(node* &Bins)
{
    int x;
    node* p = Bins;
    Bins = p->next;
    p->next = NULL;
    x = p->data;
    delete(p);
    return x;
}

void insertion(node* &Bins,int key)
{
     node *p = new node(key);
     if(Bins == NULL)
     {
       Bins = p;
     }
     else
     {
        node* root = Bins;
        while(root->next!= NULL )
        {
            root = root->next;
        }
        root->next = p;
    }

}

void bubble_sort(int arr[],int n)
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
void insertion_sort(int arr[],int n)
{
   for(int x,j,i =1;i<n;i++)
   {
       j = i -1;
       x = arr[i];
       while(j > -1 && arr[j]>x)
       {
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = x;

   }
}
void selection_sort(int arr[],int n)
{

    int i,j,k;
    for(i = 0;i<n;i++)
    {
        for(j = k = i;j<n;j++)
        {
            if(arr[j] < arr[k])
                k = j;
        }
        swap(arr[i],arr[k]);
    }
}
int partition_function(int arr[],int l,int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    do
    {
        do{i++;} while(arr[i] <= pivot);
        do{j--;} while(arr[j] > pivot);
        if(j > i)
        {
            swap(arr[i],arr[j]);
        }

    }while(i<j);
    swap(arr[l],arr[j]);
    return j;
    /*int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {

            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);*/
}
int partition_r(int arr[], int l, int h)//randomized quick sort
{
    srand(time(NULL));
    int random = l + rand()%(h- l);
    swap(arr[random], arr[l]);
    return partition_function(arr, l, h);
}
void quick_sort(int arr[],int l,int h)
{
   int j;
   if(l<h)
   {

       j = partition_r(arr,l,h);
       quick_sort(arr,l,j);
       quick_sort(arr,j+1,h);
   }
}
void merged(int arr[],int l,int mid,int h)
{

    int i,j,k;
    int n = sizeof(arr)/sizeof(int);
    int b[h+1];
    j = mid+1;
    i= l;
    k =l;
    while(i <= mid && j <=h)
    {
        if(arr[i] < arr[j])
        {
            b[k++] = arr[i++];
        }
        else
        {
            b[k++] = arr[j++];
        }

    }
    for(;i<=mid;i++)
        b[k++] = arr[i];
    for(;j<=h;j++)
        b[k++] = arr[j];
    for(int i = l;i <= h;i++)
        arr[i] = b[i];

}
void iterative_merge(int arr[],int n)
{
    int p,l,i,mid,h;
    for(p=2;p<=n;p = p*2)
    {
        for(i =0;i+p-1 < n;i = i+p)
        {
            l = i;
            h = i + p - 1;
            mid = abs((l+h)/2);
            merged(arr,l,mid,h);
        }

    }
    if(p/2 < n )
    {
       merged(arr,0,p/2-1,n);
    }
}
void recursive_merge(int arr[],int l,int h)
{
    int mid;
    if(l < h)
    {

        mid = (l+h)/2;
        recursive_merge(arr,l,mid);
        recursive_merge(arr,mid+1,h);
        merged(arr,l,mid,h);

    }

}
void shell_sort(int arr[],int n)
{
    int gap,i,j,temp;
    for(int gap = n/2;gap >= 1;gap/=2)
    {
        for(i = gap;i < n;i++)
        {
            temp = arr[i];
            j = i - gap;
            while(j > 0 && arr[j] > temp)
            {
                arr[j+gap] = arr[j];
                j = j-gap;
            }
            arr[j+gap] = temp;
        }
    }
}
int findmax(int arr[],int n)
{
    int m = INT_MIN;
    for(int i =0;i<n;i++)
    {
        if(arr[i] > m)
        {
            m = arr[i];
        }
    }
    return m;
}
void count_sort(int arr[],int n)
{
    int m,i,j;
    int *c;
    m = findmax(arr,n);
    c = new int[m +1];
    for(i=0;i<m+1;i++)
    {
        c[i] =0;
    }
    for( i =0;i< n;i++)
    {
        c[arr[i]]++;
    }
    i = 0;
    j = 0;
    while(i < m+1)
    {
        if(c[i] > 0)
        {
            arr[j++] = i;
            c[i]--;
        }
        else i++;
    }
}
void Bucket_sort(int arr[],int n)
{
    int Max,i,j;
    node **Bins;
    Max = findmax(arr,n);
    Bins = new node* [Max+1];
    for(i =0;i< Max + 1;i++)
    {
        Bins[i] = NULL;
    }
    for(i=0;i < n;i++)
    {
        insertion(Bins[arr[i]],arr[i]);

    }
    i =0;j =0;
    while(i < Max + 1)
    {
        while(Bins[i]!= NULL)
        {
            arr[j++] = Delete(Bins[i]);
        }
        i++;
    }
}
void Radix_sort(int arr[],int n)
{
    node **Bins;
    int Max,i,j;
    int brr[n];
    for(int i  =0;i < n ;i++)
    {
         brr[i] = arr[i];

    }
    Bins = new node* [10];
    Max = findmax(arr,n);
    for(i=0;i<10;i++)
    {
        Bins[i] = NULL;

    }
    int c =0;
    while(Max!=0)
    {
       c++;
       Max = Max/10;
    }
    int m ,p;
    m = p = c;
    int k = c -1;
    while(p--)
    {
        for(int i =0;i < n;i++)
        {
             int r;
             int num = arr[i];
             while(m!=k)
             {

                 r = num%10;
                 num = num/10;
                 m--;
             }
             m = c;
             insertion(Bins[r],arr[i]);
        }
        k--;
        i = 0;j = 0;
        while(i < 10)
        {
            while(Bins[i] != NULL)
            {
                arr[j++] = Delete(Bins[i]);
            }

            i++;
        }

    }

}
int main()
{
    cout<<"enter 1 for bubble sort"<<endl;
    cout<<"enter 2 for insertion sort"<<endl;
    cout<<"enter 3 for selection sort"<<endl;
    cout<<"enter 4 for quick sort"<<endl;
    cout<<"enter 5 for iterative merge sort"<<endl;
    cout<<"enter 6 for recursive merge sort"<<endl;
    cout<<"enter 7 for shell sort"<<endl;
    cout<<"enter 8 for count sort"<<endl;
    cout<<"enter 9 for Bin/Bucket sort"<<endl;
    cout<<"enter 10 for Radix sort"<<endl;
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the array element"<<endl;
    for(int i= 0;i<n;i++)
    {
        arr[i] = rand();
    }
    for(int i= 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    int ch = 1;
    double t1,t2;
    while(ch)
    {

        cout<<"enter the choice"<<endl;
        cin>>ch;
        if(ch == 1)
        {   t1 = clock();
            bubble_sort(arr,n);
            t2 = clock();
        }
        if(ch == 2)
        {
            t1 = clock();
            insertion_sort(arr,n);
            t2 = clock();
        }
        if(ch == 3)
        {
            t1 = clock();
            selection_sort(arr,n);
            t2 = clock();
        }
        if(ch == 4)
        {
             t1 = clock();
             quick_sort(arr,0,n);
             t2 = clock();
        }
        if(ch ==5)
        {
             t1 = clock();
             iterative_merge(arr,n);
             t2 = clock();
        }
        if(ch == 6)
        {
             t1 = clock();
             recursive_merge(arr,0,n);
             t2 = clock();
        }
        if(ch == 7)
        {
             t1 = clock();
             shell_sort(arr,n);
             t2 = clock();
        }
        if(ch == 8)
        {
             t1 = clock();
             count_sort(arr,n);
             t2 = clock();
        }
        if(ch == 9)
        {
              t1 = clock();
              Bucket_sort(arr,n);
              t2 = clock();
        }
        if(ch == 10)
        {
              t1 = clock();
              Radix_sort(arr,n);
              t2 = clock();
        }
        cout<<"output of sorting"<<endl;
        for(int i= 0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<"time taken by algorithum is"<<(t2-t1)/CLOCKS_PER_SEC<<endl;
    }

    }




