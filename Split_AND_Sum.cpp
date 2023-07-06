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
    vector<int> v(n);
    ll sum = 0;
    vector<ll> prefix(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        prefix[i] = sum;
    }
    int i = 0, j = n - 1;
    bool f = false;
    while (i < j)
    {
        ll a = prefix[i];
        ll b = prefix[j] - prefix[i];
        if (a & b)
        {
            f = true;
            cout << "YES" << nline;
            cout << 2 << nline;
            cout << 1 << " " << i+1 << nline;
            cout << i+2 << " " << j+1 << nline;
            return;
        }
        i++;
        j--;
    }
    if (f == false)
    {
        cout << "NO" << nline;
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
