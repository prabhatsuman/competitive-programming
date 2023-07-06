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
   map<int,int> m;
   bool flag=false;
   for(int i=0;i<n; i++)
   {
       int temp;
       cin>>temp;
       m[temp]++;
   }
   int i=0;
   for(auto &e : m)
   {
       if(e.second>=3)
       {
           i=e.first;
           flag=true;
           break;
       }
   }
   if(flag)
   {
       cout<<i<<nline;
   }
   else
   {
       cout<<"-1"<<nline;
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
