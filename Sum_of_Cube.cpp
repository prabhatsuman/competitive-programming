#include <bits/stdc++.h>
#define ll long long
#define M 998244353
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
ll sum=0;
int dp[1000001];
void fun(int i,int j,vector<ll> &pre)
{
    if(i>j){
        return;
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll>pre(n+1,0);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i-1];
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
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
