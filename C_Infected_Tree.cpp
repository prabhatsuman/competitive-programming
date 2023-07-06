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

void countSubTree(int node, int parent, vector<vector<int>> &tree, vector<int> &subtrees)
{

    subtrees[node] = 1;
    for (auto child : tree[node])
    {
        if (child == parent)
            continue;
        countSubTree(child, node, tree, subtrees);
        subtrees[node] += subtrees[child];
    }
}
void dfs(int node, int parent, vector<vector<int>> &tree, vector<int> &subtrees, vector<int> &dp)
{
    vector<int> children;
    for (auto child : tree[node])
    {
        if (child == parent)
            continue;
        children.push_back(child);

        dfs(child, node, tree, subtrees, dp);
    }
    if (children.size() == 0)
    {
        return;
    }

    if (children.size() == 1)
    {
        dp[node] = subtrees[children[0]] - 1;
        return;
    }
    dp[node] = max(dp[node], dp[children[1]] + subtrees[children[0]] - 1);
    dp[node] = max(dp[node], dp[children[0]] + subtrees[children[1]] - 1);
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    vector<int> subtrees(n + 1, 0);
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    countSubTree(1, 0, tree, subtrees);
    dfs(1, 0, tree, subtrees, dp);
    cout << dp[1] << nline;
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