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
    vector<int> v(n + 1);
    int a = 1, b = 2;
    if (n % 2 == 0)
    {

        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                v[i] = a;
                a += 2;
            }
            else
            {
                v[i] = b;
                b += 2;
            }
        }
    }
    else
    {
        int i;
        for (i = 1; i < n; i++)
        {
            if (i % 2 == 0)
            {
                v[i] = a;
                a += 2;
            }
            else
            {
                v[i] = b;
                b += 2;
            }
        }
        v[i] = a;
        if (n > 1)
            swap(v[i], v[i - 1]);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << " ";
    }
    cout << nline;
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
