#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
const int M = 1000000000;


void solve()
{
    int n;
    cin >> n;
    if(powl(3,n-1)>powl(10,9))
    {
        cout<<"NO"<<'\n';
    }
    else
    {
        cout<<"YES"<<'\n';
        for(int i=0;i<n; i++)
        {
            int ans=pow(3,i);
            cout<<ans<<" ";
        }
        cout<<nline;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
