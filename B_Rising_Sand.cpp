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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if(k==1)
    {
        cout<<(n-1)/2<<nline;
        return;
    }
    ll sum = 0;
    vector<int> sums(n, 0);
    for (int i = 1; i < n - 1; i++)
    {
        if (v[i] > (v[i - 1] + v[i + 1]))
        {
            sum++;
        }
       // sums[i] = sum;
    }
    // sums[n - 1] = sum;
    // int ans = 0;
    // for (int i = k ;i < n; i++)
    // {
    //     ans = max(ans, sums[i] - sums[i - k ]);
    // }
    cout<<sum<<nline;
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
