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
    int x;
    cin >> x;
    vector<int> v;
    v.push_back(x);
    for (int i = 0; i < 3; i++)
    {
        int a;
        cin >> a;
        if (a != 0)
            v.push_back(a);
    }

    bool f = false;
    for (int i = 0; i < 2; i++)
    {
        if (v[i] == 3)
        {
            if (v[i + 1] == 1 || v[i + 1] == 2)
                f = true;
            else
                break;
        }
        else
        {
            if (v[i + 1] == v[i] + 1)
                f = true;
            else
                break;
        }
    }
    if (f)
        cout << "YES" << nline;
    else
        cout << "NO" << nline;
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
