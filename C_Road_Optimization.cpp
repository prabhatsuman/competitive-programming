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

int helper(int i, int k, int n, vi &dist, vi &time, vvi &dp)
{
    if (i == n + 1)
        return 0;
    if (dp[i][k] != -1)
        return dp[i][k];
    int ans = 1e9;
    for (int j = 0; j <= k; j++)
    {
        if (i + j + 1 <= n + 1)
        {
            ans = min(helper(i + j + 1, k - j, n, dist, time, dp) + (dist[i + j + 1] - dist[i]) * time[i], ans);
        }
    }
    return dp[i][k] = ans;
}

void solve()
{
    int n, l, k;
    cin >> n >> l >> k;
    vi dist(n + 2, 0);
    vi time(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> dist[i];
    }
    dist[n + 1] = l;
    for (int i = 1; i <= n; i++)
    {
        cin >> time[i];
    }
    vector<vector<int>> dp(n + 2, vector<int>(k + 1, 1e9));

    cout << helper(1, k, n, dist, time, dp) << nline;
}

int main()
{
    godspeed;
    ll t = 1;
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
