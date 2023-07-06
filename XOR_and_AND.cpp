#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // sort(v.begin(), v.end());
    vector<ll> l;
    for (int i = 0; i < n; i++)
    {
        l.push_back(log2(v[i]) + 1);
    }
    // for (auto &e : l)
    // {
    //     cout << e << " ";
    // }
    // cout << nline;
    map<ll, ll> m;
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        m[l[i]]++;
    }
    for (auto &e : m)
    {
        ll temp = e.second;
        res += (temp * (temp - 1)) / 2;
    }

    cout << res << nline;
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
