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
    string s;
    cin >> s;
    vector<int> w;

    int c = 0;
    // w.push_back(0);

    for (int i = 0; i < n; i++)
    {

        if (s[i] == 'W')
        {
            c++;
        }
        w.push_back(c);
    }
    // cout<<w.size()<<nline;
    if (k == n)
    {
        cout << c << nline;
        return;
    }
    int ans = w[k - 1];
    for (int i = k; i < n; i++)
    {
        ans = min(w[i] - w[i - k], ans);
    }
    if (ans <= 0)
    {
        cout << 0 << nline;
    }
    else
        cout << ans << nline;
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
