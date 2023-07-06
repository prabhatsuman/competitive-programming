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
    int a, b;
    cin >> a >> b;
    int p,q,r,s;
   // cout<<(2^3^4^5)<<nline;
    bool f=false;
    for(int i=a; i<=b; i++)
    {
        p=i,q=i+1,r=i+2,s=i+3;
        if((p^q^r^s)==0 && s<=b)
        {
            f=true;
            cout<<p<<" "<<q<<" "<<r<<" "<<s<<nline;
            return;
        }

    }
    if(f==false)
    {
        cout<<-1<<nline;
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
