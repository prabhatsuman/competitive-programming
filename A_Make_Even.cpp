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
   int n=s.length();

   bool even=false;
   for(int i=0; i<n; i++)
   {
       if((s[i]-'0')%2==0)
       {
           even=true;
           break;
       }

   }
   if((s[n-1]-'0')%2==0)
   {
       cout<<0<<nline;
       return;
   }
   if(!even)
   {
       cout<<-1<<nline;
   }
   else
   {
       if((s[0]-'0')%2==0)
       {
           cout<<1<<nline;
       }
       else
       {
           cout<<2<<nline;
       }
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
