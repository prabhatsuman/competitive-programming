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
    int r = n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    int k = -1;
    for (auto &e : m)
    {
        if(e.second>2)
        {
            k=1;
        }
        if (e.second > 1)
        {
            n -= e.second;
        }
    }
    int ans = 0;
    if (n % 2 == 1)
        ans = n / 2 + 1;

    else
        ans = n / 2;
    // cout<<(--m.end())->second<<nline;
   // cout<<ans<<nline;
    if ((--m.end())->second == 1 && k==-1 && n==1)
    {
        cout << ans+1  << nline;
    }
   else
     cout<<ans<<nline;
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
