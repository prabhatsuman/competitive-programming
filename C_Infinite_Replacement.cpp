#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
   string s;
   cin>>s;
   string b;
   cin>>b;
   map<char,int> a1,b1;
   for(int i=0; i<s.length(); i++)
   {
       a1[s[i]]++;
   }
   for(int i=0; i<b.length(); i++)
   {
       b1[b[i]]++;
   }
  
   if(b1['a']>0 && b.length()>1)
   {
       cout<<"-1"<<nline;
       return;
   }
   if(b1['a']==1 && b.length()==1)
   {
       cout<<1<<nline;
       return;
   }
   if(b1['a']==0)
   {
       ll ans=pow(2,a1['a']);
       cout<<ans<<nline;
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
