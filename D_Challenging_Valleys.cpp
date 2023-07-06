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
    vector<int> a;
    int r = -1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x != r)
            a.push_back(x);
        r = x;
    }

    int count = 0;
    n = a.size();
    if (n == 1)
    {
        cout << "YES" << nline;
        return;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i - 1] > a[i] && a[i] < a[i + 1])
            count++;
    }
    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << nline;
    // cout << "count: " << count << nline;

    if (a[1] > a[0])
        count++;
    if (a[n - 1] < a[n - 2])
        count++;
    if (count == 1)
    {
        cout << "YES" << nline;
    }
    else
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
