#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
vector<bool> isPrime(M, 1);
typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
void sieve();
int n, k;
vector<int> tree[50001];
int dp[50001][501];
int dp2[50001][501];
void dfs(int vertex, int parent)
{
    for (auto child : tree[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
    }
    dp[vertex][0] = 1;
    for (int i = 1; i <= k; i++)
    {
        dp[vertex][i] = 0;
        for (auto child : tree[vertex])
        {
            if (child == parent)
            {
                continue;
            }
            dp[vertex][i] += dp[child][i - 1];
        }
    }
}
void solve(int vertex, int parent)
{
    for(int i=0;i<=k;i++){
        dp2[vertex][i]=dp[vertex][i];
    }
    if(parent!=0)
    {
        dp2[vertex][1]+=dp2[parent][0];
        for(int i=2;i<=k;i++)
        {
            dp2[vertex][i]+=(dp2[parent][i-1]-dp[vertex][i-2]);
        }
    }

    for (auto child : tree[vertex])
    {
        if (child == parent)
            continue;
            solve(child, vertex);
    }
    
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    solve(1, 0);

    ll ans=0;
    for (int i = 1; i <= n; i++)
    {
        ans+=dp2[i][k];
    }
    cout<<(int)(0.5*ans)<<nline;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;

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