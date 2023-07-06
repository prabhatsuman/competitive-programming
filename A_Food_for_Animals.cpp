#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    bool f1 = false, f2 = false;
    if (a >= x)
        f1 = true;
    else
    {
        if (x - a <= c)
        {
            f1 = true;
            c = c - (x - a);
        }
    }
    if (b >= y)
        f2 = true;
    else
    {
        if (y - b <= c)
        {
            f2 = true;
            c = c - (y - b);
        }
    }
    if(f1 && f2)
    
    {
        cout<<"YES"<<nline;
    }
    else
    {
        cout<<"NO"<<nline;
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
