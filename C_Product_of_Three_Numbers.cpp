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
    cin>>n;

    int x=n;
    vector<int> a;
   //prime factors of n
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            a.push_back(i);
            n/=i;
        }
    }
  
    if(n>1)
    {
       
        a.push_back(n);
    }
    if(a.size()<3)
    {
        cout<<"NO"<<nline;
    }
    else if(a[1]==n)
    {
        cout<<"NO"<<nline;
    }
    else
    {
        cout<<"YES"<<nline;
        cout<<a[0]<<" "<<a[1]<<" "<<x/(a[0]*a[1])<<" "<<nline;
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
