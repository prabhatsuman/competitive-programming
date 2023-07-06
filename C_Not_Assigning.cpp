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
map<pair<int, int>, int> mp;
void sieve();
void dfs(int node, int parent, vector<int> tree[], int r = 2)
{
    for (auto child : tree[node])
    {
        if (child != parent)
        {
            pair<int, int> p = {min(node, child), max(node, child)};
            mp[p] = r;

            dfs(child, node, tree, r ^ 1);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> tree[n + 1];
    vector<pair<int, int>> edge;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        pair<int, int> p = {min(u, v), max(u, v)};
        edge.push_back(p);

        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    bool flag = true;
    int count = 0;
    int leaf = n;
    for (int i = 1; i <= n; i++)
    {
        if (tree[i].size() == 1)
        {
            leaf = min(leaf, i);
            count++;
            if (count > 2)
            {
                flag = false;
                break;
            }
        }
    }
    // sort(tree, tree + n + 1);
    if (flag)
    {

        dfs(leaf, -1, tree);
        for (auto x : edge)
        {
            cout << mp[x] << " ";
        }
        cout << nline;
    }
    else
    {
        cout << -1 << nline;
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