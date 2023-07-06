#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
vector<ll> sqr;

void solve()
{

    ll n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        a.push_back(i);
    }
    vector<int> b = a;
    int j = n - 1;
    while (j >= 0)
    {
        int c1 = a[j];
        int x = *lower_bound(sqr.begin(), sqr.end(), c1);
      //  cout<<x<<nline;
        int d = x - c1;
        reverse(b.begin() + d, b.begin() + c1 + 1);
        j = d - 1;
    }
    for (auto &e : b)
    {
        cout << e << " ";
    }
    cout << nline;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    for (int i = 0; i*i <= 2e5; i++)
    {
        sqr.push_back(i * i);
    }
    // for(auto &e: sqr)
    // {
    //     cout<<e<<" ";
    // }
    // cout<<nline;
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
