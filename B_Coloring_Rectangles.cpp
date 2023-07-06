#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    int m, n;
    cin >> m >> n;
    int ans1 = 0, ans2 = 0;
    if (m == 1)
    {
        if (n % 3 == 0)
        {
            cout << n / 3 << nline;
            return;
        }
        else
        {
            cout << (n / 3) + 1 << nline;
            return;
        }
    }
    if (n == 1)
    {
        if (m % 3 == 0)
        {
            cout << m / 3 << nline;
            return;
        }
        else
        {
            cout << (m / 3) + 1 << nline;
            return;
        }
    }
    if (n % 3 == 0)
    {
        ans1 = (n / 3) * m;
    }
    else
    {
        if (n % 3 == 1)
        {
            ans1 = (n / 3) * m;
            if (m % 3 == 0)
            {
                ans1 += m / 3;
            }
            else if (m % 3 == 1 || m % 3 == 2)
            {
                ans1 += m / 3;
                ans1++;
            }
        }
        else
        {
            ans1 = (n / 3) * m;
            if (m % 3 == 0)
            {
                ans1 += (m / 3) * 2;
            }
            else if (m % 3 == 1)
            {
                ans1 += (m / 3) * 2;
                ans1++;
            }
            else if (m % 3 == 2)
            {
                ans1 += (m / 3) * 2;
                ans1 += 2;
            }
        }
    }
    if (m % 3 == 0)
    {
        ans2 = (m / 3) * n;
    }
    else
    {
        if (m % 3 == 1)
        {
            ans2 = (m / 3) * n;
            if (n % 3 == 0)
            {
                ans2 += n / 3;
            }
            else if (n % 3 == 1 || n % 3 == 2)
            {
                ans2 += n / 3;
                ans2++;
            }
        }
        else
        {
            ans2 = (m / 3) * n;
            if (n % 3 == 0)
            {
                ans2 += (n / 3) * 2;
            }
            else if (n % 3 == 1)
            {
                ans2 += (n / 3) * 2;
                ans2++;
            }
            else if (n % 3 == 2)
            {
                ans2 += (n / 3) * 2;
                ans2 += 2;
            }
        }
    }

    cout << min(ans1, ans2) << nline;
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
