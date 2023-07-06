#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    ll res = 0;
    unordered_set<ll> s;
    for (ll i = 1; i * i <= n; i++)
    {
        s.insert(i*i);
    }
    for (ll i = 1; i * i * i <= n; i++)
    {
        s.insert(i*i*i);
    }
    cout << s.size() << '\n';
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
