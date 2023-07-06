#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
     ll n,s;
     cin>>n>>s;
     n*=n;
     ll res=s/n;
     cout<<res<<'\n';
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
