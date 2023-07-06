#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
vector<bool> isPrime(M, 1);
void seive();

void solve()
{
    int n, m, x, y, d;
    cin >> n >> m >> x >> y >> d;

    bool f1 = false, f2 = false, f3 = false, f4 = false, flag = true;
    for (int i = 1; i <= m; i++)
    {
        if (abs(y - i) + abs(1 - x) <= d)
            f1 = true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (abs(x - i) + abs(1 - y) <= d)
            f2 = true;
    }
    if (f1 && f2)
    {
        flag = false;
    }
    if (!f2)
    {

        for (int i = 1; i <= m; i++)
        {
            if (abs(y - i) + abs(n - x) <= d)
                f3 = true;
        }
    }
    if (!f1)
    {

        for (int i = 1; i <= n; i++)
        {
            if (abs(x - i) + abs(m - y) <= d)
                f4 = true;
        }
    }
    if (flag == false)
        cout << -1 << nline;
    else if (!f1 && f4)

    {
        if (f2)
            cout << -1 << nline;
        else
        {
            if (f3)
            {
                cout << -1 << nline;
            }
            else
            {
                cout << n + m - 2 << nline;
            }
        }
    }
    else if (!f2 && f3)
    {
        if (f1)
            cout << -1 << nline;
        else
        {
            if (f4)
            {
                cout << -1 << nline;
            }
            else
            {
                cout << n + m - 2 << nline;
            }
        }
    }
    else
        cout << n + m - 2 << nline;
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

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= M; i++)
    {
        if (isPrime[i] == true)
        {
            for (ll j = i * i; j <= M; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}