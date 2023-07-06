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
   vector<int> v(n);
   for(int i=0; i<n; i++)
   {
       cin>>v[i];
   }
   bool f1=false,f2=false;
   int i1=v[0]%2,i2=v[1]%2;
   for(int i=0; i<n; i+=2)
   {
       if((v[i]%2)!=i1)
       {
           f1=true;
           break;
       }
   }
   for(int i=1; i<n; i+=2)
   {
       if((v[i]%2)!=i2)
       {
           f2=true;
           break;
       }
   }
   if(f1 || f2)
   {
       cout<<"NO"<<nline;
   }
   else{
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
