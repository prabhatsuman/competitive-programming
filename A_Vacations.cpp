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
int minRest(vector<int> &v, vector<vector<int>>&dp,int i,int last)
{
    if(i<0)
    {
        return 0;
    }
    if(dp[i][last]!=-1)
    {
        return dp[i][last];
    }
    if(v[i]==0)
    {
        return dp[i][last]=minRest(v,dp,i-1,0)+1;
    }
    if(v[i]==1)
    {
        if(last==v[i])
        {
            return dp[i][last]=1+minRest(v,dp,i-1,0);

        }
        else
        {
            return dp[i][last]=minRest(v,dp,i-1,1);
        }
    }
    if(v[i]==2)
    {
        if(last==v[i])
        {
            return dp[i][last]=1+minRest(v,dp,i-1,0);

        }
        else
        {
            return dp[i][last]=minRest(v,dp,i-1,2);
        }
    }
    if(v[i]==3)
    {
        int a=INT_MAX,b=INT_MAX;
        if(last==1)
        {
            a=minRest(v,dp,i-1,2);
        }
        else if(last==2)
        {
            a=minRest(v,dp,i-1,1);
        }
        else
        {
            a=min(minRest(v,dp,i-1,1),minRest(v,dp,i-1,2));
        }
        dp[i][last]=min(a,b);

    }
    return dp[i][last];

}
void solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>>dp(n,vector<int>(3,-1));
    print(minRest(v,dp,n-1,0));
    print2d(dp);
    





  
    
    


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

