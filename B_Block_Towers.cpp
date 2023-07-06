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
    vector<ll> v;
    ll first = -1;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (first == -1)
        {
            first = x;
        }
        else if (x > first)
        {
            v.push_back(x);
        }
    }
    ll ans = first;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if ((v[i] - first) % 2 == 0)
        {
            ans += (v[i] - first) / 2;
            first += (v[i] - first) / 2;
        }
        else
        {
            ans += (v[i] - first) / 2 + 1;
            first += (v[i] - first) / 2 + 1;
        }
    }
    cout << ans << nline;
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
