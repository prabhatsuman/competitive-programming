#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    ll m, n;
    cin >> m >> n;
    vector<ll> v(m);
    ll sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++)
    {
        sum += v[i];
    }

    // cout<<sum<<nline;
    if (sum + m - v[0] + v[m - 1] <= n)
        cout << "YES" << nline;
    else
    {
        cout << "NO" << nline;
    }
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
