#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node* left, *right;
    Node(int x)
    {
        left = NULL;
        right = NULL;
        key = x;
    }
};
int search(int arr[], int strt, int end, int value)
{
    for (int i = strt; i <= end; i++)
        if (arr[i] == value)
            return i;
    return -1;
}
int *extrackKeys(int in[], int level[], int m, int n)
{
    int *newlevel = new int[m], j = 0;
    for (int i = 0; i < n; i++)
        if (search(in, 0, m-1, level[i]) != -1)
            newlevel[j++] = level[i];
    return newlevel;
}

Node* newNode(int key)
{
    Node *node = new Node(key);
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}
Node* buildTree(int in[], int level[], int inStrt, int inEnd, int n)
{
    if (inStrt > inEnd)
        return NULL;
    Node *root = newNode(level[0]);


    if (inStrt == inEnd)
        return root;

    int inIndex = search(in, inStrt, inEnd, root->key);

    int *llevel  = extrackKeys(in, level, inIndex, n);
    int *rlevel  = extrackKeys(in + inIndex + 1, level, n-inIndex-1, n);


    root->left = buildTree(in, llevel, inStrt, inIndex-1, n);
    root->right = buildTree(in, rlevel, inIndex+1, inEnd, n);
    delete [] llevel;
    delete [] rlevel;

    return root;
}

void printInorder(Node* node)
{
    if (node == NULL)
       return;
    printInorder(node->left);
    cout << node->key << " ";
    printInorder(node->right);
}

int main()
{       int t;
        cin>>t;
       while(t--)
       {
            int n;
            cin>>n;
            int in[n];
            int level[n];
            for(int i=0;i<n;i++)
            {
                cin>>in[i];
            }
            for(int i=0;i<n;i++)
            {
                cin>>level[i];
            }

            Node *root = buildTree(in, level, 0, n - 1, n);
            printInorder(root);
       }
    return 0;
}
