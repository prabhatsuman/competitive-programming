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
#define read(x)       \
    for (auto &c : x) \
        cin >> c;
#define printv(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";
#define print2d(v)                            \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
            cout << v[i][j] << " ";           \
        cout << nline;                        \
    }
#define printp(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i].first << " " << v[i].second << nline;
#define printm(m)                                  \
    for (auto it = m.begin(); it != m.end(); it++) \
        cout << it->first << " " << it->second << nline;
#define prints(s)                                  \
    for (auto it = s.begin(); it != s.end(); it++) \
        cout << *it << " ";
#define pb push_back
#define print(x) cout << x << nline;
#define print2(x, y) cout << x << " " << y << nline;
#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
#define godspeed                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

/* -----------------------------Code Begins from here-------------------------------------------*/

void solve()
{
    ll n, k, c;
    cin >> n >> k >> c;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n-1; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<ll> cost(n + 1, 0);
    queue<ll> q;
    q.push(1);
    cost[1] = 0;
    vector<bool> vis(n + 1, false);
    vis[1] = true;
    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                cost[it] = cost[node] + c;
                q.push(it);
            }
        }
    }

    vector<ll> dis1(n + 1, 0);
    vis.assign(n + 1, false);

    q.push(1);
    vis[1] = true;
    dis1[1] = 0;
    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                dis1[it] = dis1[node] + k;
                q.push(it);
            }
        }
    }
    ll m = 0;
    ll it1 = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (dis1[i] > m)
        {
            m = dis1[i];
            it1 = i;
        }
    }
    vector<ll> dis2(n + 1, 0);
    vis.assign(n + 1, false);
    q.push(it1);
    vis[it1] = true;
    dis2[it1] = 0;

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;

                dis2[it] = dis2[node] + k;
                q.push(it);
            }
        }
    }

    vis.assign(n + 1, false);
    q.push(1);
    vis[1] = true;
    ll ans = (dis2[1] - cost[1]);
    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                ans = max(ans, dis2[it] - cost[it]);
                q.push(it);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    godspeed;
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
    ll res = power(a, b / 2);
    if (b & 1)
    {
        return (a * (res * res) % M) % M;
    }
    else
    {
        return (res * res) % M;
    }
}
