#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
set<int> s[2];
vector<bool> vis(100005, false);
vector<bool> ins(100005, false);

vector<int> a[100005];
void dfs(int node, int par, int c)
{
    s[c].insert(node);
    for (auto i : a[node])
    {
        if (i != par)
        {
            dfs(i, node, !c);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 0,0);
    // for(int i=0;i<2;i++)
    // {
    //     for(auto j:s[i])
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<nline;
    // }

  
    int ans = 0;
    cout << s[0].size() * s[1].size() - (n - 1) << nline;
    // for (int i = 1; i <= n; i++)
    // {
    //     set<int> temp;
    //     if (s[0].find(i) != s[0].end())
    //     {
    //         temp = s[1];
    //     }
    //     else
    //     {
    //         temp = s[0];
    //     }
    //     for (auto j : temp)
    //     {
    //         if (find(a[i].begin(), a[i].end(), j) == a[i].end())
    //         {
    //             ans++;
    //             a[i].push_back(j);
    //             a[j].push_back(i);
    //         }
    //     }
    // }
    // cout << ans << nline;
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
