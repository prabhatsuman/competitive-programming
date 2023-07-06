#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        int a=0;
        cin>>str;
        for (int i=0; i<str.length(); i++)
        {
            if ((str[i]=='1')&&((str[i+1]=='0')||(str[i+1]=='1')))
            {
                a=1;
                break;
            }
        }
        if(a==1)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}
