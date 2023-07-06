#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);

void solve()
{
   int m,n;
   cin>>m>>n;
   if(abs(m-n)>1 && (m==1 || n==1) )
   {
       cout<<"-1"<<nline;
       return;
   }
//    if (m==1 && n!=1)
//    {
//         cout<<"-1"<<nline;
//        return;
//    }
   if(m==n)
   {
       cout<<2*m-2<<nline;
   }
   else
   {
       int x=max(m,n);
       if((m%2 && n%2==0) || (n%2 && m%2==0))
       {
           cout<<2*x-3<<nline;
       }
       else
       {
           cout<<2*x-2<<nline;
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
