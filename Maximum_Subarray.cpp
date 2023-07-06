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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll m;
    cin >> m;
    vector<ll> b(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    ll pos = 0, neg = 0;
    ll m1 = LLONG_MIN;
    for (ll i = 0; i < m; i++)
    {
        if (b[i] > 0)
        {
            pos += b[i];
        }
        else
        {
            neg += b[i];
        }
        m1 = max(m1, b[i]);
    }

    ll add1 = 0, add2 = 0;
    if (pos == 0)
    {
        add1 = m1;

        add2 = neg - m1;
    }
    else
    {
        add1 = pos;
        add2 = neg;
    }
    vector<ll> c1;
    vector<ll> c2;
    for (int i = 0; i < n; i++)
    {
        c1.push_back(a[i]);
    }

    c1.push_back(add1);
    c2.push_back(add1);
    for (int i = 0; i < n; i++)
    {
        c2.push_back(a[i]);
    }
    // apply kadane's algorithm on c1 and c2 and find max
    ll max1 = LLONG_MIN;
    ll max2 = LLONG_MIN;
    ll max_so_far = 0;
    for (int i = 0; i < c1.size(); i++)
    {
        max_so_far += c1[i];
        if (max_so_far < 0)
        {
            max_so_far = 0;
        }
        max1 = max(max1, max_so_far);
    }
    max_so_far = 0;
    for (int i = 0; i < c2.size(); i++)
    {
        max_so_far += c2[i];
        if (max_so_far < 0)
        {
            max_so_far = 0;
        }
        max2 = max(max2, max_so_far);
    }
    cout << max(max1, max2) << nline;
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
