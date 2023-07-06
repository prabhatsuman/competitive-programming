#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < n; i++)
    {
        ll sum = 0, preffix = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            preffix += v[j] - preffix % v[j];
            sum += preffix / v[j];
        }
        preffix = 0;
        for (int j = i + 1; j < n; j++)
        {
            preffix += v[j] - preffix % v[j];
            sum += preffix / v[j];
        }
        ans = min(ans, sum);
    }
    cout<<ans<<nline;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
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
ll power(int a, int b)
{
    if (b == 0)
        return 1;
    int res = power(a, b / 2);
    if (b & 1)
    {
        return (a * (res * res) % M) % M;
    }
    else
    {
        return (res * res) % M;
    }
}
