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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll a = v[0], b = v[1];
    for (int i = 0; i < n; i += 2)
    {
        a = __gcd(a, v[i]);
    }
    for (int i = 1; i < n; i += 2)
    {
        b = __gcd(b, v[i]);
    }
    bool f1=true,f2=true;
    for(int i=0;i<n-1;i++)
    {
        if(v[i]%a==0 && v[i+1]%a==0)
        {
            f1=false;
            break;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        if(v[i]%b==0 && v[i+1]%b==0)
        {
            f2=false;
            break;
        }
    }
    if(f1 == true)
    {
        cout<<a<<nline;
    }
    else if(f2==true)
    {
        cout<<b<<nline;
    }
    else 
    {
        cout<<0<<nline;
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
