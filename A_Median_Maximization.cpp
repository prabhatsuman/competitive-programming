#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n,s;
    cin>>n>>s;
    int mid=(n/2)+(n%2);
    int div= n-mid+1;
    cout<<s/div<<'\n';

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
