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
    string a, b;
    cin >> a >> b;
    if (n < m)
    {
        cout << "NO" << nline;
        return;
    }
    int j;
    bool f = true;

    for (int i = 1; i < m; i++)
    {
        if (a[n - m + i] != b[i])
        {
            f = false;
            break;
        }
    }
    if (!f)
    {
        cout << "NO" << nline;
        return;
    }

    for (int i = 0; i < n - m + 1; i++)
    {
        if (a[i] == b[0])
        {
            f = false;
            break;
        }
    }

    if (f)
    {
        cout << "NO" << nline;
    }
    else
    {
        cout << "YES" << nline;
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
