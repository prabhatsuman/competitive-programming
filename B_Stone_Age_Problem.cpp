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
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    map<ll, ll> m;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        m.insert({i + 1, v[i]});
    }
    ll second = -1;
    ll sc = -1;
    set<int> s;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll a;
            cin >> a;
            ll x;
            cin >> x;

            if (second == -1)
            {
                sum -= m[a];
                sum += x;
                m[a] = x;
            }
            else
            {
                if (s.find(a) == s.end())
                {
                    m[a] = sc;
                }
                s.insert(a);
                sum -= m[a];
                sum += x;
                m[a] = x;
            }
        }
        else
        {
            second = 1;
            ll x;
            cin >> x;
            sc = x;
            sum = x * n * 1LL;
            s.clear();
        }
        cout << sum << nline;
    }
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
