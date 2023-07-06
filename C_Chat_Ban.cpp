#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
ll ksum(ll x)
{
    return x  * (x + 1) / 2;
}
void solve()
{
    ll k, x;
    cin >> k >> x;
    ll l = 1, r = 2 * k - 1;
    ll res = 2 * k - 1;

    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (mid >= k)
        {
            if (ksum(k) + ksum(k - 1) - ksum(2 * k - 1 - mid) >= x)
            {

                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (ksum(mid) >= x)

            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    cout << res << nline;
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
