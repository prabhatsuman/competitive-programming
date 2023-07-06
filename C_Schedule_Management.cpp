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
    vector<int> v(n, 0);

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        x--;
        v[x]++;
    }

    sort(v.begin(), v.end());

    ll lo = 0, hi = m;

    while (lo < hi)
    {
        ll mid = ((hi + lo) / 2);

        // cout << mid << nline;
        ll temp = 0, x = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] <= mid)
            {
                temp += (mid - v[i]) / 2;
            }
            else
            {
                x += (v[i] - mid);
            }
        }
        //     cout << "temp"
        //          << " " << temp << " mid " << mid << nline;
        //    cout<<hi<<" "<<lo<<nline;
        if (temp >= x)
        {

            hi = mid;
        }
        // else

        else
        {
            lo = mid + 1;
        }
        // if (hi == mid)
        // {
        //     break;
        // }

        // if (c == 0)
        // {
        //     break;
        // }
        // c--;
    }

    cout << lo << nline;
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
