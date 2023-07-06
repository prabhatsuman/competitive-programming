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
    int n;
    cin >> n;
    char a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    // cout<<"hi"<<nline;
    ll ans = 0;
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            ll c0 = 0, c1 = 0;
            (a[i][j] == '1') ? c1++ : c0++;
            (a[j][n-i-1] == '1') ? c1++ : c0++;
            (a[n - i - 1][n - j - 1] == '1') ? c1++ : c0++;
            (a[n - j - 1][i] == '1') ? c1++ : c0++;
            ans += min(c0, c1);
            
        }
    }
    cout << ans/4 << nline;
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
