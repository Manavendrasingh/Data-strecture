#include <iostream>
#include<string.h>
#include<sstream>
#include<stack>

using namespace std;

stack<char>st;

int isprec(char ch)
{
    if(ch=='^')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else
        return -1;
}
char *convert(string str)
{
    char *postfix = new char[str.length()+1];
    int j=0;
  for(int i=0;i<str.length();i++)
  {
            if(str[i]=='(')
                st.push(str[i]);
            else if(str[i]==')')
            {
                while(!st.empty()&&st.top()!='(')
                {
                    postfix[j++] = st.top();
                    st.pop();
                }

                st.pop();
            }
            else if( (tolower(str[i])>='a') && (tolower(str[i])<='z') )
                postfix[j++] = str[i];
            else
            {
                    while(!st.empty() && isprec(str[i]) <= isprec(st.top()))
                    {
                        postfix[j++] = st.top();
                        st.pop();
                    }
                    st.push(str[i]);

            }
        }
        while(!st.empty())
        {
            postfix[j++] = st.top();
            st.pop();
        }
        return postfix;
    }


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char *post;
        string str;
        cin>>str;
        post = convert(str);
        for(int i=0;post[i]!='\0';i++)
        {
            cout<<post[i];
        }
        cout<<endl;
    }

	return 0;

}
