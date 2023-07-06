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
int n;
vector<int> g[100005];
vector<int> cur(100005, 0);
vector<int> req(100005, 0);
vector<int> vt;
int ans = 0;
void dfs(int vertex, int parent, int odd_count,int even_count,int level)
{
    if(level%2==0)
    {
        int cur_val=(cur[vertex]+even_count)%2;
        if(cur_val!=req[vertex])
        {
            ans++;
            vt.push_back(vertex);
            even_count++;
        }
    }
    else
    {
        int cur_val=(cur[vertex]+odd_count)%2;
        if(cur_val!=req[vertex])
        {
            ans++;
             vt.push_back(vertex);
            odd_count++;
        }
    }
    for(auto child: g[vertex])
    {
        if(child == parent)
            continue;
        dfs(child, vertex, odd_count, even_count, level+1);
    }
}
void solve()
{
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>cur[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>req[i];
    }
    dfs(1,0,0,0,0);
    cout<<ans<<nline;
    for(auto e: vt)
    {
        cout<<e<<nline;
    }
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