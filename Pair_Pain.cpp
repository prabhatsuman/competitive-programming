#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> m;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]]++;
    }
    ll res = 0;
    res = (m[1] * (n - m[1]));
    if (m[1] > 1)
        res += (m[1] * (m[1] - 1)) / 2;
    if (m[2] > 1)
        res += (m[2] * (m[2] - 1)) / 2;
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
