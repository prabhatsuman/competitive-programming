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
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    if (x % ((k - 1) * n + (m+n)) == 0)
    {
        cout << "YES" << nline;
    }
    else
    {
        int q = x / ((k - 1) * n + (m+n));
        int t = q * ((k - 1) * n + (m+n));
        // t-=m;
        
        t+=(k-1)*n;
       
       
        if (x > t && x <= t + m+n)
        {
            cout << "YES" << nline;
        }
        else
        {
            cout << "NO" << nline;
        }
       
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
