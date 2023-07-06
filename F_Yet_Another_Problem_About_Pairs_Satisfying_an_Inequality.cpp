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
    {
        cin >> v[i];
    }
    vector<ll> r1,r2;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < i + 1)
        {
            r1.push_back(i+1);
            r2.push_back(v[i]);
        }
    }
    sort(r2.begin(), r2.end());
    ll ans = 0;
    int t = r1.size();
    for (int i = 0; i < t; i++)
    {
        ll x = r1[i];
        auto it = upper_bound(r2.begin(), r2.end(), x);
        ans += (it - r2.end());
    }
    cout<<abs(ans)<<nline;
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
