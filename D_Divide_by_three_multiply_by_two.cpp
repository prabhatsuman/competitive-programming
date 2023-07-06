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
vector<int> g[200005];
vector<int> vis(200005, 0);
vector<ll> v(200005);
map<ll, int> m;

int n;
void dfs(int node)
{
    if (vis[node] == 1)
        return;
    vis[node] = 1;
    ll x = v[node];
    if (m[x * 2] != 0)
    {
        g[node].push_back(m[x * 2]);
        g[m[x * 2]].push_back(node);
    }
    else if (x % 3 == 0 && m[x / 3] != 0)
    {
        g[node].push_back(m[x / 3]);
        g[m[x / 3]].push_back(node);
    }
    else
    {
        return;
    }
}
void print(int node, int par, vector<ll> &ans)
{

    ans.push_back(node);

    for (auto i : g[node])
    {
        if (i != par)
            print(i, node, ans);
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        v[i] = a;
        m[a] = i;
    }
    // print the graph
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i);
    }
    // print the graph
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << v[i] << " : ";
    //     for (auto j : g[i])
    //     {
    //         cout << v[j] << " ";
    //     }
    //     cout << nline;
    // }

    // find two nodes with degree 1
    int node1 = -1, node2 = -1;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == 1)
        {
            if (node1 == -1)
            {
                node1 = i;
            }
            else
            {
                node2 = i;
                break;
            }
        }
    }
    vector<ll> ans1;
    vector<ll> ans2;
    print(node1, -1, ans1);
    print(node2, -1, ans2);
    // for (auto i : ans1)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << nline;
    // for (auto i : ans2)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << nline;

    vector<ll> ans;
    bool flag = true;
    for (int i = 0; i < ans1.size() - 1; i++)
    {
        if ((v[ans1[i]] / 3LL == v[ans1[i + 1]]) || (v[ans1[i]] * 2LL == v[ans1[i + 1]]))
        {
            // cout<<"hi"<<nline;
            ans.push_back(ans1[i]);
        }
        else
        {
            flag = false;
            break;
        }
    }
        ans.push_back(ans1[ans1.size() - 1]);
    // for (auto i : ans)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << nline;
    
    if (flag)
    {

        for (auto i : ans)
        {
            cout << v[i] << " ";
        }
        cout << nline;
    }
    else
    {
       for(auto i:ans2){
           cout<<v[i]<<" ";
       }
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