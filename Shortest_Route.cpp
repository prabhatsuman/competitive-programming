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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    vector<int> l(n + 1, INT_MAX);
    vector<int> r(n + 1, INT_MAX);
    int t = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            t = i;
        if (t != -1)
            l[i] = i - t;
    }
    t = -1;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 2)
            t = i;
        if (t != -1)
            r[i] = t - i;
    }
    for (int i = 1; i <= m; i++)
    {
        int c = b[i];
        if(c==1)
        {
            cout << 0 << " ";
            continue;
        }
        if (a[c] != 0)
        {
            cout << 0 << " ";
            continue;
        }
        if (l[c] == INT_MAX && r[c] == INT_MAX)
        {
            cout << -1 << " ";
            continue;
        }
        cout << min(l[c], r[c]) << " ";
    }
    cout << nline;
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
