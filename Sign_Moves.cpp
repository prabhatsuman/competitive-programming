#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
void solve()
{
    int n;
    cin>>n;
    if(n%2==0)
    {
        cout<<n/2<<'\n';
    }
    else
    {
        cout<<-(n/2+1)<<nline;
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
