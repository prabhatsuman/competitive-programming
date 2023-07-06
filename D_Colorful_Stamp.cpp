#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += "W";
    int a = 0, b = 0;
    bool f = true;
    for (int i = 0; i <= n; i++)
    {
        if (s[i] == 'R')
            a = 1;
        else if (s[i] == 'B') b = 1;
        if (s[i] == 'W' && a + b == 1)
            f = false;
        if (s[i] == 'W')
        {
            a = 0, b = 0;
        }
    }
    if(f)
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
