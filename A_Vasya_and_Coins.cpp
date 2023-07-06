#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
void solve()
{

    int a,b;
    cin>>a>>b;
    if(a==0)
    {
        cout<<1<<nline;
        return;

    }
    
    cout<<(2*b+a)+1<<nline;
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
