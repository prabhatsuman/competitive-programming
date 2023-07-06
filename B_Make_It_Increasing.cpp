#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll count = 0;
    ll m = v[n - 1];
    bool f = true;
    for (int i = n-2; i >=0; i--)
    {
        if (v[i] < m)
        {
            m = v[i];
        }
        else
        {
            if (m == 0)
            {
                f = false;
                break;
            }
            while (v[i] >= m)
            {
                count++;
                v[i] /= 2;
            }
            m = v[i];
        }
    }
    if (f)
    {
        cout << count << nline;
    }
    else
    {
        cout << -1 << nline;
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
