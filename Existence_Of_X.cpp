#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
bool ith_bit(int n, int i)
{
    return (n >> i) & 1;
}
bool bitsum(bool a, bool b, bool c)
{
    return (a ^ b ^ c);
}
bool bitcarry(bool a, bool b, bool c)
{
    return ((a ^ b) & c) + (a & b);
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int carry = 0;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 32; i++)
    {
        int ai = ith_bit(a, i);
        int bi = ith_bit(b, i);
        int ci = ith_bit(c, i);
        sum1 = bitsum(ai ^ 0, bi ^ 0, carry);
        int aix = ai ^ 1;
        int bix = bi ^ 1;
        int cix = ci ^ 1;
        sum2 = bitsum(aix, bix, carry);
        if (sum1 == ci)
        {
            carry = bitcarry(ai, bi, carry);
        }
        else if (sum2 == cix)
        {
            carry = bitcarry(aix, bix, carry);
        }
        else
        {
            break;
        }
    }
    if (carry == 0)
    {
        cout << "YES" << nline;
    }
    else
    {
        cout << "NO" << nline;
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
