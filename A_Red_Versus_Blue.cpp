#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
   int n,a,b;
   cin>>n>>a>>b;
   int p=a/(b+1);
   int q=a%(b+1);
   for(int i=0; i<q; i++)
   {
       cout<<string(p+1,'R')<<'B';
   }
   for(int i=q; i<b;i++)
   {
       cout<<string(p,'R')<<'B';
   }
   cout<<string(p,'R');
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
    ll sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
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
