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

    ll n, i, j, s1, s2, s3, s4, c, s5, s6, s7;

    cin >> n;

    ll a[n], b[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    s1 = abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]);
    s2 = abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]);

    s3 = abs(a[0] - b[0]);

    c = 100000000000;
    for (i = 0; i < n; i++)
    {
        c = min(c, abs(a[n - 1] - b[i]));
    }

    s3 = s3 + c;

    c = 100000000000;
    for (i = 0; i < n; i++)
    {
        c = min(c, abs(b[n - 1] - a[i]));
    }

    s3 = s3 + c;

    s4 = abs(a[n - 1] - b[n - 1]);

    c = 100000000000;
    for (i = 0; i < n; i++)
    {
        c = min(c, abs(a[0] - b[i]));
    }

    s4 = s4 + c;

    c = 100000000000;
    for (i = 0; i < n; i++)
    {
        c = min(c, abs(b[0] - a[i]));
    }

    s4 = s4 + c;

    s5 = 0;

    c = 100000000000;
    for (i = 0; i < n; i++)
    {
        c = min(c, abs(b[0] - a[i]));
    }
    s5 = s5 + c;

    c = 100000000000;
    for (i = 0; i < n; i++)
    {
        c = min(c, abs(a[0] - b[i]));
    }
    s5 = s5 + c;

    c = 100000000000;
    for (i = 0; i < n; i++)
    {
        c = min(c, abs(b[n - 1] - a[i]));
    }
    s5 = s5 + c;

    c = 100000000000;
    for (i = 0; i < n; i++)
    {
        c = min(c, abs(a[n - 1] - b[i]));
    }
    s5 = s5 + c;

    s6 = abs(a[0] - b[n - 1]);

    c = 100000000000;
    for (i = 0; i < n; i++)
    {
        c = min(c, abs(a[n - 1] - b[i]));
    }

    s6 = s6 + c;

    c = 100000000000;
    for (i = 0; i < n; i++)
    {
        c = min(c, abs(b[0] - a[i]));
    }

    s6 = s6 + c;

    s7 = abs(a[n - 1] - b[0]);

    c = 100000000000;
    for (i = 0; i < n; i++)
    {
        c = min(c, abs(a[0] - b[i]));
    }

    s7 = s7 + c;

    c = 100000000000;
    for (i = 0; i < n; i++)
    {
        c = min(c, abs(b[n - 1] - a[i]));
    }

    s7 = s7 + c;

    cout << min(s1, min(s2, min(s3, min(s4, min(s5, min(s6, s7)))))) << "\n";

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
