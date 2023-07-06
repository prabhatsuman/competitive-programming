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
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        m[a].push_back(i);
    }

    // for (auto &e : m)
    // {
    //     cout << e.first << " ";
    //     for (auto v : e.second)
    //     {
    //         cout << v << " ";
    //     }
    //     cout << nline;
    // }
    // cout<<m.size()<<nline;
    while (k--)
    {
        int b, c;
        cin >> b >> c;
        // cout<<b<<nline;
        int x;
        if (m.find(b) != m.end())
            x = m[b].front();
        else

        {
            cout << "NO" << nline;
            continue;
        }

        // cout<<it<<",x"<<nline;
        bool f = false;
        if (m.find(c) != m.end())
        {
            if (m[c].back() >= x)
                f = true;
        }
        if (f)
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
