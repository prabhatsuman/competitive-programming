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
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<ll> p1(n + 1, 0), p2(n + 1, 0);
    ll s1 = 0, s2 = 0;
    for (int i = 1, j = n; i<n, j> 1; i++, j--)
    {
        if (v[i] > v[i + 1])
        {
            s1 += v[i] - v[i + 1];
        }
        p1[i + 1] = s1;

        if (v[j] > v[j - 1])
        {

            s2 += v[j] - v[j - 1];
        }
        p2[j - 1] = s2;
    }
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (b > a)
        {
            cout << abs(p1[b] - p1[a]) << nline;
        }
        else
        {
            cout << abs(p2[a] - p2[b]) << nline;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
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
