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
    ll n, c, d;
    cin >> n >> c >> d;
    vector<ll> v(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<ll>());
    for (int i = 0; i < min(d, n); i++)
    {
        sum += v[i];
    }
    if (v[0] * d < c)
    {
        cout << "Impossible" << nline;
        return;
    }
    if (sum >= c)
    {
        cout << "Infinity" << nline;
        return;
    }
    ll lo = 0, hi = d;
    ll ans = -1;
    while (lo<hi)
    {

        ll k = (lo + hi) / 2;
        ll sum1 = 0;
        ll q = d / (k + 1);
        // cout<<"k : "<<k<<nline;
        // cout<<"q : "<<q<<nline;
        for (int i = 0; i < min(k + 1, n); i++)
        {
            sum1 += (v[i] * q);
        }
        ll rem = d % (k + 1);
        for (int i = 0; i < min(rem, n); i++)
        {
            sum1 += v[i];
        }
        // cout << "sum1 : " << sum1 << nline;
        if (sum1 >= c)
        {
            lo = k + 1;
            ans = k;
        }
        else
        {
            hi = k;
        }
        // cout<<"lo : "<<lo<<" hi : "<<hi<<nline;
    }
    //  cout<<"lo : "<<lo<<" hi : "<<hi<<nline;
    ll sum1 = 0;
    ll q = d / (lo + 1);
    // cout<<"k : "<<k<<nline;
    // cout<<"q : "<<q<<nline;
    for (int i = 0; i < min(lo + 1, n); i++)
    {
        sum1 += (v[i] * q);
    }
    ll rem = d % (lo + 1);
    for (int i = 0; i < min(rem, n); i++)
    {
        sum1 += v[i];
    }
    ll sum2 = 0;
    q = d / (hi + 1);
    // cout<<"k : "<<k<<nline;
    // cout<<"q : "<<q<<nline;
    for (int i = 0; i < min(hi + 1, n); i++)
    {
        sum2 += (v[i] * q);
    }
    rem = d % (hi + 1);
    for (int i = 0; i < min(rem, n); i++)
    {
        sum2 += v[i];
    }
    // cout<<"sum1 : "<<sum1<<nline;
    // cout<<"sum2 : "<<sum2<<nline;
    if (sum2 >= c)
    {
        cout << hi << nline;
    }
    else
    {
        cout << ans << nline;
    }
    // cout << "sum1 : " << sum1 << nline;
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
