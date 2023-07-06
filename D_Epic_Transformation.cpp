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
    map<ll, ll> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    priority_queue<ll> pq;
    for (auto i : m)
    {
        pq.push(i.second);
    }
    ll ans = n;
    while (pq.size() > 1)
    {
        ll a = pq.top();
        pq.pop();
        a--;
        ans--;
        ll b = pq.top();
        pq.pop();
        b--;
        ans--;
        if (a > 0)
        {
            pq.push(a);
        }
        if (b > 0)
        {
            pq.push(b);
        }
    }
    cout << ans<<nline;
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
