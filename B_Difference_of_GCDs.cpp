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
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> v(n + 1, 0);

    bool f = true;
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        if (l % i)
            x = (i * (l / i)) + i;
        else
            x = (i * (l / i));
        if (x <= r)
        {
            v[i] = x;
        }
        else
        {
            f = false;
        }
    }
    if (f)
    {
        cout << "YES" << nline;
        for (int i = 1; i <= n; i++)
        {
            cout << v[i] << " ";
        }
        cout << nline;
    }
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
