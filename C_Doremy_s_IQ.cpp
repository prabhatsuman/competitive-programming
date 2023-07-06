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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> res(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int q=0;

    for(int i=n-1;i>=0;i--)
    {

        if(a[i]<=q)
        {
            res[i]=1;
        }
        else if(a[i]>q && q<k)
        {
            res[i]=1;
            q++;
        }
        else
        {
            res[i]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<res[i];
    }
    cout<<nline;

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