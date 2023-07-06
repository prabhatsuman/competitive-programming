#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
vector<bool> isPrime(M, 1);
void seive();
bool cmp(pair<int,int> a,pair<int,int> b)
{
    double x=(double)a.first/a.second;
    double y=(double)b.first/b.second;
    return x<y;
}
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> b(n);
    for(int i=0;i<n;i++)
        cin>>b[i];
    vector<pair<int,int>> c(n);
    for(int i=0;i<n;i++)
    {
        c[i].first=b[i];
        c[i].second=a[i];
    }
    sort(c.begin(),c.end(),cmp);
    ll ans=0;
    ll st=0;
    for(int i=0;i<n;i++)
    {
        ans+=c[i].first*st;
        st+=c[i].second;
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

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= M; i++)
    {
        if (isPrime[i] == true)
        {
            for (ll j = i * i; j <= M; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}