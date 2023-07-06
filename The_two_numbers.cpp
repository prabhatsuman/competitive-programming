#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
void solve()
{
    ll n;
    cin >> n;
    ll i = n;
    ll a, b, ans;
    if (n == 2)
    {

        cout << 0 << nline;
        return;
    }

    if (n % 2 == 1)
    {
        a = n / 2;
        b = n / 2 + 1;
        ans = lcm(a, b) - gcd(a, b);
    }
    else
    {
        if ((n / 2) % 2 == 0)
        {
            a = n / 2 - 1;
            b = n / 2 + 1;
        }
        else
        {
            a = n / 2 - 2;
            b = n / 2 + 2;
        }
        ans = lcm(a, b) - gcd(a, b);
    }
    cout << ans << nline;
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
