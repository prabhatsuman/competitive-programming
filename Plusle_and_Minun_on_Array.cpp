#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] = abs(v[i]);
    }
    ll sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += (pow(-1, i) * v[i]);
    }
    ll min_add = LLONG_MAX;
    ll max_sub = LLONG_MIN;

    for (int i = 0; i < n; i += 2)
    {
        min_add = min(min_add, v[i]);
    }
    for (int i = 1; i < n; i += 2)
    {
        max_sub = max(max_sub, v[i]);
    }
    auto i = find(v.begin(), v.end(), min_add);
    auto j = find(v.begin(), v.end(), max_sub);
    // cout << *i << " " << *j << '\n';
    iter_swap(i, j);
    // for (auto &e : v)
    // {
    //     cout << e << " ";
    // }
    ll sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum2 += (pow(-1, i) * v[i]);
    }
    cout << max(sum1, sum2) << '\n';
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
