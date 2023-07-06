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
   vector<int> v(n);
   for(int i=0; i<n; i++)
   {
       cin>>v[i];
   } 
   int i=0;
   int j=n-1;
   map<int,int> m;
   int ans=n;
   for(int k=0; k<n; k++)
   {
       j=n-k-1;
       int temp;
       i=max((m.find(v[k])!=m.end() ? temp=m[v[k]]: temp=0),i);
       m[v[k]]=k+1;
       ans=min((min(i,j)+j+i),ans);

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
