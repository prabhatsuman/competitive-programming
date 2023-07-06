#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    string s;
    cin>>s;
    ll n =s.length();
   
    map<char,int> m;
    for(int i=0; i<n; i++)
    {
        m[s[i]]++;
    }
    if((m['0']!=0 && m['1']!=0) && m['0']!=m['1'])
    {
        if(m['0']>m['1']) cout<<m['1']<<'\n';
        else if (m['0']<m['1']) cout<<m['0']<<'\n';
        
    }
    else if((m['0']!=0 && m['1']!=0) && m['0']==m['1'])
    {
        char temp;
        temp=s[n-1];
     
    
        if(m[temp]-1==0)
        {
            cout<<"0"<<'\n';
        }
        else
        {
            cout<<m[temp]-1<<'\n';
        }
    }
    else if (m['0']==0 || m['1']==0)
    {
        cout<<"0"<<'\n';
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
       solve();
    }
    return 0;
}
