/* 
    Prabhat_007
*/
#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
#define print2d(v) for (int i = 0; i < v.size(); i++) { for (int j = 0; j < v[i].size(); j++) cout << v[i][j] << " "; cout << nline; }
#define printp(v) for (int i = 0; i < v.size(); i++) cout << v[i].first << " " << v[i].second << nline;
#define printm(m) for (auto it = m.begin(); it != m.end(); it++) cout << it->first << " " << it->second << nline;
#define prints(s) for (auto it = s.begin(); it != s.end(); it++) cout << *it << " ";
#define pb push_back
#define print(x) cout << x << nline;
#define print2(x, y) cout << x << " " << y << nline;
#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
#define godspeed ios_base::sync_with_stdio(false); cin.tie(NULL);

/* -----------------------------Code Begins from here-------------------------------------------*/
// ll solve(int n,int pos, vector<vector<ll>> &v, vector<vector<ll>> &dp)
// {
//     if(dp[pos][n]!=-1)
//     {
//         return dp[pos][n];
//     }
//     if(n==0)
//     {
//         if(pos==0)
//         {
//             return v[0][0];
//         }
//         else{
//             return v[1][0];
//         }
//     }
//     if(pos==0)
//     {
//         return dp[pos][n]= max(solve(n-1,1,v,dp)+v[0][n],solve(n-1,0,v,dp));
//     }
//     else{
//         return dp[pos][n]= max(solve(n-1,0,v,dp)+v[1][n],solve(n-1,1,v,dp));
//     }
// }

void solve()
{
    int n;
    cin>>n;
   vector<vector<ll>> v(2,vector<ll>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        cin>>v[0][i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>v[1][i];
    }
    vector<vector<ll>> dp(2,vector<ll>(n+1,0));

  
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=max(dp[1][i-1]+v[0][i],dp[0][i-1]);
        dp[1][i]=max(dp[0][i-1]+v[1][i],dp[1][i-1]);
    }
   
   
    cout<<max(dp[0][n],dp[1][n])<<nline;

    // cout<<max(solve(n-1,0,v,dp),solve(n-1,1,v,dp));

}

int main()
{
    godspeed;
    ll t=1;
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

