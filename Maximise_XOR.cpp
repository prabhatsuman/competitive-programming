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
    string a;
    cin >> a;
    string b;
    cin >> b;
    int n = a.length();
    int m = b.length();
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '0')
        {
            c0++;
        }
        else
        {
            c1++;
        }
    }
    int d0 = 0, d1 = 0;
    for (int i = 0; i < m; i++)
    {
        if (b[i] == '0')
        {
            d0++;
        }
        else
        {
            d1++;
        }
    }
    string ans = "";
    for(int i=0;i<min(c1,d0);i++){
        ans+="1";
    }
    for(int i=0;i<min(d1,c0);i++){
        ans+="1";
    }
    for(int i=ans.length();i<n;i++){
        ans+="0";
    }
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
