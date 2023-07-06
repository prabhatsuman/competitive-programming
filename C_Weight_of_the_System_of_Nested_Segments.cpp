#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    ll n, m;
    cin >> n >> m;

    multimap<ll, pair<ll, ll>> m1;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        m1.insert({y, {x, i}});
    }
    ll count = 0;
    ll sum = 0;

    vector<pair<ll, ll>> res;
    for (auto &e : m1)
    {
        sum += e.first;
        count++;
        // cout<<e.second.first<<nline;

        res.push_back(e.second);

        if (count == 2 * n)
        {
            break;
        }
    }
    cout << sum << nline;
    sort(res.begin(), res.end());
    // cout<<res[0].first<<nline;
    for (int i = 0; i < n; i++)
    {
        cout << res[i].second << " " << res[2 * n - i - 1].second << nline;
    }
    cout << nline;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    cout << nline;
    while (t--)
    {
        solve();
    }
    return 0;
}
ll sum_of_digits(ll n)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
ll count_of_digits(ll n)
{
    ll count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
