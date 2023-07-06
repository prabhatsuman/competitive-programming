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
   if(n%2)
   {
       cout<<"NO"<<nline;
   }
   else
   {
       string s1="";
       string s2="";
       for(int i=0; i<n/2;i++)
       {
           s1+=s[i];
       }
       for(int i=n/2; i<n; i++)
       {
           s2+=s[i];
       }
       if(s1==s2)
       {
           cout<<"YES"<<nline;
       }
       else
       {
           cout<<"NO"<<nline;
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
