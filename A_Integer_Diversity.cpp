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
   cin>>n;
   int ans =n;
   map<int,int> m;
   for(int i=0; i<n; i++)
   {
       int temp;
       cin>>temp;
       m[abs(temp)]++;
   }
   for(auto &e: m)
   {
       if(e.second>2 && e.first!=0)
       {
           ans-=e.second;
           ans+=2;
       }
       if(e.first==0)
       {
          ans-=e.second;
          ++ans;
       }
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
