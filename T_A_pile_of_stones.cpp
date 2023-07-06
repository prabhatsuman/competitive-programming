#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int res=0;
   
    for(int i=0; i<n; i++)
    {
        
        if(s[i]=='-')
        {
            res--;
        }
        else
        {
            res++;
        }
        if(res<0)res =0;

    }
    cout<<res;
    
    
    return 0;
}
