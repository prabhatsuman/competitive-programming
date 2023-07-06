#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    vector<ll> prefix(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        prefix[i] = sum;
    }
    ll res = sum;
    for (int i = 0; i < n; i++)
    {
        res = min(max(prefix[i], sum - prefix[i]), res);
    }
    cout << res << '\n';
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
