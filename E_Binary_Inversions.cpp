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
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll ans1 = 0, ans2 = 0;
    vector<ll> a = v;
    vector<ll> b = v;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            a[i] = 1;
            break;
        }
    }
    ll dp[n];
    if (a[n - 1] == 0)
        dp[n - 1] = 1;
    else
        dp[n - 1] = 0;
    for (ll i = n - 2; i >= 0; i--)
    {
        if (a[i] == 0)
        {
            dp[i] = dp[i + 1] + 1;
        }
        else
        {
            dp[i] = dp[i + 1];
        }
    }
    for (ll i = 0; i < n - 1; i++)
    {
        if (a[i] == 1)
        {
            ans1 += dp[i];
        }
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        if (b[i] == 1)
        {
            b[i] = 0;
            break;
        }
    }
    // prll b
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << nline;
    ll ans3 = 0;
    if (b[n - 1] == 0)
        dp[n - 1] = 1;
    else
        dp[n - 1] = 0;
    for (ll i = n - 2; i >= 0; i--)
    {
        if (b[i] == 0)
        {
            dp[i] = dp[i + 1] + 1;
        }
        else
        {
            dp[i] = dp[i + 1];
        }
    }
    for (ll i = 0; i < n - 1; i++)
    {
        if (b[i] == 1)
        {
            ans2 += dp[i];
        }
    }
    if (v[n - 1] == 0)
        dp[n - 1] = 1;
    else
        dp[n - 1] = 0;
    for (ll i = n - 2; i >= 0; i--)
    {
        if (v[i] == 0)
        {
            dp[i] = dp[i + 1] + 1;
        }
        else
        {
            dp[i] = dp[i + 1];
        }
    }
    for (ll i = 0; i < n - 1; i++)
    {
        if (v[i] == 1)
        {
            ans3 += dp[i];
        }
    }
    cout << max(max(ans1, ans2), ans3) << nline;
    // // prll dp
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << nline;
    // cout << ans1 << nline;
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
