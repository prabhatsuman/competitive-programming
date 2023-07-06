#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    multimap<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m.insert({a[i], b[i]});
    }
    for (auto &e : m)
    {
        if (e.first <= k)
        {
            k += e.second;
        }
    }
    cout << k << '\n';
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
