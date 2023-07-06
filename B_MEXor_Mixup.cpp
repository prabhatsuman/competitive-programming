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

    int a, b;
    cin >> a >> b;
    int pXor;
    if (a % 4 == 1)
    {
        pXor = a - 1;
    }
    else if (a % 4 == 2)
    {
        pXor = 1;
    }
    else if (a % 4 == 3)
    {
        pXor = a;
    }
    else
    {
        pXor = 0;
    }

    if (pXor == b)
    {
        cout << a << '\n';
    }
    else if ((pXor ^ b) != a)
    {
        cout << a + 1 << '\n';
    }
    else
    {
        cout << a + 2 << '\n';
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
