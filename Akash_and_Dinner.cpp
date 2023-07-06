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
    ll n, k;
    cin >> n >> k;
    map<ll, ll> m;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m.insert({a[i], INT_MAX});
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        m[a[i]] = min(m[a[i]], b[i]);
    }
    if(m.size()<k)
    {
        cout<<-1<<nline;
        return;
    }
    // print map
    vector<ll> v;
    for (auto i : m)
    {
        v.push_back(i.second);
    }
    sort(v.begin(), v.end());
    ll sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += v[i];
        
    }
    cout << sum << nline;
    // cout << nline;
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
