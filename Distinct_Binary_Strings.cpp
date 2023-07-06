#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    char temp=s[0];
    int res=1;
    for(int i=0;i<n; i++)
    {
        if(temp!=s[i])
        {
            res++;
            temp=s[i];
        }
    }
    cout<<res<<'\n';
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
