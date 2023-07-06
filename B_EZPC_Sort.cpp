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
   int p=-1,c=-1,z=-1,e=-1;
   for(int i=0; i<n; i++)
   {
       if(s[i]=='p')
       {
           p=i;
       }
       else if(s[i]=='c')
       {
           c=i;
       }
       else if(s[i]=='z')
       {
           z=i;
       }
       else if(s[i]=='e')
       {
           e=i;
       }
   }
   if(p>c || p<z || e>c)
   {
       cout<<"NO"<<nline;
   }
   else
   {
       cout<<"YES"<<nline;
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
