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
        cin >> v[i];
    vector<ll> op(n);
    op[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        op[i] = v[i] + op[i - 1];
    }
    // for(int i=0;i<n;i++){
    //     cout<<op[i]<<" ";
    // }
    // cout<<nline;
    bool f = true;
    for (int i = 0; i < n; i++)
    {
        if (op[i] < 0 && i!=n-1)
        {
            f = false;
            //  break;
        }  
        if(i==n-1 && op[i]!=0)
        {
            f=false;
        }
    }
    bool c1 = false;
    for (int i = 0; i < n; i++)
    {
        if (op[i] == 0)
            c1 = true;
        if (c1 && op[i] != 0)
            f = false;
    }
    if (f)
        cout << "Yes" << nline;
    else
        cout << "No" << nline;
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
