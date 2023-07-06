#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll a, b, c;
    cin>>a>>b>>c;
    
    if(2*b==a+c)
    {
        cout<<"YES"<<'\n';
    }
    else if((2*b)>a+c)
    {
        if(((2*b)-c)%a==0)
        {
            cout<<"YES"<<'\n';

        }
        else if(((2*b)-a)%c==0)
        {
            cout<<"YES"<<'\n';
        }
        else
        {
            cout<<"NO"<<'\n';
        }
    }
    else 
    {
        if((a+c)%(2*b)==0)
        {
            cout<<"YES"<<'\n';
        }
        else
        {
            cout<<"NO"<<'\n';
        }
    }
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
