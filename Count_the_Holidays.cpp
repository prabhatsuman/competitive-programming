#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int res = 0;
    for (int i = 1; i <= 30; i++)
    {
        if (i % 7 == 0 || i % 7 == 6)
        {
            res++;
        }
    }
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 7 != 0 && v[i] % 7 != 6)
        {
            res++;
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
