#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    int sum=0;
    for(int i=0; i<n ; i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    cout<<sum<<nline;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    
    while(t--)
    {
       solve();
    }
    return 0;
}
