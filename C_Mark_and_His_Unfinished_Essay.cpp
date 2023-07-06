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
    ll n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    vector<ll> left(c + 1), right(c + 1), diff(c + 1);
    left[0] = 0;
    right[0] = n;

    for (int i = 1; i <= c; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        left[i] = right[i - 1];
        right[i] = left[i] + (b - a + 1);
        diff[i] = left[i] - a;
    }

    while (q--)
    {
        ll a;
        cin >> a;
        a--;
        for (int i = c; i >= 1; i--)
        {
            if (a < left[i])
                continue;
            else
                a -= diff[i];
        }
        cout<<s[a]<<nline;
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
