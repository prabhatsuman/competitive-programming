#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    string s;
    cin >> s;
    if(count(s.begin(),s.end(),'N')==1)
    {
        cout<<"NO"<<'\n';

    }
    else
    {
        cout<<"YES"<<'\n';
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
